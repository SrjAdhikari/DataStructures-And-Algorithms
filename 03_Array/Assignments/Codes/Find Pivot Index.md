# Question : [Find Pivot Index - (LeetCode : 724)](https://leetcode.com/problems/find-pivot-index/description/)

Given an array of integers `nums`, calculate the **pivot index** of this array.

The **pivot index** is the index where the sum of all the numbers **strictly** to the left of the index is equal to the sum of all the numbers **strictly** to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return the **leftmost pivot index.** If no such index exists, return `-1`.

### Example 1:

```plaintext
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
```

### Example 2 :

```plaintext
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```

### Example 3 :

```plaintext
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
```

### Constraints:

```plaintext
1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
```

## Solution 1

```Cpp
Brute Force Approach :

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Loop to iterate through each elements of the array
        for(int i = 0; i < n; i++){
            int leftSum, rightSum = 0;

            // Calculate sum of element to the left
            for(int j = 0; j < i; j++){
                leftSum += nums[i];
            }

            // Calculate sum of element to the right
            for(int j = i + 1; j < n; j++){
                rightSum += nums[i];
            }

            // Check if leftSum is equal to rightSum
            if(leftSum == rightSum)
                return i;   // Pivot index found
        }
        return -1;  // No pivot index found
    }
};

Time Complexity = O(n) * (O(n) + O(n))
                = O(n) * O(n) => O(n^2)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Optimal Approach (Using Two Vectors) :

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Initialize vector to store left and right sum
        vector<int>leftSum(n, 0);
        vector<int>rightSum(n, 0);

        // Calculate left sum
        for(int i = 1; i < n; i++){
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        // Calculate right sum
        for(int i = n - 2; i >= 0; i--){
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        // Check for pivot index using left and right sum
        for(int i = 0; i < n; i++){
            if(leftSum[i] == rightSum[i]){
                return i;   // Pivot index found
            }
        }
        return -1;  // No pivot index found
    }
};

Time Complexity = O(n) + O(n) + O(n) => O(n)
Space Complexity = O(n)
```

## Solution 3

```Cpp

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        // Calculate the total sum of the array
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];                                // Sum all elements in the array
        }

        int prefixSum = 0;                                      // Initialize prefix sum to 0
        for(int i = 0; i < n; i++){
            int suffixSum = totalSum - prefixSum - nums[i];     // Calculate suffix sum
            if(prefixSum == suffixSum){                         // Check if prefix sum is equal to suffix sum
                return i;                                       // Return the current index if it is a pivot index
            }
            prefixSum += nums[i];                               // Update prefix sum
        }
        return -1;                                              // Return -1 if no pivot index is found
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
