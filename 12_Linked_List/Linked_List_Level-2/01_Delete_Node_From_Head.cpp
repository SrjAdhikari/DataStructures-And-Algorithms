#include <iostream>
using namespace std;

// Definition of the Node class, which represents an element in the linked list.
class Node
{
public:
    int data;   // Variable to store the data of the node
    Node *next; // Pointer to the next node in the linked list

    // Constructor to initialize the node with data and set the next pointer to NULL.
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print all elements of the linked list
void printLinkedList(Node *head)
{
    Node *temp = head; // Start from the head of the list

    // Traverse the linked list until the end
    while (temp)
    {
        cout << temp->data << " -> "; // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    cout << endl;
}

// Function to delete the head node from the linked list.
void deleteFromHead(Node *&head)
{
    // Check if the linked list is empty.
    if (head == NULL)
    {
        // If the list is empty, print a message and return.
        cout << "Linked List does not exist, can't delete node.";
        return;
    }
    else
    {
        // If the list is not empty:
        Node *temp = head; // Store the current head node in a temporary pointer.
        head = temp->next; // Move the head pointer to the next node.
        delete temp;       // Delete the old head node to free the memory.
    }
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
        // If the list is empty (head is NULL), create the first node.
        if (head == NULL)
        {
            head = new Node(array[i]); // Create the first node with the current array element.
            tail = head;               // Set the tail to the first node as well.
        }
        else
        {
            // Create a new node with the current array element.
            Node *temp = new Node(array[i]);

            // Link the new node to the current tail.
            tail->next = temp;

            // Move the tail pointer to the new node.
            tail = temp;
        }
    }

    // Print the linked list before deletion.
    cout << "Linked List before deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    // Delete the node from the head of the linked list.
    deleteFromHead(head);

    // Print the linked list after deletion.
    cout << "Linked List after deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}
