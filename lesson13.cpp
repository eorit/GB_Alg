/*
1 Реализовать обход в глубину с использованием стека
2 Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями.
 Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
- обход графа рекурсивной функцией (с подсчётом только тех вершин, в которые можно прийти из стартовой)
- обход графа по матрице смежности (с подсчётом всех вершин графа) В конце обхода вывести два получившихся
 списка всех узлов в порядке уменьшения количества ссылок на них.
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T int
#define true 1==1
#define false 1!=1

typedef int boolean;


typedef struct Node {
    T dat;
    struct Node* next;
} Node;

typedef struct NodeLst {
    int dat;
    struct NodeLst* next;
} NodeLst;

typedef struct {
    Node* head;
    int size;
} Stack;


void init(Stack* stack) {
    stack->head = NULL;
    stack->size = 0;
}

boolean push(Stack* stack, T value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    //temp->dat = NULL;
    //temp->next = NULL;
    if (temp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    temp->dat = value;
    temp->next = stack->head;
    stack->head = temp;
    stack->size++;
    return true;
}

T pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return data;
}

void printOneLinkCharNode(Node* n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}


void printOneLinkCharStack(Stack* stack) {
    Node* current = stack->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    }
    else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);

    }
    printf("Size: %d \n", stack->size);
}

const int n=6;
int matrix[n][n]= {
        {0, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0},

};

int visited[n]={0};
void depthTravers(int st){
    int r;
    printf("%d", st);
    visited[st]=1;
     for (r=0; r<n; ++r){
        if (matrix [st][r]==1 && !visited[r]){
            depthTravers(r);
        }
    }
}

int searchStack(Stack* stack, int query){
    Node* current = stack->head;
    if (current == NULL) {
        return 0;
    }
    else {
        do {
            if (current->dat == query) {
                return 1;
            } else {
                current = current->next;
            }
            //current = stack->head->next;

        } while (current != NULL);

    }
}

void depthTraversStack(int st, Stack* stack){
    int r;
    printf("%d", st);
    push(stack, st);
    for (r=0; r<n; ++r){
       if (matrix [st][r]==1 && !searchStack(stack, r)){
            depthTraversStack(r, stack);
        }
    }
}
void depthTraversStack2(int st, Stack* stack){
    int r;
    int buffer;
    printf("%d", st);
    visited[st]=1;
    push(stack, st);
    for (int i=0; i<n; i++){
        i=buffer;
        for (r=0; r<n; ++r){
            if (matrix [i][r]==1 && !visited[r]) {
                printf("%d", r);
                visited[r] = 1;
                push(stack, r);
                i=r;
                r=0;
            }
       }
        pop(stack);
        if (stack->size>=1) {
            buffer = pop(stack);
            push(stack, buffer);
            i=buffer;
        }
    }
    pop(stack);
}


void resetArray(){
    for (int i=0; i<n; ++i){
        visited[i]=0;
    }
}
void task13_1(){
    int firstKnote=0;
    //Stack* stack;
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    Stack* stack2 = (Stack*)malloc(sizeof(Stack));
    init(stack);
    printf ("With matrix: \n");
    depthTravers(firstKnote);
    resetArray();
    printf ("\nWith Stack: \n");
    depthTraversStack(firstKnote, stack);
    init(stack2);
    printf ("\nWith Stack2: \n");
    depthTraversStack2(firstKnote, stack2);
}


int main() {
    //task 13/1
    task13_1();
    return 0;
}