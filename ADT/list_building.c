/* File : listdp.c */
/* ADT ListBdengan Double Pointer */
/* Representasi berkait dengan addressB adalah pointer */
/* infotypeB adalah integer */

#include "list_building.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* ListBkosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressB P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsBuildingEQ(Building B1, Building B2)
{
    return (B1.ID == B2.ID) && (B1.Gold == B2.Gold) && EQPOINT(B1.Location,B2.Location) && (B1.OwnerID == B2.OwnerID) && (B1.Type == B2.Type);
}

boolean IsEmptyBuilding (ListB L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil && Last(L) == Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyBuilding (ListB *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
addressB AlokasiBuilding (infotypeB X)
/* Mengirimkan addressB hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressB tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    addressB P = (addressB) malloc (sizeof(ElmtListB));
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
void DealokasiBuilding (addressB P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressB P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressB SearchBuilding (ListB L, infotypeB X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressB elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressB P = First(L);
    while (Next(P) != Nil && !IsBuildingEQ(Info(P), X))
    {
        P = Next(P);
    }

    if(!IsBuildingEQ(Info(P), X))
    {
        return Nil;
    } else
    {
        return P;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstBuilding (ListB *L, infotypeB X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressB P = First(*L);
    First(*L) = AlokasiBuilding(X);
    if(P != Nil)
    {
        Prev(P) = First(*L);
        Next(First(*L)) = P;
    } else
    {
        Last(*L) = First(*L);
    }
}
void InsVLastBuilding (ListB *L, infotypeB X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressB P = First(*L);
    if(IsEmptyBuilding(*L))
    {
        First(*L) = AlokasiBuilding(X);
        Last(*L) = First(*L);
    }
    else
    {
        P = Last(*L);
        Next(P) = AlokasiBuilding(X);
        Prev(Next(P)) = P;
        Last(*L) = Next(P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstBuilding (ListB *L, infotypeB *X)
/* I.S. ListBL tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    *X = Info(First(*L));
    addressB Pdel;
    if(Next(First(*L)) == Nil)
    {
        DealokasiBuilding(First(*L));
        CreateEmptyBuilding(L);
    } else
    {
        Pdel = First(*L);
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
        DealokasiBuilding(Pdel);
    }
}
void DelVLastBuilding (ListB *L, infotypeB *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressB P = First(*L);
    if(Next(P) == Nil)
    {
        *X = Info(P);
        DealokasiBuilding(First(*L));
        CreateEmptyBuilding(L);
    }
    else
    {
        P = Prev(Last(*L));
        *X = Info(Next(P));
        DealokasiBuilding(Next(P));
        Next(P) = Nil;
        Last(*L) = P;
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstBuilding (ListB *L, addressB P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressB P sebagai elemen pertama */
{
    addressB PTemp;
    if(IsEmptyBuilding(*L))
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
void InsertLastBuilding (ListB *L, addressB P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if(IsEmptyBuilding(*L))
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
void InsertAfterBuilding (ListB *L, addressB P, addressB Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    if(Prec == Last(*L))
    {
        InsertLastBuilding(L,P);
    } else
    {
        addressB PTemp;
        PTemp = Next(Prec);
        Next(Prec) = P;
        Prev(P) = Prec;
        Next(Next(Prec)) = PTemp;
        Prev(PTemp) = P;
    }
}
void InsertBeforeBuilding (ListB *L, addressB P, addressB Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
    if(Succ == First(*L))
    {
        InsertFirstBuilding(L, P);
    } else
    {
        addressB PTemp;
        PTemp = Prev(Succ);
        Prev(Succ) = P;
        Prev(P) = PTemp;
        Next(P) = Succ;
        Next(PTemp) = P;
    }


}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstBuilding (ListB *L, addressB *P)
/* I.S. ListBtidak kosong */
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
        CreateEmptyBuilding(L);
    }
}
void DelLastBuilding (ListB *L, addressB *P)
/* I.S. ListBtidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
    if(Next(First(*L)) == Nil)
    {
        *P = First(*L);
        CreateEmptyBuilding(L);
    }
    else
    {
        *P = Last(*L);
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
}
void DelPBuilding (ListB *L, infotypeB X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressB P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListBmungkin menjadi kosong karena penghapusan */
{
    addressB P = First(*L);
    addressB Pdel;
    if(SearchBuilding(*L, X) != Nil)
    {

        if (IsBuildingEQ(Info(First(*L)), X))
        {
            DelFirstBuilding(L,&Pdel);
            DealokasiBuilding(Pdel);
        }
        else
        if(IsBuildingEQ(Info(Last(*L)), X))
        {
            DelLastBuilding(L,&Pdel);
            DealokasiBuilding(Pdel);
        }
        else
        if(!IsBuildingEQ(Info(P), X))
        {
            while(!IsBuildingEQ(Info(Next(P)), X)&& Next(P) != Nil)
            {
                P = Next(P);
            }
            Pdel = Next(P);
            Next(P) = Next(Next(P));
            Prev(Next(P)) = P;
            DealokasiBuilding(Pdel);
        }

    }
}
void DelAfterBuilding (ListB *L, addressB *Pdel, addressB Prec)
/* I.S. ListBtidak kosong. Prec adalah anggota list. */
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
void DelBeforeBuilding (ListB *L, addressB *Pdel, addressB Succ)
/* I.S. ListBtidak kosong. Succ adalah anggota list. */
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


