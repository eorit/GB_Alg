#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <stdlib.h>
//#include <string.h>
#define HEIGHT 8
#define WIDTH 8
#define KING HEIGHT * WIDTH - 1



void PrintArray(int* array, int len) {
    for (int i = len-1; i >= 0; i--) {
        printf("%d", array[i]);
    }
}

//int* InitArray(int A) {
//    int* array = new int[A/2]
//}



void Task1(int A) {
    int B[10] = { 0 };
    /*for (int i = 0; i < 10; i++) {
        B[i] = 0;
    }*/
    static int step = -1;
    DecToBi(A, B, step);
    //char rslt[] = {0};
    //binr(A);
    PrintArray(B, 10);
    //printf("%c", rslt);
}

int binr(int n) {
    if (n <= 0) return;
    int A;
    A=binr(n / 2);
    printf("%d", ((n % 2 == 0) ? "0" : "1"));
}

int DecToBi (int a, int* array, int step){
    //char C[100] = {1};
    //int B[1000] = {0};
    //int i = 0;
/*	while (A>=1){
		B=(A)%2;

		printf("%d", A);
		printf("%d", B);
		A=A/2;
		sprintf(C, "%d", B);
   	}
*/
    if (a>=1) {
        step = step + 1;
        array[step] = ((DecToBi(floor(a / 2),array ,step)) % 2);
        //printf("%d", a / 2);
        return (a % 2);
    }
    
}
//=============================================================
/*Возвежение числа а в степень в рекурсивно*/
/*int rise_rec(int A, int B) {
    if (B > 0) {
        A = A * rise_rec(A, B - 1);
        return A;
    }
}*/
//============================================================
/*Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная, 
основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат 
умножается на основание, а показатель уменьшается на единицу)*/
//==============================================================
/*int rise_rec2(int A, int B, int C) {
    int res;
    if (B >1 && B % 2 == 0) {
        A = rise_rec2(A *A, B / 2, C);
        //C = A;
        //B = B / 2;
    }
    else if (B >= 1 && B % 2 != 0) {
        A = A*rise_rec2(A, B - 1, C);
        //B = B - 1;
    }
    else if (B == 1) return A;
    else return 1;
    //printf("%d", A);
    return A;
 
}*/

/*===============================================================================
Реализовать нахождение количества маршрутов шахматного короля с препятствиями 
(где единица - это наличие препятствия, а ноль - свободная для хода клетка).
Король ходит только по прямой, маршруты считаются с клетки (0, 0)*/
int routes(int x, int y) {
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 ^ y == 0)
        return 1;
    else
        return routes(x, y - 1) + routes(x - 1, y);
}
//=========================================
int board[HEIGHT][WIDTH];
void printBoard() {
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            printf("%d ", board[i][j]);
    printf("%s", "\n");
     }
int possible[][2] = {{0, 1}, {1, 0}, {1, 1}};

int isPossible(int x, int y) {
    return x > 0 && x < WIDTH&& y>0 && y < HEIGHT
        && board[x][y] == 0;
}

int kingMove(int x, int y, int move) {
    int nextX;
    int nextY;
    board[y][x] = move;
    if (move > KING) return 1;
    for (int i = 0; i < 10; ++i) {
        nextX = x + possible[i][1];
        nextY = y + possible[i][0]; 
        if (isPossible(nextX, nextY) && kingMove(nextX, nextY, move + 1))
            return 1;
        }
        board[y][x] = 0;
        return 0;
}
        
int main() {
    //========Задача 1
    /*int A;
    scanf("%d", &A);
    Task1(A);*/
    
    //===========Задача 2.1
    /*int N;
    int E;
    int res;
    scanf("%d", &N);
    scanf("%d", &E);
    res = rise_rec(N, E);
    printf("%d", res);
    */
    // ========== задча2.2
    /*int Z;
     int X;
     //int res;
     scanf("%d", &Z);
     scanf("%d", &X);
     printf ("%d", rise_rec2(Z, X, Z));
     //printf("%d", res);*/
     
     //===========задача3
    
   // const int f = 1;  //какой-то странный глюк в MS visual - первое значение не определяется средойт разраюотки как объявленное
    //const int sizeY = 5;
    //const int sizeX = 5;
    //for (int y = 0; y < sizeY; y++) {
    //    for (int x = 0; x < sizeX;  ++x) {
     //       printf("%5d", routes(x, y));
      //  }
     //   printf("\n");
   // }
   // return 0;

    kingMove(0, 0, 1);
    printBoard();
    
    char l;                     //что бы консоль не закрывалась сразу
    scanf("%s", &l);

}