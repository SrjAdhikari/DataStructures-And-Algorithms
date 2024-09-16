# Question : [First negative in every window of size k - GFG](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)

Given an array `A[`] of size `N` and a positive integer `K`, find the first negative integer for each and every window(contiguous subarray) of size `K`.

### Example 1

```
Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
```

### Example 2

```
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
```

### Your Task:

You don't need to read input or print anything. Your task is to complete the function `printFirstNegativeInteger()` which takes the array `A[]`, its size `N` and an integer `K` as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)
```

### Constraints

`1 <= N <= 10^5`
`-10^5 <= A[i] <= 10^5`
`1 <= K <= N`

## Solution 1

```Cpp
class Solution {
public:
    // Function to find the first negative integer in the queue
    // Returns the first negative integer if present, otherwise returns 0
    long long negativeInteger(queue<long long> q) {
        // Traverse the queue until we find the first negative integer
        while (!q.empty()) {
            // Check if the front element is negative
            if (q.front() < 0)
                return q.front();  // Return the first negative integer found

            // If the front element is not negative then remove it from the queue
            q.pop();
        }

        // Return 0 if no negative integer is found
        return 0;
    }

    // Function to print the first negative integer in every subarray of size K
    vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
        vector<long long> ans;      // Vector to store the result for each window
        queue<long long> q;         // Queue to store the elements of the current window

        // Process the first K-1 elements of the array (to set up the sliding window)
        for (int i = 0; i < K - 1; i++) {
            q.push(A[i]);
        }

        // Iterate through the array starting from the K-1th element
        for (int i = K - 1; i < N; i++) {
            // Add the current element to the queue
            q.push(A[i]);

            // Find the first negative integer in the current window and add it to the result vector
            ans.push_back(negativeInteger(q));

            // Remove the oldest element from the queue (i.e., the element at the start of the window)
            q.pop();
        }

        // Return the result vector containing the first negative integers for each subarray
        return ans;
    }
};

Time Complexity = O(N * K)
Space Complexity = O(K)
```

## Solution 2

```Cpp
class Solution {
public:
    // Function to print the first negative integer in every subarray of size K
    vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
        // Queue to store indices of negative elements within the current window
        queue<long long> q;

        // Vector to store the result for each subarray
        vector<long long> ans;
    
        // Initialize the queue with indices of negative integers in the first window of size K-1
        for(int i = 0; i < K - 1; i++) {
            if(A[i] < 0)
                q.push(i); // Store the index of the negative integer
        }
    
        // Process the remaining elements starting from index K-1
        for(int i = K - 1; i < N; i++) {
            // Add the current element's index to the queue if it is negative
            if(A[i] < 0)
                // Store the index of the negative integer
                q.push(i);
        
            // If the queue is empty, no negative integer is present in the current window
            if(q.empty())
                // Add 0 if no negative integer is found
                ans.push_back(0);
            else {
                // Remove indices from the queue that are outside the current window
                if(q.front() <= i - K)
                    // Remove the front index if it is out of the current window
                    q.pop();
                
                // Check if the queue is empty after removing out-of-window indices
                if(q.empty())
                    // Add 0 if no negative integer is found
                    ans.push_back(0);
                else {
                    // Add the first negative integer of the current window
                    ans.push_back(A[q.front()]);
                }
            }
        }

        // Return the result vector containing the first negative integers for each subarray
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(K)
```