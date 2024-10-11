# Question : [Find median in a stream - GFG](https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1)

Given an input stream of `N` integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of `X` to the new stream.

### Example 1

```
Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
```

### Example 2

```
Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
```

### Your Task
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:
    1. `insertHeap()` which takes x as input and inserts it into the heap, the function should then call `balanceHeaps()` to balance the new heap.
    2. `balanceHeaps()` does not take any arguments. It is supposed to balance the two heaps.
    3. `getMedian()` does not take any arguments. It should return the current median of the stream.

```
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
```

### Constraints

- `1 <= N <= 10^6`
- `1 <= x <= 10^6`

## Solution

```Cpp
class Solution {
public:
    // Define two heaps:
    // leftMaxHeap: max heap to store the smaller half of the elements
    // rightMinHeap: min heap to store the larger half of the elements
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

    // Function to insert a new element into one of the heaps
    void insertHeap(int &x) {
        // Step 1: If leftMaxHeap is empty, insert the element into it
        if(leftMaxHeap.empty()) {
            leftMaxHeap.push(x);
            return;
        }
        // Step 2: Insert element into appropriate heap
        else if(x > leftMaxHeap.top()) {
            // If the new element x is greater than the max element in leftMaxHeap,
            // it belongs to the larger half, so insert it into rightMinHeap
            rightMinHeap.push(x);
        } 
        else {
            // If the new element x is smaller or equal to the max element in leftMaxHeap,
            // it belongs to the smaller half, so insert it into leftMaxHeap
            leftMaxHeap.push(x);
        }
        
        // Step 3: Balance the heaps so that the size difference between heaps is at most 1
        balanceHeaps();
    }

    // Function to balance the two heaps
    void balanceHeaps() {
        // If rightMinHeap has more elements than leftMaxHeap, move the smallest element
        // from rightMinHeap to leftMaxHeap to balance the heaps
        if(rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());   // Move top of min heap to max heap
            rightMinHeap.pop();                     // Remove the element from min heap
        } 
        // If the left max heap has more than one extra element, move the largest element 
        // from the left max heap to the right min heap
        else {
            if(rightMinHeap.size() < leftMaxHeap.size() - 1) {
                rightMinHeap.push(leftMaxHeap.top());   // Move top of max heap to min heap
                leftMaxHeap.pop();                      // Remove the element from max heap
            }
        }
    }

    // Function to return the median of the elements inserted so far
    double getMedian() {
        // If leftMaxHeap has more elements, the median is its top element
        if(leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        } 
        // If both heaps have the same size, the median is the average of their top elements
        else {
            double median = leftMaxHeap.top() + rightMinHeap.top();     // Sum the tops of both heaps
            median /= 2;        // Calculate the average
            return median;      // Return the average as the median
        }
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```