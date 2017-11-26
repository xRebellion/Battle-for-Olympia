/* File : listdp.c */
/* ADT ListU dengan Double Pointer */
/* Representasi berkait dengan addressU adalah pointer */
/* infotypeU adalah integer */

#include "list_unit.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* ListU kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressU P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsUnitEQ(TypeUnit U1, TypeUnit U2)
{
    return (U1.ID == U2.ID) && (!strcmp(U1.Name,U2.Name)) && (EQPOINT(U1.Location, U2.Location)) && (U1.Attack == U2.Attack) && (U1.AttackType == U2.AttackType) && (U1.Harga == U2.Harga) && (U1.Health == U2.Health) && (U1.Hit == U2.Hit) && (U1.MaxHealth == U2.MaxHealth) && (U1.MaxMove == U2.MaxMove) && (U1.Move == U2.Move) && (U1.Upkeep == U2.Upkeep);
}

boolean IsEmptyUnit (ListU L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil && Last(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUnit (ListU *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
addressU AlokasiUnit (infotypeU X)
/* Mengirimkan addressU hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressU tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    addressU P = (addressU) malloc (sizeof(ElmtListU));
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
void DealokasiUnit (addressU P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressU P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressU SearchUnit (ListU L, infotypeU X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressU elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressU P = First(L);
    while (Next(P) != Nil && !IsUnitEQ(Info(P), X))
    {
        P = Next(P);
    }

    if(!IsUnitEQ(Info(P), X))
    {
        return Nil;
    } else
    {
        return P;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstUnit (ListU *L, infotypeU X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressU P = First(*L);
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
void InsVLastUnit (ListU *L, infotypeU X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressU P = First(*L);
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
void DelVFirstUnit (ListU *L, infotypeU *X)
/* I.S. ListU L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    *X = Info(First(*L));
    addressU Pdel;
    if(Next(First(*L)) == Nil)
    {
        DealokasiUnit(First(*L));
        CreateEmptyUnit(L);
    } else
    {
        Pdel = First(*L);
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
        DealokasiUnit(Pdel);
    }
}
void DelVLastUnit (ListU *L, infotypeU *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressU P = First(*L);
    if(Next(P) == Nil)
    {
        *X = Info(P);
        DealokasiUnit(First(*L));
        CreateEmptyUnit(L);
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
void InsertFirstUnit (ListU *L, addressU P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressU P sebagai elemen pertama */
{
    addressU PTemp;
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
void InsertLastUnit (ListU *L, addressU P)
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
void InsertAfterUnit (ListU *L, addressU P, addressU Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    if(Prec == Last(*L))
    {
        InsertLastUnit(L,P);
    } else
    {
        addressU PTemp;
        PTemp = Next(Prec);
        Next(Prec) = P;
        Prev(P) = Prec;
        Next(Next(Prec)) = PTemp;
        Prev(PTemp) = P;
    }
}
void InsertBeforeUnit (ListU *L, addressU P, addressU Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    if(Succ == First(*L))
    {
        InsertFirstUnit(L, P);
    } else
    {
        addressU PTemp;
        PTemp = Prev(Succ);
        Prev(Succ) = P;
        Prev(P) = PTemp;
        Next(P) = Succ;
        Next(PTemp) = P;
    }


}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstUnit (ListU *L, addressU *P)
/* I.S. ListU tidak kosong */
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
        CreateEmptyUnit(L);
    }
}
void DelLastUnit (ListU *L, addressU *P)
/* I.S. ListU tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    if(Next(First(*L)) == Nil)
    {
        *P = First(*L);
        CreateEmptyUnit(L);
    }
    else
    {
        *P = Last(*L);
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
}
void DelPUnit (ListU *L, infotypeU X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressU P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListU mungkin menjadi kosong karena penghapusan */
{
    addressU P = First(*L);
    addressU Pdel;
    if(SearchUnit(*L, X) != Nil)
    {

        if (IsUnitEQ(Info(First(*L)), X))
        {
            DelFirstUnit(L,&Pdel);
            DealokasiUnit(Pdel);
        }
        else
        if(IsUnitEQ(Info(Last(*L)), X))
        {
            DelLastUnit(L,&Pdel);
            DealokasiUnit(Pdel);
        }
        else
        if(!IsUnitEQ(Info(P), X))
        {
            while(!IsUnitEQ(Info(Next(P)), X) && Next(P) != Nil)
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
void DelAfterUnit (ListU *L, addressU *Pdel, addressU Prec)
/* I.S. ListU tidak kosong. Prec adalah anggota list. */
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
void DelBeforeUnit (ListU *L, addressU *Pdel, addressU Succ)
/* I.S. ListU tidak kosong. Succ adalah anggota list. */
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


