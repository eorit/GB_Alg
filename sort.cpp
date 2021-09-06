
#include <stdio.h>
#include <stdlib.h>

void fillRandom(int* arr, int len, int border) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % border;
    }
}

int* InitArray(int& size) {
    int* dinArray;
    //int n = 4;
    dinArray = new  int[size];
    return dinArray;
}

//void vArray(size_t len) {
 //   int* dinArray = (int*)calloc(len, sizeof(int));
//}

void delArray(int* array) {
    delete[] array;
    array = nullptr;
}

void swap(int* a, int* b) {
    int tem = *a;
    *a = *b;
    *b = tem;
}

void BubbleSort(int* array, int first_ind, int last_ind) {  //пузырьковая сортировка для одномерного массива
    //int len=last_ind-first_ind+1;
    for (int i = first_ind; i < last_ind; i++) {
        for (int j = first_ind; j < last_ind; j++) {
          //  printf("%d ", array[j]);
           // printf("%d \n", array[j+1]);
            if (array[j + 1] < array[j]) {
                swap(&array[j + 1], &array[j]);
            }
            //printf("%d \n", array[j+1]);
        }
    }
}

int getRandomIndex(int first_ind, int last_ind){
    int a=rand() % (last_ind-first_ind);
    return a;
}

void qSort(int* array, int first_ind, int last_ind) {
    int i = first_ind;
    int j = last_ind;
    int mediana1=array[getRandomIndex(i,j)];
    int mediana2=array[getRandomIndex(i,j)];
    int mediana3=array[getRandomIndex(i,j)];
    int x;
    if ((mediana1>=mediana2&&mediana2>=mediana3) ||(mediana3>=mediana2&&mediana2>=mediana1))  x=mediana2;
    else if ((mediana2>=mediana1&&mediana1>=mediana3)||(mediana3>=mediana1&&mediana1>=mediana2)) x=mediana1;
    else  x=mediana3;
    printf("%d\n", x);

    //int x = array[(first_ind + last_ind) / 2];
    do {
        while (array[i] < x) { i++; }
        while (array[j] > x) { j--; }
        if (i<= j) {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i+10 < last_ind) {
        qSort(array, i, last_ind);
    }
    else {BubbleSort (array, i, last_ind);}

    if (first_ind+10 < j) {
       qSort(array, first_ind, j);
    }
    else {BubbleSort (array, first_ind, j);}
}

void printArray(int* array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void bucketSort(int* arr, int len) {
	const int max = len;
	const int b = 10;
	int bucket[b][max + 1];
	for (int i = 0; i < b; ++i) {
			bucket[i][max] = 0;
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j <= max; j++) {
			bucket[i][j] = 0;
		}
	}

	for (int digit = 1; digit < 1000000000; digit *= 10) {
		for (int i = 0; i < max; ++i) {
			int d = (arr[i] / digit) % b;
			//printf("i= %d \n", i);
			//printf("d= %d \n", d);
			int counter = bucket[d][max];
			//printf("counter= %d \n", counter);
			bucket[d][counter] = arr[i];
			//printf("bucket[d][counter]= %d \n", arr[i]);
			counter++;
			//printf("counter++= %d \n", counter);
			bucket[d][max] = counter;
			//printf("bucket[d][max]= %d \n", counter);
			//bucket[d][bucket[d][max]++]=arr[i];
		}
		for (int i = 0; i < max; i++) {
			//printf("%d)", i);
			for (int j = 0; j <= max; j++) {
				//printf("%d ", bucket[i][j]);
			}
			//printf("\n");
		}

		int idx = 0;
		for (int i = 0; i < b; ++i) {
			//printf("i= %d ", i);
			for (int j = 0; j < bucket[i][max]; ++j) {
				//printf("j= %d ", j);
				for (int k = idx; k < max; k++) { //если элемент исходного массива нечетный, то переходим к следующему элементу
					if ((arr[idx]) % 2 != 0) {
						idx++;
					}
				}
				//printf("idx= %d ", idx);
				if (bucket[i][j] % 2 == 0) { //если элемент в корзине четный, то переносим его в сортируемый массив
					arr[idx++] = bucket[i][j];
					//printf("arr[idx++]= %d \n", arr[idx]);
				}
				else continue; //иначе выходим на новый виток цикла
				//printf("idx= %d ", idx);
				//printf("arr[idx]= %d \n", arr[idx]);
								}
			bucket[i][max] = 0;
		}
		/*printf("\n ");
		for (int j = 0; j <= max; j++) {
			printf("%d ", arr[j]);*/
		//}


	}
}

void task7_1(){
    printf("Task7.1\n");
    int sizeArray = 10;
    //int* array = &(vArray(sizeArray));
    //int* dinArray = (int*)calloc(sizeArray, sizeof(short  int));
    int* dinArray = InitArray(sizeArray);
    fillRandom(dinArray, sizeArray, 100);
    printArray(dinArray, sizeArray);
    //int dinArray[10] = { 99, 50, 45, 55, 89 , 10, 32, 25, 10, 1 };
    qSort(dinArray, 0, sizeArray - 1);
    printArray(dinArray, sizeArray);
    delArray (dinArray);
}

void task7_2(){
    printf("Task7.2\n");
    int arr[10] = { 98, 3, 75, 80, 5, 92, 1, 62, 70, 38 };
    printArray(arr, 10);

    bucketSort(arr, 10);
    printArray(arr, 10);

}

int main()
{
    task7_1();
    task7_2();
}

