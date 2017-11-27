
#include "init.h"
#include "Map.h"
#include "Movement.h"
#include "rekruit.h"
#include "UpdateInfo.h"
#include "MapInitialize.h"
boolean IsStringEQ(char * S1, char * S2);

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
    CreateEmptyQ(&Turns);

    //List of Buildings
    ListB LBuildings;

    //Begin Game

    printf("Battle for Olympia!\n");
    printf("Press ENTER to Begin Game.\n");
    while(getchar() != '\n');

    //Create New Map
    InitializeMap(&M, M.NBrsEff, M.NKolEff);
    //Testing Environment
    /*
    TypeUnit currUnit;

    currUnit.ID = 'A';
    PosX(currUnit) = 4;
    PosY(currUnit) = 3;
    currUnit.MaxMove = 2;

    AddUnitToMap(&M, currUnit);

    TypeUnit currUnit2;

    currUnit2.ID = 'B';
    PosX(currUnit2) = 5;
    PosY(currUnit2) = 3;
    currUnit2.MaxMove = 2;

    AddUnitToMap(&M, currUnit2);

    InsVFirstUnit(&P1.Unit,currUnit);
    InsVFirstUnit(&P1.Unit,currUnit2);
    */

    //Enter Game
    printf("\n\n==============================================================\n");
    printf("                   Let The Battles Begin!\n");
    printf("==============================================================\n");

    printf("\n==============================================================\n");
    printf("||                    Available Commands\n");
    printf("||    Move = Menggerakkan suatu unit yang dipilih\n");
    printf("||    Undo = Untuk mengundo movement sebelumnya\n");
    printf("||    Change_Unit = Memilih unit yang berbeda\n");
    printf("||    Recruit = Merekrut unit baru (harus memilih unit King)\n");
    printf("||    Attack = Mengattack sebuah unit di sekitar unit yang dipilih\n");
    printf("||    Map = Menampilkan map pertempuran\n");
    printf("||    Info = Menampilkan informasi suatu petak\n");
    printf("||    End_Turn = Mengakhiri turn \n");
    printf("||    Exit = Menampilkan informasi suatu petak\n");
    printf("==============================================================\n\n");









    //MoveCommand(P1,P2,&M, currUnit, &PrevLoc);

    //PrintMap(M);



    //Begin Playing




    return 0;
}
boolean IsStringEQ(char * S1, char * S2)
{
    return !strcmpi(S1,S2);
}
