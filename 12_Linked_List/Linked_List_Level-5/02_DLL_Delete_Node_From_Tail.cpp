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

// Function to delete the tail node from the doubly linked list
void deleteFromTail(Node *&head)
{
    // Check if the linked list is empty
    if (head == NULL)
    {
        // If the list is empty, print a message indicating that no deletion can be performed
        cout << "Linked List does not exist, can't delete node.";

        // Return from the function as there are no nodes to delete
        return;
    }
    else
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
            Node *curr = head; // Initialize a pointer to traverse the list, starting from the head

            // Traverse the list to find the tail node, until the last node is reached
            while (curr->next)
            {
                curr = curr->next; // Move to the next node in the list
            }

            // At this point, curr points to the tail node
            // Update the previous node's next pointer to NULL to remove the tail reference
            curr->prev->next = NULL;

            // Delete the tail node to free its memory
            delete curr;
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

    // Initialize head and tail pointers to NULL, representing an empty linked list.
    Node *head = NULL;
    Node *tail = NULL;

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
    deleteFromTail(head);

    // Print the linked list after deletion.
    cout << "Linked List after deletion: " << endl;
    printDLL(head);
    cout << endl;

    return 0;
}
