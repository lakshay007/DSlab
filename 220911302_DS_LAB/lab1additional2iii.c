#include<stdio.h>
#include<stdlib.h>
int mul(int a, int b,int temp){
    if(b==1) return a;
     a = a + temp;
    return mul(a,--b,temp);
}
int main(){
    int a,b;
    scanf("%i %i" , &a, &b);
    int temp = a;
    printf("\n %i" , mul(a,b,temp));
}
