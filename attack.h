#include "ADT/boolean.h"
#include "init.h"
#include "ADT/list_unit.h"
#include "Map.h"
#include "ADT/point.h"
#include <stdio.h>

boolean AccuracyCheck();
/* Fungsi untuk menentukan hit/miss suatu serangan */

boolean isAdjacent(TypeUnit T1, TypeUnit T2);
/* Memeriksa apakah T1 dan T2 bersebelahan */

void ChooseTarget(Map M, POINT *P, TypeUnit T1,  Player P1, Player P2);
/* Meminta input koordinat unit yang ingin diserang dan menyerangnya jika dipenuhi syarat-syarat tertentu */

boolean isEnemyUnit(Map M, POINT P, Player P2);
/* Memeriksa apakah ada unit milih P2 di koordinat P */

void Attack(TypeUnit *T1, TypeUnit *T2, Player *P1, Player *P2, Map *M);
/* T1 adalah unit milik P1 yang menyerang, T2 adalah unit milik P2 yang diserang */
