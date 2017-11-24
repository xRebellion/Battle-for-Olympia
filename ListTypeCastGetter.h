#ifndef LISTTYPECASTGETTER_H
#define LISTTYPECASTGETTER_H

#include "init.h"
#include "ListTypeCast.h"

char getBuildingID (int addr);
// Usage : char = getBuildingID(Info(P))

Player getBuildingOwner (int addr);
// Usage : Player = getBuildingOwner(Info(P))

int getBuildingGold (int addr);
// Usage : gold = getBuildingGold(Info(P))

char getBuildingType (int addr);
// Usage : type = getBuildingType(Info(P))

int setBuildingID (Building building, char NewID);
// Usage : Info(P) = setBuildingID(NewID)

int setBuildingOwner (Building building, Player Owner);
// Usage : Info(P) = setBuildingOwner(NewOwner)

int setBuildingGold (Building building, int Gold);
// Usage : Info(P) = setBuildingGold(NewGold)

int setBuildingType (Building building, char NewType);
// Usage : Info(P) = setBuildingType(NewType)
TypeUnit getUnit (int addr);
// Usage : unit = getUnit (Info(P))



#endif
