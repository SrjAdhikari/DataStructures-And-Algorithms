# Question : [Remove Duplicates from Sorted Array - (LeetCode : 26)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates in-place such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**. Then return _the number of unique elements in_ `nums`.

Consider the number of unique elements of `nums`@ to be `k`, to get accepted, you need to do the following things:

1. Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
2. Return `k`.

### Custom Judge:

The judge will test your solution with the following code:

```plaintext
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted**.

### Example 1

```plaintext
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Example 2

```plaintext
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Constraints

```plaintext
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
```

## Solution 1

```Cpp

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int index = 1;  // Start from the second element
        int uniqueIndex = 0;  // Index of the last unique element

        // Loop through the array starting from the second element
        while (index < nums.size()) {
            // If the current element is the same as the last unique element
            if (nums[index] == nums[uniqueIndex]) {
                index++;  // Move to the next element
            }
            // If the current element is different from the last unique element
            else {
                uniqueIndex++;  // Move the unique index to the next position
                nums[uniqueIndex] = nums[index];  // Update the next unique position with the current element
            }
        }

        // Return the number of unique elements
        return uniqueIndex + 1;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
