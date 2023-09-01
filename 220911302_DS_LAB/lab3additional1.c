#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top[50];
int stack[50];
int bound[50];
void initialize(int n){
    for(int i = 0;i<n;i++){
        top[i] = bound[i] = (50/n)*i-1;
    }

}
void push(int data, int i){
    if(top[i] == bound[i+1]){
        printf("overflow");exit(0);
    }
    stack[++top[i]] = data;
}
int pop(int i){
    if(top[i] < bound[i]){
        printf("underflow");exit(0);
    }
    return stack[top[i]--];
}
int topp(int i){
    return stack[top[i]];
}

int main(){
    int n;
    scanf("%d", &n);
    initialize(n);
    push(4,0);
    push(3,0);
    push(6,0);
    push(8,0);
    push(3,2);
    printf("%d\n", pop(0));
    printf("%d\n", topp(2));



}
