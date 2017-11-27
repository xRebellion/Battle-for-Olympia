/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#ifndef _QUEUE_H
#define _QUEUE_H
#include "boolean.h"
#include <stdlib.h>
#include "list_unit.h"
#include "list_building.h"

/* Konstanta */
#define Nil NULL

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

/* Deklarasi infotype */
typedef Player infotypeQ;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * addressQ;
typedef struct tElmtQueue {
	Player InfoQ;
	addressQ NextQ;
} ElmtQueue;

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct {
	addressQ HEAD;  /* alamat penghapusan */
	addressQ TAIL;  /* alamat penambahan */
} Queue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->InfoQ
#define InfoTail(Q) (Q).TAIL->InfoQ
#define NextQ(P) (P)->NextQ
#define InfoQ(P) (P)->InfoQ

/* Prototype manajemen memori */
void AlokasiQ (addressQ *P, infotypeQ X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoQ(P)=X dan
        NextQ(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQ (addressQ  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQ (Queue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmtQ(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmptyQ(Queue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void AddQ (Queue * Q, infotypeQ X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void DelQ(Queue * Q, infotypeQ * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif
