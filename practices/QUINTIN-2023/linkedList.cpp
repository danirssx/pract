#include <stdio.h>
#include <iostream>
#include <cstdlib> // Include the necessary header for rand() and srand()

typedef struct Node {
    int data;
    Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

List *createList() {
    List *new_list = new List;
    if(new_list) {
        new_list->head = NULL;
    }
    return new_list;

}

Node *createNode(int data) {
    Node *new_node = new Node;
    if(new_node) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Functions

List *addToList(List *list, int data) {
    Node *current_node = list->head;
    Node *prev_node = NULL;

    // In the last position
    if(current_node == NULL) { // In case it didn't find any element in the head
        list->head = createNode(data);
    } else {
        while(current_node != NULL) { // here starts a while that will goe to the last element
            prev_node = current_node;
            current_node = current_node->next;
        }
        prev_node->next = createNode(data); // create the new node next to the prev-node
    }

    // In the first position 
    return list;
}

// Add an element in the beggining of the list

List *addToListBeggining(List *list, int data) {
    Node *current_node = list->head;

    if(current_node == NULL) {
        list->head = createNode(data);
    } else {
        list->head = createNode(data);
        list->head->next = current_node;
    }
    return list;
}

// Add an element in an specific position 1.3)

List *addToListSpecific(List *list, int data, int target) {
    Node *current_node = list->head;
    Node *prev_node = NULL;
    bool cond = false;

    if(current_node == NULL) { // En caso de que no haya ningun elemento
        list->head = createNode(data);
        printf("No hay ningun element en la lista que cumple la condicion");
    } else {
        while(current_node->next != NULL) {
            prev_node = current_node;
            current_node = current_node->next;

            if(current_node->data == target) { // Coincide el elemento y por lo tanto lo agrego en la siguiente posicion
                prev_node = prev_node->next;
                current_node = current_node->next;

                prev_node->next = createNode(data);
                prev_node->next->next = current_node;

                cond = true;

                printf("%d => ", prev_node->data);
            };
        }

        if(!cond) {
            prev_node = current_node;
            prev_node->next = createNode(data);
            printf("No coincide con ningun elemento de la lista por lo que se agregara al final\n\n");
        }
    }
    return list;
}

// Iteration to add new nodes in sequence

void seqList(List *list, int data, int length, bool randomize) {
    int value = data;

    if(randomize) {
        for(int i = 1; i <= length; i++) {
         int randomInRange = 1 + rand() % (10 - 1 + 1);
         addToList(list, randomInRange);
        }
    } else {
        for(int i = 1; i <= length; i++) {
           value = data*i;            
            addToList(list, value);
        }
        
    }
}

// Print the list

void printList(List *list) {
    Node *current = list->head;
    printf("Linked list elements: ");

    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    List *main_list = createList();

    system("cls || clear");

    // Call the list
    seqList(main_list, 1, 5, true);
    printList(main_list);

    // NULL value
    scanf("%*s");
    printf("\n");

    // add new stuff
    addToListSpecific(main_list, 8, 6);
    printList(main_list);

    while (main_list->head != NULL) {
        Node *current_node = main_list->head;
        main_list->head = current_node->next; // Update the head of the list.
        free(current_node); // Free the node.
    }
    return 0;
}

