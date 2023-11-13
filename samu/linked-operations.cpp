#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node *create_node(int data)
{
    Node *new_node = new Node;

    if (new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
    }

    return new_node;
}

// Add an element to the beginning of the list (head)
Node *add_to_list_beginning(Node **headRef, int data)
{
    Node *current = *headRef;

    //  If list is empty (create node de una)
    if (current == NULL)
    {
        current = create_node(data);
        *headRef = current;
    }
    // If not empty, change head element to new node
    else
    {
        current = create_node(data);
        current->next = *headRef;
        *headRef = current;
    }
    return current;
}

// Add an element at the end of the list
void add_to_list_end(Node **headRef, int data)
{

    Node *current = *headRef;

    // If list is empty (create node de una)
    if (current == NULL)
    {
        current = create_node(data);
        *headRef = current;
    }
    else
    {
        // Locate last node
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = create_node(data); // Add the new node as the last element of the list
    }
}

// Add an element after a specific element
void add_to_list_after_element(Node **headRef, int data, int target)
{
    Node *current = *headRef;
    Node *prev = NULL;

    bool found = false;

    // Elemento target en 1era posicion
    if (current->data == target)
    {
        prev = current;
        current = current->next;

        prev->next = create_node(data);
        prev->next->next = current;
    }

    // Empty list
    if (current == NULL)
    {
        current = create_node(data);
        *headRef = current;
        printf("No hay ningun elemento en la lista con el valor: %d", target);
    }
    else
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;

            if (current->data == target)
            {
                found = true;

                // If it's not the last element
                if (current->next != NULL)
                {
                    prev = prev->next;
                    current = current->next;

                    prev->next = create_node(data);
                    prev->next->next = current;
                }
                // If the target is in last position
            }
            else
            {
                prev->next = create_node(data);
                prev->next->next = current;
            }
            printf("%d => ", prev->data);
        }

        if (!found)
        {
            current->next = create_node(data);
            printf("No coincide con ningun elemento de la lista, se agregará al final");
        }
    }
}

void print_list(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("Data: %d, ", current->data);
        if (current->next != NULL)
        {
            printf("Next Data: %d", current->next->data);
        }
        else
        {
            printf("Next: NULL");
        }
        printf("\n");
        current = current->next;
    }
}

void delete_node_by_position(Node **headRef, int pos)
{

    if (pos <= 0)
    {
        return;
    }

    Node *current = *headRef;
    Node *prev = NULL;
    int count = 0;

    while (current != NULL)
    {

        if (count == pos)
        {
            if (prev == NULL)
            {
                // If deleting head node, update head
                current = current->next;
                *headRef = current;
            }
            else
            {
                prev->next = current->next;
            }
        }
        prev = current;
        current = current->next;
        count++;
    }
    if (pos > count)
    {
        printf("Position out of the bounds of the list, list elements: %d and position is: %d , not element deleted\n", count, pos);
    }
}

void delete_by_target(Node **headRef, int target)
{
    Node *current = *headRef;
    Node *prev = NULL;
    int count = 0;
    bool found = false;

    if (current == NULL)
    {
        printf("Empty list, no element found");
        return;
    }

    // Check if the head node matches the target value
    if (current->data == target)
    {
        *headRef = current->next; // Update the head to the next node
        // Free the memory of the deleted node
        found = true;
    }
    else
    {

        while (current->next != NULL and !found)
        {
            prev = current;
            current = current->next;

            if (current->data == target)
            {
                prev->next = current->next;
                current = current->next;
                // free(current); // Free the memory
                found = true;
            }
        }
        if (!found)
        {
            printf("No element %d in list :( \n", target);
        }
    }
}

int main(void)
{

    Node *head = NULL; // Inicializar head en null (lista vacia)

    // Add elements to list
    add_to_list_end(&head, 25);
    add_to_list_end(&head, 8);

    add_to_list_end(&head, 30);
    add_to_list_end(&head, 26);

    add_to_list_beginning(&head, 18);
    // List rn 18, 25, 8, 30, 26
    delete_node_by_position(&head, 4); // Deletes 26
    delete_by_target(&head, 18);       // Deletes 18

    print_list(head);

    return 0;
}
