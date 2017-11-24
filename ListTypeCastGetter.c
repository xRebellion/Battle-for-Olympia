#include "ListTypeCastGetter.h"

// List of villages and list of units.
// Cara pakai:

// Untuk mengeset
// Info(First(LVillage)) = setBuilding (building)
// Info(First(LUnit)) = setUnit(unit)

// Untuk meng-get
// building = getBuilding(Info(P))
// unit = getUnit (Info(P))


char getBuildingID (int addr)
// Usage : char = getBuildingID(Info(P))
{
    return getBuilding(addr).ID;
}

Player getBuildingOwner (int addr)
// Usage : Player = getBuildingOwner(Info(P))
{
    return getBuilding(addr).Owner;
}

int getBuildingGold (int addr)
// Usage : gold = getBuildingGold(Info(P))
{
    return getBuilding(addr).Gold;
}

char getBuildingType (int addr)
// Usage : type = getBuildingType(Info(P))
{
    return getBuilding(addr).Type;
}

int setBuildingID (Building building, char NewID)
// Usage : Info(P) = setBuildingID(NewID)
{
    building.ID = NewID;
    return &bulding;
}

int setBuildingOwner (Building building, Player Owner)
// Usage : Info(P) = setBuildingOwner(NewOwner)
{
    building.Owner = Owner;
    return &building;
}

int setBuildingGold (Building building, int Gold)
// Usage : Info(P) = setBuildingGold(NewGold)
{
    building.Gold = Gold;
    return &building;
}

int setBuildingType (Building building, char NewType)
// Usage : Info(P) = setBuildingType(NewType)
{
    building.Type = NewType;
    return &building;
}
