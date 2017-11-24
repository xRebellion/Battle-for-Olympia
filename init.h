#ifndef tipebentukan_H
#define tipebentukan_H

#include "ADT/boolean.h"

#include "ADT/point.h"
#include "ADT/listdp.h"
#include <stdio.h>
#include <stdlib.h>


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
    List Unit;
    List Villages;
    int Income;
    int Upkeep;
    //Warna
    //aing gatau warna pake tipe apa lul
} Player;

//untuk tipe infotype dan address disesuaikan nanti queue mau dipake di bagian mana
typedef int infotype;
typedef int idx;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype * T;   /* tabel penyimpan elemen */
                 idx HEAD;  /* alamat penghapusan */
                 idx TAIL;  /* alamat penambahan */
                 int MaxEl;     /* Max elemen queue */
               } Queue;
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl


//untuk mesin kata
typedef struct {
	char TabKata[30+1]; /* container penyimpan kata, indeks yang dipakai [1..30] */
    int Length;
} Kata;

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
} TypeUnit;

#define PosX(U) (U).Location.X
#define PosY(U) (U).Location.Y


typedef struct {
    //kepemilikan, gold, tipe
    char ID;
    Player Owner;
    int Gold;
    char Type;
} Building;
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





#endif
