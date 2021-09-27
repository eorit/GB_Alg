
/*
ВНИМАНИЕ!
 Это заглушка для соблюдения сроков сдачи!
 В данной версии файла задачи еще не решены.

Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет
 наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.*/

#include <iostream>
#include "geek.h"

typedef int K;
typedef int htIndex;
int htSize;
htIndex hash (int data){
    return data % htSize;
}
bool insertNode(OneLinkNode** table, K data){
    OneLinkNode *p, *p0;
    htIndex bucket=hash (data);
    p=(OneLinkNode*) malloc (sizeof(OneLinkNode));
    if (p==NULL){
        printf ("Out of memory! \n");
        return false;
    }
    p0=table[bucket];
    table[bucket]=p;
    p->next=p0;
    p->dat=data;
    return true;
}
OneLinkNode* findNode (OneLinkNode** table, K data){
    OneLinkNode *p=table[hash(data)];
    while (p&&!(p->dat==data))
        p=p->next;
    return p;
}

void deleteNode (OneLinkNode** table, K data) {
    OneLinkNode *parent, *current;
    parent=NULL;
    htIndex bucket=hash(data);
    current=table[bucket];
    while (current && !(current->dat==data)){
        parent=current;
        current=current->next;
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
