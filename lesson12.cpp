/*
не понимаю, где ошибка в первой задаче. При небольшом количестве элементов при работе в режиме отладки в Clion значения считаются, а при запуске-нет. 
в VisualStudio  подтягиваются какие-то мусорные значения
1 Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
- создаст [50] деревьев по [10000] узлов и заполнит узлы случайными целочисленными значениями;
- рассчитает, какой процент из созданных деревьев является сбалансированными.
2 Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} TreeNode;


void initTree(TreeNode* t) {
    t->key = NULL;
    t->left = NULL;
    t->right = NULL;

}

TreeNode* treeInsert(TreeNode* t, int data) {
    TreeNode* newNode;
    newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode* current = t;
    TreeNode* parent = t;
    if (t == NULL) {
        t = newNode;
    }
    else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode* root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left) {
                printTree(root->left);
            }
            else {
                printf("NULL");
            }
            printf(",");
            if (root->right) {
                printTree(root->right);
            }
            else {
                printf("NULL");
            }
            printf(")");
        }

    }
}

int getNum(int boarder) {
    srand(time(NULL));
    int Num = rand() % boarder;
    return Num;
}

int checkBalancing (TreeNode* tree) {
    int countLeft = 1;
    int countRight = 1;
    if (tree) {
        if (tree->left || tree->right) {
            if (tree->left) {

                countLeft=countLeft+checkBalancing(tree->left);
            }
            if (tree->right) {
                countRight=+checkBalancing(tree->right);
            }
        }

    }
    return countLeft, countRight;
}

int checkBalancingTree (TreeNode* tree) {
   
    if (tree) {
        if (tree->left || tree->right) {
            if (tree->left==NULL&&(tree->right->left!=NULL||tree->right->right!=NULL)) {
                return 0;
            }
            else if (tree->right==NULL&&(tree->left->left!=NULL||tree->left->right!=NULL)) {
                return 0;
            } else if (checkBalancing(tree->right)==checkBalancing(tree->left)||checkBalancing(tree->right)==checkBalancing(tree->left)+1||checkBalancing(tree->right)+1==checkBalancing(tree->left)){
                return 1;
            }
        }

    }
}




void Task12_1(int quantity, int numbElements,int border) {
    int counter = 0;
    int percent=0;
    for (int i = 0; i < quantity; i++) {
        TreeNode *tree = (TreeNode *) malloc(sizeof(TreeNode));
        initTree(tree);
        tree = NULL;
        for (int j = 0; j < numbElements; j++) {
            tree = treeInsert(tree, getNum(border));
            //
        }
        counter = counter + checkBalancingTree(tree);
    }
    percent=(counter*100)/quantity;
    //printf("%d \n", counter);
    printf("%d percent of weighted trees", percent);
}

int preOrderTravers(TreeNode *tree, int request){
    int flag= 0 ;
    if (tree){
        if (tree->key==request){
            flag = 1;
        }
        else {
            if(preOrderTravers(tree->left, request)){
                flag = 1;
            } else if (preOrderTravers(tree->right, request)) {
                flag = 1;
            }
        }
        return flag;
        
    }
}

void Task12_2(int numbElements,int border, int request){
   TreeNode *tree2 = (TreeNode *) malloc(sizeof(TreeNode));
   initTree(tree2);
   tree2 = NULL;
   for (int j = 0; j < numbElements; j++) {
       tree2 = treeInsert(tree2, getNum(border));
   }
   treeInsert(tree2, 5);
   if (preOrderTravers(tree2,request)==0){
       printf ("%d not found", request);
   }
   else {
       printf ("%d find", request);
   };

}
int main()
{

    int quantity = 5;
    int numbElements = 2;
    int border = 2;
    //Task12_1(quantity, numbElements, border);
    int request = 5;
    numbElements = 10;
    border = 10;
    Task12_2(numbElements,border, request);





    return 0;
}