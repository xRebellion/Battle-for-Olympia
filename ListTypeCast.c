#include "ListTypeCast.h"

// List of villages and list of units.
// Cara pakai:

// Untuk mengeset
// Info(First(LVillage)) = setBuilding (building)
// Info(First(LUnit)) = setUnit(unit)

// Untuk meng-get
// building = getBuilding(Info(P))
// unit = getUnit (Info(P))

Building getBuilding (int addr)
{
    return (*(Building*)addr);
}

TypeUnit getUnit (int addr)
{
    return (*(TypeUnit*)addr);
}

int setBuilding (Building building)
{
    return &building;
}

int setUnit (TypeUnit unit)
{
    return &unit;
}
