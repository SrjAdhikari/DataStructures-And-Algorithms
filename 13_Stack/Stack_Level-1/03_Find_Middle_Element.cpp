#include <iostream>
#include <stack>
using namespace std;

// Function to find and print the middle element of the stack
void findMiddleElement(stack<int>& s, int mid) {
    // Base case: when mid reaches 0, we have reached the middle element
    if(mid == 0) {
        // Print the middle element
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    int topElement = s.top();   // Store the current top element of the stack
    s.pop();                    // Remove the top element from the stack
    mid--;                      // Decrease the middle count as we move down the stack

    // Recursive call to find the middle element
    findMiddleElement(s, mid);

    // After finding the middle, push the elements back onto the stack in the same order
    s.push(topElement);
}

int main() {
    stack<int> st;
    // Push elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // Calculate the size of the stack
    int size = st.size();

    // Calculate the index of the middle element (0-based index)
    int mid = size / 2;

    // Call the function to find and print the middle element
    findMiddleElement(st, mid);

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* ********************************************** 