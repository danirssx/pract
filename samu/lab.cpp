#include <iostream>
using namespace std;

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

// Add to list beginning
void push(Node **headRef, int data)
{

    Node *current = *headRef;

    // If list is empty
    if (current == NULL)
    {
        current = create_node(data);
        *headRef = current;
    }
    else
    {
        // Change the current head element for the new node
        current = create_node(data);
        current->next = *headRef;
        *headRef = current;
    }
}

// Delete last node of a list
int delete_last_node(Node **headRef)
{
    int x;
    Node *current = *headRef;
    Node *prev = NULL;

    // Check if list is not empty
    if (current == NULL)
    {
        cout << "List empty";
        return 0;
    }

    // Check if theres only one element
    if (current->next == NULL)
    {
        x = current->data;
        delete (current);
        *headRef = NULL; // Set head to NULL
    }
    else
    {

        while (current->next != NULL)
        {

            prev = current;
            current = current->next;
        }

        // If its the last element
        x = current->data;
        delete (current);
        prev->next = NULL; // Set the next del penultimate to NULL (making it the new last element)
    }
    return x;
}

// Print only the elements of the list with numbers > 10
void print_condition(Node *head)
{

    Node *current = head;

    while (current != NULL)
    {
        if (current->data > 10)
        {
            cout << "Data: " << current->data << ", ";

            if (current->next != NULL)
            {
                cout << "Next data: " << current->next->data;
            }
            else
            {
                cout << "Next: NULL";
            }
            cout << "\n";
        }

        current = current->next;
    }
}

void print_list(Node *head)
{

    Node *current = head;

    while (current != NULL)
    {
        cout << "Data: " << current->data << ", ";
        if (current->next != NULL)
        {
            cout << "Next data: " << current->next->data;
        }
        else
        {
            cout << "Next: NULL";
        }
        cout << "\n";
        current = current->next;
    }
}

int main(void)
{

    Node *head = NULL;

    int i;

    // Add 15 elments to the list
    for (i = 1; i <= 15; i++)
    {
        push(&head, i);
    }

    print_condition(head);
    delete_last_node(&head);
    print_list(head);
}