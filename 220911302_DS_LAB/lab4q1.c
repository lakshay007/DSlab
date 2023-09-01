#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[5];
int front = -1;
int rear = -1;
int isfull(){
    if((rear+1)% MAX == front) return 1;
    return 0;
}
int isempty(){
    if(front == -1 && rear ==front) return 1;
    return 0;
}
void enqueue(int data){
    if(isfull()){printf("the queue is full \n"); return;}
    if(front == -1) front+=1;
     rear = (rear + 1)%MAX;
    queue[rear] = data;

}
void dequeue(){
    if(isempty()){
        printf("the queue is empty \n"); return;
    }
    if(front==rear){
        printf("the deleted element is: %d \n", queue[front]);
        front  = -1; rear = -1;
    }
    else{
        printf("the deleted element is: %d \n", queue[front]);

        front = (front +1) % MAX;


     }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(1);
    enqueue(2);
    dequeue();



}
