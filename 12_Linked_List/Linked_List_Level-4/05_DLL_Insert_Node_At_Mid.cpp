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
        this->data = data; // Set the data for the node to the provided value
        this->prev = NULL; // Initialize the prev pointer to NULL
        this->next = NULL; // Initialize the next pointer to NULL
    }
};

// Function to create a Doubly Linked List from an array
void createDLL(Node *&head, Node *&tail, int arr[], int size)
{
    // Iterate through each element of the array
    for (int i = 0; i < size; i++)
    {
        // Check if the list is empty by checking if the head is NULL
        if (head == NULL)
        {
            // Create a new node with the current array element and set it as both head and tail
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            // If the list is not empty, create a new node for the next element in the array
            Node *temp = new Node(arr[i]);

            // Set the next pointer of the current tail to the new node
            tail->next = temp;

            // Set the previous pointer of the new node to the current tail
            temp->prev = tail;

            // Update the tail to be the new node
            tail = temp;
        }
    }
}

// Function to insert a new node with given data at a specific position in the Doubly Linked List
void insertAtMid(Node *&head, int position, int data)
{
    // Check if the position is 0 (i.e., insert at the beginning of the list)
    if (position == 0)
    {
        // If the list is empty, create a new node and set it as the head
        if (head == NULL)
        {
            head = new Node(data); // Allocate memory for a new node and initialize it with the given data
        }
        else
        {
            // Create a new node with the given data
            Node *temp = new Node(data);

            // Set the new node's next pointer to the current head
            temp->next = head;

            // Set the current head's prev pointer to the new node
            head->prev = temp;

            // Update the head to be the new node
            head = temp;
        }
    }
    else
    {
        // For inserting at positions other than the beginning
        Node *curr = head; // Initialize a pointer to traverse the list starting from the head
        Node *prev = NULL; // Initialize a pointer to keep track of the previous node

        // Traverse the list to find the node just before the insertion position
        while (position != 1)
        {
            prev = curr;       // Update prev to be the current node
            curr = curr->next; // Move curr to the next node in the list
            position--;        // Decrement the position counter
        }

        // Check if we are inserting at the end of the list
        if (curr->next == NULL)
        {
            // Create a new node with the given data
            Node *temp = new Node(data);

            // Set the new node's prev pointer to the current node
            temp->prev = curr;

            // Make the current node's next pointer point to the new node
            curr->next = temp;
        }
        else
        {
            // Create a new node with the given data
            Node *temp = new Node(data);

            // Make the previous node's next pointer point to the new node
            prev->next = temp;

            // Set the new node's prev pointer to the previous node
            temp->prev = prev;

            // Make the new node's next pointer point to the current node
            temp->next = curr;

            // Set the current node's prev pointer to the new node
            curr->prev = temp;
        }
    }
}

// Function to print the Doubly Linked List from head to tail
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

// Main function to test the Doubly Linked List operations
int main()
{
    // Define an array of integers to initialize the list
    int array[] = {30, 40, 60, 80, 100};

    // Calculate the size of the array
    int size = sizeof(array) / sizeof(int);

    // Initialize head and tail pointers to NULL
    Node *head = NULL;
    Node *tail = NULL;

    // Create the Doubly Linked List from the array
    createDLL(head, tail, array, size);

    // Print the newly created linked list
    cout << "Newly created linked list is : " << endl;
    printDLL(head); // Call the function to print the linked list
    cout << endl;

    // Define the position and data for insertion
    int position = 3;
    int data = 50;

    // Insert the new node at the specified position
    insertAtMid(head, position, data);

    // Print the linked list after insertion
    cout << "Linked List after inserting " << data << " at position " << position << ":" << endl;
    printDLL(head); // Call the function to print the linked
    cout << endl;

    // Return 0 to indicate successful execution
    return 0;
}