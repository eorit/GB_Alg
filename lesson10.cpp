// lesson10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T char
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

void checkSequence(Stack* st, char* str) {
    int i = 0;
    int flag = 0;
    T temp;
    int counter = 0; //счетчик для подсчета количества открывающих скобок в стеке. Количество данных в стеке не используется исходя из предположения,
                    // что в нем может быть что-то еще(хотя,конечно, можно было бы сделать проверку количества данных в стеке)

    while (str[i] != '\0') {
        if (str[i] == '\0') break;
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(st, str[i]);
            counter++;
            //printf("push %c %d \n", str[i], counter);
        }
        else if (str[i] == ')') {
            temp = pop(st);
            if (temp == '(') {
                flag = 1;
                counter--;
                //printf("pop, temp %c, counter %d \n", temp, counter);
            }
            else {
                push(st, temp);
                flag = 0;
                break;
            }
        }
        else if (str[i] == '}') {
            temp = pop(st);
            if (temp == '{') {
                flag = 1;
                counter--;
            }
            else {
                push(st, temp);
                flag = 0;
                break;
            }
        }
        else if (str[i] == ']') {
            temp = pop(st);
            if (temp == '[') {
                flag = 1;
                counter--;
            }
            else {
                push(st, temp);
                flag = 0;
                break;
            }
        }
        i++;
    }

    if (flag == 1 && counter == 0) {
        printf("The Sequence is correct \n");
    }
    else if (flag == 0 || counter != 0) {
        printf("The Sequence is incorrect \n");
    }
}



typedef struct {
    NodeLst* head;
    int size;
} List;

void init(List* lst) {
    lst->head = NULL;
    lst->size = 0;
}
 
void ins(List* lst, int data) {
    NodeLst* newL = (NodeLst*) malloc(sizeof(NodeLst));
    newL->dat = data;
    newL->next = NULL;
    NodeLst* current = lst->head;
    if (current == NULL) {
        lst->head = newL;
        lst->size++;
    }
    else {
        while (current->next != NULL) {
            current = current->next;

        }
    current->next = newL;
    lst->size++;
        
    }
}

NodeLst* rm(List* lst, int data) {
    NodeLst* current = lst->head;
    NodeLst* parent = NULL;
    if (current == NULL) {
        return NULL;
    }
    while (current->next != NULL && current->dat!=data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent -> next = current->next;
    lst->size--;
    return current;
}


void printNodeLst(NodeLst* n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printList(List* lst) {
    NodeLst* current = lst->head;
    if (current == NULL) {
        printNodeLst(current);
    }
    else {
        do {
            printNodeLst(current);
            current = current->next;
        } while (current != NULL);
    }
    printf("Size: %d \n", lst->size);
}


void copyList(List* lst, List* copy) {
    init(copy);
    NodeLst* current = lst->head;
    while (current != NULL) {
        ins(copy, current->dat);
        current = current->next;
    }
 }
 
void checkSorting(List* lst) {
    NodeLst* current = lst->head;
    T temp= current->dat;
    int flag_inc = 0;
    int flag_dec = 0;
    while (current != NULL) {
        if ((current->dat) >= temp && flag_dec == 0) {
            flag_inc = 1;
            temp = current->dat;
        }
        else if ((current->dat) <= temp && flag_inc == 0) {
            flag_dec = 1;
            temp = current->dat;
        }
        else {
            flag_inc = 0;
            flag_dec = 0;
            break;
        }
        current = current->next;
    }
    if (flag_inc == 1) {
        printf("List is sorted by increase. \n");
    } else  if (flag_dec == 1) {
        printf("List is sorted by decrease. \n");
    }
    else {
        printf("List is not sorted. \n");
    }
}


int main(){
    //Task 10.1============================================
    Stack* st = (Stack*)malloc(sizeof(Stack));
    init(st);
    push(st, '2');
    push(st, '0');
    push(st, '9');
   
    printOneLinkCharStack(st);
    
    
    char str[80] = {'0'};
    gets_s(str);
    checkSequence(st, str);
    
    //Task 10.2============================================


    List* lst = (List*)malloc(sizeof(List));
    List* copy = (List*)malloc(sizeof(List));
   
    init(lst);
    printList(lst);
    ins(lst, 1);
    ins(lst, 30);
    ins(lst, 20);
    //printList(lst);

    copyList(lst, copy);
    printList(lst);
    printList(copy);
    ins(lst, 50);
    ins(copy, 100);
    printList(lst);
    printList(copy);
    rm(lst, 20);
    rm(copy, 30);
    printList(lst);
    printList(copy);
    copyList(lst, copy);
    printList(copy);
    
    //Task 10.3============================================
    
    checkSorting(lst);
    ins(lst, 10);
    printList(lst);
    checkSorting(lst);

    return 0;
    
}

