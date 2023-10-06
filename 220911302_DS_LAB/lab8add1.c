#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node* getUnion(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp = NULL;
    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL && list2 != NULL) {
            if (list1->data < list2->data) {
                insertAtEnd(&result, list1->data);
                list1 = list1->next;
            } else if (list1->data > list2->data) {
                insertAtEnd(&result, list2->data);
                list2 = list2->next;
            } else {
                insertAtEnd(&result, list1->data);
                list1 = list1->next;
                list2 = list2->next;
            }
        } else if (list1 != NULL) {
            insertAtEnd(&result, list1->data);
            list1 = list1->next;
        } else if (list2 != NULL) {
            insertAtEnd(&result, list2->data);
            list2 = list2->next;
        }
    }
    return result;
}

Node* getIntersection(Node* list1, Node* list2) {
    Node* result = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else {
            insertAtEnd(&result, list1->data);
            list1 = list1->next;
            list2 = list2->next;
        }
    }
    return result;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 4);

    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    Node* unionList = getUnion(list1, list2);
    printf("Union: ");
    displayList(unionList);

    Node* intersectionList = getIntersection(list1, list2);
    printf("Intersection: ");
    displayList(intersectionList);

    return 0;
}
