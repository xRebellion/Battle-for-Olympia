#include "Map.h"


void CreateEmptyMap(Map *M,int *NBrs, int *NKol) {
    int i,j;
    printf("Masukkan Ukuran Map\n");
    printf("Panjang (Sumbu Y): \n");
    scanf("%d",NBrs);
    printf("Lebar (Sumbu X): \n");
    scanf("%d",NKol);

    for (i = 0; i < *NBrs; i++) {
        for (j = 0; j < *NKol; j++) {
            (*M).Tiles[i][j].building.ID = ' ';
            (*M).Tiles[i][j].unit.ID = ' ';
            (*M).Tiles[i][j].Misc = ' ';
        }
    }

}



void PrintMap(Map M,int NBrs, int NKol) {
    int i,j,idx,idxBrs;
    printf(" ");
    idx = 0;
    for (j = 1; j <= NKol*5-NKol+1; j++) {
        if ((j-3) % 4 == 0) {
            printf("%d",idx);
            idx++;
        }
        else {
            printf(" ");
        }
    }
    printf("\n ");
    for (j = 1; j <= NKol*5-NKol+1; j++) {
        printf("*");
    }
    printf("\n");
    idx = 0;
    for (i = 0; i < NBrs*4; i++) {
        if ((i-1) % 4 == 0) {
            printf("%d*",idx);
            idx++;
        }
        else {
            printf(" *");
        }
        idxBrs = 0;
        for (j = 0; j < NKol; j++) {
            if (i % 4 == 0) {
                printf(" %c *",M.Tiles[i/4][j].building.ID);

            }
            else if ((i-1) % 4 == 0) {
                printf(" %c *",M.Tiles[i/4][j].unit.ID);
            }
            else if ((i-2) % 4 == 0) {
                printf(" %c *",M.Tiles[i/4][j].Misc);
            }
            else if ((i-3) % 4 == 0) {
                printf("****");
            }
            idxBrs++;
        }
        printf("\n");
    }

}

void AddUnitToMap(Map * M, TypeUnit Unit)
{
    (*M).Tiles[PosY(Unit)][PosX(Unit)].unit.ID = Unit.ID;
}

void RemoveUnitFromMap(Map * M, TypeUnit Unit)
{
    (*M).Tiles[PosY(Unit)][PosX(Unit)].unit.ID = ' ';
}

void AddBuildingToMap(Map * M, Building building)
{
    (*M).Tiles[PosY(building)][PosX(building)].building.ID = building.ID;
}

void RemoveBuildingFromMap(Map * M, Building building)
{
    (*M).Tiles[PosY(building)][PosX(building)].building.ID = ' ';
}


