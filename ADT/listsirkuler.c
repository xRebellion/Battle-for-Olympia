/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "listsirkuler.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else
    {
        return Nil;
    }

}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    while (Next(P) != First(L) && Info(P) != X)
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
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = First(*L);
    First(*L) = Alokasi(X);
    if(P != Nil)
    {
        Next(First(*L)) = P;

        //Mengubah next(last) = first(L);
        address iP = P;
        while(Next(iP) != P) //P adalah alamat First sebelum ditambahkan elemen first.
        {
            iP = Next(iP);
        }
        Next(iP) = First(*L);

    } else
    {
        Next(First(*L)) = First(*L);
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = First(*L);
    if(IsEmpty(*L))
    {
        First(*L) = Alokasi(X);
        Next(First(*L)) = First(*L);
    }
    else
    {
        while(Next(P) != First(*L))
        {
            P = Next(P);
        }
        Next(P) = Alokasi(X);
        Next(Next(P)) = First(*L);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    *X = Info(First(*L));
    address Pdel;
    if(Next(First(*L)) == First(*L))
    {
        Dealokasi(First(*L));
        First(*L) = Nil;
    } else
    {
        Pdel = First(*L);
        First(*L) = Next(First(*L));

         //Mengubah next(last) = first(L); baru
        address iP = Pdel;
        while(Next(iP) != Pdel) //P adalah alamat First sebelum ditambahkan elemen first.
        {
            iP = Next(iP);
        }
        Next(iP) = First(*L);

        //Dealokasi
        Dealokasi(Pdel);
    }
}

void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    if(Next(P) == First(*L))
    {
        *X = Info(P);
        Dealokasi(First(*L));
        First(*L) = Nil;
    }
    else
    {
        while(Next(Next(P)) != First(*L))
        {
            P = Next(P);
        }
        *X = Info(Next(P));
        Dealokasi(Next(P));
        Next(P) = First(*L);
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    address PTemp;
    if(IsEmpty(*L))
    {
        First(*L) = P;
        Next(First(*L)) = First(*L);
    } else
    {
        PTemp = First(*L);
        First(*L) = P;
        Next(First(*L)) = PTemp;

         //Mengubah next(last) = first(L); baru
        address iP = PTemp;
        while(Next(iP) != PTemp) //P adalah alamat First sebelum ditambahkan elemen first.
        {
            iP = Next(iP);
        }
        Next(iP) = First(*L);
    }
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address iP = First(*L);
    if(IsEmpty(*L))
    {
        First(*L) = P;
        Next(First(*L)) = First(*L);
    }
    else
    {
        while(Next(iP) != First(*L))
        {
            iP = Next(iP);
        }
        Next(iP) = P;
        Next(Next(iP)) = First(*L);
    }
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    address PTemp;
    PTemp = Next(Prec);
    Next(Prec) = P;
    Next(Next(Prec)) = PTemp;
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if(Next(*P) != First(*L))
    {
        First(*L) = Next(*P);

         //Mengubah next(last) = first(L); baru
        address iP = *P;
        while(Next(iP) != *P) //P adalah alamat First sebelum ditambahkan elemen first.
        {
            iP = Next(iP);
        }
        Next(iP) = First(*L);

    } else
    {
        CreateEmpty(L);
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address PTemp = First(*L);
    if(Next(PTemp) == First(*L))
    {
        CreateEmpty(L);
        *P = PTemp;
    }
    else
    {
        while(Next(Next(PTemp)) != First(*L))
        {
            PTemp = Next(PTemp);
        }
        *P = Next(PTemp); // P yang mau dihapus
        Next(PTemp) = First(*L);
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if(Next(Prec) != First(*L))
    {
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
    } else
    {
        *Pdel = First(*L);
    }
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = First(*L);
    address Pdel;
    if(Search(*L, X) != Nil)
    {
        if(Info(P) != X)
        {
            while(Info(Next(P)) != X && Next(P) != First(*L))
            {
                P = Next(P);
            }
            Pdel = Next(P);
            Next(P) = Next(Next(P));
            Dealokasi(Pdel);
        }
        else
        {
            DelFirst(L,&Pdel);
        }

    }

}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P = First(L);
    printf("[");
        if(!IsEmpty(L))
        {
            printf("%d", Info(P));
            while(Next(P) != First(L))
            {
                printf(",");
                P = Next(P);
                printf("%d", Info(P));
            }
        }

    printf("]");
}

