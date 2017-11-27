#include <stdio.h>
#include "boolean.h"
#include "turn.h"

void ChangeTurn (Queue *P) {
    infotypeQ temp;
    DelQ(&(*P), &temp);
    AddQ(&(*P), temp);
    UpdateInfo(&InfoHead(*P));
    RefreshMovementAndAttack(&InfoHead(*P));

}

void RefreshMovementAndAttack (Player *P){
//Mengisi kembali movement unit dengan max move dan attack condition
    //Kamus lokal
    addressU X;
    TypeUnit Unit;
    //Algoritma
    if (!IsEmptyUnit((*P).Unit)){
        X = First((*P).Unit);
        Unit = Info(X);
        Unit.Move = Unit.MaxMove;
        Unit.Attack = true;
        while (Next(X) != Nil) {
            X = Next(X);
            Unit = Info(X);
            Unit.Move = Unit.MaxMove;
            Unit.Attack = true;
        }
    }
}
