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

void deleteFromTail(Node *&head)
{
    // If the linked list is empty, there is no node to delete.
    if (head == NULL)
    {
        cout << "Linked List does not exist, can't delete node." << endl;
        return;
    }
    else
    {
        // Case 1: If the linked list has only one node.
        if (head->next == NULL)
        {
            Node *temp = head; // Save the head node in a temporary pointer.
            delete temp;       // Delete the only node.
            head = NULL;       // Set the head to NULL as the list is now empty.
        }
        // Case 2: If the linked list has more than one node.
        else
        {
            Node *curr = head; // Initialize the current pointer to the head.
            Node *prev = NULL; // Initialize the previous pointer to NULL.

            // Traverse the list until you reach the last node.
            while (curr->next != NULL)
            {
                prev = curr;       // Move the previous pointer to the current node.
                curr = curr->next; // Move the current pointer to the next node.
            }
            // At this point, curr points to the last node and prev points to the second last node
            delete curr;       // Delete the last node.
            prev->next = NULL; // Set the next pointer of the second-to-last node to NULL.
        }
    }
}

int main()
{
    int array[] = {2, 4, 6, 8, 10};         // Initialize an array of integers
    int size = sizeof(array) / sizeof(int); // Calculate the number of elements in the array

    Node *head = NULL; // Initialize the head of the linked list to NULL
    Node *tail = NULL; // Initialize the tail of the linked list to NULL

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

    // Print the linked list before deletion
    cout << "Linked List before deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    // Delete the last node (tail) from the linked list
    deleteFromTail(head);

    // Print the linked list after deletion
    cout << "Linked List after deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}
