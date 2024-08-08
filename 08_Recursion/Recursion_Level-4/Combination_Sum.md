# Question : [Combination Sum - (LeetCode : 39)](https://leetcode.com/problems/combination-sum/description/)

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all* ***unique combinations*** of `candidates` *where the chosen numbers sum to* `target`. You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

### Example 1
```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

### Example 2
```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

### Example 3
```
Input: candidates = [2], target = 1
Output: []
```

### Constraints

-   `1 <= candidates.length <= 30`
-   `2 <= candidates[i] <= 40`
-   All elements of `candidates` are distinct.
-   `1 <= target <= 40`

## Solution

```Cpp

class Solution {
public:
    // Helper function to find all combinations that sum up to the target
    void printCombination(vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int>& temp) {
        // Base case: if the target is 0, add the current combination to the result
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // Base case: if we have considered all candidates or the target becomes negative, stop recursion
        if(index == candidates.size() || target < 0) {
            return;
        }

        // Recursive call without including the current candidate
        printCombination(candidates, index + 1, target, ans, temp);

        // Include the current candidate in the combination
        temp.push_back(candidates[index]);

        // Recursive call including the current candidate (allowing for repeated use of the same candidate)
        printCombination(candidates, index, target - candidates[index], ans, temp);

        // Backtrack: remove the last added candidate to explore other combinations
        temp.pop_back();
    }

    // Function to find all combinations that sum up to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;    // Vector to store all valid combinations
        vector<int> temp;           // Temporary vector to store the current combination
        printCombination(candidates, 0, target, ans, temp);
        return ans;                 // Return all valid combinations
    }
};

Time Complexity = O(2^n * k)
Space Complexity = O(n + k)
=> where n is the number of candidates and k is the average length of a combination.
```