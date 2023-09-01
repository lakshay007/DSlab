#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    if(a>b) return a;
    return b;

}
int main(){
    int r,c, arr[10][10] , arr1[10][10], maxar[10][10];
    printf("enter the rows and columns for the matrices: \n");
    scanf("%i %i", &r ,&c);
    printf("enter matrix 1: \n");
    for(int i = 0 ;i<r;i++){
            for(int j = 0;j<c;j++){
                scanf("%i" , &arr[i][j]);
            }
    }
    printf("enter matrix 2: \n");
    for(int i = 0 ;i<r;i++){
            for(int j = 0;j<c;j++){
                scanf("%i" , &arr1[i][j]);
            }
    }
    for(int i = 0 ;i<r;i++){
            for(int j = 0;j<c;j++){
                maxar[i][j] = max(arr[i][j],arr1[i][j]);
            }
    }
    printf("The matrix is: \n");
    for(int i = 0 ;i<r;i++){
            for(int j = 0;j<c;j++){
                printf("%i " , maxar[i][j]);
            }
            printf("\n");
    }







}
