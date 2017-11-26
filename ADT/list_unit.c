/* File : listdp.c */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyUnit (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil && Last(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUnit (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address AlokasiUnit (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
        return P;
    } else
    {
        return Nil;
    }
}
void DealokasiUnit (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchUnit (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    while (Next(P) != Nil && Info(P) != X)
    {
        P = Next(P);
    }

    if(Info(P) != X)
    {
        return Nil;
    } else
    {
        return P;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstUnit (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = First(*L);
    First(*L) = AlokasiUnit(X);
    if(P != Nil)
    {
        Prev(P) = First(*L);
        Next(First(*L)) = P;
    } else
    {
        Last(*L) = First(*L);
    }
}
void InsVLastUnit (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = First(*L);
    if(IsEmptyUnit(*L))
    {
        First(*L) = AlokasiUnit(X);
        Last(*L) = First(*L);
    }
    else
    {
        P = Last(*L);
        Next(P) = AlokasiUnit(X);
        Prev(Next(P)) = P;
        Last(*L) = Next(P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstUnit (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    *X = Info(First(*L));
    address Pdel;
    if(Next(First(*L)) == Nil)
    {
        DealokasiUnit(First(*L));
        CreateEmpty(L);
    } else
    {
        Pdel = First(*L);
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
        DealokasiUnit(Pdel);
    }
}
void DelVLastUnit (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    if(Next(P) == Nil)
    {
        *X = Info(P);
        DealokasiUnit(First(*L));
        CreateEmpty(L);
    }
    else
    {
        P = Prev(Last(*L));
        *X = Info(Next(P));
        DealokasiUnit(Next(P));
        Next(P) = Nil;
        Last(*L) = P;
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstUnit (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    address PTemp;
    if(IsEmptyUnit(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    } else
    {
        PTemp = First(*L);
        First(*L) = P;
        Next(First(*L)) = PTemp;
        Prev(Next(First(*L))) = First(*L);
    }
}
void InsertLastUnit (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmptyUnit(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}
void InsertAfterUnit (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    if(Prec == Last(*L))
    {
        InsertLastUnit(L,P);
    } else
    {
        address PTemp;
        PTemp = Next(Prec);
        Next(Prec) = P;
        Prev(P) = Prec;
        Next(Next(Prec)) = PTemp;
        Prev(PTemp) = P;
    }
}
void InsertBeforeUnit (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    if(Succ == First(*L))
    {
        InsertFirstUnit(L, P);
    } else
    {
        address PTemp;
        PTemp = Prev(Succ);
        Prev(Succ) = P;
        Prev(P) = PTemp;
        Next(P) = Succ;
        Next(PTemp) = P;
    }


}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstUnit (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if(Next(*P) != Nil)
    {
        First(*L) = Next(*P);
        Prev(First(*L)) = Nil;
    } else
    {
        CreateEmpty(L);
    }
}
void DelLastUnit (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    if(Next(First(*L)) == Nil)
    {
        *P = First(*L);
        CreateEmpty(L);
    }
    else
    {
        *P = Last(*L);
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
}
void DelPUnit (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = First(*L);
    address Pdel;
    if(SearchUnit(*L, X) != Nil)
    {

        if (Info(First(*L)) == X)
        {
            DelFirstUnit(L,&Pdel);
            DealokasiUnit(Pdel);
        }
        else
        if(Info(Last(*L)) == X)
        {
            DelLastUnit(L,&Pdel);
            DealokasiUnit(Pdel);
        }
        else
        if(Info(P) != X)
        {
            while(Info(Next(P)) != X && Next(P) != Nil)
            {
                P = Next(P);
            }
            Pdel = Next(P);
            Next(P) = Next(Next(P));
            Prev(Next(P)) = P;
            DealokasiUnit(Pdel);
        }

    }
}
void DelAfterUnit (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if(Next(Prec) != Nil)
    {
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
        if(Next(Prec) != Nil)
        {
            Prev(Next(Prec)) = Prec;
        } else
        {
            Last(*L) = Prec;
        }

    } else
    {
        *Pdel = Nil;
    }
}
void DelBeforeUnit (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if(Prev(Succ) != Nil)
    {
        *Pdel = Prev(Succ);
        Prev(Succ) = Prev(Prev(Succ));
        if(Prev(Succ) != Nil)
        {
            Next(Prev(Succ)) = Succ;
        } else
        {
            First(*L) = Succ;
        }

    } else
    {
        *Pdel = Nil;
    }
}


