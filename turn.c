#include <stdio.h>
#include "boolean.h"
#include "turn.h"

void ChangeTurn (Queue *P) {
    infotypeQ temp;
    DelQ(&(*P), &temp);
    AddQ(&(*P), temp);
    UpdateInfo(&InfoHead(*P));
}
