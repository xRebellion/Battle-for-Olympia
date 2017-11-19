#include "boolean.h"
#include "point.h"
#include "listdp.h"
#include "init.h"

int Earning (player P)
/*Untuk menghitung income player */
{
    Player P;
    int sum = 0;
    if(!IsEmpty(Player.Villages)){
        addressV P;
        P = Player.Villages.First;
        while (!IsEmpty(Player.Villages)){
            sum = sum + Info(P);
            P = Next(P);
        }
    }
    return sum;
}

int Expense (player P)
/*Untuk menghitung income player */
{
    Player P;
    int sum = 0;
    if(!IsEmpty(Player.Unit)){
        addressU P;
        P = Player.Unit.First;
        while (!IsEmpty(Player.Unit)){
            sum = sum + Info(P);
            P = Next(P);
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

player UpdateInfo ()
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
