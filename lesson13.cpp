/*Реализовать обход в глубину с использованием стека
Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями. Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
- обход графа рекурсивной функцией (с подсчётом только тех вершин, в которые можно прийти из стартовой)
- обход графа по матрице смежности (с подсчётом всех вершин графа) В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.
Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define T char
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
    //printf("\n");
}

TreeNode* getSuccessor(TreeNode* node) {
    TreeNode* current = node->right;
    TreeNode* parent = node;
    TreeNode* s = node;
    while (current != NULL) {
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}


boolean del(TreeNode* root, int key) {
    TreeNode* current = root;
    TreeNode* parent = root;
    boolean isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        }
        else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL) {
            return false;
        }
    }
    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            root = NULL;
        }
        else if (isLeftChild) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
    }
    else if (current->right == NULL) {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        TreeNode* successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;

    }
    return true;
}

int getNum(int boarder) {
    srand(time(NULL));
    int Num = rand() % boarder;
    return Num;
}
/*void fillTreeRandom(TreeNode* t, int count, int border) {
    for (int i = 0; i < count; i++) {
        t=treeInsert(t, getNum(border));
    }
    return t;
}*/

/*Node** getTrees(int quantity, int numbElements, int border) {
    //TreeNod* * arrTree[quantity]=(TreeNode*)malloc(sizeof(TreeNode))
    Node** arrTree = (Node**)malloc(sizeof(Node));
    for (int i = 0; i < quantity; i++) {
        arrTree[i] = (Node*)malloc(sizeof(Node));
        arrTree[i] = NULL;
        for (int j = 0; j <= numbElements; j++) {
            //arrTree[i]=fillTreeRandom(arrTree[i], numbElements, border);
            arrTree[i] = treeInsert(arrTree[i], getNum(border));

        }
    }
    //TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
    //tree =NULL;
    //fillTreeRandom (tree, count, border);
    return arrTree;
}*/

/*void printTrees(Node** arrTree, int quantity) {
    for (int i = 0; i < quantity; i++) {
        printf("%d) ", i + 1);
        printTree(arrTree[i]);

    }
}*/
int checkBalancing (TreeNode* tree) {
    int countLeft = 0;
    int countRight = 0;
    if (tree) {
        if (tree->left || tree->right) {
            if (tree->left==NULL) {
                checkBalancing(tree->left);
                countLeft++;
            } else if (tree->left) {
                checkBalancing(tree->left);
            q}
            if (tree->right) {
                countRight++;
                checkBalancing(tree->right);
            }

        }

    }
    if (countLeft + 1 != countRight || countLeft != countRight + 1 || countLeft != countRight) {
        return 0;
    } else {
        return 1;
    }
    return 0;
}

void Task12_1(int quantity, int numbElements,int border) {
    int counter = 0;
    int percent=0;
    for (int i = 0; i < quantity; i++) {
        TreeNode *tree = (TreeNode *) malloc(sizeof(TreeNode));
        initTree(tree);
        tree = NULL;
        for (int j = 0; j <= numbElements; j++) {
            tree = treeInsert(tree, getNum(border));
            //
        }
        //printf("%d \n", i);
        printTree(tree);
        counter = counter + checkBalancing(tree);
        //free(tree);
    }
    percent=(counter*100)/quantity;
    printf("%d \n", counter);
    printf("%d percent of weighted trees", percent);
}
int main()
{

    /*    TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
        //initTree(tree);
        tree =NULL;
        fillTreeRandom(tree, 10000, 100000);
        treeInsert(tree, 8);
        treeInsert(tree, 11);
        treeInsert(tree, 15);
        treeInsert(tree, 20);
        treeInsert(tree, 1);
        printTree(tree);
        printf("\n");*/

    //    getTrees (int quantity, int numbElements,int border)
    int quantity = 10;
    int numbElements = 10;
    int border = 1000;
   // NAode** arrTree = getTrees(quantity, numbElements, border);
    //printTrees(arrTree, quantity);
    Task12_1(quantity, numbElements, border);






    return 0;
}