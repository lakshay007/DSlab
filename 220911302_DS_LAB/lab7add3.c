#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* list3 = NULL;
    struct Node* current1 = list1;
    struct Node* current2 = list2;

    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            insertEnd(&list3, current1->data);
            current1 = current1->next;
        }

        if (current2 != NULL) {
            insertEnd(&list3, current2->data);
            current2 = current2->next;
        }
    }

    return list3;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);

    insertEnd(&list2, 4);
    insertEnd(&list2, 5);
    insertEnd(&list2, 6);

    struct Node* list3 = mergeLists(list1, list2);

    printList(list3);

    free(list1);
    free(list2);
    free(list3);

    return 0;
}
