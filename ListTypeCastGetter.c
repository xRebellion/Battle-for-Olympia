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

int getUnitMaxHealth (int addr)
// Usage : int = getUnitMaxHealth (Info(P))
{
    return getUnit(addr).MaxHealth;
}

int getUnitHealth (int addr)
// Usage : int = getUnitHealth (Info(P))
{
    return getUnit(addr).Health;
}

int getUnitAttack (int addr)
// Usage : int = getUnitAttack (Info(P))
{
    return getUnit(addr).Attack;
}

int getUnitMaxMove (int addr)
// Usage : int = getUnitMaxMove (Info(P))
{
    return getUnit(addr).MaxMove;
}

int getUnitMove (int addr)
// Usage : int = getUnitMove (Info(P))
{
    return getUnit(addr).Move;
}

char getUnitAttackType(int addr)
// Usage : char = getUnitAttackType (Info(P))
{
    return getUnit(addr).AttackType;
}

boolean getUnitHit(int addr)
// Usage : boolean = getUnitHit (Info(P))
{
    return getUnit(addr).Hit;
}

POINT getUnitLocation(int addr)
// Usage : location = getUnitLocation (Info(P))
{
    return getUnit(addr).Location;
}

int getUnitHarga (int addr)
// Usage : harga = getUnitHarga (Info(P))
{
    return getUnit(addr).Harga;
}


int setUnitMaxHealth (TypeUnit unit, int MaxHealth)
// Usage : Info(P) = setUnitMaxHealth(MaxHealth)
{
    unit.MaxHealth = MaxHealth;
    return &unit;
}

int setUnitHealth (TypeUnit unit, int Health)
// Usage : Info(P) = setUnitHealth(Health)
{
    unit.Health = Health;
    return &unit;
}

int setUnitAttack (TypeUnit unit, int Attack)
// Usage : Info(P) = setUnitAttack(Attack)
{
    unit.Attack = Attack;
    return &unit;
}

int setUnitMaxMove (TypeUnit unit, int MaxMove)
// Usage : Info(P) = setUnitMaxMove(MaxMove)
{
    unit.MaxMove = MaxMove;
    return &unit;
}

int setUnitMove (TypeUnit unit, int Move)
// Usage : Info(P) = setUnitMove(Move)
{
    unit.Move = Move;
    return &unit;
}

char setUnitAttackType(TypeUnit unit, char AttackType)
// Usage : Info(P) = setUnitAttackType(AttackType)
{
    unit.AttackType = AttackType;
    return &unit;
}

boolean setUnitHit(TypeUnit unit, boolean Hit)
// Usage : Info(P) = setUnitHit(Hit)
{
    unit.Hit = Hit;
    return &unit;
}

POINT setUnitLocation(TypeUnit unit, POINT Location)
// Usage : Info(P) = setUnitLocation(Location)
{
    unit.Location = Location;
    return &unit;
}

int setUnitHarga (TypeUnit unit, int Harga)
// Usage : Info(P) = setUnitHarga(Harga)
{
    unit.Harga = Harga;
    return &unit;
}
