#include "UpdateInfo.h"


int Earning (Player P)
/*Untuk menghitung income player */
{
    int sum = 0;
    if(!IsEmptyBuilding(P.Villages))
    {
        addressB A;
        A = First(P.Villages);
        while (A != Nil)
        {
            sum = sum + (Info(A).Gold);
            A = Next(A);
        }
    }
    return sum;
}

int Expense (Player P)
/*Untuk menghitung expense player */
{

    int sum = 0;
    if(!IsEmptyUnit(P.Unit))
    {
        addressU A;
        A = First(P.Unit);
        while (A != Nil)
        {
            sum = sum + (Info(A).Upkeep);
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
    if(!IsEmptyUnit(P.Unit)){
        addressU A;
        A = First(P.Unit);
        while (A != Nil)
        {
            count++;
            UnitName = Info(A).Name;
            MovePoint = Info(A).Move;
            AttackStatus = Info(A).Hit;

            printf("%d. %s (%d,%d) | Health: %d/%d | Movement Point: %d | Attack Status: ",
            count,UnitName,PosX(Info(A)),PosY(Info(A)),Info(A).Health,Info(A).MaxHealth,MovePoint);

            if (AttackStatus == true) {
                printf("Available\n");
            }
            else {
                printf("Not Available\n");
            }
            A = Next(A);
        }
    }
}

void UpdateInfo (Player * P)
/* Mengupdate informasi pemain tiap turn */
{
    (*P).Income = Earning(*P);
    (*P).Upkeep = Expense(*P);
    (*P).Gold = (*P).Gold + (*P).Income - (*P).Upkeep;
    printf("Player %d's Turn\n",(*P).PlayerID);
    printf("Cash: %dG | Income: %dG | Upkeep: %dG\n",(*P).Gold,(*P).Income,(*P).Upkeep);
    printf("Unit: ");
}

void PrintInfo (TypeUnit selectedunit) {
    printf("%s (%d,%d) | Health: %d/%d | Movement Point: %d | Attack Status: ", selectedunit.Name,selectedunit.Location.X,
           selectedunit.Location.Y, selectedunit.Health,selectedunit.MaxHealth,selectedunit.Move);
    if (selectedunit.Hit == true) {
        printf("Available\n");
    }
    else {
        printf("Not Available\n");
    }
}
