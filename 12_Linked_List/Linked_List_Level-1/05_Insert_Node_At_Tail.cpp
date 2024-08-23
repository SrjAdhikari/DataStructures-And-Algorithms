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

// Function to insert elements at the tail of the linked list
void insertAtTail(Node* &head, Node* &tail, int arr[], int size) {
    // Iterate over the array and add each element to the tail of the linked list
    for(int i = 0; i < size; i++) {
        // If the list is empty, initialize the head and tail with the first element
        if(head == NULL) {
            head = new Node(arr[i]);    // Create a new node with the current array element
            tail = head;                // Set the tail to the head since it's the only node in the list
        }
        else {
            // Create a new node with the current array element
            Node* temp = new Node(arr[i]);

            // Link the new node to the current tail
            tail->next = temp;

            // Move the tail pointer to the new node
            tail = temp;
        }
    }
}

// Function to print all elements of the linked list
void printLinkedList(Node *head) {
    Node *temp = head;                  // Start from the head of the list

    // Traverse the linked list until the end
    while (temp)
    {
        cout << temp->data << " -> ";   // Print the data of the current node
        temp = temp->next;              // Move to the next node
    }
    cout << endl;
}

int main() {
    int array[] = {2, 4, 6, 8, 10};
    int size = sizeof(array) / sizeof(int);

    // Manually create an initial linked list with two nodes: 5 -> 15 -> NULL
    Node *head = new Node(5);       // Create the first node with data 5
    head->next = new Node(15);      // Create the second node with data 15 and link it to the first node
    Node *tail = head->next;        // Set the tail to point to the last node (15)

    cout << "Initial Linked List:" << endl;
    printLinkedList(head);

    insertAtTail(head, tail, array, size);

    cout << "Linked List after adding a node at the tail:" << endl;
    printLinkedList(head);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 