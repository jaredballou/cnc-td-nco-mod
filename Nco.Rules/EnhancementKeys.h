#pragma once

#include "rules_ini_enhancements.h"
#include "RulesIniRuleKey.h"

#define INIT_ENHANCEMENT_KEY(key, rule) key = key != NULL ? key : &RulesIniRuleKey::BuildRuleKey(ENHANCEMENTS_RULES_SECTION_NAME, rule)

class EnhancementKeys final
{
private:
	EnhancementKeys()
	{
	}

public:
	static RulesIniRuleKey* RALLY_POINTS_RULE_KEY;
	static RulesIniRuleKey* A_STAR_PATH_FINDING_RULE_KEY;
	static RulesIniRuleKey* COMMANDO_GUARD_RULE_KEY;

	static RulesIniRuleKey* AI_HARVESTERS_PER_REFINERY_RULE_KEY;
	static RulesIniRuleKey* HUMAN_HARVESTERS_PER_REFINERY_RULE_KEY;

	static RulesIniRuleKey* MULTI_WALL_LENGTH_RULE_KEY;
	static RulesIniRuleKey* FULL_COST_MULTI_WALLS_LENGTH_RULE_KEY;

	static void InitIfNeeded()
	{
		INIT_ENHANCEMENT_KEY(RALLY_POINTS_RULE_KEY, RALLY_POINTS_RULE);

		INIT_ENHANCEMENT_KEY(A_STAR_PATH_FINDING_RULE_KEY, A_STAR_PATH_FINDING_RULE);
		INIT_ENHANCEMENT_KEY(COMMANDO_GUARD_RULE_KEY, COMMANDO_GUARD_RULE);

		INIT_ENHANCEMENT_KEY(AI_HARVESTERS_PER_REFINERY_RULE_KEY, AI_HARVESTERS_PER_REFINERY_RULE);
		INIT_ENHANCEMENT_KEY(HUMAN_HARVESTERS_PER_REFINERY_RULE_KEY, HUMAN_HARVESTERS_PER_REFINERY_RULE);

		INIT_ENHANCEMENT_KEY(MULTI_WALL_LENGTH_RULE_KEY, MULTI_WALL_LENGTH_RULE);
		INIT_ENHANCEMENT_KEY(FULL_COST_MULTI_WALLS_LENGTH_RULE_KEY, FULL_COST_MULTI_WALLS_LENGTH_RULE);
	}
};
