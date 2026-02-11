#include <stdio.h>
int checkscore(char std[]);
char keys[10]={'D','B','D','C','C','D','A','E','A','D'};
int no1 = 0;
int main() {
    int i,j;
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
            {'D','B','A','B','C','A','E','E','A','D'},//6
            {'E','D','D','A','C','B','E','E','A','D'},//5
            {'C','B','A','E','D','C','E','E','A','D'},//4
            {'A','B','D','C','C','D','E','E','A','D'},//8
            {'B','B','E','C','C','D','E','E','A','D'},//7
            {'B','B','A','C','C','D','E','E','A','D'},//7
            {'E','B','E','C','C','D','E','E','A','D'}};//7
    char s[10];
    for(i = 0;i<8;i++){
        for(j = 0;j<10;j++){
            s[j] = ans[i][j];
        }
    	printf("std %d => %d\n", (i+1), checkscore(s));
    }
    printf("No.1 correct = %d \n",no1);

}
int checkscore(char std[]){
    int i,poi=0;
    for(i=0;i<10;i++){
        if(std[i] == keys[i]){
            poi += 1;
        }
    }
    if(std[0] == keys[0]){
        no1 += 1;
    }
    return poi;
}
