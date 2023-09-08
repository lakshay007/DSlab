#include<stdio.h>
#include<string.h>
char a[50];
void rev(char a[]){
int n = strlen(a);
for(int i = 0;i<n/2;i++){
char temp = a[i];
a[i] = a[n-i-1];
a[n-i-1] = temp;
}
}
void replace(char a[]){
for(int i = 0;i<strlen(a);i++){
if(a[i] == '(') a[i] = ')';
else if(a[i] == ')') a[i] = '(';
}
}
char stack[50];
int top = -1;
void push(char data){
stack[++top] = data;
}
char pop(){
char el = stack[top];
top--;
return el;
}
char peek(){
return stack[top];
}
int isoperand(char data){
if((data>='a' && data<='z') || (data>='A' && data <='Z') || (data>='1' && data <='9')) return 1;
return 0;

}

int preced(char a){
if(a == '^') return 3;
if(a == '*' || a == '/') return 2;
if(a == '+' || a == '-') return 1;
return -1;
}
char res[50];
void func(char a[]){
char ans[50];
int j = -1;


for(int i = 0;i<strlen(a);i++){
if(isoperand(a[i])) res[++j] = a[i];
else if(a[i] == '(') push(a[i]);
else if(a[i] == ')'){
while(stack[top]!='(' && top!=-1) res[++j] = pop();
pop();
}
else{
while(preced(a[i])<=preced(stack[top]) && top!=-1 ){
res[++j] = pop();
}
push(a[i]);
}


}
while(top!=-1){
res[++j] = pop();
}
res[strlen(a)] = '\0';




}
int main(){
gets(a);
rev(a);
replace(a);
func(a);
rev(res);
printf("%s", res);



}
