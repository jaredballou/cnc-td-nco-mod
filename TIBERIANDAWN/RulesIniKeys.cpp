#include "rules_ini_enhancements.h"
#include "rules_ini_game.h"
#include "rules_ini_mods.h"
#include "RulesIniRuleKey.h"
// enhancement rules
const RulesIniRuleKey* RALLY_POINTS_RULE_KEY;
const RulesIniRuleKey* A_STAR_PATH_FINDING_RULE_KEY;
const RulesIniRuleKey* COMMANDO_GUARD_RULE_KEY;

const RulesIniRuleKey* AI_HARVESTERS_PER_REFINERY_RULE_KEY;
const RulesIniRuleKey* HUMAN_HARVESTERS_PER_REFINERY_RULE_KEY;

const RulesIniRuleKey* MULTI_WALL_LENGTH_RULE_KEY;
const RulesIniRuleKey* FULL_COST_MULTI_WALLS_LENGTH_RULE_KEY;

// mod rules
const RulesIniRuleKey* INFANTRY_COUNT_RULE_KEY;
const RulesIniRuleKey* UNIT_COUNT_RULE_KEY;

// game rules
const RulesIniRuleKey* MAX_BUILD_DISTANCE_RULE_KEY;

const RulesIniRuleKey* CREDITS_PER_TIBERIUM_SCOOP_RULE_KEY;
const RulesIniRuleKey* MAX_HARVESTER_CAPACITY_RULE_KEY;

const RulesIniRuleKey* PRODUCTION_STEPS_PER_TICK_RULE_KEY;
const RulesIniRuleKey* FACTORY_COUNT_STEP_MULTIPLER_RULE_KEY;
const RulesIniRuleKey* TOTAL_PRODUCTION_STEPS_RULE_KEY;

const RulesIniRuleKey* UNIT_REPAIR_FACTOR_RULE_KEY;
const RulesIniRuleKey* UNIT_REPAIR_STEP_RULE_KEY;

const RulesIniRuleKey* AIRCRAFT_REPAIR_FACTOR_RULE_KEY;
const RulesIniRuleKey* AIRCRAFT_REPAIR_STEP_RULE_KEY;

const RulesIniRuleKey* RENAME_TECH_CENTER_TO_PRISON_RULE_KEY;
const RulesIniRuleKey* SURVIVORS_FROM_BUILDINGS_RULE_KEY;
const RulesIniRuleKey* ALLOW_BUILDING_BESIDE_WALLS_RULE_KEY;
const RulesIniRuleKey* PREVENT_BUILDING_IN_SHROUD_RULE_KEY;
const RulesIniRuleKey* HIDE_E3_FROM_GDI_RULE_KEY;
const RulesIniRuleKey* HIDE_MSAM_FROM_GDI_RULE_KEY;
const RulesIniRuleKey* HIDE_APC_FROM_NOD_RULE_KEY;
const RulesIniRuleKey* HIDE_TMPL_FROM_GDI_RULE_KEY;
const RulesIniRuleKey* HIDE_OBLI_FROM_GDI_RULE_KEY;
const RulesIniRuleKey* HIDE_MSAM_FROM_NOD_RULE_KEY;
const RulesIniRuleKey* HIDE_ADV_COMM_FROM_NOD_RULE_KEY;
const RulesIniRuleKey* ALLOW_NOD_TO_BUILD_NUK2_EARLY_RULE_KEY;
const RulesIniRuleKey* HIDE_HELIPAD_FROM_NOD_RULE_KEY;
const RulesIniRuleKey* HIDE_SBAG_FROM_GDI_RULE_KEY;
const RulesIniRuleKey* SET_GDI_SCENARIO_2_BUILD_LEVEL_RULE_KEY;
const RulesIniRuleKey* ALLOW_BUILDING_ALL_FOR_HOUSE_RULE_KEY;
const RulesIniRuleKey* ONLY_GDI_CAN_USE_ION_CANNON_RULE_KEY;
const RulesIniRuleKey* ONE_TIME_NUKE_RULE_KEY;
const RulesIniRuleKey* ONLY_ALLOW_NUKE_IF_PARTS_COLLECTED_RULE_KEY;
const RulesIniRuleKey* TIBERIUM_INFANTRY_DAMAGE_RULE_KEY;
const RulesIniRuleKey* TIBERIUM_GROWTH_RATE_RULE_KEY;
const RulesIniRuleKey* TIBERIUM_SPREAD_RATE_RULE_KEY;
const RulesIniRuleKey* SPEEDY_BUILDS_RULE_KEY;
const RulesIniRuleKey* ATTACKER_ADVANTAGE_RULE_KEY;
const RulesIniRuleKey* DEFEND_AGAINST_FRIENDLY_FIRE_RULE_KEY;
const RulesIniRuleKey* TARGET_TREES_RULE_KEY;
const RulesIniRuleKey* MCV_REDEPLOY_RULE_KEY;
const RulesIniRuleKey* VISCEROIDS_RULE_KEY;
const RulesIniRuleKey* UNITS_INDESTRUCTIBLE_RULE_KEY;
const RulesIniRuleKey* THREE_POINT_TURNS_RULE_KEY;
const RulesIniRuleKey* TIBERIUM_GROWS_RULE_KEY;
const RulesIniRuleKey* TIBERIUM_SPREADS_RULE_KEY;
const RulesIniRuleKey* SLOW_TIBERIUM_RULE_KEY;
const RulesIniRuleKey* SHOW_BIBS_RULE_KEY;
const RulesIniRuleKey* AUTO_SCATTER_RULE_KEY;
const RulesIniRuleKey* NAME_CIVILIAN_BUILDINGS_RULE_KEY;
const RulesIniRuleKey* CAN_BUY_HELIPAD_ONLY_RULE_KEY;
const RulesIniRuleKey* DEBUG_LOGGING_RULE_KEY;

