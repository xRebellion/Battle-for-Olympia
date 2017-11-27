#ifndef MAPINITIALIZE_H
#define MAPINITIALIZE_H

#include "Map.h"
#include "stdio.h"
#include "ADT/list_building.h"
#include "ADT/point.h"
#include "ADT/boolean.h"

boolean IsThereBuilding(Map M, int X, int Y);

void InitializeMap(Map *M,int NBrs, int NKol);

#endif // MAPINITIALIZE_H
