
/*Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет
 наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.*/

#include <iostream>
#include "geek.h"

int Hash (char* text){
    int i=0;
    int sum=0;
    while (text[i]!=0){
        sum=sum+text[i];
        i++;
    }
    return sum;
}

void task1 (){
    int hash;
    char text[]="Hello, World";
    char text2[]="TheLordOfTheRings";
    char text3[]="TheLordoftherings";
    hash= Hash(text);
    printf ("%d", hash);
    printf("\n");
    hash= Hash(text2);
    printf ("%d", hash);
    printf("\n");
    hash= Hash(text3);
    printf ("%d", hash);
    printf("\n");
}



void printArr(int* arr, int n){
    for (int i=0; i<n; i++){

            printf("%d, ", arr[i]);

    }
    printf("\n");
}
void task2(){
    int cash=97;
    int coin[5]={50,10, 5, 2, 1};
    int counter [5]={0};
    int i=0;
    while (cash!=0){
        if (cash-coin[i]>=0){
            cash-=coin[i];
            counter[i]++;
        }
        else{
            i++;
        }
    }
    printArr(coin, 5);
    printArr(counter, 5);
}
int main() {
    task1();
    task2();
   return 0;

}
