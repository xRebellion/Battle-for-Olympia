#include "rekruit.h"
#include "init.h"



int main () {
    Player P;
    Map M;
    int NBrs,NKol;

    CreateEmptyMap(&M,&NBrs,&NKol);
    M.Tiles[0][NBrs - 1].building.OwnerID=1;
    M.Tiles[0][NBrs - 1].building.ID='C';
    M.Tiles[0][NBrs - 1].unit.ID=' ';
    M.Tiles[1][NBrs - 2].building.OwnerID=1;
    M.Tiles[1][NBrs - 2].building.ID='C';
    M.Tiles[1][NBrs - 2].unit.ID='S';
    M.Tiles[1][NBrs].building.OwnerID=1;
    M.Tiles[1][NBrs].unit.ID='S';
    M.Tiles[2][NBrs - 1].building.OwnerID=1;
    M.Tiles[2][NBrs - 1].unit.ID='S';
    M.Tiles[NKol - 2][1].building.OwnerID=2;
    M.Tiles[NKol - 2][1].unit.ID=' ';
    M.Tiles[NKol - 2][1].building.ID='C';
    M.Tiles[NKol - 1][0].building.OwnerID=2;
    M.Tiles[NKol - 1][0].unit.ID=' ';
    M.Tiles[NKol - 1][2].building.OwnerID=2;
    M.Tiles[NKol - 1][2].unit.ID=' ';
    M.Tiles[NKol][1].building.OwnerID=2;
    M.Tiles[NKol][1].unit.ID=' ';
    InitializePlayer(P,1);
    P.Gold = 100;

    Recruit(M,&P,&NBrs,&NKol);
    printf("%d",P.Gold);

}
