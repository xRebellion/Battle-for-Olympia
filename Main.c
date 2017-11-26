#include "Movement.h"
#include "Map.h"
#include "rekruit.h"
#include "UpdateInfo.h"
#include "init.h"
#include "ListTypeCast.h"

int main()
{
    // List of villages and list of units.
    // Cara pakai:
    // INSERT
    // InsVFirst/... (&L, &building)
    // InsVLast/... (&L, &unit)
    //
    // SET
    // Info(ListAddr) = setBuildingID(Info(ListAddr), NEWID);
    // Info(ListAddr) = setUnitName(Info(ListAddr), NEWNAME);
    Map M;
    List LVillage;
    //sebenarnya list of building, tetapi yang dimasukkan hanya building bertipe village saja.
    List LUnit;
    TypeUnit unit;
    Building building;
    int NBrsMap, NKolMap;

    unit.ID = 'A';
    PosX(unit) = 0;
    PosY(unit) = 0;
    CreateEmptyMap(&M,&NBrsMap,&NKolMap);
    AddUnitToMap(&M, unit);
    PrintMap(M, NBrsMap, NKolMap);
    RemoveUnitFromMap(&M, unit);
    PrintMap(M,NBrsMap,NKolMap);

    return 0;
}
