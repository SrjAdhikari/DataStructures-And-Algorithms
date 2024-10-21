# Question : [Two Sum - (LeetCode : 1)](https://leetcode.com/problems/two-sum/description/)

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly one solution***, and you may not use the *same* element twice.

You can return the answer in any order.

### Example 1

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

### Example 2

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

### Example 3

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Constraints

-   `2 <= nums.length <= 10^4`
-   `-10^9 <= nums[i] <= 10^9`
-   `-10^9 <= target <= 10^9`
-   **Only one valid answer exists**.

**Follow-up**: Can you come up with an algorithm that is less than O(n^2) time complexity?

## Solution

```Cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;     // This map stores the value and its index in the array
        vector<int> ans;                // To store the final answer (indices of the two elements)
        
        // Loop through the array
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];          // The current number
            
            // Checks if the complement (i.e. target - num) is already present in the map
            // If the complement exists in the map, it means we have found the two numbers that add up to target
            if(mp.count(target - num)) {
                ans.push_back(mp[target - num]);    // Push the index of the number that complements 'num'
                ans.push_back(i);                   // Push the current index i
                return ans;                         // Return the answer as soon as we find the solution
            }
            
            // If the complement doesn't exist in the map, add current number to the map with its index
            if(mp.count(num) == 0)
                mp[num] = i;
        }
        
        // Return empty vector if no such pair is found after completing the iteration
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```