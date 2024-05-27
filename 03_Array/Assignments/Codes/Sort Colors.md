# Question : [Sort Colors - (LeetCode : 75)](https://leetcode.com/problems/sort-colors/description/)

Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

### Example 1

```plaintext
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

### Example 2

```plaintext
Input: nums = [2,0,1]
Output: [0,1,2]
```

### Constraints

`n == nums.length`

`1 <= n <= 300`

`nums[i] is either 0, 1, or 2.`

## Solution 1

```Cpp

class Solution {
public:
    // Function to sort an array of colors represented as 0, 1, and 2 (red, white, and blue)
    void sortColors(vector<int>& nums) {

        int n = nums.size();                        // Get the size of the array
        int index = 0, left = 0, right = n - 1;     // Initialize three pointers: index, left, and right

        // Iterate through the array until index meets or exceeds right
        while(index <= right){
            // If the current element is 0 (red), swap it with the element at the left pointer
            // and increment both left and index pointers
            if(nums[index] == 0){
                swap(nums[index], nums[left]);
                left++, index++;
            }

            // If the current element is 2 (blue), swap it with the element at the right pointer
            // and decrement the right pointer
            else if(nums[index] == 2){
                swap(nums[index], nums[right]);
                right--;
            }
            
            // If the current element is 1 (white), simply move to the next element (increment index)
            else {
                index++;
            }
        } 
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
