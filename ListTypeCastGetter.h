#ifndef LISTTYPECASTGETTER_H
#define LISTTYPECASTGETTER_H

#include "init.h"
#include "ListTypeCast.h"

// List of villages and list of units.
    // Cara pakai:
    // INSERT
    // InsVFirst/... (&L, &building)
    // InsVLast/... (&L, &unit)
    //
    // SET
    // Info(ListAddr) = setBuildingID(Info(ListAddr), NEWID);
    // Info(ListAddr) = setUnitName(Info(ListAddr), NEWNAME);

char getBuildingID (int addr);
// Usage : char = getBuildingID(Info(P))

Player getBuildingOwner (int addr);
// Usage : Player = getBuildingOwner(Info(P))

int getBuildingGold (int addr);
// Usage : gold = getBuildingGold(Info(P))

char getBuildingType (int addr);
// Usage : type = getBuildingType(Info(P))

POINT getBuildingLocation(int addr);




int setBuildingID (Building * building, char NewID);
// Usage : Info(P) = setBuildingID(NewID)

int setBuildingOwner (Building * building, Player Owner);
// Usage : Info(P) = setBuildingOwner(NewOwner)

int setBuildingGold (Building * building, int Gold);
// Usage : Info(P) = setBuildingGold(NewGold)

int setBuildingType (Building * building, char NewType);
// Usage : Info(P) = setBuildingType(NewType)

int setBuildingLocation(Building * building, POINT Location);



int getUnitMaxHealth (int addr);
// Usage : int = getUnitMaxHealth (Info(P))

int getUnitHealth (int addr);
// Usage : int = getUnitHealth (Info(P))

int getUnitAttack (int addr);
// Usage : int = getUnitAttack (Info(P))

int getUnitMaxMove (int addr);
// Usage : int = getUnitMaxMove (Info(P))

int getUnitMove (int addr);
// Usage : int = getUnitMove (Info(P))

char getUnitAttackType(int addr);
// Usage : char = getUnitAttackType (Info(P))

boolean getUnitHit(int addr);
// Usage : boolean = getUnitHit (Info(P))

POINT getUnitLocation(int addr);
// Usage : location = getUnitLocation (Info(P))

int getUnitHarga (int addr);
// Usage : harga = getUnitHarga (Info(P))


int setUnitMaxHealth (TypeUnit * unit, int MaxHealth);
// Usage : Info(P) = setUnitMaxHealth(MaxHealth)

int setUnitHealth (TypeUnit * unit, int Health);
// Usage : Info(P) = setUnitHealth(Health)

int setUnitAttack (TypeUnit * unit, int Attack);
// Usage : Info(P) = setUnitAttack(Attack)

int setUnitMaxMove (TypeUnit * unit, int MaxMove);
// Usage : Info(P) = setUnitMaxMove(MaxMove)

int setUnitMove (TypeUnit * unit, int Move);
// Usage : Info(P) = setUnitMove(Move)

int setUnitAttackType(TypeUnit * unit, char AttackType);
// Usage : Info(P) = setUnitAttackType(AttackType)

int setUnitHit(TypeUnit * unit, boolean Hit);
// Usage : Info(P) = setUnitHit(Hit)

int setUnitLocation(TypeUnit * unit, POINT Location);
// Usage : Info(P) = setUnitLocation(Location)

int setUnitHarga (TypeUnit * unit, int Harga);
// Usage : Info(P) = setUnitHarga(Harga)

int setUnitUpkeep (TypeUnit * unit, int Upkeep);
// Usage : Info(P) = setUnitUpkeep(Upkeep)

int setUnitName (TypeUnit * unit, char * Name);
// Usage : Info(P) = setUnitUpkeep(Info(P) Upkeep)

#endif
