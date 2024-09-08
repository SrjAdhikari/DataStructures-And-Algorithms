#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//* Brute force approach:
// Brute-force approach to find the next greater element for each element in the array.
vector<int> bruteForceApproach(int arr[], int n) {
    // Initialize a vector to store the result with default values of -1.
    // This means if no greater element is found for a specific index, the value remains -1.
    vector<int> ans(n, -1);

    // Outer loop: Traverse each element of the array.
    for(int i = 0; i < n; i++) {
        
        // Inner loop: Traverse the elements to the right of the current element arr[i].
        for(int j = i + 1; j < n; j++) {
            
            // If a greater element is found, set it as the next greater element for arr[i].
            if(arr[j] > arr[i]) {
                ans[i] = arr[j];    // Assign arr[j] as the next greater element for arr[i].
                break;              // Break the loop since we found the first next greater element.
            }
        }
    }

    // Return the result array containing the next greater elements.
    return ans;
}

//* *********************************************
    //* Time Complexity = O(n^2)
    //* Space Complexity = O(1)
//* *********************************************


//* Optimise approach using stack from left to right:
// Function to find the next greater element for each element in the array
vector<int> nextGreaterElement(int arr[], int n) {
    // Initialize result vector `ans` with size `n`, defaulting each element to -1
    // -1 indicates that no greater element is found to the right of a particular element
    vector<int> ans(n, -1);

    // Stack to store indices of the elements for which we are still searching for the next greater element
    stack<int> st;

    // Traverse the array from left to right
    for(int i = 0; i < n; i++) {

        // While stack is not empty and the current element (arr[i]) is greater than the element at index `st.top()`
        // it means we've found the next greater element for the element at `st.top()`.
        while(!st.empty() && arr[st.top()] < arr[i]) {
            // Set the next greater element for the element at index `st.top()` to arr[i]
            ans[st.top()] = arr[i];

            // Remove the index from the stack as we've processed it
            st.pop();
        }

        // Push the current index `i` onto the stack
        // We will later find its next greater element (if any) in future iterations
        st.push(i);
    }

    // At the end of the loop, any indices still left in the stack have no next greater element.
    // This is already handled since the default value in the `ans` vector is -1, so no further action is needed.

    // Return the result vector which contains the next greater elements for all array elements
    return ans;
}

//* *********************************************
    //* Time Complexity = O(n)
    //* Space Complexity = O(n)
//* *********************************************


//* Optimise approach using stack from right to left:
// Function to find the next greater element for each element in the array.
vector<int> nextGreaterElement2(int arr[], int n) {
    // Initialize a vector to store the result, with default values of -1.
    // If no greater element is found for an element, its result remains -1.
    vector<int> ans(n, -1);
    
    // Stack to store indices of array elements.
    // It helps in tracking elements whose next greater element is not yet found.
    stack<int> st;

    // Traverse the array from right to left.
    for(int i = n - 1; i >= 0; i--) {
        
        // While the stack is not empty and the element at the top of the stack (arr[st.top()])
        // is smaller than the current element (arr[i]), pop the stack.
        // This means that arr[i] is greater than arr[st.top()], so we discard arr[st.top()] from the stack.
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        // If the stack is not empty after the above loop, it means the current top of the stack
        // is the next greater element for arr[i].
        if(!st.empty()) {
            ans[i] = arr[st.top()]; // Set the next greater element for arr[i].
        }

        // Push the current index onto the stack.
        // This index is now waiting to find its next greater element from future iterations.
        st.push(i);
    }

    // Return the result vector containing the next greater element for each index.
    return ans;
}

//* *********************************************
    //* Time Complexity = O(n)
    //* Space Complexity = O(n)
//* *********************************************


int main() {
    // Initialize an array of stock prices (or any numbers for which we want to find next greater elements)
    int arr[] = {8, 6, 4, 7, 4, 9, 10, 8, 12};

    // Calculate the number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call the function to find the next greater elements for the array
    vector<int> ans = nextGreaterElement(arr, size);
    // vector<int> ans = bruteForceApproach(arr, size);
    // vector<int> ans = nextGreaterElement2(arr, size);

    // Print the next greater element for each element in the input array
    for(int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}