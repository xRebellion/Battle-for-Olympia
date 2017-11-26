/* File : listdp.h */
/* ADT ListU dengan Double Pointer */
/* Representasi berkait dengan addressU adalah pointer */
/* infotypeU adalah integer */

#ifndef list_unit_H
#define list_unit_H

#include "boolean.h"

#define Nil NULL

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
/* Definisi Type Data */
typedef TypeUnit infotypeU;
typedef struct tElmtlistU *addressU;
typedef struct tElmtlistU {
	infotypeU info;
	addressU next;
	addressU prev;
} ElmtListU;
typedef struct {
	addressU First;
	addressU Last;
} ListU;

/* Definisi list : */
/* ListU kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressU P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyUnit (ListU L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyUnit (ListU *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressU AlokasiUnit (infotypeU X);
/* Mengirimkan addressU hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressU tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiUnit (addressU P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressU P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressU SearchUnit (ListU L, infotypeU X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressU elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstUnit (ListU *L, infotypeU X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastUnit (ListU *L, infotypeU X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstUnit (ListU *L, infotypeU *X);
/* I.S. ListU L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastUnit (ListU *L, infotypeU *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstUnit (ListU *L, addressU P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressU P sebagai elemen pertama */
void InsertLastUnit (ListU *L, addressU P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterUnit (ListU *L, addressU P, addressU Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeUnit (ListU *L, addressU P, addressU Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstUnit (ListU *L, addressU *P);
/* I.S. ListU tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastUnit (ListU *L, addressU *P);
/* I.S. ListU tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPUnit (ListU *L, infotypeU X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressU P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListU mungkin menjadi kosong karena penghapusan */
void DelAfterUnit (ListU *L, addressU *Pdel, addressU Prec);
/* I.S. ListU tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeUnit (ListU *L, addressU *Pdel, addressU Succ);
/* I.S. ListU tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */


#endif
