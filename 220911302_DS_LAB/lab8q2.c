#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void concatenateLists(struct Node** X1, struct Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
        return;
    }

    struct Node* current = *X1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = X2;
    X2->prev = current;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;

    X1 = createNode(1);
    X1->next = createNode(2);
    X1->next->prev = X1;
    X1->next->next = createNode(3);
    X1->next->next->prev = X1->next;

    X2 = createNode(4);
    X2->next = createNode(5);
    X2->next->prev = X2;

    concatenateLists(&X1, X2);

    printList(X1);

    return 0;
}

