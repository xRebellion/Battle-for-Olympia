#include <stdio.h>

typedef struct
{
    int a;
    char b;
    float c;
} SomeType;

SomeType get_SumTaip(int x){
    return((*(SomeType*)x));
}

int main()
{
    SomeType A;
    A.a = 10;
    A.b = 'a';
    A.c = 10.0;
    int X;
    X = &A;
    printf("%c\n", get_SumTaip(X).b);
}
