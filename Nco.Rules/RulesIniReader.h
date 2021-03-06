#pragma once

#include <functional>

#include <Logger.h>
#include <ResultWithValue.h>
#include <TwoWayStringMap.h>

#include "IRulesIni.h"
#include "IRulesIniReader.h"
#include "RulesIniRuleKey.h"

class RulesIniReader : public IRulesIniReader
{
protected:
	RulesIniReader(IRulesIni& rulesIniToRead) : IRulesIniReader(rulesIniToRead)
	{
	}

	template<class T> T GetParsedStringRule(
		RulesIniRule& rule,
		const char* typeName,
		std::function<ResultWithValue<T>*(const char *)> parser,
		T defaultValue
	)
	{
		auto& stringValueOptional = rulesIni.ReadOptionalStringRule(rule);

		if (!stringValueOptional.Present())
		{
			delete &stringValueOptional;

			return rule.GetDefaultValueOr<T>(defaultValue);
		}

		auto stringValue = stringValueOptional.Get<char*>();

		auto& parseResult = *parser(stringValue);

		if (parseResult.IsErrorResult())
		{
			rulesIni.MarkAsInvalid();

			ShowError("Failed to parse value '%s' as %s for [%s]: %s", stringValue, typeName, rule.GetStringKey(), parseResult.GetError());
			
			delete &stringValueOptional;
			delete &parseResult;

			return rule.GetDefaultValueOr<T>(defaultValue);
		}

		auto value = parseResult.GetValue();
		
		delete &stringValueOptional;
		delete &parseResult;

		return value;
	}

	bool ReadBoolRule(RulesIniRule& rule)
	{
		auto defaultValue = rule.GetDefaultValueOr(false);

		auto& ruleValueOptional = rulesIni.ReadOptionalStringRule(rule);

		if (!ruleValueOptional.Present())
		{
			LogTrace("No rules ini value found, default will be used");

			delete &ruleValueOptional;

			return defaultValue;
		}

		auto ruleValue = ruleValueOptional.Get<char*>();

		auto boolValue = ParseBooleanOrDefault(ruleValue, defaultValue);

		delete &ruleValueOptional;

		return boolValue;
	}

	unsigned int ReadUnsignedIntRule(RulesIniRule& rule)
	{
		auto defaultValue = rule.GetDefaultValueOr(0u);

		LogTrace("Resolving rule value: %s", rule.GetStringKey());
		LogTrace("Default value: %u", defaultValue);

		auto& ruleValueOptional = rulesIni.ReadOptionalStringRule(rule);

		if (!ruleValueOptional.Present())
		{
			LogTrace("No rules ini value found, default will be used");

			delete &ruleValueOptional;

			return defaultValue;
		}

		auto ruleValueStr = ruleValueOptional.Get<char*>();

		auto isValid = IsUnsignedIntString(ruleValueStr);

		if (!isValid)
		{
			rulesIni.MarkAsInvalid();

			ShowError(
				"Rule [%s] must be a unsigned integer number. Value provided: %s",
				rule.GetStringKey(),
				ruleValueStr
			);

			delete &ruleValueOptional;

			return defaultValue;
		}

		auto ruleValue = strtoul(ruleValueStr, NULL, 10);

		delete &ruleValueOptional;

		if (!rule.HasValueToAllowAlways() || ruleValue != rule.GetValueToAllowAlways<unsigned int>())
		{
			auto minValueInclusive = rule.GetMinOrDefault(0u);
			auto maxValueInclusive = rule.GetMaxOrDefault(UINT_MAX);

			if (ruleValue < minValueInclusive || ruleValue > maxValueInclusive)
			{
				rulesIni.MarkAsInvalid();

				ShowError(
					"Rule [%s] must be between %u and %u (inclusive). Value provided: %u",
					rule.GetStringKey(),
					minValueInclusive,
					maxValueInclusive,
					ruleValue
				);

			}
		}

		LogTrace("Resolved value: %u", ruleValue);
		LogDebug("Setting rule [%s] = %u", rule.GetStringKey(), ruleValue);

		return ruleValue;
	}

