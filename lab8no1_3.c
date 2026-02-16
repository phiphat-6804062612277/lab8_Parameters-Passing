#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random(int arr[]);
int chk(int tar , int arr[]);
void sort(int arr[]);
void swap(int *x , int *y);

int main(){
    int scoAr[4];
    srand(time(NULL));
    for (int i = 0 ;i < 4;i++){
        scoAr[i] = random(scoAr);
    }
    printf("\n-----------\n");
    for (int i = 0 ;i < 4;i++){
        printf("%d ",scoAr[i]);
    }
    sort(scoAr);    
    printf("\n-----------\n");
    printf("3 best score from 4 = ");
    for (int i = 0 ;i < 3;i++){
        printf("%d ",scoAr[i+1]);
    }

    return 0;
}
int random(int arr[]){
    int random,loopsame=1;
    while(loopsame){
        random = (rand() % 100) + 1; 
        printf("%d ",random);
        if(chk(random,arr)){ //ถ้าไม่ซ้ำ == 1
            loopsame = 0;
        }
    }// ถ้าซ้ำ loop
    return random;
}
int chk(int tar , int arr[]){
    int i;
    for (i = 0 ;i < 4;i++){
        if (tar == arr[i]){
            return 0; // ถ้าซ้ำ
        }
    }
    return 1; // ถ้าไม่ซ้ำ
}
void sort(int arr[]){
    int i,j;
    for (i = 0;i<3;i++){
        for (j=0;j<3-i;j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void swap(int *x , int *y){
    int te = *x;
    *x = *y;
    *y = te;
}
