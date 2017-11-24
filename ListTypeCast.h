#ifndef LISTTYPECAST_H
#define LISTTYPECAST_H

#include "init.h"

Building getBuilding (int addr);
// Usage : building = getBuilding(Info(P))

TypeUnit getUnit (int addr);
// Usage : unit = getUnit (Info(P))

int setBuilding (Building building);
// Usage : Info(First(LVillage)) = setBuilding (building)

int setUnit (TypeUnit unit);
// Usage : Info(First(LUnit)) = setUnit(unit)

#endif
