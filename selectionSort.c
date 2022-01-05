#include<stdio.h>

void swap(int *a, int *b);
void displayArr(int *m, int size);
void selSort(int *m, int size);     //sap xep tang dung pp selection sort

int main(){
    int arr[] = {4, 2, 6, 8, 2, 1, 0, 1};
    int num = sizeof(arr)/sizeof(int);
    printf("Mang ban dau: \n");
    displayArr(arr, num);
    selSort(arr, num);
    printf("Mang sap xep theo pp selection sort: \n");
    displayArr(arr, num);
    return 0;
}

//ham selection sort
void selSort(int *m, int size){
    int i, j, min_index;
    for(i = 0; i < size - 1; i++){
        min_index = i;
        for(j = i + 1; j < size; j++){
            if(m[j] < m[min_index]){
                min_index = j;
            }
        }
        swap(&m[i], &m[min_index]);
    }
}

//doi cho hai so
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//hien thi mang 
void displayArr(int *m, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%5d", m[i]);
    }
    printf("\n");
}