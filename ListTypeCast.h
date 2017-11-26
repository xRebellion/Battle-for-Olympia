#ifndef LISTTYPECAST_H
#define LISTTYPECAST_H

#include "init.h"

// List of villages and list of units.
    // Cara pakai:
    // INSERT
    // InsVFirst/... (&L, &building)
    // InsVLast/... (&L, &unit)
    //
    // SET
    // Info(ListAddr) = setBuildingID(Info(ListAddr), NEWID);
    // Info(ListAddr) = setUnitName(Info(ListAddr), NEWNAME);

Building getBuilding (int addr);
// Usage : building = getBuilding(Info(P))

TypeUnit getUnit (int addr);
// Usage : unit = getUnit (Info(P))

int setBuilding (Building building);
// Usage : Info(First(LVillage)) = setBuilding (building)

int setUnit (TypeUnit unit);
// Usage : Info(First(LUnit)) = setUnit(unit)

#endif
