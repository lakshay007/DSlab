#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[50];
int top = -1;
void push(char data){
    stack[++top] = data;
}
char pop(){
    char el = stack[top];
    --top;
    return el;

}
void convert(int n, int base){
    if(n==0){
        printf("0\n"); return;
    }
    int ind = 0;
    char str[] = "0123456789ABCDEF";
    char ans[50];
    while(n>0){
        int rem = n%base;
         push(str[rem]);
        n = n/base;
    }
    while(top!=-1) printf("%c", pop());

}
int main(){
    int n, base;
    scanf("%d %d" , &n , &base);
    convert(n,base);

}
