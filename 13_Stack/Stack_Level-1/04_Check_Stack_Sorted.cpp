#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

// Function to check if the stack is sorted in non-increasing order
bool checkSorted(stack<int>& s) {
    // Check if the stack is empty or has only one element
    if (s.empty()) 
        return true;    // An empty stack is trivially sorted

    if (s.size() == 1) 
        return true;    // A stack with one element is trivially sorted

    // Initialize 'prev' with the top element of the stack
    int prev = s.top();
    s.pop();

    // Iterate through the stack until it is empty
    while(!s.empty()) {
        // Retrieve the current top element of the stack
        int current = s.top();
        s.pop();
        
        // Check if the current element is greater than the previous element
        // If so, the stack is not sorted in non-increasing order
        if(prev < current)
            return false;
        
        // Update 'prev' to the current element for the next comparison
        prev = current;
    }

    // If all elements were in non-increasing order, return true
    return true;
}

int main() {
    // Create a stack of integers
    stack<int> s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // Call the function to check if the stack is sorted in non-increasing order
    bool isSorted = checkSorted(s);
    
    // Output the result based on whether the stack is sorted
    isSorted ? cout << "Stack is sorted" : cout << "Stack is not sorted" << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 