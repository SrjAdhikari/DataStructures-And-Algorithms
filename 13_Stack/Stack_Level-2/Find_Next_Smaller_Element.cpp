#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//* Brute force approach:
// Brute-force approach to find the next smaller element for each element in the array.
vector<int> bruteForceApproach(int arr[], int n) {
    // Initialize a vector to store the result, with default values of -1.
    // If no smaller element is found for a specific index, the value remains -1.
    vector<int> ans(n, -1);

    // Outer loop: Traverse each element of the array.
    for(int i = 0; i < n; i++) {
        
        // Inner loop: Traverse the elements to the right of the current element arr[i].
        for(int j = i + 1; j < n; j++) {
            
            // If a smaller element is found, set it as the next smaller element for arr[i].
            if(arr[j] < arr[i]) {
                ans[i] = arr[j];    // Assign arr[j] as the next smaller element for arr[i].
                break;              // Break the loop once the first smaller element is found.
            }
        }
    }

    // Return the result vector containing the next smaller elements.
    return ans;
}

//* *********************************************
    //* Time Complexity = O(n^2)
    //* Space Complexity = O(1)
//* *********************************************


//* Optimise approach using stack:
// Function to find the next smaller element for each element in the array.
vector<int> nextSmallerElement(int arr[], int n) {
    // Initialize a vector to store the result with default values of -1.
    // If no smaller element is found, the result will remain -1 for that element.
    vector<int> ans(n, -1);
    
    // Stack to store indices of elements. The stack will help in tracking elements
    // that are waiting for their next smaller element.
    stack<int> st;

    // Traverse the array from left to right.
    for(int i = 0; i < n; i++) {
        
        // While the stack is not empty, and the current element arr[i] is smaller
        // than the element at the index stored at the top of the stack (arr[st.top()]),
        // it means we've found the next smaller element for arr[st.top()].
        while(!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = arr[i];     // Set the next smaller element for arr[st.top()].
            st.pop();                   // Pop the index from the stack as its smaller element is found.
        }

        // Push the current index onto the stack to find its next smaller element in future iterations.
        st.push(i);
    }

    // Return the result array containing the next smaller elements.
    return ans;
}

//* *********************************************
    //* Time Complexity = O(n)
    //* Space Complexity = O(n)
//* *********************************************


int main() {
    // Initialize an array of stock prices (or any numbers for which we want to find next smaller elements)
    int arr[] = {8, 6, 4, 7, 4, 9, 10, 8, 12};

    // Calculate the number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call the function to find the next smaller elements for the array
    vector<int> ans = nextSmallerElement(arr, size);
    // vector<int> ans = bruteForceApproach(arr, size);

    // Print the next smaller element for each element in the input array
    for(int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}