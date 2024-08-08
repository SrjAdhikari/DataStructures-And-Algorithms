# Question : [Perfect Sum Problem - GFG](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1)

Given an array **arr** of size **n** of non-negative integers and an integer **sum**, the task is to count all subsets of the given array with a sum equal to a given **sum**.

**Note**: Answer can be very large, so, output answer modulo **10^9+7**.

### Example 1
```
Input: 
n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
Output: 
3
Explanation: 
{5, 2, 3}, {2, 8}, {10} are possible subsets.
```

### Example 2
```
Input: 
n = 5, arr = [2, 5, 1, 4, 3], sum = 10
Output: 
3
Explanation: 
{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.
```

```
Expected Time Complexity: O(n*sum)
Expected Auxiliary Space: O(n*sum)
```

### Constraints

`1 ≤ n*sum ≤ 10^6`
`0 ≤ arr[i] ≤ 10^6`

## Solution

```Cpp

class Solution {
public:
    // Recursive function to count subsets with a given sum
    int countSubset(int arr[], int index, int n, int sum) {
        // Base case: If we've considered all elements in the array
        if (index == n) {
            // Check if the remaining sum is 0; if so, return 1 (valid subset), otherwise 0
            return sum == 0;
        }

        // Count subsets that exclude the current element
        int exclude = countSubset(arr, index + 1, n, sum);

        // Count subsets that include the current element
        int include = countSubset(arr, index + 1, n, sum - arr[index]);

        // Return the total count, modulo 1000000007 to prevent overflow
        return (exclude + include) % 1000000007;
    }

    // Function to initialize and start the recursion
    int perfectSum(int arr[], int n, int sum) {
        return countSubset(arr, 0, n, sum);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```
