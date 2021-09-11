#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SZ 10
#define T int
#define SIZE 1000
#define true 1==1
#define false 1!=1
typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}


void ins(int pr, int dat) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;
    if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    }
    else {
        arr[tail++] = node;
        items++;
    }
}

Node* rem() {
    int flag;
    if (items == 0) {
        return NULL;
    }
    else {
        int i = 0;
        int idx = 0;
        Node* tmp;
        int temp_i=0;
        for (i = head; i < tail-1; ++i) {
            idx = i % SZ;
            if (arr[(i+1)%SZ]->pr > arr[idx]->pr) {
                tmp = arr[(i + 1) % SZ];
                temp_i = i+1;
                idx++;
            }
        }
        
        i = temp_i;
        printf("Out [%d, %d]\n", arr[i]->pr, arr[i]->dat);
        flag = i % SZ;
        while (i < tail) {
            if (i == tail-1) {
                idx = i % SZ; 
                arr[idx] = NULL;
                i++;
            }
            else {
                idx = i % SZ;
                arr[idx] = arr[(i + 1) % SZ];
                i++;
            }
        }
        items--;
        tail--;
    }
}
    
    /*else {
        int idx = head++ % SZ;
        Node* tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}*/


void printQueue() {
    printf("Actual Queue [ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*,*]");
        else
            printf("[%d, %d]", arr[i]->pr, arr[i]->dat);

    }
    printf("]\n\n");
}
/*
9
1 описать очередь с приоритетным исключением
2 реализоваьт перевод из десфятичной в двочиную систему счисления с использованием стека
10
1 написать программу, которая определяет является ли веденая скгоьбочная
последвоательность правильной. Примеры правильных скобочных последовательностей
()..
2 Создать функцию, копирующую односвязный списко(без удаления первого списка)
3 реализуйте алгритм. которые определяет, отсортирован ли связный список
*/
typedef int boolean;
int cursor = -1;
T stack[SIZE];

boolean push(T data) {
    if (cursor < SIZE) {
        stack[++cursor] = data;
        return true;
    }
    else {
        printf("%s \n", "Stack overflow");
    }
}

T pop() {
    if (cursor != -1) {
        return stack[cursor--];
    }
    else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}


int main() {
//Task9.1==========================

    int num;
    scanf("%d", &num);
    while (num > 0) {
        if (num == 1){
            push(1);
            num = 0;
        }
        else {
            push(num % 2);
            num = num / 2;
        }
    }
    while (cursor != -1) {
        printf("%d", pop());
    }

    //Task9.2==========================

    init();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(5, 44);
    ins(4, 55);
    ins(6, 66);
    ins(7, 77);
    ins(9, 88);
    ins(8, 99);
    ins(6, 1);
    printQueue();

    for (int i = 0; i < SZ/2; i++) {
        rem();
        printQueue();
    }
    
    ins(8, 77);
    ins(8, 88);
    ins(7, 99);
    for (int i = 0; i < SZ; i++) {
        rem();
        printQueue();
    }
  
    
    return 0;
}
