#include "attack.h"
/* Tinggal Memanggil fungsi ChooseTarget(Map M, Point *P, TypeUnit T1, TypeUnit T2, Player P1, Player P2) di program utama! */

boolean AccuracyCheck() {
    int i,Accuracy,Chance,AccCheck;
    /*scanf("%d",&Accuracy);
    while (Accuracy <0 && Accuracy >100) {
        scanf("%d",&Accuracy);
    }*/
    Accuracy = 90; //Asumsi semua accuracy unit adalah 90%
    Chance = 100-Accuracy;
    srand(time(NULL));
    AccCheck = 1 + rand() % 99;
    if (AccCheck > Chance) {
        return true;
    }
    else {
        return false;
    }
}

isAdjacent(T1 TypeUnit, T2 TypeUnit) {
    boolean Adjacent = false;
    if ((T1.Location.X == T2.Location.X) && (T1.Location.X == T2.Location+1)) {
        Adjacent = true;
    }
    else ((T1.Location.X == T2.Location.X) && (T1.Location.X == T2.Location-1)) {
        Adjacent = true;
    }
    else ((T1.Location.X == T2.Location.X+1) && (T1.Location.X == T2.Location)) {
        Adjacent = true;
    }
    else ((T1.Location.X == T2.Location.X-1) && (T1.Location.X == T2.Location)) {
        Adjacent = true;
    }
    return Adjacent;
}

void ChooseTarget(Map M, Point *P, TypeUnit T1, TypeUnit T2, Player P1, Player P2) {
    if (T1.Hit) {
        printf("Masukan lokasi musuh (Sb X) : ");
        scanf("%d",P.X);
        printf("Masukan lokasi musuh (Sb Y) : ");
        scanf("%d", P.Y);
        if ((isEnemyUnit(M,*P)) && (isAdjacent(T1,T2))) {
            Attack(&T1,&T2,&P1,&P2,&M);
        }
        else {
            printf("Tidak ditemukan musuh yang dapat diserang.\n");
        }
    }
    else {
        printf("Unit sudah melakukan serangan!\n");
    }
}

boolean isEnemyUnit(Map M, Point P, Player P2) {
    TypeUnit T;
    T = M.Tiles[P.X][P.Y].unit;
    if (SearchUnit(P2.ListU,T) != Nil) {
        return true;
    }
    else {
        return false;
    }
}

void Attack(TypeUnit *T1, TypeUnit *T2, Player *P1, Player *P2, Map *M)
/* T1 dan T2 terdefinisi */
/* T1 adalah unit yang menyerang, T2 adalah unit yang diserang*/
{
    if (AccuracyCheck) {
        (*T2).Health -= (*T1).Attack;
        printf("You attacked the enemy for %d damage!\n",(*T1).Attack);
        if ((*T2).Health <= 0) {
            DelPUnit(P2.ListU,(*T2));
            RemoveUnitFromMap(M,*T2);
            printf("The enemy unit is killed.\n");
        }
    }
    else {
        printf("Miss!\n");
    }
    if (((*T2).Health >0) && ((*T1).AttackType == (*T2).AttackType)) {  //Retaliation
        if (AccuracyCheck) {
            (*T1).Health -= (*T2).Attack;
            printf("The enemy hit you for %d damage!\n",(*T2).Attack);
            if ((*T1).Health <= 0) {
                DelPUnit(P1.ListU,(*T1));
                RemoveUnitFromMap(M,*T1);
                printf("Your unit is killed.\n");
            }
        }
        else {
            printf("The enemy counters but it missed!\n");
        }
    }
    T1.Hit = false;
}
