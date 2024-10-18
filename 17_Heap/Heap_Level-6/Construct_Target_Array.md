# Question : [Construct Target Array With Multiple Sums - (LeetCode : 1354)](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

You are given an array `target` of n integers. From a starting array `arr` consisting of `n` 1's, you may perform the following procedure :

- let `x` be the sum of all elements currently in your array.
- choose index `i`, such that `0 <= i < n` and set the value of `arr` at index `i` to `x`.
- You may repeat this procedure as many times as needed.

Return `true` *if it is possible to construct the `target` array from `arr`, otherwise, return `false`*.

### Example 1

```
Input: target = [9,3,5]
Output: true
Explanation: Start with arr = [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```

### Example 2

```
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
```

### Example 3

```
Input: target = [8,5]
Output: true
```

### Constraints
- `n == target.length`
- `1 <= n <= 5 * 10^4`
- `1 <= target[i] <= 10^9`

## Solution

```Cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Priority queue (max-heap) to store the elements of the target vector
        priority_queue<long long> pq;

        // Variable to store the sum of all elements in the target array
        long long sum = 0;

        // Step 1: Push all elements from the target array into the priority queue
        // And keep track of the sum of all elements
        for (int i = 0; i < target.size(); i++) {
            pq.push(target[i]);  // Push the element into the max-heap
            sum += target[i];    // Add the element to the total sum
        }

        long long maxValue, remainSum, element;

        // Step 2: Process the max-heap until the top of the heap (largest element) becomes 1.
        while (pq.top() != 1) {
            maxValue = pq.top();  // Get the largest element from the heap
            pq.pop();             // Remove the largest element from the heap

            // Calculate the remaining sum of elements (excluding the largest)
            remainSum = sum - maxValue;

            // Step 3: // If the remaining sum is less than or equal to 0 or greater than or equal to the largest element,
            // it's not possible to form the target array.
            if (remainSum <= 0 || remainSum >= maxValue) 
                return false;

            // Step 4: // Calculate the new value for the largest element using modulus operation
            element = maxValue % remainSum;

            // If the remainder is zero, check whether the remaining sum is 1.
            // If the remainder is 0 and remainSum is not 1, return false as we cannot reduce the array further.
            if (element == 0) {
                if (remainSum != 1)
                    return false;
                else
                    return true;
            }

            // Update the total sum to reflect the new value
            sum = remainSum + element;

            // Push the new value of the element back into the max-heap
            pq.push(element);
        }

        // If all elements are reduced to 1, return true
        return true;
    }
};

Time Complexity = O(NlogN)
Space Complexity = O(N)
```