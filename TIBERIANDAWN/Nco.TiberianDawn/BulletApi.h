#pragma once

#include <IRulesIniSection.h>
#include <LambdaValidator.h>
#include <LuaValueAdapter.h>
#include <NumericRangeValidator.h>
#include <ParseCheckValidator.h>
#include <RulesSectionTypeWrapperApi.h>

#include "../DEFINES.H"
#include "../TYPE.H"

#include "rules_ini_bullet.h"
#include "rules_ini_generic.h"
#include "rules_ini_mods.h"
#include "TiberianDawnNcoRuntime.h"

#define EXTRACTOR_BLT(f) EXTRACTOR(BulletTypeClass, f)
#define INJECTOR_BLT(t, f) INJECTOR(BulletTypeClass, t, f)
#define SIMPLE_EXTRACTOR_BLT(f) SIMPLE_EXTRACTOR(BulletTypeClass, f)
#define SIMPLE_INJECTOR_BLT(t, f) SIMPLE_INJECTOR(BulletTypeClass, t, f)

class BulletApi : public RulesSectionTypeWrapperApi<BulletTypeClass, BulletType>
{
protected:
	BulletApi(IRulesIniSection& rulesInfo, std::function<int(void)> getCount) :
		RulesSectionTypeWrapperApi(
			strdup("Bullets"),
			rulesInfo,
			BULLET_FIRST,
			getCount,
			[](auto typeString) {
				return &NcoTypeConverter().Parse<BulletType>(typeString);
			},
			[](auto type) {
				return &NcoTypeConverter().ToString(type);
			}
		)
	{
		technoTypeWrapper.WithFieldWrapper(
			BULLET_HIGH_RULE,
			EXTRACTOR_BLT((bool)i.IsHigh),
			SIMPLE_INJECTOR_BLT(bool, IsHigh),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_ANTI_AIRCRAFT_RULE,
			EXTRACTOR_BLT((bool)i.IsAntiAircraft),
			SIMPLE_INJECTOR_BLT(bool, IsAntiAircraft),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_TRANSLUCENT_RULE,
			EXTRACTOR_BLT((bool)i.IsTranslucent),
			SIMPLE_INJECTOR_BLT(bool, IsTranslucent),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_ARCING_RULE,
			EXTRACTOR_BLT((bool)i.IsArcing),
			SIMPLE_INJECTOR_BLT(bool, IsArcing),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_HOMING_RULE,
			EXTRACTOR_BLT((bool)i.IsHoming),
			SIMPLE_INJECTOR_BLT(bool, IsHoming),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_DROPPING_RULE,
			EXTRACTOR_BLT((bool)i.IsDropping),
			SIMPLE_INJECTOR_BLT(bool, IsDropping),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_INVISIBLE_RULE,
			EXTRACTOR_BLT((bool)i.IsInvisible),
			SIMPLE_INJECTOR_BLT(bool, IsInvisible),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_PROXIMITY_ARMED_RULE,
			EXTRACTOR_BLT((bool)i.IsProximityArmed),
			SIMPLE_INJECTOR_BLT(bool, IsProximityArmed),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_FLAME_EQUIPPED_RULE,
			EXTRACTOR_BLT((bool)i.IsFlameEquipped),
			SIMPLE_INJECTOR_BLT(bool, IsFlameEquipped),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_FUELED_RULE,
			EXTRACTOR_BLT((bool)i.IsFueled),
			SIMPLE_INJECTOR_BLT(bool, IsFueled),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_FACELESS_RULE,
			EXTRACTOR_BLT((bool)i.IsFaceless),
			SIMPLE_INJECTOR_BLT(bool, IsFaceless),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_INACCURATE_RULE,
			EXTRACTOR_BLT((bool)i.IsInaccurate),
			SIMPLE_INJECTOR_BLT(bool, IsInaccurate),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BULLET_WARHEAD_RULE,
			EXTRACTOR_BLT(NcoTypeConverter().ToStringOrDefault(i.Warhead)),
			[](BulletTypeClass& i, ILuaStateWrapper& l, LuaValueAdapter& va, int si) {
				i.Warhead = NcoTypeConverter().ParseOrDefault(
					va.Read<const char*>(l, si),
					i.Warhead
				);
			},
			ParseCheckValidator<WarheadType>::Build("Warhead", [](auto valueString) {
				return &NcoTypeConverter().Parse<WarheadType>(valueString);
			})
		).WithFieldWrapper(
			BULLET_ARMING_RULE,
			SIMPLE_EXTRACTOR_BLT(Arming),
			SIMPLE_INJECTOR_BLT(int, Arming),
			NumbericRangeValidator<>::Build(0, INT_MAX)
		).WithFieldWrapper(
			BULLET_RANGE_RULE,
			SIMPLE_EXTRACTOR_BLT(Range),
			SIMPLE_INJECTOR_BLT(int, Range),
			NumbericRangeValidator<>::Build(0, INT_MAX)
		).WithFieldWrapper(
			SPEED_RULE,
			EXTRACTOR_BLT((unsigned char)i.MaxSpeed),
			[](BulletTypeClass& i, ILuaStateWrapper& l, LuaValueAdapter& va, int si) {
				i.MaxSpeed = (MPHType)va.Read<unsigned char>(l, si);
			},
			NumbericRangeValidator<>::Build(0, UCHAR_MAX)
		).WithFieldWrapper(
			RATE_OF_TURN_RULE,
			SIMPLE_EXTRACTOR_BLT(ROT),
			SIMPLE_INJECTOR_BLT(unsigned int, ROT),
			NumbericRangeValidator<>::Build(0, UCHAR_MAX)
		).WithFieldWrapper(
			IMAGE_RULE,
			SIMPLE_EXTRACTOR_BLT(Image),
			[](BulletTypeClass& i, ILuaStateWrapper& l, LuaValueAdapter& va, int si) {
				i.Image = strdup(va.Read<const char*>(l, si));
			},
			PrimitiveTypeValidator<const char*>::Build()
		).WithFieldWrapper(
			FRIENDLY_NAME_RULE,
			SIMPLE_EXTRACTOR_BLT(FriendlyName),
			[](BulletTypeClass& i, ILuaStateWrapper& l, LuaValueAdapter& va, int si) {
				i.FriendlyName = strdup(va.Read<const char*>(l, si));
			},
			PrimitiveTypeValidator<const char*>::Build()
		).WithFieldWrapper(
			IS_MOD_TYPE_RULE,
			EXTRACTOR_BLT((bool)i.IsModType),
			SIMPLE_INJECTOR_BLT(bool, IsModType),
			PrimitiveTypeValidator<bool>::Build()
		).WithFieldWrapper(
			BASE_TYPE_RULE,
			SIMPLE_EXTRACTOR_BLT(ModBaseIniName),
			[](BulletTypeClass& i, ILuaStateWrapper& l, LuaValueAdapter& va, int si) {
				strcpy(i.ModBaseIniName, strdup(va.Read<const char*>(l, si)));
			},
			LambdaValidator<const char*>::Build("String must be at most 32 characters long", [] (const char* v) {
				return StringIsEmpty(v) || strlen(v) < 33;
			})
		);
	}

public:
	static LuaApi& Build(IRulesIniSection& rulesInfo, std::function<int(void)> getCount)
	{
		return *(new BulletApi(rulesInfo, getCount));
	}

};
