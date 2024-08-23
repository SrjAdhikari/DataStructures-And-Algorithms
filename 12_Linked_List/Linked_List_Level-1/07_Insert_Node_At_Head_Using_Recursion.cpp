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

// Recursive function to insert elements from an array at the head of the linked list
Node* insertAtHeadUsingRecursion(int arr[], int size, int index, Node* prev) {
    // Base case: If the index reaches the size of the array, return the previous node (head of the list)
    if (index == size) {
        return prev;
    }

    // Create a new node with the current array element
    Node* temp = new Node(arr[index]);

    // Set the next pointer of the new node to the previous node (building the list backward)
    temp->next = prev;

    // Recursively call the function with the next index and the new node as the previous node
    return insertAtHeadUsingRecursion(arr, size, index + 1, temp);
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

    // Use recursion to create a linked list from the array with elements added at the head
    Node* head = insertAtHeadUsingRecursion(array, size, 0, NULL);

    // Print the resulting linked list
    cout << "Linked List created using recursion:" << endl;
    printLinkedList(head);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 