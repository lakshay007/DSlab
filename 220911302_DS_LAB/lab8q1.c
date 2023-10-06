#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node * NODE;
NODE head = NULL;
NODE createnode(int data){
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}
void insert( int data) {
    NODE newNode = createnode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        NODE current = head;
        while (current->next != NULL) {
            current = current->next;
    }
        current->next = newNode;
        newNode->prev = current;
    }

}
void insertbefore(int el, int data){
    NODE newnode = createnode(data);
    NODE temp = head;
    while(temp->next->data!=el){
        temp = temp->next;
    }
    temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;

}
void insertafter(int el, int data){
    NODE newnode = createnode(data);
    NODE temp = head;
    while(temp->data!=el){
        temp = temp->next;
    }
    temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
}
void delete( int data) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return ;
}
    NODE current = head;
    NODE previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
}
    if (current == NULL) {
        printf("Element not found in the linked list.\n");
        return;
}
    if (previous == NULL) {
        head = current->next;
    } else {
        current->next->prev = previous;
        previous->next = current->next;
}
    free(current);
    printf("Element deleted successfully.\n");

}
void rev(){
    NODE curr = head;
    NODE previous = NULL;
    NODE forw;
    while(curr!=NULL){
        forw = curr->next;
        curr->next = previous;
        curr->prev = forw;
        previous = curr;
        curr = forw;
    }
    head = previous;
    }

void print(NODE head){
    NODE temp = head;
    while(temp!=NULL){
            printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {

int choice, data;
while (1) {
printf("\n1. Insert an element at the end\n");
printf("2. insert an element after element\n");
printf("3. insert an element before element\n");
printf("4. Display the linked list\n");
printf("5. delete an element\n");
printf("6. reverse the list\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
    printf("Enter the element to insert: ");
    scanf("%d", &data);
     insert( data);
    break;
case 2:
    printf("Enter the element to insert and the element after which to insert: ");
    int el;
    scanf("%d %d", &data, &el);
    insertafter(el,data);
    break;
case 3:
    printf("Enter the element to insert and the element before which to insert: ");
    scanf("%d %d", &data, &el);
     insertbefore(el,data);
    break;


case 4:
    print(head);
    break;
case 5:
    printf("\n enter the element to be deleted\n");
    scanf("%d", &el);
     delete( el);
    break;
case 6:
    rev(); break;
case 7:
    exit(0);

}
}
return 0;
}
