#include <iostream>
using namespace std;

// Definition of the Node class, which represents an element in the linked list.
class Node {
    public:
    int data;       // Variable to store the data of the node
    Node* next;     // Pointer to the next node in the linked list

    // Constructor to initialize the node with data and set the next pointer to NULL.
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to print all elements of the linked list starting from the head node.
void printLinkedList(Node* head) {
    Node* temp = head;                  // Temporary pointer to traverse the linked list
    while(temp) {                       // Loop until temp is not NULL (reaches the end of the list)
        cout << temp->data << "  ";     // Print the data of the current node
        temp = temp->next;              // Move to the next node in the list
    }
    cout << endl;
}

// Function to create a linked list from an array of integers.
// The head of the linked list is passed by reference using Node*& to update the original head.
void createLinkedList(Node*& head, int arr[], int size) {
    // Iterate through the array elements
    for(int i = 0; i < size; i++) {
        // If the linked list is empty (head is NULL), create the first node.
        if(head == NULL) {
            head = new Node(arr[i]);        // Create a new node with the current array element and set it as the head
        }
        // If the linked list is not empty, create a new node and insert it at the beginning of the list.
        else {
            Node* temp = new Node(arr[i]);  // Create a new node with the current array element
            temp->next = head;              // Set the new node's next pointer to the current head node
            head = temp;                    // Update the head to point to the new node
        }
    }
}

// Main function to execute the program
int main() {
    int array[] = {2, 4, 6, 8, 10};             // Initialize an array with values to be added to the linked list
    int size = sizeof(array) / sizeof(int);     // Calculate the number of elements in the array

    Node *head = NULL;                          // Initialize the head of the linked list as NULL
    createLinkedList(head, array, size);        // Call the function to create the linked list

    cout << "Newly created linked list is : " << endl;
    printLinkedList(head);                      // Call the function to print the linked list

    return 0;
}