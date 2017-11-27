//Movement.c
#include "Movement.h"
#include "ADT\queue.h"
#include "ADT\stackt.h"


char determineDirection(TypeUnit unit, int x, int y)
//Untuk menentukan arah gerak dari si unit
//Belum dibuat untuk yang diagonal
{
    char direction;
    if (PosX(unit) == x)
    {
        if(PosY(unit) < y)
        {
            direction = 's';
        }
        else
        if(PosY(unit) > y)
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
boolean isThereUnit (Player P1, TypeUnit unit, int x, int y) {
    addressU P = First(P1.Unit);
    boolean cek = false;

    while ((P != Nil) && (!cek)) {
        if ((x == PosX(Info(P))) && (y == PosY(Info(P))) && (!IsUnitEQ(unit, Info(P)))) {
            cek = true;
        }
        P = Next(P);
    }
    return cek;
}
boolean isThereEnemy (Player P1, Player P2, TypeUnit unit, int x, int y) {
    //P2 dianggap enemy, x y adalah di petak tsb
    addressU P = First(P2.Unit);

    boolean cek = false;
    while ((P != Nil) && (!cek)) {
        if ((x == PosX(Info(P))) && (y == PosY(Info(P)))) {
            cek = true;
        }
        P = Next(P);
    }
    return cek;
}

boolean isMovePossible (Player P1, Player P2, Map M, TypeUnit unit, char direction, int x, int y)
{
    int i;
    int maxmove = unit.Move;
    boolean cek=false;
    POINT location = unit.Location;
    if (direction == 'n') {
        if ( (PosX(unit) == x) &&(y<=(M).NBrsEff) && (y>=0) && (PosY(unit)-y <= unit.Move)) {
            i = 1;
            while ((i<=(PosY(unit)-y)) && (!cek)) {
                cek = isThereEnemy(P1,P2,unit,x,y+i);
                i++;
            }
            return (!cek);
        }
    } else if (direction == 's') {
        if ((PosX(unit) == x) && (y<=(M).NBrsEff) && (y>=0) && (y-PosY(unit) <= unit.Move)) {
            i = 1;
            while ((i<=(y-PosY(unit)) && (!cek))) {
                cek = isThereEnemy(P1,P2,unit,x,y-i);
                i++;
            }
            return (!cek);
        }
    } else if (direction == 'e') {
        if ((PosY(unit) == y) && (x<=(M).NKolEff) && (x>=0) && (x-PosX(unit) <= unit.Move)) {
            i = 1;
            while ((i<=(x-PosX(unit)) && (!cek))) {
                cek = isThereEnemy(P1,P2,unit,x-i,y);
                i++;
            }
            return (!cek);
        }
    } else if (direction == 'w') {
        if ((PosY(unit) == y) && (x<=(M).NKolEff) && (x>=0) && (PosX(unit)-x <= unit.Move)) {
            i = 1;
            while ((i<=(PosX(unit)-x) && (!cek))) {
                cek = isThereEnemy(P1,P2,unit,x+i,y);
                i++;
            }
            return (!cek);
        }
    } else {
        return false;
    }
}


boolean Move(Player P1, Player P2, Map * M, TypeUnit unit, int x, int y)
{
    char direction = determineDirection(unit,x,y); //Initial State: X, arti: not possible
    boolean movePossible = isMovePossible(P1, P2, * M, unit, direction, x, y);
    //step = &(unit.Move);
    //movePossible = isMovePossible(M, *unit, direction, x, y);
    return (movePossible);
}

void PushStack (Stack *S, Player P1, Map M, TypeUnit currUnit) {
    infotypeS temp;
    temp.M = M;
    temp.P = P1;
    temp.unit = currUnit;

}

void Undo (Stack *S, Player *P1, Map *M, TypeUnit *currUnit) {
    infotypeS temp;
    if(IsEmptyS(*S)) {
        printf("Oops! You can undo no more.\n");
    } else {
        Pop(&(*S), &temp);
        *P1 = temp.P;
        *M = temp.M;
        *currUnit = temp.unit;
    }
}

void InsertDummyMap(Player P1, Player P2, Map M, Map * MDummy, TypeUnit currUnit)
{
    *MDummy = M;

    TypeUnit Dummy[100];
    int count=0,i;


    printf("\n");
    //n
    for (i=1; i<=currUnit.Move; i++) {
        if (isMovePossible(P1, P2,M, currUnit, 'n', PosX(currUnit), PosY(currUnit)-i)) {
            if(M.Tiles[PosY(currUnit)-i][PosX(currUnit)].unit.ID == ' ')
            {

                count++;
                Dummy[count] = currUnit;
                Dummy[count].ID = '#';
                Dummy[count].Location.X = PosX(currUnit);
                Dummy[count].Location.Y = PosY(currUnit)-i;

            }

        }
    }
    //s
    for (i=1; i<=currUnit.Move; i++) {
        if (isMovePossible(P1, P2,M, currUnit, 's', PosX(currUnit), PosY(currUnit)+i)) {
            if(M.Tiles[PosY(currUnit)+i][PosX(currUnit)].unit.ID == ' ')
            {
                count++;
                Dummy[count] = currUnit;
                Dummy[count].ID = '#';
                Dummy[count].Location.X = PosX(currUnit);
                Dummy[count].Location.Y = PosY(currUnit)+i;
            }
        }
    }
    //e
    for (i=1; i<=currUnit.Move; i++) {
        if (isMovePossible(P1, P2,M, currUnit, 'e', PosX(currUnit)+i, PosY(currUnit))) {
            if(M.Tiles[PosY(currUnit)][PosX(currUnit)+i].unit.ID == ' ')
            {
                count++;
                Dummy[count] = currUnit;
                Dummy[count].ID = '#';
                Dummy[count].Location.X = PosX(currUnit)+i;
                Dummy[count].Location.Y = PosY(currUnit);
            }
        }
    }
    //w
    for (i=1; i<=currUnit.Move; i++) {
        if (isMovePossible(P1, P2,M, currUnit, 'w', PosX(currUnit)-i, PosY(currUnit))) {
            if(M.Tiles[PosY(currUnit)][PosX(currUnit)-i].unit.ID == ' ')
            {
                count++;
                Dummy[count] = currUnit;
                Dummy[count].ID = '#';
                Dummy[count].Location.X = PosX(currUnit)-i;
                Dummy[count].Location.Y = PosY(currUnit);
            }
        }
    }
    printf("%d\n",count);
    for (i=1; i<=count; i++) {
        AddUnitToMap(&(*MDummy), Dummy[i]);
        printf("\n");
    }
}


void MoveCommand(Stack *S, Player P1, Player P2, Map * M, TypeUnit *currUnit, POINT * PrevLoc)
{
    Map MDummy;
    MDummy = *M;

    char direction;
    int x, y;
    (*PrevLoc).X = PosX(*currUnit);
    (*PrevLoc).Y = PosY(*currUnit);
    PushStack (&(*S), P1, *M, *currUnit);
    InsertDummyMap(P1, P2, * M, &MDummy, *currUnit);
    PrintMap(MDummy);
    //RemoveDummyUnit(M, *currUnit);
    printf("Where do you want to move? ( Input: x y )\n");
    scanf ("%d %d", &x, &y);
    direction = determineDirection(*currUnit,x,y);
    printf("%d %d %c\nx y %d %d\n",!isMovePossible(P1, P2, *M, *currUnit, direction,x,y), isThereEnemy(P1, P2, *currUnit,x,y), direction,x,y);
    if(!isMovePossible(P1, P2, *M, *currUnit, direction,x,y) || isThereEnemy(P1, P2, *currUnit,x,y) || isThereUnit(P1, *currUnit, x, y)) //Kalo movenya gagal
    {
        printf("Oops, you can't move there!\n");
    } else
    {
        printf("You have successfully moved to (%d,%d)\n", x, y);
        RemoveUnitFromMap(M, *currUnit);
        int mx = abs(PosX(*currUnit) - x + PosY(*currUnit) - y);
        PosX(*currUnit) = x;
        PosY(*currUnit) = y;
        (*currUnit).Move -= mx;
        AddUnitToMap(M, *currUnit);
        if ((*M).Tiles[y][x].building.Type = 'V') {
            (*M).Tiles[y][x].building.OwnerID = P1.PlayerID;
            InsVLastBuilding(&(P1).Villages,(*M).Tiles[y][x].building);
        }
        PushStack (&(*S), P1, *M, *currUnit);
    }

}
