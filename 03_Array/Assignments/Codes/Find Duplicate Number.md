# Question : [Find the Duplicate Number - (LeetCode : 287)](https://leetcode.com/problems/find-the-duplicate-number/description/)

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only one repeated number in `nums`, return this repeated number.

You must solve the problem without modifying the array `nums` and uses only constant extra space.

### Example 1

```plaintext
Input: nums = [1,3,4,2,2]
Output: 2
```

### Example 2

```plaintext
Input: nums = [3,1,3,4,2]
Output: 3
```

### Example 3

```plaintext
Input: nums = [3,3,3,3,3]
Output: 3
```

### Constraints

`1 <= n <= 10^5`

`nums.length == n + 1`

`All the integers in nums appear only once except for precisely one integer which appears two or more times.`

### Follow up

How can we prove that at least one duplicate number must exist in `nums`?

Can you solve the problem in linear runtime complexity?

## Solution 1

```Cpp
Brute Force Approach (Using STL sort() function) :

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //  Sort the array
        sort(nums.begin(), nums.end());

        // Iterate over the array
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i + 1]){
                return nums[i];
            }
        }
        return -1;
    }
};

Time Complexity = O(nlogn)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Negative Marking (Visited) Method : 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int ans = -1;   // Variable to store duplicate number

        // Interate over the array
        for(int i = 0; i < nums.size(); i++){
            // Get the index to be checked (using absolute value to handle negative numbers)
            int index = abs(nums[i]);
            
            // Check if the element at the calculated index is negative
            if(nums[index] < 0){    // If true, it means this index has been encountered before indicating a duplicate
                ans = index;
                break;
            }

            // Mark the element at the calculated index as visited by making it negative
            nums[index] *= -1;
        }
        return ans;     // Return the found duplicate number
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```

## Solution 3

```Cpp
Positioning Method : 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Iterate until the value at the current index is not equal to the value at the index
        // equal to the value at the current index
        while(nums[0] != nums[nums[0]]){

            // Swap the value at index 0 with the value at the index equal to the value at index 0
            swap(nums[0], nums[nums[0]]);
        }

        // Return the duplicate number found
        return nums[0];
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```