//Movement.c
#include "Movement.h"


char determineDirection(TypeUnit unit, int x, int y)
//Untuk menentukan arah gerak dari si unit
//Belum dibuat untuk yang diagonal
{
    char direction;
    if (PosX(unit) == x)
    {
        if(PosY(unit) > y)
        {
            direction = 's';
        }
        else
        if(PosY(unit) < y)
        {
            direction = 'n';
        }
        else //kalo sama
        {
            direction = 'x';
        }
    }
    else
    if (PosY(unit) == y)
    {
        if(PosX(unit) > x)
        {
            direction = 'w';
        }
        else
        if (PosX(unit) < x)
        {
            direction = 'e';
        }
        else
        {
            direction = 'x';
        }
    } else //cek diagonal
    {
        /*DIAGONAL IDENTIFIER:
         North East -> 'a'
         South East -> 'b'
         South West -> 'c'
         North West -> 'd'
        */
        //cek diagonal
        //else
        direction = 'x';
    }
    return direction;
}



boolean isMovePossible (Map * M, TypeUnit unit, char direction, int x, int y)
{
    int i;
    int maxmove = unit.MaxMove;
    POINT location = unit.Location;
    if (direction == 'n') {
        return ((x == PosX(unit)) && (y<=(*M).NKolEff) && (y>=0) && (PosY(unit)-y <= unit.MaxMove));
    } else if (direction == 's') {
        return ((x == PosX(unit)) && (y<=(*M).NKolEff) && (y>=0) && (y-PosY(unit) <= unit.MaxMove));
    } else if (direction == 'e') {
        return ((y == PosY(unit)) && (x<=(*M).NBrsEff) && (x>=0) && (x-PosX(unit) <= unit.MaxMove));
    } else if (direction == 'w') {
        return ((y == PosY(unit)) && (x<=(*M).NBrsEff) && (x>=0) && (PosX(unit)-x <= unit.MaxMove));
    }
/*
    int i;
    boolean blocked = false;
    int * step = &unit.MaxMove;

    if(direction == 'n') // north
    {
        for (i = 0;((i <= *step) && (!blocked)); i++)
        {
            if (M.Tiles[PosX(unit)][PosY(unit)])
            {
                blocked = true;
            }
        }

    } else
    if(direction == 'e') // east
    {
        for (i = 0;((i <= *step) && (!blocked)); i++)
        {
            if (/*ada unit musuh di M[unit.x+i][unit.y])
            {
                blocked = true;
            }
        }
    } else
    if(direction == 's') // south
    {
        for (i = 0;((i <= *step) && (!blocked)); i++)
        {
            if (/*ada unit musuh di M[unit.x][unit.y-i] )
            {
                blocked = true;
            }
        }
    } else
    if(direction == 'w') // west
    {
        for (i = 0;((i <= *step) && (!blocked)); i++)
        {
            if (/*ada unit musuh di M[unit.x-i][unit.y] )
            {
                blocked = true;
            }
        }
    }
    if (direction ='x') //direction = x berarti koordinat x y tidak bisa ditempati/dicapai
    {
        blocked = true;
    }

    //Check apakah X Y berada dalam jangkauan movement point
    if(!blocked)
    {

    }

    return !blocked;
*/
}


boolean Move(Map * M, TypeUnit * unit, int x, int y)
{
    char direction = determineDirection(*unit,x,y); //Initial State: X, arti: not possible
    boolean movePossible = isMovePossible(M, *unit, direction, x, y);
    //step = &(unit.MaxMove);
    //movePossible = isMovePossible(M, *unit, direction, x, y);
    if(!movePossible)
    {
        return false;
    } else
    {
        PosX(*unit) = x;
        PosY(*unit) = y;

        return true;
    }


}

void InsertDummyMap(Map * M, Map * MDummy, TypeUnit currUnit)
{
    *MDummy = *M;

    TypeUnit Dummy[100];
    int count=0,i;
    int n,s,e,w;

    n=0;s=0;e=0;w=0;
    //n
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(M, currUnit, n, PosX(currUnit)+i, PosY(currUnit))) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].Location.X = PosX(currUnit)+i;
            Dummy[count].Location.Y = PosY(currUnit);
        }
    }
    //s
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(M, currUnit, s, PosX(currUnit)-i, PosY(currUnit))) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].Location.X = PosX(currUnit)-i;
            Dummy[count].Location.Y = PosY(currUnit);
        }
    }
    //e
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(M, currUnit, e, PosX(currUnit), PosY(currUnit)+i)) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].Location.X = PosX(currUnit);
            Dummy[count].Location.Y = PosY(currUnit)+i;
        }
    }
    //w
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(M, currUnit, w, PosX(currUnit), PosY(currUnit)-i)) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].Location.X = PosX(currUnit);
            Dummy[count].Location.Y = PosY(currUnit)-i;
        }
    }

    for (i=1; i<=count; i++) {
        //AddUnitToMap(MDummy, Dummy[i]);
    }
    //PrintMap(*MDummy,(*MDummy).NBrsEff,(*MDummy).NKolEff);
}

void MoveCommand(Map * M, TypeUnit currUnit, POINT * PrevLoc)
{

    Map MDummy;
    char direction;
    int x, y;

    (*PrevLoc).X = PosX(currUnit);
    (*PrevLoc).Y = PosY(currUnit);
    //InsertDummyMap(M, &MDummy, currUnit);
    //printf("%d, %d\n", (*M).NBrsEff,(*M).NKolEff);
    //PrintMap(*M,(*M).NBrsEff,(*M).NKolEff);
    //RemoveDummyUnit(M, currUnit);
    printf("Where do you want to move? ( Input: x y )\n");
    scanf ("%d %d", &x, &y);
    direction = determineDirection(currUnit,x,y);

    if(!Move(M,&currUnit,x,y)) //Kalo movenya gagal
    {
        printf("Oops, you can't move there!\n");
    } else
    {
        printf("You have successfully moved to (%d,%d)\n", x, y);
        PosX(currUnit) = x;
        PosY(currUnit) = y;
    }

}
