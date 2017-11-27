/* File : stack.h */
#ifndef _STACK_H
#define _STACK_H

#include "boolean.h"
#include <stdlib.h>
#include "queue.h"
#include "..\init.h"

/* Konstanta */
#define Nil NULL
#define BrsMin 0
#define BrsMax 20
#define KolMin 0
#define KolMax 20
/* Deklarasi infotypeS */
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

typedef struct {
    TypeUnit unit;
    Map M;
    Player P;
} infotypeS;
/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * addressS;
typedef struct tElmtStack {
	infotypeS InfoS;
	addressS NextS;
} ElmtStack;

/* Type stack dengan ciri TOP : */
typedef struct {
	addressS TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->InfoS
#define NextS(P) (P)->NextS
#define InfoS(P) (P)->InfoS

/* Prototype manajemen memori */
void AlokasiS (addressS *P, infotypeS X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoS(P)=X dan
        NextS(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiS (addressS P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyS (Stack S);
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmptyS (Stack * S);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotypeS X);
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infotypeS * X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

#endif
