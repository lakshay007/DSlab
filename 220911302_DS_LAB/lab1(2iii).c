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
    for(int i = 1;i<n;i++){
        int curr = arr[i];
        int j = i-1;
        while(curr<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }


    for(int i = 0;i<n;i++){
        printf("%i ",arr[i]);
    }



}
