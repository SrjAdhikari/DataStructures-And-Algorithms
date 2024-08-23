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

// Recursive function to insert elements from an array at the tail of the linked list
Node* insertAtTailUsingRecursion(int arr[], int size, int index) {
    // Base case: If index reaches the size of the array, return NULL (end of the list)
    if(index == size) {
        return NULL;
    }

    // Create a new node with the current array element
    Node* temp = new Node(arr[index]);

    // Recursively call the function to create and attach the next nodes
    temp->next = insertAtTailUsingRecursion(arr, size, index + 1);

    // Return the current node, which becomes part of the linked list
    return temp;
}

// Function to print all elements of the linked list
void printLinkedList(Node *head) {
    Node *temp = head;                  // Start from the head of the list

    // Traverse the linked list until the end
    while (temp) {
        cout << temp->data << " -> ";   // Print the data of the current node
        temp = temp->next;              // Move to the next node
    }
    cout << endl;
}

int main() {
    int array[] = {2, 4, 6, 8, 10};
    int size = sizeof(array) / sizeof(int);

    // Use recursion to create a linked list from the array
    Node* head = insertAtTailUsingRecursion(array, size, 0);

    // Print the resulting linked list
    cout << "Linked List created using recursion :" << endl;
    printLinkedList(head);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 