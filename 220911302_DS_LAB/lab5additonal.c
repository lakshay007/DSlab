#include<stdio.h>
#define SIZE 20
int stack[SIZE];
int stack1[SIZE];
int top = -1;
int top1 = -1;
void enqueue(int n){
    if(top == SIZE -1){
        printf("overflow"); return;
    }
    stack[++top] = n;
}
void dequeue(){
    if(top==-1){printf("underflow");return;}

    while(top!=-1){
        stack1[++top1] = stack[top--];
    }
    int n = stack1[top1];
    --top1;
    while(top1!=-1){
        stack[++top] = stack1[top1--];
    }
    printf("%d\n",n);

}
int main(){
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}
