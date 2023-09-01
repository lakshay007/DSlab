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
int main(){
    char str[50];
    gets(str);
    for(int i = 0;i<strlen(str);i++){
        push(str[i]);
    }
    for(int i = 0;i<strlen(str);i++){
        if(pop()!=str[i]){
            printf("not a palindrome"); exit(0);
        }
    }
    printf("palindrome");


}
