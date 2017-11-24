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
            sum = sum + getUnit(Info(A)).Gold;
            A = Next(A);
        }
    }
    return sum;
}

int Expense (Player P)
/*Untuk menghitung income player */
{

    int sum = 0;
    if(!IsEmpty(P.Unit))
    {
        address A;
        A = First(Player.Unit);
        while (A != Nil)
        {
            sum = sum + Info(A);
            A = Next(A);
        }
    }
    return sum;
}

void PrintUnit (Player P)
/* Menampilkan semua unit yang dimiliki player */
{
    Player P;
    int MovePoint;
    int count = 0;
    boolean AttackStatus;
    if(!IsEmpty(Player.Unit)){
        addressU P;
        P = Player.Unit.First;
        while (!IsEmpty(Player.Unit)){
            count ++;
            MovePoint = Info(P).MaxMove;
            AttackStatus = Info(P).Hit;
            printf("%d. /*namaunit*/(/*koordinat*/) | Movement Point: %d | Attack Status: ",&count,/*namaunit*/,/*koordinat*/,&MovePoint);
            if (AttackStatus == true) {
                printf("Available\n");
            }
            else {
                Printf("Not Available\n");
            }
        }
    }
}

Player UpdateInfo ()
/* Mengupdate informasi pemaain tiap turn */
{
    Player P;

    P.Income = Earning(P);
    P.Upkeep = Expense(P);S
    P.Gold = P.Gold + P.Income - P.Upkeep;
    printf("Player 1's Turn\n");
    printf("Cash: %dG | Income: %dG | Upkeep: %dG\n",&P.Gold,&P.Income,&P.Upkeep);
    printf("Unit: \n");
    PrintUnit(P);
}