	double ReadDoubleRule(RulesIniRule& rule, bool* valueFound = NULL)
	{
		auto defaultValue = rule.GetDefaultValueOr(0.0);

		LogTrace("Resolving rule value: %s", rule.GetStringKey());
		LogTrace("Default value: %f", defaultValue);

		auto& ruleValueOptional = rulesIni.ReadOptionalStringRule(rule);

		if (!ruleValueOptional.Present())
		{
			LogTrace("No rules ini value found, default will be used");

			if (valueFound != NULL)
			{
				*valueFound = false;
			}

			delete &ruleValueOptional;

			return defaultValue;
		}

		if (valueFound != NULL)
		{
			*valueFound = true;
		}

		auto ruleValueStr = ruleValueOptional.Get<char*>();

		auto isValid = IsDoubleString(ruleValueStr);

		if (!isValid)
		{
			rulesIni.MarkAsInvalid();

			ShowError(
				"Rule [%s] must be a floating point number. Value provided: %s",
				rule.GetStringKey(),
				ruleValueStr
			);

			delete &ruleValueOptional;

			return defaultValue;
		}

		auto ruleValue = strtod(ruleValueStr, NULL);

		delete &ruleValueOptional;

		if (!rule.HasValueToAllowAlways() || ruleValue != rule.GetValueToAllowAlways<double>())
		{
			auto minValueInclusive = rule.GetMinOrDefault(DBL_MIN);
			auto maxValueInclusive = rule.GetMaxOrDefault(DBL_MAX);

			if (ruleValue < minValueInclusive || ruleValue > maxValueInclusive)
			{
				rulesIni.MarkAsInvalid();

				ShowError(
					"Rule [%s] must be between %f and %f (inclusive). Value provided: %f",
					rule.GetStringKey(),
					minValueInclusive,
					maxValueInclusive,
					ruleValue
				);
			}
		}

		LogTrace("Resolved value: %f", ruleValue);
		LogDebug("Setting rule [%s] = %f", rule.GetStringKey(), ruleValue);

		return ruleValue;
	}

	/// <summary>
	/// Fixed is a reference to the C++ type used in Red Alert for
	/// it's INI double values that are converted to unsigned integers
	/// </summary>
	/// <returns>The double rules value converted to a `fixed` unsigned int</returns>
	unsigned int ReadFixedRule(RulesIniRule& rule)
	{
		auto defaultValue = rule.GetDefaultValueOr(0u);

		bool valueFound = false;
		auto ruleValueAsDouble = ReadDoubleRule(rule, &valueFound);

		if (!valueFound)
		{
			return defaultValue;
		}

		if (ruleValueAsDouble < 0.00 || ruleValueAsDouble > 0.99)
		{
			rulesIni.MarkAsInvalid();

			ShowError(
				"Rule [%s] must be a floating point number between 0.00 and 0.99 (inclusive), value provided: %f",
				rule.GetStringKey(),
				ruleValueAsDouble
			);

			return defaultValue;
		}

		auto defaultValueAsPercentage = rule.GetDefaultValueAsPercentage<double>();

		auto onePercent = defaultValue / (defaultValueAsPercentage * 100);
		auto ruleValueAsPercentage = ruleValueAsDouble * 100;

		return nearbyint(ruleValueAsPercentage * onePercent);
	}

	virtual bool SetDefaultRuleValue(RulesIniRule& rule)
	{
		return false;
	}

public:
	static IRulesIniReader& Build(IRulesIni& rules)
	{
		return *(new RulesIniReader(rules));
	}

	RulesIniRule& GetRule(const RulesIniRuleKey& key)
	{
		if (!rulesIni.HasSection(key.SectionKey))
		{
			rulesIni << key.Section;
		}

		auto& section = rulesIni[key.SectionKey];

		if (!section.HasRule(key.RuleKey))
		{
			section << key.Rule;
		}

		return section[key.RuleKey];
	}

	RulesIniRule& GetRule(SectionName section, RuleName ruleName)
	{
		auto& key = RulesIniRuleKey::BuildRuleKey(section, ruleName);
		auto& rule = GetRule(key);

		delete &key;

		return rule;
	}

};
