#include "Map.h"
#include "ADT/stackt.h"
#include "UpdateInfo.h"

void CreateEmptyMap(Map *M,int *NBrs, int *NKol) {
    int i,j;
    printf("========================================\n");
    printf("              Map Creation\n");
    printf("========================================\n");
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

    printf("========================================\n");
    printf("        Map Successfully Created!\n");
    printf("========================================\n");

}

void PrintMap(Map M)
{

    int i,j,idx,idxBrs;
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
        } else{
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
                idx++;
            } else
            {
                printf("%d*",idx);
                idx++;
            }

        }
        else {
            printf("  *");
        }
        idxBrs = 0;
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
            idxBrs++;
        }
        printf("\n");
    }

}

void AddUnitToMap(Map * M, TypeUnit Unit)
{
    (*M).Tiles[PosY(Unit)][PosX(Unit)].unit = Unit;
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

void InfoM (Player P1, Player P2, Map M) {
    int x, y;
    printf("Enter the coordinate of the cell x y : ");
    scanf ("%d %d", &x, &y);
    if (!(M.Tiles[y][x].building.ID == ' ')) {
        printf("== Cell Info ==\n");
        if (M.Tiles[y][x].building.ID == 'V') {
            printf("Village\n");
        } else if (M.Tiles[y][x].building.ID == 'C') {
            printf("Castle\n");
        } else if (M.Tiles[y][x].building.ID == 'T') {
            printf("Tower\n");
        }
        if (M.Tiles[y][x].building.OwnerID == 1) {
            printf("Owned by Player 1\n \n");
        }
    }
    if (!(M.Tiles[y][x].unit.ID == ' ')) {
        printf("== Unit Info==\n");
        if (M.Tiles[y][x].unit.ID == 'S') {
            printf("Swordsman\n");
        } else if (M.Tiles[y][x].unit.ID == 'A') {
            printf("Archer\n");
        } else if (M.Tiles[y][x].unit.ID == 'W') {
            printf("White Mage\n");
        } else if (M.Tiles[y][x].unit.ID == 'K') {
            printf("King\n");
        }
        if (SearchUnit(P1.Unit, M.Tiles[y][x].unit)) {
            printf("Owned by Player 1\n");
        } else {
            printf("Owned by Player 2\n");
        }
        PrintInfo(M.Tiles[y][x].unit);
    }
}
