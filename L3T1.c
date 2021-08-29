#define _CRT_SECURE_NO_WARNINGS
//@@ -1,29 +0,0 @@
#include <stdio.h>

void testPrimeNumber (int A) { /*функция проверки простоты числа*/
    float C;
    int i=0;       /*флаг*/
    if ((A % 2 == 0) && (A != 2))
        i = 1;
    else {
        for (int j = 3; j < A; j=j+2) {
            C = A % j;
            //printf ("%f", C);
            if (C == 0) {           /* если остаток от деления числа А на j (где 1<j<A) равен нулю, то число простое */
                i = 1;             /* флаг поднимается */
                break;           /*цикл проверки прерывается*/
            }
        }
    }

    if (i==1) {              /* если флаг поднят, то чсло не простое*/
        printf("number is not Prime");
    }else{
        printf("number is Prime"); /* иначе -число простое*/
    }
}

int main (){
    int A;                      /*переменая для проверки простоты числа*/
    char l;                     /* переменная для задержки окна с результатом*/
    printf("Insert mumber for chek on prime: \n");
    scanf ("%d", &A);          /*получение числа для проверки простоты*/
    testPrimeNumber (A);        /* фызов функции проверки числа*/
    scanf ("%s", &l );         /* ввод любого символа для задержки программы*/
    return 0;
}