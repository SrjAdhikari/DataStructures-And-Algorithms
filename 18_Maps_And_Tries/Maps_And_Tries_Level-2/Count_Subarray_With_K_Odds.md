# Question : [Count Subarray with k odds - GFG](https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1)

You are given array `nums` of `n` elements and integer `k`, count the number of subarrays that has k odd numbers.

### Example 1

```
Input:
n = 5
nums = [1,1,2,1,1]
k = 3
Output:
2
Explanation:
There are 2 subarrays with k odds [1,1,2,1] and [1,2,1,1]
```

### Example 2

```
Input:
n=3
nums = [2,4,6]
k = 1
Output:
0
```

### Your Task:
You don't have to read input or print anything. Your task is to complete the function `countSubarray()` which takes the integer `n` and array nums and integer `k` as input and returns the count of subarray having k odds number.

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

### Constraints

- `1 <= n <= 10^5`
- `1 <= nums <= 10^9`
- `1 <= k <= n`

## Solution

```Cpp
class Solution {
public:
    // Function to count the number of subarrays containing exactly k odd numbers.
    int countSubarray(int n, vector<int>& nums, int k) {
        // Create an unordered map to store the frequency of odd counts encountered.
        // mp[oddCount] will track how many times we have seen a subarray with 'oddCount' odd numbers.
        unordered_map<int, int> mp;
        
        // Initialize variables to keep track of the count of odd numbers and the count of valid subarrays.
        int oddCount = 0;         // Counts the number of odd numbers in the current subarray.
        int subarrayCount = 0;    // Stores the total number of subarrays with exactly k odd numbers.
        
        // Initialize the map with a base case.
        // mp[0] = 1 indicates that there is one way to have zero odd numbers at the start (an empty subarray).
        mp[0] = 1;

        // Traverse the array to count odd numbers and track their frequency.
        for (int i = 0; i < n; i++) {
            // If the current number is odd, increment the odd count.
            if (nums[i] % 2)
                oddCount++;
            
            // Update the frequency of the current odd count in the map.
            mp[oddCount]++;
            
            // If k is 0, we want to count subarrays with no odd numbers.
            // Subtract 1 from the count since we are not interested in the current subarray.
            if (k == 0)
                subarrayCount = mp[oddCount - k] - 1;   // Subtract one to avoid counting the current subarray itself.
            
            // Otherwise, check if there is a previous subarray that has 'oddCount - k' odd numbers.
            // If such a subarray exists, add that count to subarrayCount.
            else if (mp.count(oddCount - k))
                subarrayCount += mp[oddCount - k];
        }
        
        // Return the total count of subarrays with exactly k odd numbers.
        return subarrayCount;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```