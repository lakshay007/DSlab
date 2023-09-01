#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int arr[10],n;
    scanf("%i",&n);
    for(int i = 0;i<n;i++){
        scanf("%i",&arr[i]);
    }
    for(int i = 0;i<n-1;i++){
        int small = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[small]) small = j;
        }
        swap(&arr[i],&arr[small]);
    }


    for(int i = 0;i<n;i++){
        printf("%i ",arr[i]);
    }



}
