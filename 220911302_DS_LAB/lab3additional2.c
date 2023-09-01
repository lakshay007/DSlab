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
char topp(){
    return stack[top];
}
int main(){
    char str[20];
    gets(str);
    for(int i = 0;i<strlen(str);i++){
        if((str[i]== '{') || (str[i]== '(') || (str[i]== '[')) push(str[i]);
        else if((str[i] == '}' && topp()!= '{') || (str[i] == ')' && topp()!= '(') || (str[i] == ']' && topp()!= '[')){
            printf("not valid"); exit(0);
        }
        else pop();
    }
    if(top==-1){
        printf("valid");
    }
    else{
        printf("not valid");
    }

}
