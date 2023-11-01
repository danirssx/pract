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

    if(current_node->data == target) { // En caso de que tenga que sustituir en la 1ra posicion
        prev_node = current_node;
        current_node = current_node->next;

        prev_node->next = createNode(data);
        prev_node->next->next = current_node;
    }

    if(current_node == NULL) { // En caso de que no haya ningun elemento
        list->head = createNode(data);
        printf("No hay ningun element en la lista que cumple la condicion");
    } else {
        while(current_node->next != NULL) {
            prev_node = current_node;
            current_node = current_node->next;

            if(current_node->data == target) { // Coincide el elemento y por lo tanto lo agrego en la siguiente posicion
                cond = true;


                if(current_node->next != NULL) {
                prev_node = prev_node->next;
                current_node = current_node->next;

                prev_node->next = createNode(data);
                prev_node->next->next = current_node;

                } else { // En caso de que sea la ultima posicion
                    prev_node = current_node;
                    prev_node->next = createNode(data);
                }

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

// Delete an element from a list

enum class DeleteOption {
    first,
    last,
    everyone
};

List *deleteNode(List *list, int target, DeleteOption option) {
    Node *current_node = list->head;
    Node *prev_node = NULL;
    
    if(option != DeleteOption::last) { // Delete the first element in case it's necessary
        if(current_node->data == target) {
            list->head = list->head->next;
        }

        if(option == DeleteOption::first) { // En caso de que solo quiera eliminar el primer elemento evitar la iteracion
            return list;
        }
    };


    if(option == DeleteOption::first || option == DeleteOption::everyone) {
        while(current_node->next != NULL) {
            prev_node = current_node;
            current_node = current_node->next;

            if(current_node->data == target) {
                prev_node->next = current_node->next;

                if(option == DeleteOption::first) {
                    return list;
                    }
                } 
        }
    }

    if(option == DeleteOption::last) {
        int iterador = 0; // Voy a contar la cantidad de veces en las que encuentro el valor
        int buscador = 0; 

        while(current_node->next != NULL) {
            prev_node = current_node;
            current_node = current_node->next;

            if(current_node->data == target) {
               iterador = iterador + 1;

            }
        }

        // Regreso los valores
        current_node = list->head;
        prev_node = NULL;

        printf("%d Dani\n ", iterador);

        while(current_node->next != NULL) {
            prev_node = current_node;
            current_node = current_node->next;

            if(current_node->data == target) {
                buscador = buscador + 1;
                if(iterador == buscador) {
                    prev_node->next = current_node->next;
                    return list;
                }
            }
        }
    }
    
    
    return list;
};

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
    seqList(main_list, 2, 3, false);
    seqList(main_list, 2, 3, false);
    seqList(main_list, 2, 3, false);

    printList(main_list);

    // NULL value
    scanf("%*s");
    printf("\n");

    // Delete element
    deleteNode(main_list, 2, DeleteOption::last);

    printList(main_list);


    while (main_list->head != NULL) {
        Node *current_node = main_list->head;
        main_list->head = current_node->next; // Update the head of the list.
        free(current_node); // Free the node.
    }
    return 0;
}

