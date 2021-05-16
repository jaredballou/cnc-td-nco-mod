#pragma once

const auto ON_SCENARIO_START_EVENT = "ScenarioStart";
const auto ON_SAVE_LOAD_EVENT = "SaveLoad";
const auto ON_GAME_TICK_EVENT = "GameTick";
const auto ON_CAN_BUILD_EVENT = "CanBuild";

int GetEventCount();

const char** GetEventNames();


// sync events
void OnCanBuild(const char* type, const char* playerHouse);
void OnScenarioLoad(char* name);

void OnSaveLoad(const char* playerHouse, unsigned int scenarioNumber);

// async events
void OnGameTick();
