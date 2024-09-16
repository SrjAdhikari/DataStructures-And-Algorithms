#include <iostream>
#include <queue>
using namespace std;

// Function to print the elements of the queue
void printQueue(queue<int>& q) {
    // Get the initial size of the queue
    int size = q.size();
    
    // Iterate over the entire queue
    while(size) {
        // Print the front element of the queue
        cout << q.front() << "  ";
        
        // Push the front element to the back of the queue to maintain the original order
        q.push(q.front());
        
        // Remove the front element
        q.pop();
        
        // Decrease the size counter to track how many elements have been processed
        size--;
    }
    cout << endl;
}

int main() {
    // Declare a queue of integers
    queue<int> q;

    // Push elements into the queue (enqueue operation)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Print the elements of the queue
    cout << "Elements of Queue:" << endl;
    printQueue(q);  // The queue remains unchanged after this operation due to the cyclic re-enqueuing

    return 0;
}

//* **********************************************
    //* Time Complexity : O(N)
    //* Space Complexity : O(1) 
//* ********************************************** 