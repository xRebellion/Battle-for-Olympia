#include "init.h"
#include <stdio.h>
#include <stdlib.h>

void Recruit(Map M, Player P)
{
    //Kamus lokal
    TypeUnit Swordsman, Archer, WMage;
    int pilunit,X,Y;
    boolean kosong, loop;


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

    //Algoritma recruit

    /*if(semua castle == penuh){
        printf("All your castle is occupied\n");
    }
    else{//castle gapenuh*/
        printf("Please enter castle coordinate : ");
        scanf("%d %d",&X,&Y);

        kosong = false;
        while(!kosong){
            if (M.Tiles[X][Y].building.ID!='C'){//koordinat yang dituju bukan castle
                    printf("This is not a castle, please enter castle coordinate\n");
                    printf("Please enter castle coordinate : ");
                    scanf("%d %d",&X,&Y);
            }
            else{//koordinat yang dituju castle
                if (M.Tiles[X][Y].building.OwnerID != P.PlayerID){//bukan castle milik player tersebut
                    printf("This is not your castle!\nPlease enter your castle coordinate:");

                    scanf("%d %d",&X,&Y);
                }
                else {//castle milik player tersebut
                    if (M.Tiles[X][Y].unit.ID!=' ') {//castle tidak terisi
                        kosong = true;
                    }
                    else{//terdapat unit di lokasi castle
                        printf("Castle is occupied\n");
                        printf("Please enter another castle coordinate : ");
                        scanf("%d %d",&X,&Y);
                    }
                }
            }

        }
        printf("=== List of Recruits ===\n");
        printf("1. Archer | Health 20 | ATK 4 | 5G\n ");
        printf("2. Swordsman | Health 20 | ATK 3 | 4G\n ");
        printf("3. White Mage | Health 15 | ATK 2 | 10G\n");
        printf("Enter no. of unit you want to recruit:");
        scanf("%d",&pilunit);
        loop = true;

        while(loop){
            if(pilunit==1){
                loop = false;
                if(P.Gold >= Archer.Harga){
                    P.Gold = P.Gold - Archer.Harga;
                    Archer.Location.X = X;
                    Archer.Location.Y = Y;
                    InsVLastUnit(&P.Unit, Archer);
                }
                else {//P.Gold< harga
                    printf("You don't have enough gold \n");
                }
            }
            else if (pilunit==2){
                loop = false;
                if(P.Gold >= Swordsman.Harga){
                    P.Gold = P.Gold - Swordsman.Harga;
                    Swordsman.Location.X = X;
                    Swordsman.Location.Y = Y;
                    InsVLastUnit(&P.Unit, Swordsman);
                }
                else {//P.Gold< harga
                    printf("You don't have enough gold \n");
                }
            }
            else if (pilunit == 3){
                loop = false;
                if(P.Gold >= WMage.Harga){
                    P.Gold = P.Gold - WMage.Harga;
                    WMage.Location.X = X;
                    WMage.Location.Y = Y;
                    InsVLastUnit(&P.Unit, WMage);
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

