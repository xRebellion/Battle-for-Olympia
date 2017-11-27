#include "MapInitialize.h"

boolean IsThereBuilding(Map M, int X, int Y)
{
    return M.Tiles[Y][X].building.Type != ' ';
}


void InitializeMap(Map *M,int NBrs, int NKol)
{
    /*Menginisialisasi map*/
    CreateEmptyMap(M,&NBrs,&NKol);
    (*M).NBrsEff = NBrs;
    (*M).NKolEff = NKol;

    ListB B;
    POINT Coor;
    infotypeB C1,C2,C3,C4,C5,C6,C7,C8,T1,T2,V1,V2,V3,V4,V5;

    CreateEmptyBuilding(&B);
    /*Menaruh building di list*/
    /*Building player 1*/
    InsVFirstBuilding(&B,C1);
    C1.ID = 'C';
    C1.OwnerID = 1;
    C1.Gold = 0;
    C1.Type = 'C';
    Coor.X = 0;
    Coor.Y = NBrs-2;
    C1.Location = Coor;
    AddBuildingToMap(M,C1);

    InsVFirstBuilding(&B,C2);
    C2.ID = 'C';
    C2.OwnerID = 1;
    C2.Gold = 0;
    C2.Type = 'C';
    Coor.X = 1;
    Coor.Y = NBrs-3;
    C2.Location = Coor;
    AddBuildingToMap(M,C2);

    InsVFirstBuilding(&B,C3);
    C3.ID = 'C';
    C3.OwnerID = 1;
    C3.Gold = 0;
    C3.Type = 'C';
    Coor.X = 1;
    Coor.Y = NBrs-1;
    C3.Location = Coor;
    AddBuildingToMap(M,C3);

    InsVFirstBuilding(&B,C4);
    C4.ID = 'C';
    C4.OwnerID = 1;
    C4.Gold = 0;
    C4.Type = 'C';
    Coor.X = 2;
    Coor.Y = NBrs-2;
    C4.Location = Coor;
    AddBuildingToMap(M,C4);

    InsVFirstBuilding(&B,T1);
    T1.ID = 'T';
    T1.OwnerID = 1;
    T1.Gold = 0;
    T1.Type = 'T';
    Coor.X = 1;
    Coor.Y = NBrs-2;
    T1.Location = Coor;
    AddBuildingToMap(M,T1);

    /*Building player 2*/
    InsVFirstBuilding(&B,C5);
    C5.ID = 'C';
    C5.OwnerID = 2;
    C5.Gold = 0;
    C5.Type = 'C';
    Coor.X = NKol-3;
    Coor.Y = 1;
    C5.Location = Coor;
    AddBuildingToMap(M,C5);

    InsVFirstBuilding(&B,C6);
    C6.ID = 'C';
    C6.OwnerID = 2;
    C6.Gold = 0;
    C6.Type = 'C';
    Coor.X = NKol-2;
    Coor.Y = 0;
    C6.Location = Coor;
    AddBuildingToMap(M,C6);

    InsVFirstBuilding(&B,C7);
    C7.ID = 'C';
    C7.OwnerID = 2;
    C7.Gold = 0;
    C7.Type = 'C';
    Coor.X = NKol-2;
    Coor.Y = 2;
    C7.Location = Coor;
    AddBuildingToMap(M,C7);

    InsVFirstBuilding(&B,C8);
    C8.ID = 'C';
    C8.OwnerID = 2;
    C8.Gold = 0;
    C8.Type = 'C';
    Coor.X = NKol-1;
    Coor.Y = 1;
    C8.Location = Coor;
    AddBuildingToMap(M,C8);

    InsVFirstBuilding(&B,T2);
    T2.ID = 'T';
    T2.OwnerID = 2;
    T2.Gold = 0;
    T2.Type = 'T';
    Coor.X = NKol-2;
    Coor.Y = 1;
    T2.Location = Coor;
    AddBuildingToMap(M,T2);

    /*Village*/
    InsVFirstBuilding(&B,V1);
    V1.ID = 'V';
    V1.Gold = 10;
    V1.Type = 'V';
    if ((NKol % 2) == 1){
        Coor.X = ((NKol-1)/2) - 1;
    }
    else {
        Coor.X = (NKol/2) - 1;
    }
    if ((NBrs % 2) == 1){
        Coor.Y = ((NBrs-1)/2) - 1;
    }
    else {
        Coor.Y = (NBrs/2) - 1;
    }
    V1.Location = Coor;
    AddBuildingToMap(M,V1);

    InsVFirstBuilding(&B,V2);
    V2.ID = 'V';
    V2.Gold = 5;
    V2.Type = 'V';
    Coor.X = rand() % (NKol - 1);
    Coor.Y = rand() % (NBrs - 1);
    if (IsThereBuilding(*M,Coor.X,Coor.Y)){
        while (IsThereBuilding(*M,Coor.X,Coor.Y)){
            Coor.X = rand() % (NKol - 1);
            Coor.Y = rand() % (NBrs - 1);
        }
    }
    V2.Location = Coor;
    AddBuildingToMap(M,V2);

    InsVFirstBuilding(&B,V3);
    V3.ID = 'V';
    V3.Gold = 5;
    V3.Type = 'V';
     Coor.X = rand() % (NKol - 1);
    Coor.Y = rand() % (NBrs - 1);
    if (IsThereBuilding(*M,Coor.X,Coor.Y)){
        while (IsThereBuilding(*M,Coor.X,Coor.Y)){
            Coor.X = rand() % (NKol - 1);
            Coor.Y = rand() % (NBrs - 1);
        }
    }
    V3.Location = Coor;
    AddBuildingToMap(M,V3);

    InsVFirstBuilding(&B,V4);
    V4.ID = 'V';
    V4.Gold = 5;
    V4.Type = 'V';;
    Coor.X = rand() % (NKol - 1);
    Coor.Y = rand() % (NBrs - 1);
    if (IsThereBuilding(*M,Coor.X,Coor.Y)){
        while (IsThereBuilding(*M,Coor.X,Coor.Y)){
            Coor.X = rand() % (NKol - 1);
            Coor.Y = rand() % (NBrs - 1);
        }
    }
    V4.Location = Coor;
    AddBuildingToMap(M,V4);

    InsVFirstBuilding(&B,V5);
    V5.ID = 'V';
    V5.Gold = 5;
    V5.Type = 'V';
    Coor.X = rand() % (NKol - 1);
    Coor.Y = rand() % (NBrs - 1);
    if (IsThereBuilding(*M,Coor.X,Coor.Y)){
        while (IsThereBuilding(*M,Coor.X,Coor.Y)){
            Coor.X = rand() % (NKol - 1);
            Coor.Y = rand() % (NBrs - 1);
        }
    }
    V5.Location = Coor;
    AddBuildingToMap(M,V5);
    PrintMap(*M);
    printf("==============================================================\n");
    printf("               Map Successfully Initialized!\n");
    printf("==============================================================\n");
}
