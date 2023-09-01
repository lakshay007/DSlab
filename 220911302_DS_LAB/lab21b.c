#include<stdio.h>
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
    int j = 0;
    for(int i = len1;i<len2+len1;i++){
        str1[i] = str2[j];j++;
    }
    str1[len1+len2] = '\0';
    puts(str1);

}
