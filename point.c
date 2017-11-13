//BODY/REALISASI POINT_H

//Nama File: point.c

//Nama: Daniel Y
//NIM: 13516145

#include "point.h"
#include <stdio.h>
#include <math.h>


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;

    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
    scanf("%f %f", &Absis(*P), &Ordinat(*P));
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

{
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
    return (!((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
    return (Ordinat(P) == 0); //ketika y = 0, titik terletak pada sumbu x
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
    return (Absis(P) == 0); //ketika x = 0, titik terletak pada sumbu y
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
    int kuad;
    if ((Absis(P) > 0) && (Ordinat(P) > 0))
    {
        kuad = 1;
    } else if ((Absis(P) < 0) && (Ordinat(P) > 0))
    {
        kuad = 2;
    } else if ((Absis(P) < 0) && (Ordinat(P) < 0))
    {
        kuad = 3;
    } else if ((Absis(P) > 0) && (Ordinat(P) < 0))
    {
        kuad = 4;
    }

    return kuad;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
    return MakePOINT((Absis(P)+1), Ordinat(P));
}

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
    return MakePOINT(Absis(P), (Ordinat(P)+1));
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
    return MakePOINT((Absis(P) + deltaX), (Ordinat(P) + deltaY));
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
    if(SbX)
    {
        return MakePOINT(Absis(P), (-1 * Ordinat(P)));
    } else
    {
        return MakePOINT((-1 * Absis(P)), Ordinat(P));
    }
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return (sqrt((Absis(P))*(Absis(P)) + (Ordinat(P))*(Ordinat(P))));
}
float Panjang (POINT P1, POINT P2)
/* Menghitung jarak antar dua titik - a.k.a. panjang garis */
{
    //KAMUS LOKAL - u/ menghitung selisih, kemudian dikuadratkan, lalu di akar.
    float selisihX, selisihY;
    selisihX = Absis(P1) - Absis(P2);
    selisihY = Ordinat(P1) - Ordinat(P2);

    return(sqrt((selisihX * selisihX) + (selisihY * selisihY)));

}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    *P = PlusDelta(*P, deltaX, deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    *P = MakePOINT(Absis(*P), 0);
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    *P = MakePOINT(0, Ordinat(*P));
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    *P = MirrorOf(*P, SbX);
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
    //KAMUS LOKAL
    float XBaru, YBaru;
    const float PI = 3.14159265358979323846;
    //MENGGUNAKAN RUMUS TRANSFORMASI ROTASI PADA SUATU TITIK DENGAN PUSAT (0,0)
    XBaru = Absis(*P) * cos(-Sudut*PI/180) - Ordinat(*P) * sin(-Sudut*PI/180);
    YBaru = Absis(*P) * sin(-Sudut*PI/180) + Ordinat(*P) * cos(-Sudut*PI/180);
     //OUTPUT
    *P = MakePOINT(XBaru,YBaru);
}
