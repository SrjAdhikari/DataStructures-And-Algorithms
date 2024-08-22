#include <iostream>
using namespace std;

// Definition of the Node class, representing a single element in the linked list
class Node {
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with data and set the next pointer to NULL
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

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
    // Creating individual nodes with values 10, 20, 30, 40, and 50
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    // Linking the nodes together to form a linked list
    first->next = second;   // First node points to the second node
    second->next = third;   // Second node points to the third node
    third->next = fourth;   // Third node points to the fourth node
    fourth->next = fifth;   // Fourth node points to the fifth node

    Node *head = first;     // The head of the list points to the first node

    // Printing the linked list
    cout << "Printing the linked list: " << endl;
    printLinkedList(head);

    return 0;
}