void InitaliseRuleKeys()
{
	RALLY_POINTS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, RALLY_POINTS_RULE);
	A_STAR_PATH_FINDING_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, A_STAR_PATH_FINDING_RULE);
	COMMANDO_GUARD_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, COMMANDO_GUARD_RULE);

	AI_HARVESTERS_PER_REFINERY_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, AI_HARVESTERS_PER_REFINERY_RULE);
	HUMAN_HARVESTERS_PER_REFINERY_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, HUMAN_HARVESTERS_PER_REFINERY_RULE);

	MULTI_WALL_LENGTH_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, MULTI_WALL_LENGTH_RULE);
	FULL_COST_MULTI_WALLS_LENGTH_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, FULL_COST_MULTI_WALLS_LENGTH_RULE);

	INFANTRY_COUNT_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(MOD_RULES_SECTION_NAME, INFANTRY_COUNT_RULE);
	UNIT_COUNT_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(MOD_RULES_SECTION_NAME, UNIT_COUNT_RULE);

	MAX_BUILD_DISTANCE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, MAX_BUILD_DISTANCE_RULE);

	CREDITS_PER_TIBERIUM_SCOOP_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, CREDITS_PER_TIBERIUM_SCOOP_RULE);
	MAX_HARVESTER_CAPACITY_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, MAX_HARVESTER_CAPACITY_RULE);

	PRODUCTION_STEPS_PER_TICK_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, PRODUCTION_STEPS_PER_TICK_RULE);
	FACTORY_COUNT_STEP_MULTIPLER_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, FACTORY_COUNT_STEP_MULTIPLER_RULE);
	TOTAL_PRODUCTION_STEPS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TOTAL_PRODUCTION_STEPS_RULE);

	UNIT_REPAIR_FACTOR_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, UNIT_REPAIR_FACTOR_RULE);
	UNIT_REPAIR_STEP_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, UNIT_REPAIR_STEP_RULE);

	AIRCRAFT_REPAIR_FACTOR_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, AIRCRAFT_REPAIR_FACTOR_RULE);
	AIRCRAFT_REPAIR_STEP_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, AIRCRAFT_REPAIR_STEP_RULE);

	RENAME_TECH_CENTER_TO_PRISON_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, RENAME_TECH_CENTER_TO_PRISON_RULE);
	SURVIVORS_FROM_BUILDINGS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, SURVIVORS_FROM_BUILDINGS_RULE);
	ALLOW_BUILDING_BESIDE_WALLS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ALLOW_BUILDING_BESIDE_WALLS_RULE);
	PREVENT_BUILDING_IN_SHROUD_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, PREVENT_BUILDING_IN_SHROUD_RULE);
	HIDE_E3_FROM_GDI_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_E3_FROM_GDI_RULE);
	HIDE_MSAM_FROM_GDI_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_MSAM_FROM_GDI_RULE);
	HIDE_APC_FROM_NOD_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_APC_FROM_NOD_RULE);
	HIDE_TMPL_FROM_GDI_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_TMPL_FROM_GDI_RULE);
	HIDE_OBLI_FROM_GDI_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_OBLI_FROM_GDI_RULE);
	HIDE_MSAM_FROM_NOD_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_MSAM_FROM_NOD_RULE);
	HIDE_ADV_COMM_FROM_NOD_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_ADV_COMM_FROM_NOD_RULE);
	ALLOW_NOD_TO_BUILD_NUK2_EARLY_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ALLOW_NOD_TO_BUILD_NUK2_EARLY_RULE);
	HIDE_HELIPAD_FROM_NOD_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_HELIPAD_FROM_NOD_RULE);
	HIDE_SBAG_FROM_GDI_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, HIDE_SBAG_FROM_GDI_RULE);
	SET_GDI_SCENARIO_2_BUILD_LEVEL_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, SET_GDI_SCENARIO_2_BUILD_LEVEL_RULE);
	ALLOW_BUILDING_ALL_FOR_HOUSE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ALLOW_BUILDING_ALL_FOR_HOUSE_RULE);
	ONLY_GDI_CAN_USE_ION_CANNON_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ONLY_GDI_CAN_USE_ION_CANNON_RULE);
	ONE_TIME_NUKE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ONE_TIME_NUKE_RULE);
	ONLY_ALLOW_NUKE_IF_PARTS_COLLECTED_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ONLY_ALLOW_NUKE_IF_PARTS_COLLECTED_RULE);
	TIBERIUM_INFANTRY_DAMAGE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TIBERIUM_INFANTRY_DAMAGE_RULE);
	TIBERIUM_GROWTH_RATE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TIBERIUM_GROWTH_RATE_RULE);
	TIBERIUM_SPREAD_RATE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TIBERIUM_SPREAD_RATE_RULE);
	SPEEDY_BUILDS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, SPEEDY_BUILDS_RULE);
	ATTACKER_ADVANTAGE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, ATTACKER_ADVANTAGE_RULE);
	DEFEND_AGAINST_FRIENDLY_FIRE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, DEFEND_AGAINST_FRIENDLY_FIRE_RULE);
	TARGET_TREES_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TARGET_TREES_RULE);
	MCV_REDEPLOY_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, MCV_REDEPLOY_RULE);
	VISCEROIDS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, VISCEROIDS_RULE);
	UNITS_INDESTRUCTIBLE_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, UNITS_INDESTRUCTIBLE_RULE);
	THREE_POINT_TURNS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, THREE_POINT_TURNS_RULE);
	TIBERIUM_GROWS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TIBERIUM_GROWS_RULE);
	TIBERIUM_SPREADS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, TIBERIUM_SPREADS_RULE);
	SLOW_TIBERIUM_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, SLOW_TIBERIUM_RULE);
	SHOW_BIBS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, SHOW_BIBS_RULE);
	AUTO_SCATTER_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, AUTO_SCATTER_RULE);
	NAME_CIVILIAN_BUILDINGS_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, NAME_CIVILIAN_BUILDINGS_RULE);
	CAN_BUY_HELIPAD_ONLY_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, CAN_BUY_HELIPAD_ONLY_RULE);
	DEBUG_LOGGING_RULE_KEY = &RulesIniRuleKey::BuildRuleKey(GAME_RULES_SECTION_NAME, DEBUG_LOGGING_RULE);
}