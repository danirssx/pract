#include <stdio.h>
#include <iostream>


// Declare the the Node and the List

typedef struct Node {
    int data;
    Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

// Create the list and the Nodes

List *createList() {
    List *new_list = new List;
    new_list->head = NULL;
    return new_list;
}

Node *createNode(int data) {
    Node *new_node = new Node;
    if (new_node) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Functions to interact with it

List *addToList(List *list, int data) {
    Node *current_node = list->head;
    Node *prev_node = NULL;
    if(current_node == NULL)//primer nodo en existir
     {
        list->head = createNode(data);
    } else {
        while (current_node != NULL) {
            prev_node = current_node;
            current_node = current_node->next;
        }
        prev_node->next = createNode(data);
    }
    return list;
}

List *deleteNode(List *list, int element) {
    Node *current_node = list->head; //valor de primer nodo
    Node *prev_node = NULL;

     if(current_node->data == element) {
        printf("TRUE\n");
        list->head = list->head->next;
        return list;
     };

     while(current_node != NULL) {
        prev_node = current_node;
        current_node = current_node->next;

        if(current_node->data == element) 
        {
            prev_node->next = current_node->next;
        }
        printf("%d => ", prev_node);
     }
    printf("lo siento pa no consegui nada");
    return list;
}


// Interaction with the list

void printList(List *list) {
    Node *current = list->head;
    printf("Linked list Elements: ");

    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void expList(List *list, int iterador, int length) {
    int j = iterador;

    for (int i = 1; i <= length; i++) {
        j = i*iterador;
        addToList(list, j);
    }
}

// Main function

int main() {
    List *main_list = createList();

    // Create the list
    expList(main_list, 3, 5);
    expList(main_list, 3, 5);

    deleteNode(main_list, 6);

    printList(main_list);

    while (main_list->head != NULL) {
        Node *current_node = main_list->head;
        Node *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }


    return 0;
}