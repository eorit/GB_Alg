#include <stdio.h>

void testPrimeNumber (int A) { /*функция проверки простоты числа*/
    float C;
    int i=0;       /*флаг*/
    for (int j=2; j<A; j++) {
        C=A%j;
        //printf ("%f", C);
        if (C==0){           /* если остаток от деления числа А на j (где 1<j<A) равен нулю, то число простое */
            i=1;             /* флаг поднимается */
            break;           /*цикл проверки прерывается*/
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
    scanf ("%d", &A);          /*получение числа для проверки простоты*/
    testPrimeNumber (A);        /* фызов функциипроверки числа*/
    scanf ("%s", &l );         /* ввод любого символа для задержки программы*/
    return 0;
}
