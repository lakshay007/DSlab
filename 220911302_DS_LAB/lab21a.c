#include<stdio.h>
int main(){
    char str[20];
    gets(str);
    int len = 0;
    for(int i = 0;str[i]!='\0';i++){
        len++;
    }
    printf("the length is: %d" , len);

}
