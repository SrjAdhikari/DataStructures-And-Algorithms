#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(30);
    maxHeap.push(40);
    maxHeap.push(50);

    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(30);
    minHeap.push(40);
    minHeap.push(50);

    // Max Heap Properties
    cout << "Max Heap Size: " << maxHeap.size() << endl;

    cout << "Max Heap Top: " << maxHeap.top() << endl;
    maxHeap.pop();

    cout << "Max Heap Size: " << maxHeap.size() << endl;

    if(maxHeap.empty()) {
        cout << "Max Heap is empty" << endl;
    } 
    else {
        cout << "Max Heap is not empty" << endl;
    }
    cout << endl;


    // Min Heap Properties
    cout << "Min Heap Size: " << minHeap.size() << endl; 

    cout << "Min Heap Top: " << minHeap.top() << endl;
    minHeap.pop();

    cout << "Min Heap Size: " << minHeap.size() << endl;

    if(minHeap.empty()) {
        cout << "Max Heap is empty" << endl;
    } 
    else {
        cout << "Max Heap is not empty" << endl;
    }

    return 0;
}