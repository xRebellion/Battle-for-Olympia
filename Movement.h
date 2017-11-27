//Movement.c

#include "init.h"
#include "Map.h"



char determineDirection(TypeUnit unit, int x, int y);
//Untuk menentukan arah gerak dari si unit
//Belum dibuat untuk yang diagonal




boolean isThereEnemy (Player P1, Player P2, TypeUnit unit, int x, int y);

boolean isMovePossible (Player P1, Player P2, Map M, TypeUnit unit, char direction, int x, int y);

boolean Move(Player P1, Player P2, Map * M, TypeUnit unit, int x, int y);

void InsertDummyMap(Player P1, Player P2, Map M, Map * MDummy, TypeUnit currUnit);
