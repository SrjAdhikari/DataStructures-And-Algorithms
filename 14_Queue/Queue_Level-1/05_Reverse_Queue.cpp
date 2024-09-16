#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the elements of a queue
void reverseQueue(queue<int>& q) {
    stack<int> st;  // Stack to hold the queue elements
    
    // Step 1: Transfer elements from queue to stack
    while(!q.empty()) {
        st.push(q.front());  // Push the front element of the queue onto the stack
        q.pop();             // Remove the front element from the queue
    }

    // Step 2: Transfer elements back from stack to queue (this reverses the order)
    while(!st.empty()) {
        q.push(st.top());    // Push the top element of the stack back to the queue
        st.pop();            // Remove the top element from the stack
    }
}

// Function to print the elements of the queue
void printQueue(queue<int>& q) {
    while(!q.empty()) {
        cout << q.front() << "  ";  // Print the front element
        q.pop();                    // Remove the front element
    }
    cout << endl;
}

int main() {
    // Create a queue of integers
    queue<int> q;

    // Enqueue elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Reverse the queue
    reverseQueue(q);

    // Print the reversed queue
    cout << "Queue after reversal:" << endl;
    printQueue(q);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 