/* File : listdp.h */
/* ADT ListB dengan Double Pointer */
/* Representasi berkait dengan addressB adalah pointer */
/* infotypeB adalah integer */

#ifndef list_building_H
#define list_building_H

#include "point.h"
#include "boolean.h"
#include "list_unit.h"

#define Nil NULL



typedef struct {
    //kepemilikan, gold, tipe
    char ID;
    int OwnerID;
    int Gold;
    char Type;
    POINT Location;
} Building;

/* Definisi Type Data */
typedef Building infotypeB;
typedef struct tElmtlistB *addressB;
typedef struct tElmtlistB {
	infotypeB info;
	addressB next;
	addressB prev;
} ElmtListB;
typedef struct {
	addressB First;
	addressB Last;
} ListB;

/* Definisi list : */
/* ListB kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressB P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsBuildingEQ(Building B1, Building B2);
boolean IsEmptyBuilding (ListB L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyBuilding (ListB *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressB AlokasiBuilding (infotypeB X);
/* Mengirimkan addressB hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressB tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiBuilding (addressB P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressB P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressB SearchBuilding (ListB L, infotypeB X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressB elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstBuilding (ListB *L, infotypeB X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastBuilding (ListB *L, infotypeB X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstBuilding (ListB *L, infotypeB *X);
/* I.S. ListB L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastBuilding (ListB *L, infotypeB *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstBuilding (ListB *L, addressB P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressB P sebagai elemen pertama */
void InsertLastBuilding (ListB *L, addressB P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterBuilding (ListB *L, addressB P, addressB Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeBuilding (ListB *L, addressB P, addressB Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstBuilding (ListB *L, addressB *P);
/* I.S. ListB tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastBuilding (ListB *L, addressB *P);
/* I.S. ListB tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPBuilding (ListB *L, infotypeB X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressB P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListB mungkin menjadi kosong karena penghapusan */
void DelAfterBuilding (ListB *L, addressB *Pdel, addressB Prec);
/* I.S. ListB tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeBuilding (ListB *L, addressB *Pdel, addressB Succ);
/* I.S. ListB tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */


#endif
