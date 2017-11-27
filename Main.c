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
    InitializePlayer(P1,1);
    //PLAYER 2
    InitializePlayer(P2,2);

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


    //Testing Environment
    TypeUnit currUnit;

    currUnit.ID = 'A';
    PosX(currUnit) = 3;
    PosY(currUnit) = 3;

    //Create New Map
    CreateEmptyMap(&M, &(M.NBrsEff), &(M.NKolEff));
    MoveCommand(P1,P2,&M, currUnit, &PrevLoc);
    PrintMap(M);

    //InitializeMap(&M, M.NBrsEff, M.NKolEff);


    //Begin Playing




    return 0;
}
