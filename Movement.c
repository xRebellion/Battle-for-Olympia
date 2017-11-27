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

boolean isThereEnemy (Player P1, Player P2, TypeUnit unit, int x, int y) {
    //P2 dianggap enemy, x y adalah di petak tsb
    addressU P = First(P2.Unit);
    boolean cek = false;
    while ((P != Nil) && (!cek)) {
        if ((x == Info(P).Location.X) && (y == Info(P).Location.Y)) {
            cek = true;
        }
        P = Next(P);
    }
    return cek;
}

boolean isMovePossible (Player P1, Player P2, Map * M, TypeUnit unit, char direction, int x, int y)
{
    int i;
    int maxmove = unit.MaxMove;
    boolean cek=false;
    POINT location = unit.Location;
    if (direction == 'n') {
        if ((x == PosX(unit)) && (y<=(*M).NKolEff) && (y>=0) && (PosY(unit)-y <= unit.MaxMove)) {
            i = 1;
            while ((i<=y) && (!cek)) {
                cek = isThereEnemy(P1,P2,unit,x,y-i);
                i++;
            }
            return (!cek);
        }
    } else if (direction == 's') {
        if ((x == PosX(unit)) && (y<=(*M).NKolEff) && (y>=0) && (y-PosY(unit) <= unit.MaxMove)) {
            i = 1;
            while ((i<=y) && (!cek)) {
                cek = isThereEnemy(P1,P2,unit,x,y+i);
                i++;
            }
            return (!cek);
        }
    } else if (direction == 'e') {
        if ((y == PosY(unit)) && (x<=(*M).NBrsEff) && (x>=0) && (x-PosX(unit) <= unit.MaxMove)) {
            i = 1;
            while ((i<=y) && (!cek)) {
                cek = isThereEnemy(P1,P2,unit,x+i,y);
                i++;
            }
            return (!cek);
        }
    } else if (direction == 'w') {
        if ((y == PosY(unit)) && (x<=(*M).NBrsEff) && (x>=0) && (PosX(unit)-x <= unit.MaxMove)) {
            i = 1;
            while ((i<=y) && (!cek)) {
                cek = isThereEnemy(P1,P2,unit,x-i,y);
                i++;
            }
            return (!cek);
        }
    } else {
        return false;
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


boolean Move(Player P1, Player P2, Map * M, TypeUnit * unit, int x, int y)
{
    char direction = determineDirection(*unit,x,y); //Initial State: X, arti: not possible
    boolean movePossible = isMovePossible(P1, P2, M, *unit, direction, x, y);
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

void InsertDummyMap(Player P1, Player P2, Map M, Map * MDummy, TypeUnit currUnit)
{
    *MDummy = M;

    TypeUnit Dummy[100];
    int count=0,i;
    int n,s,e,w;

    n=0;s=0;e=0;w=0;
    //n
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(P1, P2,&M, currUnit, n, PosX(currUnit)+i, PosY(currUnit))) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].ID = '#';
            Dummy[count].Location.X = PosX(currUnit)+i;
            Dummy[count].Location.Y = PosY(currUnit);
        }
    }
    //s
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(P1, P2, &M, currUnit, s, PosX(currUnit)-i, PosY(currUnit))) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].ID = '#';
            Dummy[count].Location.X = PosX(currUnit)-i;
            Dummy[count].Location.Y = PosY(currUnit);
        }
    }
    //e
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(P1, P2, &M, currUnit, e, PosX(currUnit), PosY(currUnit)+i)) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].ID = '#';
            Dummy[count].Location.X = PosX(currUnit);
            Dummy[count].Location.Y = PosY(currUnit)+i;
        }
    }
    //w
    for (i=1; i<=currUnit.MaxMove; i++) {
        if (isMovePossible(P1, P2, &M, currUnit, w, PosX(currUnit), PosY(currUnit)-i)) {
            count++;
            Dummy[count] = currUnit;
            Dummy[count].ID = '#';
            Dummy[count].Location.X = PosX(currUnit);
            Dummy[count].Location.Y = PosY(currUnit)-i;
        }
    }
    for (i=1; i<=count; i++) {
        AddUnitToMap(&(*MDummy), Dummy[i]);
    }
}

void MoveCommand(Player P1, Player P2, Map * M, TypeUnit currUnit, POINT * PrevLoc)
{

    Map MDummy;
    char direction;
    int x, y;
    (*PrevLoc).X = PosX(currUnit);
    (*PrevLoc).Y = PosY(currUnit);
    InsertDummyMap(P1, P2, *M, &MDummy, currUnit);
    PrintMap(MDummy);
    //RemoveDummyUnit(M, currUnit);
    printf("Where do you want to move? ( Input: x y )\n");
    scanf ("%d %d", &x, &y);
    direction = determineDirection(currUnit,x,y);

    if(!Move(P1, P2, M,&currUnit,x,y)) //Kalo movenya gagal
    {
        printf("Oops, you can't move there!\n");
    } else
    {
        printf("You have successfully moved to (%d,%d)\n", x, y);
        PosX(currUnit) = x;
        PosY(currUnit) = y;
    }

}
