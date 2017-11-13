/*
Nama    :   Daniel Y.
NIM     :   13516145
*/

#include "array.h"
#include <stdio.h>

//Definisi null
#define null 0

void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    //Iterator
    int i;

    //Proses pengosongan. Default = 0
    for(i = IdxMin; i <= IdxMax; i++)
    {
        Elmt(*T,i) = null;
    }

    Neff(*T) = 0;

}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return Neff(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IdxMin && i <= MaxNbEl(T));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (Neff(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    //Kamus lokal
    int i, N;

    //Jumlah input yang ingin dimasukkan
    do
    {
        scanf("%d", &N);

    } while((N < 0) || (N > MaxNbEl(*T)));

    Neff(*T) = N; //Inisialisasi Neff
    //iterasi input
    i = IdxMin;
    while (i <= N)
    {
        scanf("%d", &Elmt(*T,i));
        i++;
    }
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    //Kamus lokal
    ElType input;
    //Inisialisasi Neff
    Neff(*T) = 0;

    //Proses pembacaan
    do
    {
        scanf("%d", &input);
        if (input != -9999)
        {
            Neff(*T)++;
            Elmt(*T,Neff(*T)) = input; //tambah neff, lalu masukan ke index setelah ditambah.
        }
    } while(input != -9999 && Neff(*T)<= MaxNbEl(*T));
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    //Kamus lokal
    int i;

    //Validasi tabel
    if (NbElmt(T) == 0)
    {
        printf("Tabel kosong\n");
    } else
    {
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("[%d]%d\n", i, Elmt(T, i));
        }
    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    //Kamus lokal
    int i;

    //Validasi tabel
    printf("[");
        for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
        {
            printf("%d", Elmt(T, i));
            if (i != GetLastIdx(T))
            {
                printf(","); //selama masih belum last index, tulis koma setelahnya
            }
        }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    //Kamus lokal
    TabInt TSum;
    int i;

    //Pengosongan TSum
    MakeEmpty(&TSum);

    //Proses penambahan.
    //Soal mengatakan ukuran sama dan penambahan elemen T1 T2 pada index yang sama.
    //Saya menggunakan T1 sebagai acuan
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        Elmt(TSum,i) = Elmt(T1,i) + Elmt(T2,i);
    }
    Neff(TSum) = Neff(T1);

    return TSum;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
     //Kamus lokal
    TabInt TSum;
    int i;

    //Pengosongan TSum
    MakeEmpty(&TSum);

    //Proses penambahan.
    //Soal mengatakan ukuran sama dan penambahan elemen T1 T2 pada index yang sama.
    //Saya menggunakan T1 sebagai acuan
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        Elmt(TSum,i) = Elmt(T1,i) - Elmt(T2,i);
    }
    Neff(TSum) = Neff(T1);

    return TSum;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
     //Kamus lokal
    TabInt TSum;
    int i;

    //Pengosongan TSum
    MakeEmpty(&TSum);

    //Proses penambahan.
    //Soal mengatakan ukuran sama dan penambahan elemen T1 T2 pada index yang sama.
    //Saya menggunakan T1 sebagai acuan
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        Elmt(TSum,i) = Elmt(T1,i) * Elmt(T2,i);
    }
    Neff(TSum) = Neff(T1);
    return TSum;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    //KAMUS LOKAL
    TabInt TResult;
    int i;

    //Proses perkalian dengan c
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
    {
        Elmt(TResult,i) = Elmt(Tin,i) * c;
    }
    Neff(TResult) = Neff(Tin);
    return TResult;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    //KAMUS LOKAL
    boolean eq = true;
    int i = GetFirstIdx(T1); // index pertama tabel 1
    int j = GetFirstIdx(T2) - i; //index pertama tabel 2 relatif thdp tabel 1

    //Proses pengecekan elemen
    while ((i <= GetLastIdx(T1) || i+j <= GetLastIdx(T2)) && eq ) //i+j = index tabel 2.
    {
        if (Elmt(T1, i) != Elmt(T2, i+j))
        {
            eq = false;
        }

        i++;
    }

    return eq;
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    //KAMUS LOKAL
    int i = GetFirstIdx(T1);
    boolean less = true;
    //proses
    while (Elmt(T1, i) == Elmt(T2, i) && (i <= GetLastIdx(T1) && i <= GetLastIdx(T2)))//kalo sama dan masih lebih kecil, tetep ngeloop.
    {
        i++;
    }

    if(Elmt(T1,i) > Elmt(T2,i))
    {
        less = false;
    }

    //cek ukuran
    if (NbElmt(T1) > NbElmt(T2))
    {
        less = false;
    }

    return less;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    //KAMUS LOKAL
    int i = GetFirstIdx(T);

    //Proses pencarian
    while (Elmt(T, i) != X && i <= GetLastIdx(T))
    {
        i++;
    }

    if (Elmt(T, i) == X)
    {
        return i;
    } else
    {
       return IdxUndef;
    }
}

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    //KAMUS + INISIALISASI
    int i = GetFirstIdx(T);
    boolean found = false;

    //PROSES SEARCHING
    while (!found && i <= GetLastIdx(T))
    {
        if (Elmt(T, i) == X)
        {
            found = true;
        } else
        {
            i++;
        }
    }

    if (!found)
    {
        i = IdxUndef;
    }

    return i;
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{

    //KAMUS + INISIALISASI
    int i = GetFirstIdx(T);
    boolean found = false;

    //PROSES SEARCHING
    while (!found && i <= GetLastIdx(T))
    {
        if (Elmt(T, i) == X)
        {
            found = true;
        } else
        {
            i++;
        }
    }

    return found;

}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
    //KAMUS LOKAL
    int i = GetLastIdx(T);

    //Peletakan sentinel
    Elmt(T, 0) = X;

    //Pencarian
    while (Elmt (T,i) != X)
    {
        i--;
    }
    if (i == 0)
    {
        return false;
    } else
    {
        return true;
    }
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    //KAMUSLOKAL
    int i = GetFirstIdx(T);
    ElType maximum = Elmt(T, i); //inisialisasi first elmt

    //PROSES CARI MAX
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        if (maximum < Elmt(T, i))
        {
            maximum = Elmt(T, i);
        }
    }

    //OUTPUT
    return maximum;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    //KAMUSLOKAL
    int i = GetFirstIdx(T);
    ElType minimum = Elmt(T, i); //inisialisasi first elmt

    //PROSES CARI MIN
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
        if (minimum > Elmt(T, i))
        {
            minimum = Elmt(T, i);
        }
    }

    //OUTPUT
    return minimum;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    return Search1(T, ValMax(T));
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    return Search1(T, ValMin(T));
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    int i = GetFirstIdx(Tin);
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
    {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }

    Neff(*Tout) = Neff(Tin);
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    // KAMUS LOKAL
    TabInt tempTab;
    int i = GetFirstIdx(T);
    int j = GetLastIdx(T);
    Neff(tempTab) = Neff(T);

    //Proses pembalikkan / inverse
    while (i <= GetLastIdx(T))
    {
        Elmt(tempTab, i) = Elmt(T, j);

        i++;
        j--;
    }

    return tempTab;
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    // KAMUS LOKAL
    int i = GetFirstIdx(T);
    int j = GetLastIdx(T);
    boolean simetris = true;

    //Proses pembalikkan / inverse
    while (i < j && simetris)
    {
        if(Elmt(T, i) != Elmt(T, j))
        {
            simetris = false;
        }

        i++;
        j--;
    }

    return simetris;
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    //Kamus lokal
    int pass;
    int i;
    int imax;
    int temp;

    //PROSES

    //cari max
    for (pass = GetFirstIdx(*T); pass <= GetLastIdx(*T); pass++)
    {
        //inisialisasi max
        imax = pass;
        for (i = pass; i <= GetLastIdx(*T); i++)
        {
            if (Elmt(*T,imax) < Elmt(*T, i))
            {
                imax = i;
            }
        }
        //proses menukar.
        temp = Elmt(*T, pass);
        Elmt(*T,pass) = Elmt(*T, imax);
        Elmt(*T, imax) = temp;
    }

}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    //KAMUS LOKAL
    int pass;
    int i;
    int temp;

    //PROSES
    for(pass = GetFirstIdx(*T)+1; pass <= GetLastIdx(*T); pass++)
    {
        //penyimpanan nilai yang mau diinsert
        temp = Elmt(*T, pass);
        //proses penyisipan
        i = pass - 1;

        //penggeseran
        while (temp < Elmt(*T,i) && i > GetFirstIdx(*T))
        {
            Elmt(*T, i+1) = Elmt(*T, i);
            i--;
        }

        if (temp >= Elmt(*T, i))
        {
            //sisip langsung sebagai elemen i+1
            Elmt(*T, i+1) = temp;
        } else
        {
            //sisip elemen pertama
            Elmt(*T, i+1) = Elmt(*T, i);
            Elmt(*T, i) = temp;
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Neff(*T) += 1;
    Elmt(*T, GetLastIdx(*T)) = X;
}

void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    //KAMUS LOKAL
    int j;

    //Penambahan Neff
    Neff(*T) += 1;
    //PROSES PENGGESERAN
    for(j = GetLastIdx(*T); j > i; j--)
    {
        Elmt(*T, j) = Elmt(*T,j-1);
    }

    Elmt(*T, i) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) -= 1;
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    //KAMUS LOKAL
    int j;

    *X = Elmt(*T, i);
    Neff(*T) -= 1;
    for (j = i; j <= GetLastIdx(*T);j++)
    {
        Elmt(*T, j) = Elmt(*T, j+1);
    }
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    if(SearchB(*T, X))
    {
        printf("nilai sudah ada\n");
    } else
    {
        AddAsLastEl(T, X);
    }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    return Search1(T, X);
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return Elmt(T,GetLastIdx(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return Elmt(T,GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Min = MinUrut(T);
    *Max = MaxUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    //KAMUS LOKAL
    int j;

    //Penambahan Neff
    Neff(*T) += 1;
    //PROSES PENGGESERAN
    j = GetLastIdx(*T);

    while(j > 1 && X <= Elmt(*T,j))
    {
        Elmt(*T, j) = Elmt(*T,j-1);
        j--;
    }
    if (X > Elmt(*T, j))
    {
        Elmt(*T,j+1) = X;
    } else
    {
        Elmt(*T,j) = X;
    }
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    int i = Search1(*T, X);
    int notUsed;
    if(i != IdxUndef)
    {
    DelEli(T, i, &notUsed);
    }
}
