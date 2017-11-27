#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

void AlokasiS (addressS *P, infotypeS X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka InfoS(P)=X dan
        NextS(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    *P = (addressS) malloc (sizeof(ElmtStack));
    if (*P!=Nil) {
        InfoS(*P) = X;
        NextS(*P) = Nil;
    }
}

void DealokasiS (addressS P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}

boolean IsEmptyS (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
    return (Top(S) == Nil);
}

void CreateEmptyS (Stack * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{
    Top(*S) = Nil;
}

void Push (Stack * S, infotypeS X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
    addressS P;
    AlokasiS(&P,X);
    if (P != Nil) {
        NextS(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotypeS * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
    addressS P = Top(*S);
    *X = InfoS(Top(*S));
    Top(*S) = NextS(Top(*S));
    DealokasiS(P);
}
