#include <iostream>
#include <stack>
using namespace std;

// Function to insert a value at the bottom of the stack
void insertAtBottom(stack<int>& s, int value) {
    if(s.empty()) {
        // Base case: push the value when the stack is empty
        s.push(value);
        return;
    }

    int currentTop = s.top();   // Save the current top element
    s.pop();                    // Pop the top element

    insertAtBottom(s, value);   // Recursively call to insert the value at the bottom
    s.push(currentTop);         // Restore the original top element after inserting at the bottom
}
// Function to reverse the stack recursively
void reverseStack(stack<int>& s) {
    // Base case: if stack is empty, stop recursion
    if(s.empty()) {
        return;
    }

    int currentTop = s.top();       // Save the current top element
    s.pop();                        // Pop the top element

    reverseStack(s);                // Recursively reverse the rest of the stack
    insertAtBottom(s, currentTop);  // Insert the popped element at the bottom
}

// Function to print the stack
void printStack(stack<int>& s) {
    while(!s.empty()) {
        cout << s.top() << "  ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    reverseStack(s);

    cout << "Stack after reverse : " << endl;
    printStack(s);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N^2)
    //* Space Complexity : O(N) 
//* ********************************************** 