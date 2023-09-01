#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int arr[],int n){
    if(n==0) return;
    int small = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]<arr[small]){
            swap(&arr[i],&arr[small]);
        }
    }
    sort(arr+1,--n);

}

int main(){
    int arr[10],n;
    scanf("%i",&n);
    for(int i = 0;i<n;i++){
        scanf("%i",&arr[i]);
    }
    sort(arr,n);
    for(int i = 0;i<n;i++){
        printf("%i ",arr[i]);
    }
}

