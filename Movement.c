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
{/*
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
    char direction = 'x'; //Initial State: X, arti: not possible
    int * step; //pointer to maxmove
    boolean movePossible = true;
    //step = &(unit.MaxMove);
    //movePossible = isMovePossible(M, *unit, direction);
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

void InsertDummyUnit(Map * M, TypeUnit currUnit)
{

}

void MoveCommand(Map * M, TypeUnit currUnit, int * PrevX, int * PrevY)
{
    char direction;
    int x, y;
    *PrevX = PosX(currUnit);
    *PrevY = PosY(currUnit);

    //InsertDummyUnit(M, currUnit);
 //   PrintMap(*M,(*M).NBrsEff,(*M).NKolEff);
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
    }

}
