#include <stdio.h>
#include "boolean.h"
#include "turn.h"

void ChangeTurn (Map * M, Queue *P, Player P1, Player P2) {
    infotypeQ temp;

    CreateEmptyQ(&(*P));
    AddQ(&(*P), P2);
    AddQ(&(*P), P1);
    RefreshMovementAndAttack(M, &InfoHead(*P));

}

void RefreshMovementAndAttack (Map * M,Player *P){
//Mengisi kembali movement unit dengan max move dan attack condition
    //Kamus lokal
    int i,j;
    addressU X;
    TypeUnit Unit;
    //Algoritma
    if (!IsEmptyUnit((*P).Unit)){
        X = First((*P).Unit);
        Info(X).Move = Info(X).MaxMove;
        Info(X).Hit = true;

        while (Next(X) != Nil) {
            X = Next(X);
            Info(X).Move = Info(X).MaxMove;
            Info(X).Hit = true;
        }
    }
    for(i = 0 ; i <= (*M).NBrsEff-1; i++)
    {
        for(j = 0 ; j <= (*M).NKolEff-1; j++)
        {
            if((*M).Tiles[i][j].unit.ID != ' ')
            {
                (*M).Tiles[i][j].unit.Move = (*M).Tiles[i][j].unit.MaxMove;
                (*M).Tiles[i][j].unit.Hit = true;
            }
        }
    }
}
