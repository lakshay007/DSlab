#include<stdio.h>
#include<stdlib.h>
int main(){
    char str1[20],str2[20];
    gets(str1);
    gets(str2);
    printf("please enter a position:");
    int n; scanf("%d" , &n);
    int len1 = 0;
    for(int i = 0;str1[i]!='\0';i++){
        len1++;
    }
    int len2 = 0;
    for(int i = 0;str2[i]!='\0';i++){
        len2++;
    }
    char str3[20];
    int j = 0;
    for(int i = n-1;str1[i]!='\0';i++ ){
        str3[j] = str1[i];j++;
    }
    int k = 0;
    for(int i = n-1;i<n+len2;i++){
        str1[i] = str2[k];k++;
    }
    int l = 0;
    for(int i = n+len2-1;i<len1+len2;i++){
        str1[i] = str3[l];l++;
    }
    str1[len1+len2] = '\0';
    puts(str1);

}
