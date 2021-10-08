
/*
Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.
65-90
97-122
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//#include "geek.h"

void encryptionCesar (char* text, int key, int EncryptDecrypt){
    int i=0;
    int flag;
    if (key>26){
        key=key%26;
    }
    if (key<-26){
        key=key%26;
    }
    if (EncryptDecrypt==-1){
        key=-key;
    }
    while (text[i]!='\0'){
        if (text[i]>=65 && text[i]<=90 ){
            flag=1;
        }
        else if (text[i]>=97 && text[i]<=122){
            flag=2;
        }
        else {
            flag=0;
        }
        if ((text[i]+key)>90 && flag==1 ){
            text[i]= key -(90-text[i])+64;
        }

        else if ((text[i]+key)<65 && flag==1 ){
            text[i]= 91 + (key-(text[i]-65));
        }
        else if ((text[i]+key)>122 && flag==2 ){
            text[i]=key-(122-text[i])+96;
        }
        else if ((text[i]+key)<97 && flag==2 ){

            text[i]=123+(key-(text[i]-97));
        }
        else if (flag==0){
            i++;
            continue;
        }
        else {
            text[i]=text[i]+key;
        }
        i++;
    }
}

void printArr(char* text){
    int i=0;
    while (text[i]!='\0'){
        printf("%c", text[i]);
        i++;
    }
    printf("\n");
}


void task1 (){

    int key=1;
    int EncryptDecrypt=0;

    char text1[]="A";
    char text2[]="z";
    char text3[]="Hello, World";
    char text4[]="TheLordOfTheRings";
    char text5[]="TheLordoftherings";

    printf("Message \n");
    printf("Text1: ");
    printArr(text1);
    printf("Text2: ");
    printArr(text2);
    printf("Text3: ");
    printArr(text3);
    printf("Text4: ");
    printArr(text4);
    printf("Text5: ");
    printArr(text5);

    encryptionCesar(text1, key,EncryptDecrypt);
    encryptionCesar(text2, key,EncryptDecrypt);
    encryptionCesar(text3, key,EncryptDecrypt);
    encryptionCesar(text4, key,EncryptDecrypt);
    encryptionCesar(text5, key,EncryptDecrypt);

    printf("Encryption \n");
    printf("Text1: ");
    printArr(text1);
    printf("Text2: ");
    printArr(text2);
    printf("Text3: ");
    printArr(text3);
    printf("Text4: ");
    printArr(text4);
    printf("Text5: ");
    printArr(text5);

    EncryptDecrypt=-1;

    encryptionCesar(text1, key,EncryptDecrypt);
    encryptionCesar(text2, key,EncryptDecrypt);
    encryptionCesar(text3, key,EncryptDecrypt);
    encryptionCesar(text4, key,EncryptDecrypt);
    encryptionCesar(text5, key,EncryptDecrypt);

    printf("Decryption \n");
    printf("Text1: ");
    printArr(text1);
    printf("Text2: ");
    printArr(text2);
    printf("Text3: ");
    printArr(text3);
    printf("Text4: ");
    printArr(text4);
    printf("Text5: ");
    printArr(text5);

}

/*
Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.
65-90
97-122
*/

void encryptionSwap(char* text, const int column) {

    int len = strlen(text);
    int lenForEncrypt;
    if (len < column) {
        printf("Error: ");
        printArr(text);
    } else  {
        if (len%column){
            lenForEncrypt = len + (column - (len % column));
        } else {
            lenForEncrypt=len;
        }//int row = lenForEncrypt / column;
        //char* temp=(char*)malloc((lenForEncrypt+1)*sizeof (char));
        char temp[200]={0};
        int key = column;
        int idx = 0;
        for (int i=len;i<lenForEncrypt; i++){
            text[i]='x'; //32;
        }
        temp[lenForEncrypt] = '\0';
        for (int i = 0; i <= key; i++) {
            for (int j = key; j < lenForEncrypt+key; j += key) {
                /*if (i + j > len) {
                    temp[idx++] = 'x';
                } else {*/
                    temp[idx++] = text[i + j-key];
                //}
            }

            //free (temp);
        }
        for (int i=0; i<lenForEncrypt; i++){
            text[i]=temp[i];
        }
    }
}

char* decryptionSwap(char* text, const int column){
    if (strlen(text)/column){
    int key=strlen(text)/column;
    encryptionSwap(text, key);
    return text;}
    else{
        printf ("Error:");
        printArr(text);
    }
}
void task2(){
   /* char* text1=(char*)malloc(100*sizeof (char));
    char* text2=(char*)malloc(100*sizeof (char));
    char* text3=(char*)malloc(100*sizeof (char));
    char* text4=(char*)malloc(100*sizeof (char));
    char* text5=(char*)malloc(100*sizeof (char));
*/

 
    char text1[100]= {"Abcdefghiklmn"};
    char text2[10]={"z"};
    char text3[100]={"Hello, World"};
    char text4[100]={"TheLordOfTheRings"};
    char text5[100]={"TheLordOfTheRings"};
 
 /*
  
    text1 = {"Abcdefghiklmn"};
    text2 = "z";
    text3 = "Hello, World";
    text4 = "TheLordOfTheRings";
    text5 = "TheLordoftherings";
   */
    printf("Message \n");
    printf("Text1: ");
    printArr(text1);
    printf("Text2: ");
    printArr(text2);
    printf("Text3: ");
    printArr(text3);
    printf("Text4: ");
    printArr(text4);
    printf("Text5: ");
    printArr(text5);
    
    //------------------------------------
    
    encryptionSwap(text1, 4);
    encryptionSwap(text2, 4);
    encryptionSwap(text3, 4);
    encryptionSwap(text4, 6);
    encryptionSwap(text5, 8);
    
    //------------------------------------
    
    printf("Encryption: \n");
    printf("Text1: ");
    printArr(text1);
    printf("Text2: ");
    printArr(text2);
    printf("Text3: ");
    printArr(text3);
    printf("Text4: ");
    printArr(text4);
    printf("Text5: ");
    printArr(text5);

    //-------------------------------------
    
    decryptionSwap(text1, 4);
    decryptionSwap(text2, 4);
    decryptionSwap(text3, 4);
    decryptionSwap(text4, 6);
    decryptionSwap(text5, 8);
    
    //-----------------------------------
    
    printf("Decryption: \n");
    printf("Text1: ");
    printArr(text1);
    printf("Text2: ");
    printArr(text2);
    printf("Text3: ");
    printArr(text3);
    printf("Text4: ");
    printArr(text4);
    printf("Text5: ");
    printArr(text5);
}


int main() {
    printf("Task1 \n");
    task1();
    printf("Task2 \n");
    task2();
    return 0;

}