#pragma once

#include <NcoRuntime.h>
#include <RulesRuntime.h>
#include	"function.h"

void HookEvent_ObjectTakeDamage(TechnoClass* object, int& damage, int distance, WarheadType warhead, TechnoClass* source);
void HookEvent_ObjectCreated(TechnoClass* object);
void HookEvent_ObjectDestroyed(TechnoClass* object, TechnoClass* source);
