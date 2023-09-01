#include<stdio.h>
#include<stdlib.h>
binsearch(int arr[] , int key, int hi, int lo, int mid){
    mid = (hi+lo)/2;
    if(arr[mid] == key) return mid+1;
    if(arr[mid] > key) hi = mid-1;
    else lo = mid + 1;
    if(hi<lo) return -1;
    return binsearch(arr , key , hi , lo , mid);
}
int main(){
    int arr[10],n;
    scanf("%i",&n);
    for(int i = 0;i<n;i++){
        scanf("%i",&arr[i]);
    }
    int key;
    scanf("%i", &key);
    int lo = 0; int hi = n-1; int mid ;
    int a = binsearch(arr,key,hi,lo,mid);
    if(a>=0){
        printf("the element was found at index: %i " ,a);
    }
    else printf("the element was not found");
}
