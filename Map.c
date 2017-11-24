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
    /*
    (*M).Tiles[*NBrs-1][1].Building ='C';
    (*M).Tiles[*NBrs-2][0].Building ='C';
    (*M).Tiles[*NBrs-2][2].Building ='C';
    (*M).Tiles[*NBrs-3][1].Building ='C';
    (*M).Tiles[*NBrs-2][1].Building ='T';
    (*M).Tiles[0][*NKol-2].Building ='C';
    (*M).Tiles[1][*NKol-1].Building ='C';
    (*M).Tiles[1][*NKol-3].Building ='C';
    (*M).Tiles[2][*NKol-2].Building ='C';
    (*M).Tiles[1][*NKol-2].Building ='T';
    */
}

void AddUnitToMap(Map * M, TypeUnit Unit)
{

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
                printf(" %c *",M.Tiles[idxBrs][j].building.ID);
            }
            else if ((i-1) % 4 == 0) {
                printf(" %c *",M.Tiles[idxBrs][j].unit.ID);
            }
            else if ((i-2) % 4 == 0) {
                printf(" %c *",M.Tiles[idxBrs][j].Misc);
            }
            else if ((i-3) % 4 == 0) {
                printf("****");
            }
            idxBrs++;
        }
        printf("\n");
    }

}

