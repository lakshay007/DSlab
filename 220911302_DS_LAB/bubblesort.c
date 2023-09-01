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

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1;j++){
                if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);

        }
    }
    for(int i = 0;i<n;i++){
        printf("%i ",arr[i]);
    }



}
