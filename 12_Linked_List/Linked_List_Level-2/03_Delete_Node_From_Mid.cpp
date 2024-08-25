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
            Node *temp = head; // Store the current head node in a temporary pointer
            head = temp->next; // Update head to point to the next node
            delete temp;       // Delete the old head node
        }
        else
        {
            Node *curr = head; // Pointer to traverse the list, initially set to head
            Node *prev = NULL; // Pointer to keep track of the previous node

            // Traverse the list to find the node at the given position
            while (position != 1)
            {
                prev = curr;       // Move the previous pointer to the current node.
                curr = curr->next; // Move the current pointer to the next node.
                position--;        // Decrement position
            }

            // After exiting the loop, curr points to the node to be deleted
            // and prev points to the node before curr

            // Update the next pointer of the previous node to skip the node to be deleted
            prev->next = curr->next;
            delete curr; // Delete the node at the specified position
        }
    }
}

int main()
{
    int array[] = {10, 20, 30, 40, 50};     // Array of integers to be used for creating the linked list
    int size = sizeof(array) / sizeof(int); // Calculate the number of elements in the array

    Node *head = NULL; // Pointer to the head of the linked list, initialized to NULL
    Node *tail = NULL; // Pointer to the tail of the linked list, initialized to NULL
    int position = 3;  // Position of the node to be deleted from the linked list

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
            // Create a new node with the current array element add it to the end of the list
            Node *temp = new Node(array[i]);

            // Link the current tail to the new node
            tail->next = temp;

            // Update the tail to point to the new node
            tail = temp;
        }
    }

    // Print the linked list before any deletion
    cout << "Linked List before deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    // Delete the node at the specified position from the linked list
    deleteNodeFromMid(head, position);

    // Print the linked list after the deletion
    cout << "Linked List after deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}
