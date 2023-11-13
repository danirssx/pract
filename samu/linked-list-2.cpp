// #include <stdio.h>
// #include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

int delete_last_node(Node **headRef)
{

    int x;
    Node *current = *headRef;
    Node *prev = NULL;

    // If there's only one element
    if (current->next = NULL)
    {
        delete (current);
    }

    // If list is empty
    if (current == NULL)
    {
        cout << "Empty list";
        return 0;
    }
    else
    {

        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }

        x = current->data;
        current = prev;
        current->next = NULL;
    }

    return x;
}

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
    // If list is empty (create new node as head)
    if (current == NULL)
    {
        current = create_node(data);
        *headRef = current;
    }
    else
    {
        // If list is not empty
        current = create_node(data);
        current->next = *headRef;
        *headRef = current;
    }
}

// Add to list end
void append(Node **headRef, int data)
{

    Node *current = *headRef;
    Node *new_node = create_node(data);

    // If list empty
    if (current == NULL)
    {
        *headRef = new_node;
    }
    else
    {
        // Locate the last element
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node; // Append the new node at the end
    }
}

int delete_last(Node **headRef)
{
    int x;
    Node *current = *headRef;
    Node *prev = NULL;

    if (current == NULL)
    {
        cout << "Empty list, no node can be deleted";
        return 0;
    }

    // Only one element
    if (current->next == NULL)
    {
        x = current->data;
        delete (current);
        *headRef = NULL; // Set the head to NULL
    }
    else
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }

        x = current->data;
        delete (current);
        // current = prev;
        // current->next = NULL;
        prev->next = NULL;
    }

    return x;
}

void change_node_position(Node **headRef, int pos, int n)
{
    Node *current = *headRef;
    Node *prev = NULL;
    Node *node_to_move = NULL;
    Node *prev_node_to_move = NULL;
    bool found = false;
    int count = 0;

    // Check if list is empty
    if (current == NULL)
    {
        cout << 'Empty list, no operation can be made';
        return;
    }

    // Find the node to move and its previous node
    while (current->next != NULL && !found)
    {
        // Found the element to be moved
        if (count == pos)
        {
            // If it's the last node, append n new nodes
            if (current->next == NULL)
            {
                for (int i = 0; i < n; i++)
                {
                    append(&current, i);
                }
            }
            prev_node_to_move = prev;
            node_to_move = current;
            found = true;
        }

        prev = current;
        current = current->next;
        count++;
    }

    // If the position of the node to be moved is not found
    if (node_to_move == NULL)
    {
        cout << 'Position out of range';
        return;
    }

    // Remove the node to move from its old position
    if (prev_node_to_move != NULL)
    {
        prev_node_to_move->next = node_to_move->next;
    }
    else
    {
        *headRef = node_to_move->next; // If the node to be moved is the first node
    }

    // Move to new position
}

bool are_same_list(Node *l1, Node *l2)
{

    bool is_equal = false;

    while (l1 != NULL && l2 != NULL)
    {

        if (l1->data != l2->data)
        {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    // If both lists reached the end at the same time (while - with no different elements)
    if (l1 == NULL && l2 == NULL)
    {
        return true;
    }

    return false;
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

    push(&head, 15);
    push(&head, 8);
    push(&head, 25);

    append(&head, 30);
    // 25 8 15 30
    delete_last(&head);

    print_list(head);
    return 0;
}