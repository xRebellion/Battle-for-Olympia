#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "ADT/stackt.h"



void CreateEmptyMap(Map *M,int *NBrs, int *NKol);

void PrintMap(Map M);

void AddUnitToMap(Map * M, TypeUnit Unit);

void RemoveUnitFromMap(Map * M, TypeUnit Unit);

void AddBuildingToMap(Map * M, Building building);

void RemoveBuildingFromMap(Map * M, Building building);

void InfoM (Player P1, Player P2, Map M);
