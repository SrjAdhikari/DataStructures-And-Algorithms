# Question : [Permutations II - (LeetCode : 47)](https://leetcode.com/problems/permutations-ii/description/)

Given a collection of numbers, `nums`, that might contain duplicates, return _all possible unique permutations_ **in any order**.

### Example 1

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

### Example 2

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

### Constraints

-   `1 <= nums.length <= 8`
-   `-10 <= nums[i] <= 10`

## Solution

```Cpp

class Solution {
public:
    #include <vector>
using namespace std;

    // This function generates all unique permutations of the input vector `nums` using backtracking with swapping. It fills `ans` with all unique permutations of `nums`.
    void findUniquePermute(vector<int>& nums, vector<vector<int>>& ans, int index) {
        // Base case: If the current index is equal to the size of `nums`, it means we have a complete permutation
        if(index == nums.size()) {
            ans.push_back(nums);    // Add the current permutation to the answer vector
            return;
        }

        // Vector to keep track of which elements have been used at the current index
        // Assuming nums[i] is between -10 and 10, we use a vector of size 21 to cover this range
        vector<bool> visited(21, false);

        // Iterate over the elements starting from the current index
        for(int i = index; i < nums.size(); i++) {
            // Check if the current element has already been used in the current position
            // The value nums[i] is shifted by 10 to handle negative values
            if(visited[nums[i] + 10] == 0) {
                // Swap the current element with the element at the current index
                swap(nums[index], nums[i]);

                // Recursively generate permutations for the remaining elements
                findUniquePermute(nums, ans, index + 1);

                // Backtrack by swapping the elements back to their original positions
                swap(nums[index], nums[i]);

                // Mark the current element as visited (used)
                visited[nums[i] + 10] = true;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int index = 0;              // Start index for permutation generation
        vector<vector<int>> ans;    // To store all unique permutations

        // Start the permutation process
        findUniquePermute(nums, ans, index);

        return ans;
    }
};

Time Complexity = O(n!)
Space Complexity = O(n)
```
