#include <stdio.h>
#include <iostream>

typedef struct Node {
    int data;
    Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createList() {
    List *new_list = new List;
    new_list->head = NULL;
    return new_list;
}

Node *createNode(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

List *addToList(List *list, int data) {
    Node *current_node = list->head;
    Node *last_node = NULL;
    if(current_node == NULL) {
        list->head = createNode(data);
    } else {
        while (current_node != NULL) {
            last_node = current_node;
            current_node = current_node->next;
        }
        last_node->next = createNode(data);
    }
    return list;
}

void printList(List *list) {
    Node *current = list->head;
    printf("Linked list Elements: ");

    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void cleanList(List *list) {
    Node *current_node = list->head;
    Node *last_node = NULL;

    if(current_node != NULL) {
        while (current_node != NULL) {
            last_node = current_node;
            current_node = current_node->next;
            last_node->next = NULL;
            delete last_node;
        }
    }
}

void expList(List *list, int iterador, int length) {
    int j = iterador;

    for (int i = 1; i <= length; i++) {
        j = i*iterador;
        addToList(list, j);
    }
}

int main() {
    List *main_list = createList();

    expList(main_list, 3, 10);

    printList(main_list);

    while (main_list != NULL) {
        Node *current_node = main_list->head;
        Node *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }


    return 0;
}
