# Question : [Sum of elements between k1'th and k2'th smallest elements - GFG](https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1)

Given an array `A[]` of `N` positive integers and two positive integers `K1` and `K2`. Find the sum of all elements between K1th and K2th smallest elements of the array. It may be assumed that (1 <= k1 < k2 <= n).

### Example 1

```
Input:
N  = 7
A[] = {20, 8, 22, 4, 12, 10, 14}
K1 = 3, K2 = 6
Output:
26
Explanation:
3rd smallest element is 10
6th smallest element is 20
Element between 10 and 20 
12,14. Their sum = 26.
```

### Example 2

```
Input
N = 6
A[] = {10, 2, 50, 12, 48, 13}
K1= 2, K2 = 6
Output:
73
```

### Your Task
You don't need to read input or print anything. Your task is to complete the function `sumBetweenTwoKth()` which takes the array `A[]`, its size `N` and two integers `K1` and `K2` as inputs and returns the sum of all the elements between K1th and K2th smallest elements.

```
Expected Time Complexity: O(N. log(N))
Expected Auxiliary Space: O(N)
```

### Constraints

- `1 ≤ N ≤ 10^5`
- `1 ≤ K1, K2 ≤ 10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to return the sum of elements between the K1-th and K2-th smallest elements in the array A.
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Create two max-heaps (priority queues) to store the K1-th and K2-th smallest elements, respectively.
        priority_queue<long long> pq1;      // Heap to find the K1-th smallest element.
        priority_queue<long long> pq2;      // Heap to find the (K2-1)-th smallest element.
        
        // Insert the first K1 elements into pq1. This will help us find the K1-th smallest element.
        for(long long i = 0; i < K1; i++) {
            pq1.push(A[i]);
        }
        
        // Insert the first K2-1 elements into pq2. This will help us find the K2-th smallest element.
        for(long long i = 0; i < K2 - 1; i++) {
            pq2.push(A[i]);
        }
        
        // Process the remaining elements for pq1 to find the K1-th smallest element.
        // If an element is smaller than the largest element in the heap (pq1), we replace the largest element.
        for(long long i = K1; i < N; i++) {
            if(A[i] < pq1.top()) {
                pq1.pop();
                pq1.push(A[i]);
            }
        }
        
        // Process the remaining elements for pq2 to find the (K2-1)-th smallest element.
        // Similar to pq1, replace the top element of pq2 if the current element is smaller.
        for(long long i = K2 - 1; i < N; i++) {
            if(A[i] < pq2.top()) {
                pq2.pop();
                pq2.push(A[i]);
            }
        }
        
        // Now that we have identified the K1-th smallest and (K2-1)-th smallest elements,
        // We need to sum the elements between these two.
        
        // Sum of elements in pq1 (contains K1 smallest elements).
        // Sum of elements in pq2 (contains K2-1 smallest elements).
        long long sum1 = 0, sum2 = 0;
        
        // Pop elements from pq1 and accumulate the sum.
        while(!pq1.empty()) {
            sum1 += pq1.top();
            pq1.pop();
        }
        
        // Pop elements from pq2 and accumulate the sum.
        while(!pq2.empty()) {
            sum2 += pq2.top();
            pq2.pop();
        }
        
        // Return the difference between the sum of pq2 and pq1, which gives the sum of elements between
        // the K1-th smallest and the (K2-1)-th smallest element.
        return sum2 - sum1;
    }
};

Time Complexity = O(Nlog(k2))
Space Complexity = O(k2)
```