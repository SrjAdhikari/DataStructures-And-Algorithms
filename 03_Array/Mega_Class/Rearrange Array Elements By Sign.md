# Question : [Rearrange Array Elements by Sign - (LeetCode : 2149)](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)

You are given a **0-indexed** integer array `nums` of **even** length consisting of an **equal** number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

1. Every **consecutive pair** of integers have **opposite signs.**
2. For all integers with the same sign, the order in which they were present in `nums` is **preserved.**
3. The rearranged array begins with a positive integer.

Return *the modified array after rearranging the elements to satisfy the aforementioned conditions.*

### Example 1

```plaintext
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 
```

### Example 2

```plaintext
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
```

### Constraints

`2 <= nums.length <= 2 * 10^5`

`nums.length is even`

`1 <= |nums[i]| <= 10^5`

`nums consists of equal number of positive and negative integers`

It is not required to do the modifications in-place.


## Solution 1

```Cpp
Using Extra Space : 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // Get the size of the input vector.
        int n = nums.size();
        
        // Create separate vectors to store positive and negative integers.
        vector<int> positive, negative;

        // Separate positive and negative integers into their respective vectors.
        for(int i = 0; i < n; i++){
            if(nums[i] > 0)
                positive.push_back(nums[i]);
            else
                negative.push_back(nums[i]);
        }

        // Create a new vector to store the rearranged elements.
        vector<int> ans;
        int i = 0;

        // Interleave positive and negative integers until one of them is exhausted.
        while(i < positive.size()){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
            i++;
        }
        
        // Return the rearranged vector.
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Two Pointer Approach : 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // Get the size of the input vector.
        int n = nums.size();
        
        // Create a new vector 'ans' of size 'n' initialized with -1.
        vector<int> ans(n, -1);

        // Initialize indices for even and odd positions.
        int odd = 1;
        int even = 0;

        // Iterate through the input vector.
        for(int i = 0; i < n; i++){

            // If the current number is positive, place it at the next even index.
            if(nums[i] > 0){
                ans[even] = nums[i];
                even += 2;
            }

            // If the current number is negative, place it at the next odd index.
            else{
                ans[odd] = nums[i];
                odd += 2;
            }
        }
        
        // Return the rearranged vector.
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```