# Question : [House Robber II - (LeetCode : 213)](https://leetcode.com/problems/house-robber-ii/description/)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle**. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the \*amount of money of each house, return the maximum amount of money you can rob tonight **\*without alerting the police\*\***.

### Example 1

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

### Example 2

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

### Example 3

```
Input: nums = [1,2,3]
Output: 3
```

### Constraints

-   `1 <= nums.length <= 100`
-   `0 <= nums[i] <= 1000`

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

## Solution

```Cpp

class Solution {
public:
    // Recursive function to calculate the maximum amount of money that can be robbed
    // starting from the given index and considering houses up to the given size
    int robAmount(vector<int>& nums, int index, int size) {
        // Base case: If the current index is out of bounds, return 0
        // This means we've considered all the houses we can rob from this starting point
        if (index > size) {
            return 0;
        }

        // Recursive case:
        // Option 1: Rob the current house and then skip the next house (move to index + 2)
        // This is because we can't rob two adjacent houses
        int robHouse = nums[index] + robAmount(nums, index + 2, size);

        // Option 2: Skip the current house and move to the next one (index + 1)
        // We consider the best amount from this point onwards without robbing the current house
        int skipHouse = robAmount(nums, index + 1, size);

        // Return the maximum of the two options:
        // 1. Robbing the current house and then considering the amount from the house after the next one
        // 2. Skipping the current house and considering the amount from the next house
        return max(robHouse, skipHouse);
    }

    // Function to calculate the maximum amount of money that can be robbed from a list of houses
    int rob(vector<int>& nums) {
        int size = nums.size();

        // Edge case: No houses to rob
        if (size == 0) return 0;

        // Edge case: Only one house to rob
        if (size == 1) return nums[0];

        // Case 1: Exclude the first house and rob from index 1 to size - 1
        // This means we consider the maximum amount of money we can rob if we start from the second house
        int robExcludingFirst = robAmount(nums, 1, size - 1);

        // Case 2: Exclude the last house and rob from index 0 to size - 2
        // This means we consider the maximum amount of money we can rob if we start from the first house and end at the second-to-last house
        int robExcludingLast = robAmount(nums, 0, size - 2);

        // Return the maximum of the two cases:
        // 1. Maximum amount robbing from index 1 to size - 1 (excluding the first house)
        // 2. Maximum amount robbing from index 0 to size - 2 (excluding the last house)
        return max(robExcludingFirst, robExcludingLast);
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```
