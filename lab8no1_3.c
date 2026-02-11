#include <stdio.h>
int findMax(int num[]);
void printAr(int myAr[],int size);
void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x);
void addthree(int number[],int length,int pos[][length],int lengtharray);

int main() {
	int number[5] = {20,50,100,99,9};
	int max,length,x;
    length = sizeof(number) / sizeof(number[0]);
	max = findMax(number);
    printAr(number,length);
	printf("Maximum of these number is %d\n",max);
    // addone
    int adon[5] = {1,2,3,4,5};
    addone(number,adon,length);
    printf("after addone\n");
    printAr(number,length);
    // addtwo
    printf("after addtwo\n");
    x = 30;
    int adtw[] = {4,2,0};
    int lengthadtw = sizeof(adtw) / sizeof(adtw[0]);
    addtwo(number, adtw, x);
    printAr(number,length);
    //addthree
    printf("after addthree\n");
    int po2[][2] = {{3,100},{0,8},{2,45},{1,999}};
    int lenghtadthr1 = sizeof(po2) / sizeof(po2[0]);
    int lenghtadthr2 = (sizeof(po2) / sizeof(po2[0][0])) / lenghtadthr1;
    addthree(number,lenghtadthr2,po2,lenghtadthr1);
    printAr(number,length);

    return 0;
}

int findMax(int num[]) {
	int maximum,i=0;
	maximum = num[i];

	for(i=0;i<5;i++) {
		if(num[i] > maximum)
			maximum = num[i];
	}
	return maximum;
}

void printAr(int myAr[],int size){
    int i;
    for(i =0;i<size;i++){
        printf("number[%d] : %d\n",i+1,myAr[i]);
    }
}

void addone(int number[], int add[], int sizeNum){
    int gg;
    for(int i=0;i<sizeNum;i++){
        number[i] += add[i];
    }
}

void addtwo(int number[], int pos[], int x){
    int po;
    for(int i = 0;i<3;i++){
        po = pos[i];
        number[po] = number[po] + x;
    }
}

void addthree(int number[],int length, int pos[][length],int lengtharray){
    int po,i;
    for(i = 0;i<lengtharray;i++){
        po = pos[i][0];
        number[po] += pos[i][1];
    }
}
/* result
number[1] : 20
number[2] : 50
number[3] : 100
number[4] : 99
number[5] : 9
Maximum of these number is 100
*/