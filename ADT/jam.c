//BODY FILE / REALISASI FUNGSI UNTUK JAM.H
#include "jam.h"
#include <stdio.h>

boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM J;
    Hour(J) = HH;
    Minute(J) = MM;
    Second(J) = SS;

    return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
    int jam, menit, detik;

    do { //VALIDASI

        scanf("%d %d %d", &jam, &menit, &detik);

        //PESAN ERROR
        if (!IsJAMValid(jam, menit, detik)){
            printf("Jam tidak valid\n");
        }

    } while (!IsJAMValid(jam, menit, detik));

    *J = MakeJAM(jam, menit, detik); //BUAT JAM
}


void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
    printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J)); //(00:00:00) untuk input 0 0 0
}


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return(3600*Hour(J) + 60*Minute(J) + Second(J));

}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    int N1;
    JAM J;
    N1 = N % 86400;

    Hour(J) = N1/3600;
    Minute(J) = (N1%3600)/60;
    Second(J) = (N1%3600)%60;

    return J;
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return((Hour(J1) == Hour(J2)) && ((Minute(J1) == Minute(J2)) && ((Second(J1)) == Second(J2))));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return(!((Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2))));
}

boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    return (JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
    return (JAMToDetik(J1) > JAMToDetik(J2));
}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    //KAMUS LOKAL a.k.a. buffer
    JAM time;
    Hour(time) = Hour(J);
    Minute(time) = Minute(J);
    Second(time) = Second(J);

    //PENAMBAHAN DETIK, MENIT, DAN JAM (Misal: 23:59:60 jadi 00:00:00)
    Second(time) += 1;
    if (Second(time) >= 60) {
        Second(time) = Second(time) % 60;
        Minute(time) += 1;
    }

    if (Minute(time) >= 60){
        Minute(time) = Minute(time) % 60;
        Hour(time) += 1;
    }

    if (Hour(time) >= 24){
        Hour(time) = Hour(time) % 24;
    }

    return time;

}

JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    //KAMUS LOKAL a.k.a. buffer
    JAM time;
    Hour(time) = Hour(J);
    Minute(time) = Minute(J);
    Second(time) = Second(J);

    //PENAMBAHAN DETIK, MENIT, DAN JAM (Misal: 23:59:60 jadi 00:00:00)
    Second(time) += N;
    if (Second(time) >= 60) {
        Minute(time) += Second(time)/60;
        Second(time) = Second(time) % 60;
    }

    if (Minute(time) >= 60){
        Hour(time) += Minute(time)/60;
        Minute(time) = Minute(time) % 60;
    }

    if (Hour(time) >= 24){
        Hour(time) = Hour(time) % 24;
    }

    return time;
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    //KAMUS LOKAL a.k.a. buffer
    JAM time;
    Hour(time) = Hour(J);
    Minute(time) = Minute(J);
    Second(time) = Second(J);

    //PENGURANGAN DETIK, MENIT, DAN JAM (Misal: 00:00:-01 jadi 23:59:59)
    Second(time) -= 1;
    if (Second(time) < 0) {
        Second(time) = 60 + Second(time);
        Minute(time) -= 1;
    }

    if (Minute(time) < 0){
        Minute(time) = 60 + Minute(time);
        Hour(time) -= 1;
    }

    if (Hour(time) < 0){
        Hour(time) = 24 + Hour(time);
    }

    return time;
}

JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{

//Karena belum paham (lebih tepatnya ga sempet) mempelajari cara kerja mengoperasikan jam di negatif, maka menggunakan looping.
    int i;
    JAM currentJ;
    Hour(currentJ) = Hour(J);
    Minute(currentJ) = Minute(J);
    Second(currentJ) = Second(J);
    for(i = 1; i <= N; i++)
    {
        currentJ = PrevDetik(currentJ);
    }

    return currentJ;

}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    //KAMUS LOKAL
    long jamDetikAwal, jamDetikAkhir;
    long selisih;
    //definisi
    jamDetikAwal = JAMToDetik(JAw);
    jamDetikAkhir = JAMToDetik(JAkh);

    //ALGORITMA
    if (jamDetikAwal > jamDetikAkhir)
    {
        selisih = 86400 - (jamDetikAwal - jamDetikAkhir);
    } else
    {
        selisih = jamDetikAkhir - jamDetikAwal;
    }

    return selisih;
}


