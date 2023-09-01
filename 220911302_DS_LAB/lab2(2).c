#include<stdio.h>
struct Student{
    char name[20];
    int roll; char grade;

};
void read(struct Student s[],int n){

    for(int i = 0;i<n;i++){
    printf("enter the name, rollno, grade of students \n");
    scanf("%s  %d %c", s[i].name , &s[i].roll, &s[i].grade );
    }
}
void print(struct Student s[],int n){
     printf("the data of the students is: \n");
     for(int i = 0;i<n;i++){
        printf("%s %d %c",s[i].name , s[i].roll, s[i].grade );
        printf("\n");
     }
}
void sort(struct Student s[],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-1;j++){
            if(s[j].roll>s[j+1].roll){
                struct Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}
int main(){
int n;
    printf("enter the number of students \n");
    scanf("%d", &n);
    struct Student s[n];
    read(s,n);
    sort(s,n);
    print(s,n);
}
