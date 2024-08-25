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

Node *deleteNodeUsingRecursion(Node *&head, int position)
{
    // Base case: if the position is 1, delete the head node
    if (position == 1)
    {
        Node *temp = head->next; // Save the pointer to the next node
        delete head;             // Delete the current head node
        return temp;             // Return the next node, which becomes the new head
    }

    // Recursive case: move to the next node in the list
    // and decrease the position by 1
    head->next = deleteNodeUsingRecursion(head->next, position - 1);

    // Return the current node (it remains unchanged in the context of the list)
    return head;
}

int main()
{
    int array[] = {10, 20, 30, 40, 50};     // Array of integers to be used for creating the linked list
    int size = sizeof(array) / sizeof(int); // Calculate the number of elements in the array

    Node *head = NULL; // Pointer to the head of the linked list, initialized to NULL
    Node *tail = NULL; // Pointer to the tail of the linked list, initialized to NULL
    int position = 5;  // Position of the node to be deleted from the linked list

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
    deleteNodeUsingRecursion(head, position);

    // Print the linked list after the deletion
    cout << "Linked List after deletion: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}