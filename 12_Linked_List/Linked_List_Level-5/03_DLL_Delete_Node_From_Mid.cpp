#include <iostream>
using namespace std;

// Definition of the Node class for the Doubly Linked List
class Node
{
public:
    int data;   // Variable to store the data of the node
    Node *prev; // Pointer to the previous node in the list
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize the node with data and set the prev and next pointers to NULL
    Node(int data)
    {
        this->data = data; // Set the data for the node
        this->prev = NULL; // Initialize the prev pointer to NULL
        this->next = NULL; // Initialize the next pointer to NULL
    }
};

// Function to delete a node from a specific position in a doubly linked list
void deleteNodeFromMid(Node *&head, int position)
{
    // If the linked list is empty, there is no node to delete.
    if (head == NULL)
    {
        cout << "Linked List does not exist, can't delete node." << endl;
        return;
    }
    else
    {
        // If the position is 1, we need to delete the head node
        if (position == 1)
        {
            // Check if there is only one node in the list
            if (head->next == NULL)
            {
                delete head; // Delete the single node in the list
                head = NULL; // Set head to NULL since the list is now empty
            }
            // If the list has more than one node
            else
            {
                Node *temp = head; // Store the current head node in a temporary pointer for deletion
                head = temp->next; // Move the head pointer to the next node in the list

                // After moving the head pointer, set the prev pointer of the new head to NULL
                head->prev = NULL; // The new head node should not have a previous node
                delete temp;       // Delete the old head node to free the allocated memory
            }
        }
        else
        {
            // If the position is not 1, traverse the list to find the node at the given position
            Node *curr = head; // Pointer to traverse the list, initially set to head
            Node *prev = NULL; // Pointer to keep track of the previous node

            // Traverse the list to find the node at the specified position
            while (position != 1)
            {
                prev = curr;       // Move the previous pointer to the current node.
                curr = curr->next; // Move the current pointer to the next node.
                position--;        // Decrement the position to move towards the target node
            }

            // `curr` now points to the node to be deleted, Store the next node in a temporary pointer
            Node *next = curr->next;

            // Check if the node to be deleted is the last node
            if (curr->next == NULL)
            {
                // The node to be deleted is the tail node
                prev->next = NULL; // Update the previous node's next pointer to NULL
                delete curr;       // Delete the tail node to free its memory
            }
            else
            {
                // The node to be deleted is neither the head nor the tail
                prev->next = next; // Update the previous node's next pointer to skip the current node
                next->prev = prev; // Update the next node's previous pointer to point to the previous node
                delete curr;       // Delete the current node to free its memory
            }
        }
    }
}

// Function to print all elements of the Doubly Linked List starting from the head node
void printDLL(Node *head)
{
    Node *temp = head; // Temporary pointer to traverse the linked list

    // Traverse the list until the end is reached (i.e., temp becomes NULL)
    while (temp)
    {
        cout << temp->data << " -> "; // Print the data of the current node
        temp = temp->next;            // Move to the next node in the list
    }
    cout << endl; // Print a newline character at the end of the list
}

int main()
{
    // Initialize an array of integers.
    int array[] = {1, 2, 3, 4, 5};

    // Calculate the size of the array.
    int size = sizeof(array) / sizeof(int);

    Node *head = NULL; // Pointer to the head of the linked list, initialized to NULL
    Node *tail = NULL; // Pointer to the tail of the linked list, initialized to NULL
    int position = 3;  // Position of the node to be deleted from the linked list

    // Loop through the array and create the linked list.
    for (int i = 0; i < size; i++)
    {
        // If the linked list is empty (head is NULL), create the first node
        if (head == NULL)
        {
            head = new Node(array[i]); // Create a new node with the current array element and set it as the head
            tail = head;               // Since this is the only node, head and tail both point to this node
        }
        // If the linked list is not empty, create a new node and insert it at the end of the list
        else
        {
            Node *temp = new Node(array[i]); // Create a new node with the current array element
            tail->next = temp;               // Link the current tail node's next pointer to the new node
            temp->prev = tail;               // Link the new node's prev pointer to the current tail node
            tail = temp;                     // Update the tail to point to the new node
        }
    }

    // Print the linked list before deletion.
    cout << "Linked List before deletion: " << endl;
    printDLL(head);
    cout << endl;

    // Delete the node from the head of the linked list.
    deleteNodeFromMid(head, position);

    // Print the linked list after deletion.
    cout << "Linked List after deletion: " << endl;
    printDLL(head);
    cout << endl;

    return 0;
}
