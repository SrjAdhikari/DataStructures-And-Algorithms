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

// Recursive function to insert elements from an array at the tail of the linked list
Node *createDLLUsingRecursion(int arr[], int size, int index, Node *&tail)
{
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
    Node *head = NULL;                      // Initialize the head of the Doubly Linked List as NULL
    Node *tail = NULL;                      // Initialize the tail of the Doubly Linked List as NULL
    int array[] = {1, 2, 3, 4, 5};          // Array containing the elements to be inserted into the list
    int size = sizeof(array) / sizeof(int); // Calculate the size of the array

    // Use recursion to create a doubly linked list from the array with elements added at the tail
    head = createDLLUsingRecursion(array, size, 0, tail);

    // Print the resulting linked list
    cout << "Doubly Linked List created using recursion:" << endl;
    printDLL(head);

    return 0;
}