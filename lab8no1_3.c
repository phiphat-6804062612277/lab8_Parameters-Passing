#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random1to100();
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);
void sort(int sortAr[],int numArSize);
int binarySearch(int ar[], int n, int target);
void swap(int *x , int *y);

int main() {
    int N,i;
    int A[100];
    scanf("%d",&N);
    if (N>100) 
    N=100;
    srand(time(NULL));
    for (i=0;i<N;i++)
        A[i] = checkNum(A,i);
       
    printf("\n********\n");
    printAr(A,N);
    
    return 0;
}
void printAr(int numAr[],int numArSize) {
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
} 

int checkNum(int numAr[],int numArSize) {
    int rnum;
    rnum=random1to100();
    while (searchNum(numAr,numArSize,rnum)) {
        rnum=random1to100();
    }
    return rnum;
}
int random1to100() {
    int random_num = (rand() % 100) + 1;
    printf("%d ", random_num);
    return random_num;
}

int searchNum(int numAr[],int numArSize, int target) {
        //sol1* use Linear search
        //sol2 use binary search  see.Lab6no9-10 
        int i,found=0,newar[100];
        for (i=0;i<=numArSize;i++){
        // sol1 
            // if(target == numAr[i]){
            //     found = 1;
            // }
        // sol2
            newar[i] = numAr[i];
        }
        sort(newar,numArSize);
        found = binarySearch(newar,numArSize,target);
        return found;
}
int binarySearch(int ar[], int n, int target){
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (target == ar[mid]){
            return 1;
        }
        if (target > ar[mid]){
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    return 0;
}
void sort(int sortAr[],int numArSize){
    int i,j,tt=0;
    for (i = 0 ;i<numArSize - 1;i++){
        tt = 1;
        for (j = 0;j < numArSize - i - 1;j++){
            if (sortAr[j] > sortAr[j + 1]){
                swap(&sortAr[j], &sortAr[j + 1]);
                tt = 0;
            }
        }
        if (tt == 1){
            break;
        }
    }
}
void swap(int *x , int *y){
    int te;
    te = *x;
    *x = *y;
    *y = te;
}
