#include "rekruit.h"

void Recruit(Player P)
{
    //Kamus lokal
    TypeUnit Swordsman, Archer, WM;
    int pilunit;
    boolean loop;

    //Algoritma
    /*if(semua castle == penuh){
        printf("All your castle is occupied\n");
    }
    else{//castle gapenuh
        scanf("%d %d",koordinat castle(&X,&Y))
        kosong = false;
        while(!kosong){
            if (castle udh ada unit) {
                printf("Castle is occupied\n");
                scanf("%d %d",koordinat castle);
            }
            else{//castle gaad unit
                kosong = true;
            }
        }*/
        printf("=== List of Recruits ===\n");
        printf("1. Archer | Health 20 | ATK 4 | 5G\n ");
        printf("2. Swordsman | Health 20 | ATK 3 | 4G\n ");
        printf("3. White Mage | Health () | ATK () | ()G\n");
        printf("Enter no. of unit you want to recruit:");
        scanf("%d",&pilunit);
        loop = true;

        while(loop){
            if(pilunit==1){
                loop = false;
                if(P.Gold >= Swordsman.Harga){
                    //masukin unit ke list yang mana?
                }
                else {//P.Gold< typeunit.harga
                    printf("You don't have enough gold \n");
                }
            }
            else if (pilunit==2){
                loop = false;
                if(P.Gold >= Archer.Harga){
                //masukin unit ke list yang mana?
                }
                else {//P.Gold< typeunit.harga
                    printf("You don't have enough gold \n");
                }
            }
            else if (pilunit == 3){
                loop = false;
                if(P.Gold >= WM.Harga){
                //masukin unit ke list yang mana?
                }
                else {//P.Gold< typeunit.harga
                    printf("You don't have enough gold \n");
                }
            }
            else{//pilihan diluar 1/2/3
                printf("Please enter the correct number\n");
            }
        }


}
