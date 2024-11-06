# Question : [House Robber - (LeetCode : 198)](https://leetcode.com/problems/house-robber/description/)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return _the maximum amount of money you can rob tonight_ **_without alerting the police_**.

### Example 1

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

### Example 2

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

### Constraints

-   `1 <= nums.length <= 100`
-   `0 <= nums[i] <= 400`

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

## Solution

```Cpp
class Solution {
public:
    int robAmount(vector<int>& nums, int index) {
        // Base case: If the current index is out of bounds, return 0 (no money can be robbed)
        if (index >= nums.size()) {
            return 0;
        }

        // Recursive case:
        // Option 1: Rob the current house and then skip the next one (move to index + 2)
        int robHouse = nums[index] + robAmount(nums, index + 2);

        // Option 2: Skip the current house and move to the next one (index + 1)
        int skipHouse = 0 + robAmount(nums, index + 1);

        // Return the maximum of the two options
        return max(robHouse, skipHouse);
    }

    int rob(vector<int>& nums) {
        // Start the recursion from the first house (index 0)
        return robAmount(nums, 0);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```
