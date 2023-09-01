#include<stdio.h>
#include<stdlib.h>
int main(){
    char str1[20],str2[20];
    gets(str1);
     printf("please enter another string to delete \n");
    gets(str2);

    int len1 = 0;
    for(int i = 0;str1[i]!='\0';i++){
        len1++;
    }
    int len2 = 0;
    for(int i = 0;str2[i]!='\0';i++){
        len2++;
    }
    int ptr1,ptr2,j;
    for(int i = 0;i<len1-1;i++){
            int flag = 1;
            int k = 0;
        for( j = i;j<len2+i;j++){
                if(str2[k]!=str1[j]){flag = 0;break;}
                k++;

        }
        if(flag){
            ptr1 = i; ptr2 = j-1; break;
        }
    }
    for(int i = ptr2+1;i<len1;i++){
        str1[ptr1] = str1[i];
        ptr1++;
    }
    str1[len1-len2] = '\0';
    puts(str1);

}
