#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#define HEIGHT 8
#define WIDTH 8
#define KING HEIGHT * WIDTH - 1

int DecToBi (int A){
    char C[100] = {1};
    //int B[1000] = {0};
    int i = 0;
/*	while (A>=1){
		B=(A)%2;

		printf("%d", A);
		printf("%d", B);
		A=A/2;
		sprintf(C, "%d", B);
   	}
*/
    if (A>0) {
        //B=(A/2)%2;
        //A=A/2;
        //B=B<<1;
        i = i + 1;
        C[i] = ((DecToBi(A / 2)) % 2) + '0';
        
        for (int j = sizeof(C); j == 0; j--) {
            printf("%s", C[j]);
        }
        //sprintf(C, "%d", B);
        return (A % 2);
    }
    
    //B = ~B;
    //printf("%d", B);
  printf("%s", C);
   // printf("%d", B);
}
//=============================================================
/*Возвежение числа а в степень в рекурсивно*/
int rise_rec(int A, int B) {
    if (B > 0) {
        A = A * rise_rec(A, B - 1);
        return A;
    }
}
//============================================================
/*Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число, чётная, 
основание возводится в квадрат, а показатель делится на два, а если степень нечётная - результат 
умножается на основание, а показатель уменьшается на единицу)*/
//==============================================================
int rise_rec2(int A, int B, int C) {
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
 
}

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
            printf("3%d", board[i][j]);
    printf("\n");
     }
int possible[][2] = {
    {-1, 1}, {-1,0}, {-1,-1},
    {0, -1}, {0, 1}, {-1, 0}, {1, 0},
    {1, 1}, {1,0}, {1, -1} };


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
    int A;
    scanf("%d", &A);
    DecToBi(A);
    
    //===========Задача 2.1
    int N;
    int E;
    int res;
    scanf("%d", &N);
    scanf("%d", &E);
    res = rise_rec(N, E);
    printf("%d", res);

    // ========== задча2.2
    int Z;
     int X;
     //int res;
     scanf("%d", &Z);
     scanf("%d", &X);
     printf ("%d", rise_rec2(Z, X, Z));
     //printf("%d", res);
     
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