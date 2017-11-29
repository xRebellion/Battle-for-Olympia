#include "init.h"
#include "ADT\queue.h"
#include "UpdateInfo.h"

void ChangeTurn (Map * M, Queue *P, Player P1, Player P2);
//Fungsi untuk melaukan pergantian turn

void RefreshMovementAndAttack (Map * M, Player *P);
//Mengisi kembali movement unit dengan max move dan attack condition
