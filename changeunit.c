#include <stdio.h>

#include "changeunit.h"

void change_unit(Player Player1, TypeUnit *selectedunit) {
//I.S.: Player terdefinisi
//F.S.: mengembalikan P sebagai unit yang ingin diproses
    addressU P = First(Player1.Unit);
    addressU A[50];
    int x; //sebagai input user
    int count = 0;
    int i;
    printf("== List of Units ==\n");
    while (P != Nil) {
        if ((Info(P).Move != 0) || (Info(P).Hit)) {
            count++;
            A[count] = P;
            printf("%d. %s (%d,%d) | Health %d\n", count, Info(P).Name, Info(P).Location.X, Info(P).Location.Y, Info(P).Health);
        }
        P = Next(P);
    }
    if (count == 0) {
        printf("Oops. All of your units already moved/attacked.\n");
    } else {
        P = First(Player1.Unit);
        printf("Please enter the no. of unit you want to select: ");
        scanf("%d", &x);
        *selectedunit = Info(A[x]);
        printf("You are now selecting %s\n", Info(A[x]).Name);
    }
}

void next_unit(Player Player1, TypeUnit *selectedunit){
    addressU P = First(Player1.Unit);
    int x; //sebagai input user
    int count = 0;
    int i = 1;
    //hitung jumlah unit yg dimiliki
    while (P != Nil) {
        count++;
        P = Next(P);
    }
    P = First(Player1.Unit);
    while (((Info(P).Move == 0) || (!Info(P).Hit)) && (i <= count)) {
        i++;
        P = Next(P);
    }
    if (P != Nil) {
        printf("You are now selecting %s", Info(P).Name);
        *selectedunit = Info(P);
    } else {
        printf("Oops. All of your units already moved/attacked.\n");
    }
}

