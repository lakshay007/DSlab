#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }
    insertEnd(&((*head)->next), data);
}

void traverseList(struct Node* current) {
    if (current == NULL) {
        return;
    }
    printf("%d -> ", current->data);
    traverseList(current->next);
}

void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    freeList(head);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);

    printf("Linked List: ");
    traverseList(head);
    printf("NULL\n");

    freeList(head);

    return 0;
}
