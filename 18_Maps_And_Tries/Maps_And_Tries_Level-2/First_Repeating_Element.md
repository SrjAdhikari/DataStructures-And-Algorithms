# Question : [First Repeating Element - GFG](https://www.geeksforgeeks.org/problems/first-repeating-element4018/1)

Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

**Note**: The position you return should be according to 1-based indexing. 

### Example 1

```
Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 
which is less than 3 whose first the occurring index is 3.
```

### Example 2

```
Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.
```

```
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
```

### Constraints

- `1 <= arr.size <= 10^6`
- `0 <= arr[i]<= 10^6`

## Solution

```Cpp
class Solution {
public:
    // Function to find the index of the first repeating element in the array.
    int firstRepeated(vector<int> &arr) {
        // Variable to store the 1-based index of the first repeating element
        int ans = -1;

        // Declare an unordered map to keep track of the elements we have seen.
        unordered_map<int, bool> mp;

        // Iterate through the array from the end to the beginning (right to left)
        // This ensures that the first repeated element we encounter will have the smallest index
        for (int i = arr.size() - 1; i >= 0; i--) {
            // Check if the current element already exists in the map (i.e., has been seen before)
            if (mp.count(arr[i])) {
                // If it is, update the answer to the current index (1-based)
                ans = i + 1;
            } 
            // If it is not in the map, mark it as seen
            else {
                mp[arr[i]] = true;
            }
        }

        // Return the 1-based index of the first repeated element, or -1 if no repetition is found
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```