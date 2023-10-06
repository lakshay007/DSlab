#include<stdio.h>
#include<stdlib.h>
struct poly{
    int coef;
    int expo;
    struct poly *next;
};
typedef struct poly* POLY;
POLY head1 = NULL;
POLY head2 = NULL;
POLY head3 = NULL;
POLY createnode(int coef, int expo){
    POLY newnode = (POLY)malloc(sizeof(struct poly));
    newnode -> coef = coef;
    newnode -> expo = expo;
    newnode -> next = NULL;
    return newnode;
}
void insert( int coef, int expo) {
    POLY newNode = createnode(coef,expo);
    if (head3 == NULL) {
        head3 = newNode;
    } else {
        POLY current = head3;
        while (current->next != NULL) {
            current = current->next;
    }
        current->next = newNode;
    }
}
void insert1( int coef, int expo) {
    POLY newNode = createnode(coef,expo);
    if (head1 == NULL) {
        head1 = newNode;
    } else {
        POLY current = head1;
        while (current->next != NULL) {
            current = current->next;
    }
        current->next = newNode;
    }
}
void insert2( int coef, int expo) {
    POLY newNode = createnode(coef,expo);
    if (head2 == NULL) {
        head2 = newNode;
    } else {
        POLY current = head2;
        while (current->next != NULL) {
            current = current->next;
    }
        current->next = newNode;
    }
}
void add(){
    POLY temp1 = head1;
    POLY temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
            if(temp1->expo == temp2->expo){
            int coef = temp1->coef + temp2->coef;
            insert(coef,temp1->expo);
            temp1 = temp1->next;
            temp2 = temp2->next;

            }
            else{
                if(temp1->expo>temp2->expo){
                    insert(temp1->coef,temp1->expo);
                    temp1 = temp1->next;
                }
                else{
                        insert(temp2->coef,temp2->expo);
                        temp2 = temp2->next;
            }
            }
    }
    if(temp1==NULL && temp2!=NULL){
        while(temp2!=NULL){
            insert(temp2->coef,temp2->expo);
            temp2=temp2->next;
        }
    }
    if(temp2==NULL && temp1!=NULL){
        while(temp1!=NULL){
            insert(temp1->coef,temp1->expo);
            temp1=temp1->next;
        }
    }

}
void print(){
    POLY temp = head3;
    while(temp!=NULL){
            if(temp->next==NULL){
                    printf("%dx^%d", temp->coef, temp->expo);
            return;

            }
            printf("%dx^%d+", temp->coef, temp->expo);
        temp = temp->next;
    }
}
int main(){
    insert1(4,3);
    insert1(3,2);
    insert1(3,1);
    insert2(2,3);
    insert2(2,2);

    add();
    print();

}
