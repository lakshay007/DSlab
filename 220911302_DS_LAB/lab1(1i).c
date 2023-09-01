#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[10],n;
    scanf("%i",&n);
    for(int i = 0;i<n;i++){
        scanf("%i",&arr[i]);
    }
    int key;
    scanf("%i", &key);
    int lo = 0; int hi = n-1; int mid ;
    while(hi>=lo){
        mid = (hi+lo)/2;
        if(arr[mid] == key){printf("the element was found at index: %i " , mid+1);exit(0);}
    if(arr[mid]>key){hi = mid-1;}
    else{lo = mid + 1;}



    }
    printf("the element was not found");

}
