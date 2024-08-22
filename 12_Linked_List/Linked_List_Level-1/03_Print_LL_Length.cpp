#include <iostream>
using namespace std;

// Definition of the Node class, which represents an element in the linked list.
class Node {
public:
    int data;   // Variable to store the data of the node
    Node *next; // Pointer to the next node in the linked list

    // Constructor to initialize the node with data and set the next pointer to NULL.
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to create a linked list from an array of integers.
// The head of the linked list is passed by reference using Node*& to update the original head.
void createLinkedList(Node *&head, int arr[], int size) {
    // Iterate through the array elements
    for (int i = 0; i < size; i++)
    {
        // If the linked list is empty (head is NULL), create the first node.
        if (head == NULL)
        {
            head = new Node(arr[i]); // Create a new node with the current array element and set it as the head
        }
        // If the linked list is not empty, create a new node and insert it at the beginning of the list.
        else
        {
            Node *temp = new Node(arr[i]); // Create a new node with the current array element
            temp->next = head;             // Set the new node's next pointer to the current head node
            head = temp;                   // Update the head to point to the new node
        }
    }
}

// Function to count length of a linked list.
int getLength(Node *head) {
    int count = 0;     // Initialize a counter to store the length of the linked list
    Node *temp = head; // Create a temporary pointer to traverse the linked list, starting at the head

    // Traverse the linked list until the end (when temp becomes NULL)
    while (temp)
    {
        count++;           // Increment the counter for each node encountered
        temp = temp->next; // Move to the next node in the list
    }

    return count; // Return the total count, which represents the length of the linked list
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);

    Node *head = NULL;
    createLinkedList(head, array, size);

    cout << "Length of linked list is : " << getLength(head) << endl;
    cout << endl;

    return 0;
}