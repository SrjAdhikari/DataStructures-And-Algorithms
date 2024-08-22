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

void insertAtHead(Node* &head, int data) {
    // Check if the linked list is empty
    if (head == NULL) {
        // If the list is empty, create a new node with the given data
        // and make it the head of the list
        head = new Node(data);
    }
    else {
        // If the list is not empty:
        // 1. Create a new node with the given data
        Node* temp = new Node(data);

        // 2. Set the new node's next pointer to the current head of the list
        temp->next = head;

        // 3. Update the head to point to the new node
        head = temp;
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
    Node* head = new Node(10);
    head->next = new Node(20);

    cout << "Initial Linked List:" << endl;
    printLinkedList(head);

    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);

    cout << "Linked List after adding a node at the head:" << endl;
    printLinkedList(head);

    return 0;
}