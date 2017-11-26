#include "Movement.h"
#include "Map.h"
#include "rekruit.h"
#include "UpdateInfo.h"
#include "init.h"
#include "ListTypeCast.h"


int main()
{

    //List LVillage;
    //sebenarnya list of building, tetapi yang dimasukkan hanya building bertipe village saja.
    //List LUnit;
    TypeUnit unit;
    //Building building;
    int NBrsMap, NKolMap;
    NBrsMap = NKolMap = 0;

    Map M;


    unit.ID = 'A';
    PosX(unit) = 0;
    PosY(unit) = 0;

    CreateEmptyMap(&M,&NBrsMap,&NKolMap);
    printf("NBrsMap : %d, NKolMap : %d", NBrsMap,NKolMap);
    AddUnitToMap(&M, unit);
    PrintMap(M, NBrsMap, NKolMap);

    RemoveUnitFromMap(&M, unit);
    //PrintMap(M,NBrsMap,NKolMap);


    return 0;
}
