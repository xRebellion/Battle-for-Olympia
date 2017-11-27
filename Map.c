#include "Map.h"


void CreateEmptyMap(Map *M,int *NBrs, int *NKol) {
    int i,j;
    printf("==============================================================\n");
    printf("                        Map Creation\n");
    printf("==============================================================\n");
    do
    {
        printf("Insert Map Rows (Y Axis): ");
        scanf("%d",NBrs);
        if(*NBrs < 8)
        {
            printf("Minimum Map Size: 8x8\n");
            printf("Try Again!\n");
        }
    }
    while(*NBrs < 8);
    do{
    printf("Insert Map Columns (X Axis): ");
    scanf("%d",NKol);

        if(*NKol < 8)
        {
            printf("Minimum Map Size: 8x8\n");
            printf("Try Again!\n");
        }
    } while (*NKol < 8);

    for (i = 0; i < *NBrs; i++) {
        for (j = 0; j < *NKol; j++) {
            (*M).Tiles[i][j].building.Type = ' ';
            (*M).Tiles[i][j].unit.ID = ' ';
            (*M).Tiles[i][j].Misc = ' ';
        }
    }
    (*M).NBrsEff = *NBrs;
    (*M).NKolEff = *NKol;

    printf("==============================================================\n");
    printf("                  Map Successfully Created!\n");
    printf("==============================================================\n");

}

void PrintMap(Map M)
{

    int i,j,idx;
    printf("  ");
    idx = 0;
    for (j = 1; j <= M.NKolEff*5-M.NKolEff+1; j++) {
        if(idx < 10)
        {
            if ((j-3) % 4 == 0) {
                printf("%d",idx);
                idx++;
            }
            else {
                printf(" ");
            }
        } else
        {
            if ((j-3) % 3 == 0) {
                printf("%d",idx);
                idx++;
            }
            else {
                printf(" ");
            }
            if(idx == M.NKolEff)
            {
                break;
            }
        }

    }
    printf("\n  ");
    for (j = 1; j <= M.NKolEff*5-M.NKolEff+1; j++) {
        printf("*");
    }
    printf("\n");
    idx = 0;
    for (i = 0; i < M.NBrsEff*4; i++) {
        if ((i-1) % 4 == 0) {
            if(idx < 10)
            {
                printf("%d *",idx);
            } else
            {
                printf("%d*",idx);
            }

            idx++;
        }
        else {
            printf("  *");
        }
        for (j = 0; j < M.NKolEff; j++) {
            if (i % 4 == 0) {
                printf(" %c *",M.Tiles[i/4][j].building.Type);
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
        }
        printf("\n");
    }

}

void AddUnitToMap(Map * M, TypeUnit Unit)
{
    (*M).Tiles[PosY(Unit)][PosX(Unit)].unit = Unit;
    //printf("unit ID x y = %c %d %d\n", (*M).Tiles[PosY(Unit)][PosX(Unit)].unit.ID, PosX(Unit), PosY(Unit));
}

void RemoveUnitFromMap(Map * M, TypeUnit Unit)
{
    (*M).Tiles[PosY(Unit)][PosX(Unit)].unit.ID = ' ';
}

void AddBuildingToMap(Map * M, Building BuildingIns)
{
    (*M).Tiles[PosY(BuildingIns)][PosX(BuildingIns)].building = BuildingIns;
}

void RemoveBuildingFromMap(Map * M, Building BuildingIns)
{
    (*M).Tiles[PosY(BuildingIns)][PosX(BuildingIns)].building.Type = ' ';
}


