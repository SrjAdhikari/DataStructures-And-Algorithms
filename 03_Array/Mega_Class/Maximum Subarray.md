# Question : [Maximum Subarray - (LeetCode : 53)](https://leetcode.com/problems/maximum-subarray/description/)

Given an integer array `nums`, find the subarray with the largest sum, and return *its sum*.

### Example 1

```plaintext
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

### Example 2

```plaintext
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

### Example 3

```plaintext
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

### Constraints

`1 <= nums.length <= 10^5`

`-10^4 <= nums[i] <= 10^4`


### Follow up
If you have figured out the `O(n)` solution, try coding another solution using the divide and conquer approach, which is more subtle.


## Solution 1

```Cpp
Brute Force Approach : 

class Solution {
public:
    // Find the largest sum of subarrays using the brute-force approach
    int bruteForceApproach(vector<int>& nums) {

        int ans = INT_MIN;      // Initialize the answer with the minimum possible integer value

        // Loop through each element in the array as a potential starting point of the subarray
        for(int i = 0; i < nums.size(); i++) {

            int sum = 0;    // Initialize the sum of the current subarray

            // Loop through the elements starting from the current index (nums[i])
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];         // Add the current element to the sum
                ans = max(ans, sum);    // Update the answer with the maximum sum found so far
            }
        }
        return ans;                     // Return the largest sum found
    }

    int maxSubArray(vector<int>& nums) {
        return bruteForceApproach(nums);
    }
};

Time Complexity = O(n^2)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Kadane's Algorithm : 

class Solution {
public:
    int kadaneAlgo(vector<int>& nums){

        // Initialize variables to store the maximum sum found so far (ans) 
        // and the current sum of elements being considered (sum).
        int ans = INT_MIN;
        int sum = 0;
        
        // Iterate through each element of the input vector.
        for(int i = 0; i < nums.size(); i++){
            
            // Add the current element to the sum.
            sum += nums[i];
            
            // Update the answer (maximum sum) if the current sum is greater.
            ans = max(ans, sum);
            
            // If the current sum becomes negative, reset it to 0.
            // This is because any negative sum will only decrease the 
            // total sum of the subarray, so it's better to start a new 
            // subarray from the next element.
            if(sum < 0)
                sum = 0;
        }
        
        // Return the maximum sum found.
        return ans;
    }

    int maxSubArray(vector<int>& nums) {
        return kadaneAlgo(nums);
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```