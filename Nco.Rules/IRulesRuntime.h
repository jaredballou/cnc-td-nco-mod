#pragma once

#include <Logger.h>

#include "IRulesIni.h"
#include "RulesIniReader.h"
#include "RulesIniTypes.h"
#include "RulesIniRuleKey.h"

class IRulesRuntime
{
protected:
	IRulesRuntime()
	{
	}

public:
	virtual bool LoadRulesIfRequired() = 0;

	virtual IRulesIni& GetRules() = 0;

	virtual IRulesIniReader& GetBaseRulesReader() = 0;

	template<class T> T ReadRuleValue(SectionName section, RuleName rule, T defaultValue)
	{
		return GetBaseRulesReader().ReadRuleValue<T>(section, rule, defaultValue);
	}

	template<class T> T ReadRuleValue(SectionName section, RuleName rule)
	{
		return GetBaseRulesReader().ReadRuleValue<T>(section, rule);
	}

	template<class T> T ReadRuleValue(const RulesIniRuleKey& key)
	{
		return GetBaseRulesReader().ReadRuleValue<T>(key);
	}

	virtual bool LuaIsEnabled() = 0;

	virtual bool LuaConsoleIsEnabled() = 0;

	virtual unsigned int GetGameTickIntervalInMs() = 0;

	virtual const std::vector<const char*>& GetLuaScripts() = 0;

	virtual LogLevel GetCurrentLogLevel() = 0;

	virtual const char* GetLogFilePath() = 0;
};
