#include "Movement.h"
#include "Map.h"
#include "rekruit.h"
#include "UpdateInfo.h"
#include "init.h"
#include "ListTypeCast.h"


int main()
{
    //Player Definition & Initialization
    Player P1;
    Player P2;

    //PLAYER 1
    InitializePlayer(&P1,1);
    //PLAYER 2
    InitializePlayer(&P2,2);

    //Previous Moves
    POINT PrevLoc;
    Stack MoveHistory;

    //Map Definition
    Map M;

    //Queue of turns
    Queue Turns;
    CreateEmptyQ(&Turns,10);

    //List of Buildings
    ListB LBuildings;



    //Create New Map
    CreateEmptyMap(&M, &(M.NBrsEff), &(M.NKolEff));
    //Testing Environment
    TypeUnit currUnit;

    currUnit.ID = 'A';
    PosX(currUnit) = 4;
    PosY(currUnit) = 3;
    currUnit.MaxMove = 2;

    AddUnitToMap(&M, currUnit);

    TypeUnit currUnit2;

    currUnit2.ID = 'B';
    PosX(currUnit2) = 4;
    PosY(currUnit2) = 1;
    currUnit2.MaxMove = 2;

    AddUnitToMap(&M, currUnit2);

    InsVFirstUnit(&P1.Unit,currUnit);
    InsVFirstUnit(&P2.Unit,currUnit2);

    PrintMap(M);



    MoveCommand(P1,P2,&M, currUnit, &PrevLoc);

    //InitializeMap(&M, M.NBrsEff, M.NKolEff);


    //Begin Playing




    return 0;
}
