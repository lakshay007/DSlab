#include<stdio.h>
#include<stdlib.h>
int main(){
    char str1[20],str2[20];
    gets(str1);
    gets(str2);
    int len1 = 0;
    for(int i = 0;str1[i]!='\0';i++){
        len1++;
    }
    int len2 = 0;
    for(int i = 0;str2[i]!='\0';i++){
        len2++;
    }
    int smallerlen = len1<len2?len1:len2;
    for(int i = 0;i<smallerlen;i++){
        if(str1[i]>str2[i]) {printf("string 1 is greater"); exit(0);}
        if(str1[i]<str2[i]) {printf("string 2 is greater"); exit(0);}
    }
    printf("both the strings are equal");
}
