# Question : [Count distinct elements in every window - GFG](https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1)

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

### Example 1

```
Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.
```

### Example 2

```
Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1
```

### Your Task:
Your task is to complete the function `countDistinct()` which takes the array A[], the size of the array(N) and the window size(K) as inputs and returns an array containing the count of distinct elements in every contiguous window of size K in the array A[].

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

### Constraints

- `1 <= K <= N <= 10^5`
- `1 <= A[i] <= 10^5` , for each valid i

## Solution

```Cpp
class Solution {
public:
    // Function to count distinct elements in every subarray of size k
    vector<int> countDistinct(int A[], int n, int k) {
        // Create a hashmap to store the frequency of elements in the current window
        unordered_map<int, int> mp;

        // Vector to store the result (count of distinct elements in each subarray)
        vector<int> ans;

        // Variable to keep track of the number of distinct elements
        int count = 0;

        // Process the first k elements to initialize the window
        for (int i = 0; i < k; i++) {
            int num = A[i];     // Current number from the array
            mp[num]++;          // Increment the frequency of the current number
            
            // If this is the first occurrence of the current number, increment the distinct count
            if (mp[num] == 1)
                count++;
        }

        // Store the count of distinct elements for the first subarray
        ans.push_back(count);

        // Now, slide the window over the array from k to n
        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            int old_num = A[i - k];     // Element that is sliding out of the window
            int new_num = A[i];         // New element that is sliding into the window

            // Decrement the frequency of the old element
            mp[old_num]--;

            // If the old element's frequency becomes zero, it is no longer in the window
            // Decrement the distinct count
            if (mp[old_num] == 0)
                count--;

            // Increment the frequency of the new element
            mp[new_num]++;

            // If this is the first occurrence of the new element, increment the distinct count
            if (mp[new_num] == 1)
                count++;

            // Store the current count of distinct elements
            ans.push_back(count);
        }

        // Return the vector containing counts of distinct elements for all subarrays of size k
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```