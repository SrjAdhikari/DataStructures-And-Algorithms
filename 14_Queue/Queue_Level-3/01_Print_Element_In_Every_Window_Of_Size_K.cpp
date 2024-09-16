#include <iostream>
#include <queue>
using namespace std;

// Function to print the contents of the queue
void printQueue(queue<int> q) {
    // Loop through the queue until it is empty
    while(!q.empty()) {
        // Print the element at the front of the queue
        cout << q.front() << "  ";

        // Remove the front element
        q.pop();
    }
    cout << endl;
}

int main() {
    // Initializing an array with some integer elements
    int array[] = { 2, 3, 5, 7, 6, 1, 9, 4 };

    // Calculating the number of elements in the array
    int size = sizeof(array) / sizeof(int);
    
    // The number of elements we want to process initially (variable 'k')
    int k = 3;
    
    // Declaring an empty queue of integers
    queue<int> q;

    // Push the first (k-1) elements of the array into the queue
    for(int i = 0; i < k - 1; i++) {
        q.push(array[i]);
    }

    // Process from the (k-1)-th element to the end of the array
    for(int i = k - 1; i < size; i++) {
        // Add the current element to the queue
        q.push(array[i]);
        
        // Print the current state of the queue
        printQueue(q);
        
        // Remove the element at the front of the queue
        q.pop();
    }

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(N) 
//* **********************************************