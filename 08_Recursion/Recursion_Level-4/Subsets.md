# Question : [Subsets - (LeetCode : 78)](https://leetcode.com/problems/subsets/description/)

Given an integer array `nums` of **unique** elements, *return all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

### Example 1
```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

### Example 2
```
Input: nums = [0]
Output: [[],[0]]
```

### Constraints

-   `1 <= nums.length <= 10`
-   `-10 <= nums[i] <= 10`
-   All the numbers of `nums` are **unique**.

## Solution

```Cpp

class Solution {
public:
    // Function to print all subsequences of a vector
    void printSubsequences(vector<int>& arr, int index, int size, vector<vector<int> >& ans, vector<int>& temp) {
        // Base case: If we've considered all elements in the vector
        if(index == size) {
            // Add the current subsequence to the answer list
            ans.push_back(temp);
            return;
        }

        // Recursive call without including the current element in the subsequence
        printSubsequences(arr, index + 1, size, ans, temp);

        // Include the current element in the subsequence
        temp.push_back(arr[index]);

        // Recursive call including the current element in the subsequence
        printSubsequences(arr, index + 1, size, ans, temp);

        // Backtrack: Remove the current element to explore other subsequences
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        int index = 0;
        int size = nums.size();

        printSubsequences(nums, index, size, ans, temp);
        return ans;
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```