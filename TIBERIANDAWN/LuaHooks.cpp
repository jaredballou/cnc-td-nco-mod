#include "LuaHooks.h"

int GetObjectID(TechnoClass* object) {
	switch (object->What_Am_I()) {
	case RTTI_INFANTRY:
		return Infantry.ID((InfantryClass*)object);
		break;

	case RTTI_UNIT:
		return Units.ID((UnitClass*)object);
		break;

	case RTTI_BUILDING:
		return Buildings.ID((BuildingClass*)object);
		break;

	case RTTI_AIRCRAFT:
		return Aircraft.ID((AircraftClass*)object);
		break;
	}
	return -1;
}


void HookEvent_ObjectTakeDamage(TechnoClass* object, int& damage, int distance, WarheadType warhead, TechnoClass* source) {
	int object_id = GetObjectID(object);
	if (source) {
		int source_id = GetObjectID(source);
		LogDebug("ObjectTakeDamage ininame %s house %s id %u damage %u distance %u source %s source_house %s source_id %u", object->Techno_Type_Class()->IniName, object->House->Class->IniName, object_id, damage, distance, source->Techno_Type_Class()->IniName, source->House->Class->IniName, source_id);
	}
	else {
		LogDebug("ObjectTakeDamage ininame %s house %s id %u damage %u distance %u", object->Techno_Type_Class()->IniName, object->House->Class->IniName, object_id, damage, distance);
	}

}
void HookEvent_ObjectCreated(TechnoClass* object) {
	int object_id = GetObjectID(object);
	LogDebug("ObjectCreated ininame %s house %s id", object->Techno_Type_Class()->IniName, object->House->Class->IniName, object_id);

}
void HookEvent_ObjectDestroyed(TechnoClass* object, TechnoClass* source) {
	int object_id = GetObjectID(object);
	if (source) {
		int source_id = GetObjectID(source);
		LogDebug("ObjectDestroyed ininame %s house %s id %u source %s source_house %s source_id %u", object->Techno_Type_Class()->IniName, object->House->Class->IniName, object_id, source->Techno_Type_Class()->IniName, source->House->Class->IniName, source_id);
	}
	else {
		LogDebug("ObjectDestroyed ininame %s house %s id %u", object->Techno_Type_Class()->IniName, object->House->Class->IniName, object_id);
	}
}
