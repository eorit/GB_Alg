#define _CRT_SECURE_NO_WARNINGS

// Algorithm_Lec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

/*Реализовать пузырьковую сортировку двумерного массива например, массив
1,9,2
5,7,6
4,3,8 должен на выходе стать
1,2,3
4,5,6
7,8,9*/

void swap(int* a, int* b) { //изменение мест в массиве
    int t = *a;
    *a = *b;
    *b = t;
    //return a, b;
}

void Print_DArray(int** array, int len1, int len2) {  // печать двумерного массива
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}

int* ODArray(int** array, int len1, int len2) { //инициирование одномерного динамического массива
    int* newODArray;
    newODArray = new int[len1 * len2];
    int k = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            newODArray[k] = array[i][j];
            k++;
        }
    }
    return newODArray;
}

void fillRandom(int** arr, int len1, int len2, int border) {  //заполнение двумерного динамичекого массива случайными числами
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            arr[i][j] = rand() % border;
        }
    }
}

int** BDArray(int len1, int len2) { //инициирование двумерного динамичкского массива
    int** newBDArray;
    newBDArray = new int* [len1];
    for (int j = 0; j < len1; j++) {
        newBDArray[j] = new int[len2];
    }
    return newBDArray;
}

void ODArryaToBDArray(int** array1, int* array2, int len1, int len2) { //копирование даннных из одномерного массива в двумерный
    int k = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            array1[i][j] = array2[k];
            k++;
        }
    }
}

void PrintArray(int* array, int len) {  // печать одноменого массива
    for (int i = 0; i < len; i++) {
        printf("%d ", &array[i]);
    }
    printf("\n ");
}

void BubbleSort(int* array, int len) {  //пузырьковая сортировка для одномерного массива
    for (int i = 0; i < (len - 1); ++i) {
        for (int j = 0; j < len - 1; j++) {
            if (array[j + 1] < array[j]) {
                swap(&array[j + 1], &array[j]);
            }
        }
    }
}

/*Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута 1 - запросить у пользователя 11 чисел и записать их в последовательность
П 2 - инвертировать последовательность
П 3 - для каждого элемента последовательности П произвести вычисление по формуле
sqrt(fabs(Х)) + 5 * pow(Х, 3)
и если результат вычислений превышает 400 - проинформировать пользователя.
Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С*/

void getNum(int* array, int len) {  //запрос последовательности из 11 чисел
    for (int i = 0; i < len; i++) {
        printf("Insert number %d:  ", i + 1);
        scanf("%d", &array[i]);
    }
}

void reverseArray(int* array, int len) { //инвертировать последовательность
    for (int i = 0; i < (len / 2); i++) {
        swap(&array[i], &array[len - 1 - i]);
    }
}

int calculateTPK(int* a) {   // расчет значения по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3)
    int result;
    result = sqrt(fabs(*a)) + 5 * pow(*a, 3);
    return result;
}

void attention(int i) {  // предупреждение
    printf("Attention! Result for an element with an index % d > 400 \n", i);
}


void algorithmTPK(int* array, int len) {
    //int array[11] = { 0 };
    //int len = 11;
    int array_of_result[11] = { 0 };
    getNum(array, len);    //запрос 11 чисел у пользователя
    PrintArray(array, len); //печать массива
    reverseArray(array, len); //инвертирование масисва
    PrintArray(array, len);  //печать массива
    for (int i = 0; i < len; i++) {   //расчет для каждого значения
        array_of_result[i] = calculateTPK(&array[i]);
        if ((array_of_result[i]) > 400) {
            attention(i);
        }
    }
    PrintArray(array_of_result, len); //печать массива значений, расчитанных по формуле
}

void Task6_1(int len1, int len2) { //задача 1 -пузырьковая сортировка массива
    //int origin_array[9] = { 1,9,2,5,7,6,4,3,8 };
    int** origin_array;
    int* O_ARRAY;
    origin_array = BDArray(len1, len2);
    fillRandom(origin_array, len1, len2, 10);
    O_ARRAY = ODArray(origin_array, len1, len2);
    Print_DArray(origin_array, len1, len2);
    BubbleSort(O_ARRAY, len1 * len2);
    //PrintArray(O_ARRAY, len1 * len2);
    ODArryaToBDArray(origin_array, O_ARRAY, len1, len2);
    Print_DArray(origin_array, len1, len2);
}


int main()
{

    //int origin_array[3][3] = {{1, 9, 2}, {5, 7, 6}, {4, 3, 8}};
    int len1 = 3;
    int len2 = 3;
    Task6_1(len1, len2);


    int array[11] = { 0 };
    int len = 11;
    algorithmTPK(array, len);



    /* for (int i = 0; i < 9; i++) {
         origin_array[i] = calculateTPK(&origin_array[i]);
     }
      PrintArray(origin_array, 9);*/
    return 0;
}

