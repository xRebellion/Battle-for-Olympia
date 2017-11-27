#include "attack.h"
/* Tinggal Memanggil fungsi ChooseTarget(Map M, Point *P, TypeUnit T1, TypeUnit T2, Player P1, Player P2) di program utama! */

boolean AccuracyCheck() {
    int Accuracy,Chance,AccCheck;
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

boolean isAdjacent(TypeUnit T1, TypeUnit T2) {
    boolean Adjacent = false;
    if ((T1.Location.X == T2.Location.X) && (T1.Location.Y == T2.Location.Y+1)) {
        Adjacent = true;
    }
    else if((T1.Location.X == T2.Location.X) && (T1.Location.Y == T2.Location.Y-1)) {
        Adjacent = true;
    }
    else if((T1.Location.X == T2.Location.X+1) && (T1.Location.Y == T2.Location.Y)) {
        Adjacent = true;
    }
    else if((T1.Location.X == T2.Location.X-1) && (T1.Location.Y == T2.Location.Y)) {
        Adjacent = true;
    }
    return Adjacent;
}

void ChooseTarget(Map M, POINT *P, TypeUnit T1, Player P1, Player P2) {
    POINT Pt1,Pt2,Pt3,Pt4;
    int Choose;
    Pt1.X = (*P).X + 1; //Kanan T1
    Pt1.Y = (*P).Y;
    Pt2.X = (*P).X;     //Atas T1
    Pt2.Y = (*P).Y + 1;
    Pt3.X = (*P).X - 1; //Kiri T1
    Pt3.Y = (*P).Y;
    Pt4.X = (*P).X;     //Bawah T1
    Pt4.Y = (*P).Y - 1;
    if (T1.Hit) {
        printf("Please select enemy you want to attack: \n");
        if (isEnemyUnit(M,(Pt1),P2)) {
            printf("1. %s (%d,%d) | Health %d/%d ", M.Tiles[Pt1.X][Pt1.Y].unit.name, Pt1.X,Pt1.Y,  M.Tiles[Pt1.X][Pt1.Y].unit.Health, M.Tiles[Pt1.X][Pt1.Y].unit.MaxHealth);
            if (((T1).AttackType ==  M.Tiles[Pt1.X][Pt1.Y].unit.AttackType) || ( M.Tiles[Pt1.X][Pt1.Y].unit.AttackType == 'k')) {
                printf("(Retaliates)\n");
            }
        }
        if (isEnemyUnit(M,(Pt2),P2)) {
            printf("1. %s (%d,%d) | Health %d/%d ",M.Tiles[Pt2.X][Pt2.Y].unit.name, Pt2.X,Pt2.Y,  M.Tiles[Pt2.X][Pt2.Y].unit.Health, M.Tiles[Pt2.X][Pt2.Y].unit.MaxHealth);
            if (((T1).AttackType ==  M.Tiles[Pt2.X][Pt2.Y].unit.AttackType) || ( M.Tiles[Pt2.X][Pt2.Y].unit.AttackType == 'k')) {
                printf("(Retaliates)\n");
            }
        }
        if (isEnemyUnit(M,(Pt3),P2)) {
            printf("1. %s (%d,%d) | Health %d/%d ",M.Tiles[Pt3.X][Pt3.Y].unit.name, Pt3.X,Pt3.Y,  M.Tiles[Pt3.X][Pt3.Y].unit.Health, M.Tiles[Pt3.X][Pt3.Y].unit.MaxHealth);
            if (((T1).AttackType == M.Tiles[Pt3.X][Pt3.Y].unit.AttackType) || (M.Tiles[Pt3.X][Pt3.Y].unit.AttackType == 'k')) {
                printf("(Retaliates)\n");
            }
        }
        if (isEnemyUnit(M,(Pt4),P2)) {
            printf("1. %s (%d,%d) | Health %d/%d ",M.Tiles[Pt4.X][Pt4.Y].unit.name, Pt4.X,Pt4.Y,  M.Tiles[Pt4.X][Pt4.Y].unit.Health, M.Tiles[Pt4.X][Pt4.Y].unit.MaxHealth);
            if (((T1).AttackType == M.Tiles[Pt4.X][Pt4.Y].unit.AttackType) || (M.Tiles[Pt4.X][Pt4.Y].unit.AttackType == 'k')) {
                printf("(Retaliates)\n");
            }
        }
        printf("Select the enemy you want to attack: ");
        scanf("%d",&Choose);
        if (Choose == 1) {
            Attack(&T1,(*M.Tiles[Pt1.X][Pt1.Y].unit),&P1,&P2,&M);
        }
        if (Choose == 2) {
            Attack(&T1,(*M.Tiles[Pt1.X][Pt1.Y].unit),&P1,&P2,&M);
        }
        if (Choose == 3) {
            Attack(&T1,(*M.Tiles[Pt1.X][Pt1.Y].unit),&P1,&P2,&M);
        }
        if (Choose == 4) {
            Attack(&T1,(*M.Tiles[Pt1.X][Pt1.Y].unit),&P1,&P2,&M);
        }
    }
    else {
        printf("This unit can no longer attack!\n");
    }
}

boolean isEnemyUnit(Map M, POINT P, Player P2) {
    TypeUnit T;
    T = M.Tiles[P.X][P.Y].unit;
    if (SearchUnit(P2.Unit,T) != Nil) {
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
        printf("Enemy's %s is damaged by %d.\n",(*T2).name,(*T1).Attack);
        if ((*T2).Health <= 0) {
            DelPUnit(&(*P2).Unit,(*T2));
            RemoveUnitFromMap(M,*T2);
            printf("The enemy's %s is dead.\n",(*T2).name);
        }
    }
    else {
        printf("Miss!\n");
    }
    if (((*T2).Health >0) && (((*T1).AttackType == (*T2).AttackType) || ((*T2).AttackType == 'k'))) {  //Retaliation
        if (AccuracyCheck) {
            (*T1).Health -= (*T2).Attack;
            printf("Your %s is damaged by %d\n",(*T1).name,(*T2).Attack);
            if ((*T1).Health <= 0) {
                DelPUnit(&(*P1).Unit,(*T1));
                RemoveUnitFromMap(M,*T1);
                printf("Your %s is dead :( \n",(*T1).name);
            }
        }
        else {
            printf("The enemy counters but it missed!\n");
        }
    }
    (*T1).Hit = false;
}
