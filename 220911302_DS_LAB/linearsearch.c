#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[10],n;
    scanf("%i",&n);
    for(int i = 0;i<n;i++){
        scanf("%i",&arr[i]);
    }
    int key;
    scanf("%i",&key);
    for(int i = 0;i<n;i++){
        if(arr[i]==key){
            printf("the element is present at index : %d ", i+1);
            exit(0);
        }
    }
    printf("the element is not present");

}
