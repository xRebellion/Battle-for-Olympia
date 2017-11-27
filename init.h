#ifndef init_H
#define init_H

#include "ADT/boolean.h"

#include "ADT/point.h"
#include "ADT/list_unit.h"
#include "ADT/list_building.h"
#include <stdio.h>
#include <stdlib.h>
#include "ADT/stackt_undo.h"
#include "ADT/queue.h"


/*
typedef struct {
	float X; // absis
	float Y; // ordinat
} Point; //Ini udah ada di adt point.
*/


typedef struct {
    //income, upkeep, gold, warna, dst
    int PlayerID;
    int Gold;
    ListU Unit;
    ListB Villages;
    int Income;
    int Upkeep;
    //Warna
    //aing gatau warna pake tipe apa lul
} Player;




//untuk mesin kata
typedef struct {
	char TabKata[30+1]; /* container penyimpan kata, indeks yang dipakai [1..30] */
    int Length;
} Kata;
/*
typedef struct {
    char ID;
    char * Name;
    int MaxHealth;
    int Health;
    int Attack;
    int MaxMove;
    int Move;
    char AttackType; //'m' untuk melee, 'r' untuk ranged
    boolean Hit; //kesempatan serangan, true bila belum menyerang, false bila sudah menyerang
    POINT Location;
    int Upkeep;
    int Harga;
} TypeUnit;*/ // TYPE MOVED TO LIST_UNIT

#define PosX(U) (U).Location.X
#define PosY(U) (U).Location.Y

/*
typedef struct {
    //kepemilikan, gold, tipe
    char ID;
    int OwnerID;
    int Gold;
    char Type;
    POINT Location;
} Building;*/ //TYPE MOVED TO LIST_BUILDING
// Types:
// C = Castle
// V = Village
// T = Tower

#define BrsMin 0
#define BrsMax 100
#define KolMin 0
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
typedef struct {
    Building building;
    TypeUnit unit;
    char Misc;
}ElType;

typedef struct {
	ElType Tiles[BrsMax][KolMax];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Map;




#define Info(P) (P)->info
#define Next(P) (P)->next

void InitializePlayer(Player P, int PlayerID);



#endif
