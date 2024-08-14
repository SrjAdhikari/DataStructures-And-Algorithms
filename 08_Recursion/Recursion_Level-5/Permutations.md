# Question : [Permutations - (LeetCode : 46)](https://leetcode.com/problems/permutations/description/)

Given an array `nums` of distinct integers, return _all the possible permutations_. You can return the answer in **any order**.

### Example 1

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

### Example 2

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

### Example 3

```
Input: nums = [1]
Output: [[1]]
```

### Constraints

-   `1 <= nums.length <= 6`
-   `-10 <= nums[i] <= 10`
-   All the integers of `nums` are unique.

## Solution 1

```Cpp
Using Extra Space :

class Solution {
public:
    // Function to find all permutations of a vector of integers
    void findPermute(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& visited) {
        // Base case: If the current permutation `temp` has reached the size of `nums`, add it to `ans`
        if (nums.size() == temp.size()) {
            ans.push_back(temp);                            // Add the current permutation to the result list
            return;
        }

        // Iterate through each number in nums
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not yet included in the permutation or not yet visited.
            if (visited[i] == 0) {
                visited[i] = 1;                             // Mark the number as visited
                temp.push_back(nums[i]);                    // Add the number to the current permutation
                findPermute(nums, ans, temp, visited);      // Recur to find permutations with the updated state

                // Backtrack: unmark the number as visited and remove it from the current permutation
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }

    // Function to initialize the permutation process and return all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();                        // Size of the input vector
        vector<vector<int>> ans;                    // Resultant vector to store all permutations
        vector<int> temp;                           // Temporary vector to store the current permutation
        vector<bool> visited(n, 0);                 // Vector to keep track of visited indices
        findPermute(nums, ans, temp, visited);      // Start the permutation process
        return ans;                                 // Return all permutations
    }
};

Time Complexity = O(n!)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Without Using Extra Space :

class Solution {
public:
    // This function generates all permutations of the input vector `nums` using backtracking with swapping.
    // It fills `ans` with all possible permutations of `nums`.
    void findPermute(vector<int>& nums, vector<vector<int>>& ans, int index) {
        // If the current index is equal to the size of `nums`, it means we have a complete permutation
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Iterate over the elements starting from the current index
        for(int i = index; i < nums.size(); i++) {
            // Swap the current element with the element at `index` to create a new permutation
            swap(nums[index], nums[i]);

            // Recursively generate permutations for the next index
            findPermute(nums, ans, index + 1);

            // Backtrack by swapping the elements back to their original positions
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;              // Start index for permutation generation
        vector<vector<int>> ans;    // To store all permutations

        // Start the permutation process
        findPermute(nums, ans, index);

        return ans;
    }
};

Time Complexity = O(n!)
Space Complexity = O(n)
```
