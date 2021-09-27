/*
ВНИМАНИЕ!
Это заглушка для соблюдения сроков сдачи!
В данной версии файла задачи еще не решены!

==========================================================================================
1 Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
2Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
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
        {1, 0, 1, 0, 0, 1},
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
    printf("\n");
}
int countLink[2][n] = {NULL};

void depthTraversWithCountLink(int st, int st2) {
    int r;
    //printf("%d", st);
    visited[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1) {
            if (matrix[st2][r] == 1) {
                //printf("%d ", r);
                //printf("%d ", countLink[1][r]);
                countLink[1][r]++;
                //printf("%d ", countLink[1][r]);
            }
            if (!visited[r]) {
                depthTraversWithCountLink(r, st2);
            }
        }
    }
}

void sortedCountLink() {
    int temp = 0;
    int count = n;
    for (int i = 0; i <n; i++) {
        countLink[2][i]=i;
    }
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < n; j++) {
            if (countLink[1][countLink[2][i]] > countLink[1][countLink[2][j]]) {
                temp=countLink[2][i];
                countLink[2][i]=countLink[2][j];
                countLink[2][j]=temp;

            }

        }

    }

}
void printCountLink(){
    for (int i=0; i<n; i++){
        if (countLink[1][(countLink[2][i])]>0) {
            printf("%d", countLink[2][i]);
        }
    }
    printf ("\n");
    for (int j=0; j<n; j++){
        if (countLink[1][(countLink[2][j])]>0) {
            printf("%d", countLink[1][(countLink[2][j])]);
        }
    }
    printf ("\n");
}

void resetCountLinkArray() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            countLink[i][j] = {NULL};
        }
    }
}

void task13_2_1(int st) {
    printf ("\nTask 13.2 -1: \n");
    resetArray();
    depthTraversWithCountLink(st, st);
    sortedCountLink();
    printCountLink();
}

void TraversWithCountLink(int st, Stack* stack){
    int r;
    int buffer;
    //printf("%d", st);
    visited[st]=1;
    push(stack, st);
    for (int i=0; i<n; i++){

        for (r=0; r<n; ++r){
            if (matrix [i][r]==1) {
                //printf("%d ", r);
                countLink[1][r]++;
                //printf("%d ", countLink[1][r]);
                }
            }
        }
    printf("\n");
}

void task13_2_2(int st) {
    printf ("\nTask 13.2 -2: \n");
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    init(stack);
    resetArray();
    resetCountLinkArray();
    TraversWithCountLink(st, stack);
    sortedCountLink();
    printCountLink();

}


int main() {
    //task 13.1==================
    task13_1();
    //task 13.2==================
    int st=0;
    task13_2_1(st);
    task13_2_2(st);
    return 0;
}