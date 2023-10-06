#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** merged, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*merged == NULL) {
        *merged = newNode;
    } else {
        struct Node* current = *merged;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* mergeSortedLists(struct Node* X, struct Node* Y) {
    struct Node* merged = NULL;

    while (X != NULL && Y != NULL) {
        if (X->data < Y->data) {
            insertEnd(&merged, X->data);
            X = X->next;
        } else {
            insertEnd(&merged, Y->data);
            Y = Y->next;
        }
    }

    while (X != NULL) {
        insertEnd(&merged, X->data);
        X = X->next;
    }

    while (Y != NULL) {
        insertEnd(&merged, Y->data);
        Y = Y->next;
    }

    return merged;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* X = NULL;
    struct Node* Y = NULL;

    insertEnd(&X, 1);
    insertEnd(&X, 3);
    insertEnd(&X, 5);

    insertEnd(&Y, 2);
    insertEnd(&Y, 4);

struct Node* Z = mergeSortedLists(X, Y);

printList(Z);

free(X);

free(Y);

free(Z);

return 0;
}
