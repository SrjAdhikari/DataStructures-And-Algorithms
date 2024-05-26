# Question : [Missing Number - (LeetCode : 268)](https://leetcode.com/problems/missing-number/description/)

Given an array `nums` containing n distinct numbers in the range `[0, n]`, *return the only number in the range that is missing from the array.*

### Example 1:
```plaintext
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

### Example 2 : 
```plaintext
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

### Example 3 : 
```plaintext
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

### Constraints:
```plaintext
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
```
**Follow up :** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

## Solution 1

```Cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        // Calculate sum of array elements
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        // Calculate sum of 'n' natural numbers with range [1, n]
        int actualSum = ((n) * (n + 1) / 2);
        int missingNum = actualSum - sum;

        return missingNum;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Using XOR Method :

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int missingNum = 0;

        // XOR all numbers of array
        for(int i = 0; i < n; i++){
            missingNum ^= nums[i];
        }

        // XOR all numbers from 0 ~ n
        for(int i = 0; i <= n; i++){
            missingNum ^= i;
        }
        return missingNum;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```