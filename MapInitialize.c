#include "MapInitialize.h"

void InitializeMap(Map *M,int NBrs, int NKol)
{
    /*Menginisialisasi map*/
    CreateEmptyMap(M,&NBrs,&NKol);

    ListB B;
    POINT Coor;
    infotypeB C1,C2,C3,C4,C5,C6,C7,C8,T1,T2,V1,V2,V3,V4,V5;
    Player P1,P2;
    CreateEmptyBuilding(&B);

    /*Menaruh building di list*/
    /*Building player 1*/
    InsVFirstBuilding(&B,C1);
    setBuildingID (&C1,'C');
    setBuildingOwner (&C1,P1);
    setBuildingGold (&C1,0);
    setBuildingType (&C1,'C');
    Coor.X = 0;
    Coor.Y = NBrs-1;
    setBuildingLocation(&C1,Coor);

    InsVFirstBuilding(&B,C2);
    setBuildingID (&C2,'C');
    setBuildingOwner (&C2,P1);
    setBuildingGold (&C2,0);
    setBuildingType (&C2,'C');
    Coor.X = 1;
    Coor.Y = NBrs-2;
    setBuildingLocation(&C2,Coor);

    InsVFirstBuilding(&B,C3);
    setBuildingID (&C3,'C');
    setBuildingOwner (&C3,P1);
    setBuildingGold (&C3,0);
    setBuildingType (&C3,'C');
    Coor.X = 1;
    Coor.Y = NBrs;
    setBuildingLocation(&C3,Coor);

    InsVFirstBuilding(&B,C4);
    setBuildingID (&C4,'C');
    setBuildingOwner (&C4,P1);
    setBuildingGold (&C4,0);
    setBuildingType (&C4,'C');
    Coor.X = 2;
    Coor.Y = NBrs-1;
    setBuildingLocation(&C4,Coor);

    InsVFirstBuilding(&B,T1);
    setBuildingID (&T1,'T');
    setBuildingOwner (&T1,P1);
    setBuildingGold (&T1,0);
    setBuildingType (&T1,'T');
    Coor.X = 1;
    Coor.Y = NBrs-1;
    setBuildingLocation(&T1,Coor);

    /*Building player 2*/
    InsVFirstBuilding(&B,C5);
    setBuildingID (&C5,'C');
    setBuildingOwner (&C5,P2);
    setBuildingGold (&C5,0);
    setBuildingType (&C5,'C');
    Coor.X = NKol-2;
    Coor.Y = 1;
    setBuildingLocation(&C5,Coor);

    InsVFirstBuilding(&B,C6);
    setBuildingID (&C6,'C');
    setBuildingOwner (&C6,P2);
    setBuildingGold (&C6,0);
    setBuildingType (&C6,'C');
    Coor.X = NKol-1;
    Coor.Y = 0;
    setBuildingLocation(&C6,Coor);

    InsVFirstBuilding(&B,C7);
    setBuildingID (&C7,'C');
    setBuildingOwner (&C7,P2);
    setBuildingGold (&C7,0);
    setBuildingType (&C7,'C');
    Coor.X = NKol-1;
    Coor.Y = 2;
    setBuildingLocation(&C7,Coor);

    InsVFirstBuilding(&B,C8);
    setBuildingID (&C8,'C');
    setBuildingOwner (&C8,P2);
    setBuildingGold (&C8,0);
    setBuildingType (&C8,'C');
    Coor.X = NKol;
    Coor.Y = 1;
    setBuildingLocation(&C8,Coor);

    InsVFirstBuilding(&B,T2);
    setBuildingID (&T2,'T');
    setBuildingOwner (&T2,P2);
    setBuildingGold (&T2,0);
    setBuildingType (&T2,'T');
    Coor.X = NKol-1;
    Coor.Y = 1;
    setBuildingLocation(&T2,Coor);

    /*Village*/
    InsVFirstBuilding(&B,V1);
    setBuildingID (&V1,'V');
    setBuildingGold (&V1,10);
    setBuildingType (&V1,'V');
    if ((NKol % 2) == 1){
        Coor.X = (NKol-1)/2;
    }
    else {
        Coor.X = NKol/2;
    }
    if ((NBrs % 2) == 1){
        Coor.Y = (NBrs-1)/2;
    }
    else {
        Coor.Y = NBrs/2;
    }
    setBuildingLocation(&V1,Coor);

    InsVFirstBuilding(&B,V2);
    setBuildingID (&V2,'V');
    setBuildingGold (&V2,5);
    setBuildingType (&V2,'V');
    Coor.X = rand() % ((NKol/2) + 1 - 0) + 0;
    Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
    if (Coor.X <= 2){
        while (Coor.X <=2){
            Coor.X = rand() % ((NKol/2) + 1 - 0) + 0;
        }
    }
    if (Coor.Y >= (NBrs-2)){
        while (Coor.Y >= (NBrs-2)){
            Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
        }
    }
    setBuildingLocation(&V2,Coor);

    InsVFirstBuilding(&B,V3);
    setBuildingID (&V3,'V');
    setBuildingGold (&V3,5);
    setBuildingType (&V3,'V');
    Coor.X = rand() % ((NKol/2) + 1 - 0) + 0;
    Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
    if (Coor.X <= 2){
        while (Coor.X <=2){
            Coor.X = rand() % ((NKol/2) + 1 - 0) + 0;
        }
    }
    if (Coor.Y >= (NBrs-2)){
        while (Coor.Y >= (NBrs-2)){
            Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
        }
    }
    setBuildingLocation(&V3,Coor);

    InsVFirstBuilding(&B,V4);
    setBuildingGold (&V4,5);
    setBuildingType (&V4,'V');
    Coor.X = rand() % ((NKol) + 1 - 0) + (NKol/2);
    Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
    if (Coor.X >= (NKol-2)){
        while (Coor.X <=2){
            Coor.X = rand() % ((NKol) + 1 - 0) + (NKol/2);
        }
    }
    if (Coor.Y <= 2){
        while (Coor.Y >= (NBrs-2)){
            Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
        }
    }
    setBuildingLocation(&V4,Coor);

    InsVFirstBuilding(&B,V5);
    setBuildingGold (&V5,5);
    setBuildingType (&V5,'V');
    Coor.X = rand() % ((NKol) + 1 - 0) + (NKol/2);
    Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
    if (Coor.X >= (NKol-2)){
        while (Coor.X <=2){
            Coor.X = rand() % ((NKol) + 1 - 0) + (NKol/2);
        }
    }
    if (Coor.Y <= 2){
        while (Coor.Y >= (NBrs-2)){
            Coor.Y = rand() % ((NBrs) + 1 - 0) + 0;
        }
    }
    setBuildingLocation(&V5,Coor);

}
