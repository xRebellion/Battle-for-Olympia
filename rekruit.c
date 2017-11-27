#include "rekruit.h"

void Recruit(Map *M, Player *P, int *NBrs, int *NKol)
{
    //Kamus lokal
    TypeUnit Swordsman, Archer, WMage;
    int pilunit,X,Y;
    boolean kosong, loop, c1,c2,c3,c4,c5,c6,c7,c8;


    //Pendefinisian status Swordsman
    Swordsman.ID = 'S';
    Swordsman.Name = "Swordsman";
    Swordsman.MaxHealth =20;
    Swordsman.Health = 20;
    Swordsman.Attack = 3;
    Swordsman.MaxMove = 2;
    Swordsman.Move = 0;
    Swordsman.AttackType='m';
    Swordsman.Hit = false;
    Swordsman.Upkeep = 2;
    Swordsman.Harga = 4;
    //Pendefinisian status Archer
    Archer.ID='A';
    Archer.Name = "Archer";
    Archer.MaxHealth = 20;
    Archer.Health = 20;
    Archer.Attack = 4;
    Archer.MaxMove = 2;
    Archer.Move = 0;
    Archer.AttackType='r';
    Archer.Hit = false;
    Archer.Upkeep = 3;
    Archer.Harga = 5;
    //Pendefinisian status white mage
    WMage.ID = 'W';
    WMage.Name = "White Mage";
    WMage.MaxHealth = 15;
    WMage.Attack = 2;
    WMage.MaxMove = 2;
    WMage.Move = 0;
    WMage.AttackType ='m';
    WMage.Hit = false;
    WMage.Upkeep = 5;
    WMage.Harga = 10;

    //Pengecekan status castle apakah terisi atau tidak
    if((*M).Tiles[0][*NBrs - 2].building.OwnerID!=(*P).PlayerID){
       c1 = false;
    }
    else{
        if((*M).Tiles[0][*NBrs - 2].unit.ID!=' '){
            c1=false;
        }
        else{
            c1=true;
        }
    }
    if((*M).Tiles[1][*NBrs - 3].building.OwnerID!=(*P).PlayerID){
        c2 = false;
    }
    else{
        if((*M).Tiles[1][*NBrs - 3].unit.ID!=' '){
            c2=false;
        }
        else{
            c2=true;
        }
    }
    if((*M).Tiles[1][*NBrs - 1].building.OwnerID!=(*P).PlayerID){
        c3 = false;
    }
    else{
        if((*M).Tiles[1][*NBrs - 1].unit.ID!=' '){
            c3 = false;
        }
        else{
            c3 = true;
        }

    }
    if((*M).Tiles[2][*NBrs - 2].building.OwnerID!=(*P).PlayerID){
        c4 = false;
    }
    else{
        if((*M).Tiles[2][*NBrs - 2].unit.ID!=' '){
            c4 = false;
        }
        else{
            c4 = true;
        }
    }
    if((*M).Tiles[*NKol - 3][1].building.OwnerID!=(*P).PlayerID){
        c5 = false;
    }
    else{
        if((*M).Tiles[*NKol - 3][1].unit.ID!=' '){
            c5 = false;
        }
        else{
            c5 = true;
        }
    }
    if((*M).Tiles[*NKol - 2][0].building.OwnerID!=(*P).PlayerID){
        c6 = false;
    }
    else{
        if((*M).Tiles[*NKol - 2][0].unit.ID!=' '){
            c6 = false;
        }
        else{
            c6 = true;
        }
    }
    if((*M).Tiles[*NKol - 2][2].building.OwnerID!=(*P).PlayerID){
        c7 = false;
    }
    else{
        if((*M).Tiles[*NKol - 2][2].unit.ID!=' '){
            c7 = false;
        }
        else{
            c7 = true;
        }
    }
    if((*M).Tiles[*NKol-1][1].building.OwnerID!=(*P).PlayerID){
        c8 = false;
    }
    else{
        if((*M).Tiles[*NKol-1][1].unit.ID!=' '){
            c8 = false;
        }
        else{
            c8 = true;
        }
    }

    //Cara perekruitan
    if((c1 == false) && (c2 == false) && (c3 == false) && (c4 == false) && (c5 == false) && (c6 == false) && (c7 == false) && (c8 == false)){ // semua castle terisi
        printf("All your castle is occupied\n");
    }
    else{//castle gapenuh
        printf("Please enter castle coordinate : ");
        scanf("%d %d",&X,&Y);

        kosong = false;
        while(!kosong){
            if ((*M).Tiles[X][Y].building.ID!='C'){//koordinat yang dituju bukan castle
                    printf("This is not a castle, please enter castle coordinate\n");
                    printf("Please enter castle coordinate : ");
                    scanf("%d %d",&X,&Y);
            }
            else{//koordinat yang dituju castle
                if ((*M).Tiles[Y][X].building.OwnerID != (*P).PlayerID){//bukan castle milik player tersebut
                    printf("This is not your castle!\nPlease enter your castle coordinate: ");

                    scanf("%d %d",&X,&Y);
                }
                else {//castle milik player tersebut
                    if ((*M).Tiles[X][Y].unit.ID!=' ') {//castle terisi
                        printf("Castle is occupied\n");
                        printf("Please enter another castle coordinate : ");
                        scanf("%d %d",&X,&Y);
                    }
                    else{//tidak terdapat unit di lokasi castle
                        kosong = true;
                    }
                }
            }

        }
        printf("=== List of Recruits ===\n");
        printf("1. Archer | Health 20 | ATK 4 | Upkeep 3G | Harga 5G\n");
        printf("2. Swordsman | Health 20 | ATK 3 | Upkeep 2G | Harga 4G\n");
        printf("3. White Mage | Health 15 | ATK 2 | Upkeep 5G | Harga 10G\n");
        printf("Enter no. of unit you want to recruit:");
        scanf("%d",&pilunit);
        loop = true;

        while(loop){
            if(pilunit==1){
                loop = false;
                if((*P).Gold >= Archer.Harga){
                    (*P).Gold = (*P).Gold - Archer.Harga;
                    Archer.Location.X = X;
                    Archer.Location.Y = Y;
                    InsVLastUnit(&(*P).Unit, Archer);
                    AddUnitToMap(&*M,Archer);

                }
                else {//P.Gold< harga
                    printf("You don't have enough gold \n");
                }
            }
            else if (pilunit==2){
                loop = false;
                if((*P).Gold >= Swordsman.Harga){
                    (*P).Gold = (*P).Gold - Swordsman.Harga;
                    Swordsman.Location.X = X;
                    Swordsman.Location.Y = Y;
                    InsVLastUnit(&(*P).Unit, Swordsman);
                    AddUnitToMap(&*M,Swordsman);
                }
                else {//P.Gold< harga
                    printf("You don't have enough gold \n");
                }
            }
            else if (pilunit == 3){
                loop = false;
                if((*P).Gold >= WMage.Harga){
                    (*P).Gold = (*P).Gold - WMage.Harga;
                    WMage.Location.X = X;
                    WMage.Location.Y = Y;
                    InsVLastUnit(&(*P).Unit, WMage);
                    AddUnitToMap(&*M, WMage);
                }
                else {//P.Gold< harga
                    printf("You don't have enough gold \n");
                }
            }
            else{//pilihan diluar 1/2/3
                printf("Please enter the correct number\n");
            }
        }
    }
}

void InitializeKing(Map * M, Player *P1, Player *P2)
{
    //Kamus lokal
    TypeUnit King;

    //Pendefinisian status King
    King.ID = 'K';
    King.Name = "King";
    King.MaxHealth = 35;
    King.Health = 35;
    King.MaxMove = 2;
    King.Move = 2;
    King.AttackType ='k';
    King.Hit = true;
    King.Upkeep = 0;
    King.Harga = 0;

    King.Location.X = 1;
    King.Location.Y = (*M).NBrsEff - 2;
    InsVFirstUnit(&(*P1).Unit, King);
    AddUnitToMap(M, King);

    King.Location.X = (*M).NKolEff - 2;
    King.Location.Y = 1;
    InsVFirstUnit(&(*P2).Unit, King);
    AddUnitToMap(M, King);
}


