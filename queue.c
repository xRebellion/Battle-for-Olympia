#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void AlokasiQ (addressQ *P, infotypeQ X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoQ(P)=X dan
        NextQ(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (addressQ) malloc (sizeof(ElmtQueue));
    if (*P!=Nil) {
        InfoQ(*P) = X;
        NextQ(*P) = Nil;
    }
}

void DealokasiQ (addressQ  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmtQ(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int i;
    i = 0;
    addressQ P;
    if (!IsEmptyQ(Q)) {
        P = Head(Q);
        while (P != Tail(Q)) {
            i++;
            P = NextQ(P);
        }
        i++;
    }
    return i;
}

void CreateEmptyQ(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

void AddQ (Queue * Q, infotypeQ X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    addressQ P;
    AlokasiQ(&P,X);
    if (P != Nil) {
        if (IsEmptyQ(*Q)) {
            Head(*Q) = P;
        } else {
            NextQ(Tail(*Q)) = P;
        }
        Tail(*Q) = P;
    }
}

void DelQ(Queue * Q, infotypeQ * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    addressQ P = Head(*Q);
    *X = InfoQ(P);
    if (Head(*Q) != Tail(*Q)) {
        Head(*Q) = NextQ(P);
    } else {
        CreateEmptyQ(&*Q);
    }
    DealokasiQ(P);
}
