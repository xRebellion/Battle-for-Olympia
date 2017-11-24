#include "UpdateInfo.h"


int Earning (Player P)
/*Untuk menghitung income player */
{
    int sum = 0;
    if(!IsEmpty(P.Villages))
    {
        address A;
        A = First(P.Villages);
        while (A != Nil)
        {
            sum = sum + getBuildingGold(Info(A));
            A = Next(A);
        }
    }
    return sum;
}

int Expense (Player P)
/*Untuk menghitung expense player */
{

    int sum = 0;
    if(!IsEmpty(P.Unit))
    {
        address A;
        A = First(P.Unit);
        while (A != Nil)
        {
            sum = sum + getUnitUpkeep(Info(A));
            A = Next(A);
        }
    }
    return sum;
}

void PrintUnit (Player P)
/* Menampilkan semua unit yang dimiliki player */
{
    int MovePoint;
    int count = 0;
    char * UnitName;
    boolean AttackStatus;
    if(!IsEmpty(P.Unit)){
        address A;
        A = First(P.Unit);
        while (A != Nil)
        {
            count++;
            UnitName = getUnitName(Info(A));
            MovePoint = getUnitMaxMove(Info(A));
            AttackStatus = getUnitHit(Info(A));
            printf("%d. %s (%d,%d) | Movement Point: %d | Attack Status: ",count,UnitName,PosX(getUnit(Info(A))),PosY(getUnit(Info(A))),&MovePoint);
            if (AttackStatus == true) {
                printf("Available\n");
            }
            else {
                printf("Not Available\n");
            }
        }
    }
}

void UpdateInfo (Player * P)
/* Mengupdate informasi pemaain tiap turn */
{
    (*P).Income = Earning(*P);
    (*P).Upkeep = Expense(*P);
    (*P).Gold = (*P).Gold + (*P).Income - (*P).Upkeep;
    printf("Player %d's Turn\n",(*P).PlayerID);
    printf("Cash: %dG | Income: %dG | Upkeep: %dG\n",(*P).Gold,(*P).Income,(*P).Upkeep);
    printf("Unit: \n");
    PrintUnit(*P);
}
