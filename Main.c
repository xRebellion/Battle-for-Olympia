
#include "init.h"
#include "Map.h"
#include "Movement.h"
#include "rekruit.h"
#include "UpdateInfo.h"
#include "MapInitialize.h"
#include "attack.h"
boolean IsStringEQ(Kata S1, Kata S2);
boolean IsCommandValid(Kata command);


int main()
{

    //Map Definition
    Map M;


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

    //Queue of turns
    Queue Turns;
    CreateEmptyQ(&Turns);
    AddQ(&Turns, P1);
    AddQ(&Turns, P2);

    //List of Buildings
    ListB LBuildings;

    //String Command Input
    char buffer;
    char command;
    Kata commandArr;

    Kata move;
    Kata undo;
    Kata change_Unit;
    Kata recruit;
    Kata attack;
    Kata map;
    Kata info;
    Kata end_Turn;
    Kata exit;

    InitializeKata(&move,&undo,&change_Unit,&recruit,&attack,&map,&info,&end_Turn,&exit);

    //Begin Game

    printf("Battle for Olympia!\n");
    printf("Press ENTER to Begin Game.\n");
    while(getchar() != '\n');

    //Create New Map
    InitializeMap(&M, M.NBrsEff, M.NKolEff);
    InitializeKing(&M,&P1,&P2);

    PrintMap(M);
    printf("==============================================================\n");
    printf("               Map Successfully Initialized!\n");
    printf("==============================================================\n");
    //Testing Environment

    TypeUnit selectedUnit;
    addressU addrUnit;
/*
    TypeUnit currUnit;

    currUnit.ID = 'A';
    PosX(currUnit) = 4;
    PosY(currUnit) = 3;
    currUnit.Move = 2;

    AddUnitToMap(&M, currUnit);

    TypeUnit currUnit2;

    currUnit2.ID = 'B';
    PosX(currUnit2) = 5;
    PosY(currUnit2) = 3;
    currUnit2.Move = 2;

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

    // Game Begin
    // P1 = Current Player
    // P2 = Other player
    scanf("%c", &buffer);
    do
    {
        selectedUnit = Info(Last(P1.Unit));
        UpdateInfo(&P1);
        PrintInfo(selectedUnit);

            //READ COMMAND
            do
            {
                printf("==============================================================\n");
                printf("Input Command: ");
                commandArr.Length = 0;

                do
                {
                    scanf("%c", &command);
                    if(command != '\n')
                    {
                        commandArr.Length++;
                        commandArr.TabKata[commandArr.Length] = command;
                    }


                } while (command != '\n');

                /////
                //printf("move = %d\n4 exit = %d\n undo = %d\n",IsStringEQ(command,"move"), IsStringEQ(command,"exit"),IsStringEQ(command,"undo"));
                if(IsStringEQ(commandArr, move))
                {
                    TypeUnit TempUnit = selectedUnit;
                    if(selectedUnit.Move != 0)
                        MoveCommand(&MoveHistory,P1,P2,&M,&selectedUnit,&PrevLoc);
                    else
                        printf("This unit can no longer move!\n");
                    addrUnit = SearchUnit(P1.Unit,TempUnit);
                    Info(addrUnit) = selectedUnit;

                } else
                if(IsStringEQ(commandArr, undo))
                {
                    Undo(&MoveHistory, &P1, &M, &selectedUnit);
                    scanf("%c", &buffer);

                } else
                if(IsStringEQ(commandArr, change_Unit))
                {
                    CreateEmptyS(&MoveHistory);
                    change_unit(P1,&selectedUnit);
                    scanf("%c", &buffer);
                } else
                if(IsStringEQ(commandArr,recruit))
                {
                    Recruit(&M, &P1, &M.NBrsEff, &M.NKolEff);
                } else
                if(IsStringEQ(commandArr,attack))
                {
                    //ChooseTarget(M, &P, selectedUnit, P1, P2);
                } else
                if(IsStringEQ(commandArr,map))
                {
                    PrintMap(M);
                } else
                if(IsStringEQ(commandArr,info))
                {
                    InfoM(P1, P2, M);
                } else
                if(IsStringEQ(commandArr,end_Turn))
                {
                    ChangeTurn(&Turns);
                    P1 = InfoHead(Turns);
                    P2 = InfoTail(Turns);
                } else
                if(IsStringEQ(commandArr, exit))
                {
                    printf("Exiting...\n");
                }
                else
                {
                    printf("Invalid Command!\n");
                }
                if(IsCommandValid(commandArr) && !IsStringEQ(commandArr,exit))
                    scanf("%c", &buffer);
            }
            while(!IsStringEQ(commandArr,end_Turn) && !IsStringEQ(commandArr,exit));


    }
    while(!IsStringEQ(commandArr, exit));









    //MoveCommand(P1,P2,&M, currUnit, &PrevLoc);

    //PrintMap(M);



    //Begin Playing




    return 0;
}
boolean IsStringEQ(Kata S1, Kata S2)
{
    int i;
    boolean EQ = true;
    if(S1.Length != S2.Length)
    {
        return false;
    } else
    {
        for(i = 1; (i <= S1.Length)&& EQ; i++)
        {
            if(S1.TabKata[i] != S2.TabKata[i])
            {
                EQ = false;
            }
            //printf("%c | %c\n", S1.TabKata[i], S2.TabKata[i]);
        }

    }
    return EQ;

}

boolean IsCommandValid(Kata command)
{
    Kata Move;
    Kata Undo;
    Kata Change_Unit;
    Kata Recruit;
    Kata Attack;
    Kata Map;
    Kata Info;
    Kata End_Turn;
    Kata Exit;

    InitializeKata(&Move,&Undo,&Change_Unit,&Recruit,&Attack,&Map,&Info,&End_Turn,&Exit);

    return IsStringEQ(command,Move) || IsStringEQ(command, Undo) || IsStringEQ(command, Change_Unit)
            || IsStringEQ(command,Recruit) || IsStringEQ(command,Attack) || IsStringEQ(command, Map)
            || IsStringEQ(command, Info) || IsStringEQ(command, End_Turn) || IsStringEQ(command, Exit);
}
