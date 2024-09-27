# Question : [Single Number - (LeetCode : 136)](https://leetcode.com/problems/single-number/description/)

Given a **non-empty** array of integers `nums`, every element appears _twice except_ for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1

```
Input: nums = [2,2,1]
Output: 1
```

### Example 2

```
Input: nums = [4,1,2,1,2]
Output: 4
```

### Example 3

```
Input: nums = [1]
Output: 1
```

### Constraints

-   `1 <= nums.length <= 3 * 10^4`
-   `-3 * 10^4 <= nums[i] <= 3 * 10^4`
-   Each element in the array appears twice except for one element which appears only once.

## Solution 1 : Using XOR Operator

```Cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Step 1: Initialize a variable 'ans' to 0.
        // This will store the result of the XOR operations.
        int ans = 0;

        // Step 2: Get the size of the input vector 'nums'.
        int size = nums.size();

        // Step 3: Traverse through the array using a loop.
        // The XOR operator (^) has the property that:
        // - a ^ a = 0 (i.e., XORing a number with itself results in 0)
        // - a ^ 0 = a (i.e., XORing a number with 0 keeps the number unchanged)
        // This ensures that every number appearing twice cancels itself out,
        // and only the number appearing once remains.
        for(int i = 0; i < size; i++) {
            // XOR the current element with 'ans'.
            ans = ans ^ nums[i];
        }

        // Step 4: Return 'ans', which now holds the single number that appears once.
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```

## Solution 2 : Using Hash Map

```Cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Step 1: Create an unordered map to store the frequency of each number in the array.
        unordered_map<int, int> freqMap;

        // Step 2: Iterate through the array and populate the frequency map.
        // The key in the map is the number from the array, and the value is the count of how many times it appears.
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];      // Get the current number from the array.
            freqMap[num]++;         // Increment its count in the map.
        }

        // Step 3: Declare an iterator to traverse through the frequency map.
        unordered_map<int, int>::iterator it;

        // Variable to store the result (the single number).
        int ans;

        // Step 4: Iterate through the frequency map to find the number with a frequency of 1.
        for(it = freqMap.begin(); it != freqMap.end(); it++) {
            int key = it->first;    // 'key' represents the number in the array.
            int freq = it->second;  // 'freq' represents the frequency of the number.

            // Step 5: Check if the frequency of the current number is 1.
            // If so, this is the number that appears only once in the array.
            if(freq == 1) {
                ans = key;          // Store the number with a frequency of 1 in 'ans'.
                break;              // Exit the loop as we've found the unique number.
            }
        }

        // Step 6: Return the unique number that appears only once.
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```
