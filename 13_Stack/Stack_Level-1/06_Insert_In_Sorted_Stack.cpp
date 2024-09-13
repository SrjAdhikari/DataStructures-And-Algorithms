#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element into a sorted stack
void insertInSortedStack(stack<int>& s, int value) {
    // Base case: If stack is empty or top element is less than value, push the value
    if(s.empty() || s.top() < value) {
        s.push(value);
        return;
    }

    // Store the top element and pop it from the stack
    int currentTop = s.top();
    s.pop();

    // Recursively call insertInSortedStack to find the correct position for value
    insertInSortedStack(s, value);

    // Push the stored top element back onto the stack after inserting value
    s.push(currentTop);
}

int main() {
    int value = 25;
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    insertInSortedStack(s, value);

    cout << "Stack after element insert : " << endl;
    while(!s.empty()) {
        cout << s.top() << "  ";
        s.pop();
    }
    cout << endl;

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 