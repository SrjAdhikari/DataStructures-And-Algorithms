# Question : [First Repeating Element - GFG](https://www.geeksforgeeks.org/problems/first-repeating-element4018/1)

Given an array arr[] of size n, find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

**Note:** The position you return should be according to 1-based indexing.

### Example 1

```plaintext
Input:
n = 7
arr[] = {1, 5, 3, 4, 3, 5, 6}
Output: 2
Explanation:
5 is appearing twice and
its first appearence is at index 2
which is less than 3 whose first
occuring index is 3.
```

### Example 2

```plaintext
Input:
n = 4
arr[] = {1, 2, 3, 4}
Output: -1
Explanation:
All elements appear only once so
answer is -1.
```

### Your Task

You don't need to read input or print anything. Complete the function firstRepeated() which takes arr and n as input parameters and returns the position of the first repeating element. If there is no such element, return -1.

```plaintext
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

`1 <= n <= 10^6`

`0 <= Ai<= 10^6`

## Solution 1

```Cpp
Brute Force Approach : 

class Solution {
public:
    int firstRepeated(int arr[], int n) {

        // Iterate over each element in the array
        for(int i = 0; i < n; i++) {
            bool isRepeated = false;    // Flag to check if the current element is repeated
            
            // Check the rest of the array for the current element
            for(int j = i + 1; j < n; j++) {
                // If a duplicate is found
                if(arr[i] == arr[j]) {
                    isRepeated = true;      // Set the flag to true
                    return i + 1;           // Return the 1-based index of the first repeating element
                }
            }
        }

        // If no repeating element is found, return -1
        return -1;
    }
};

Time Complexity = O(n^2)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Optimised Approach (Using Hash Table) : 

class Solution {
public:
    int firstRepeated(int arr[], int n) {

        // Create an unordered map to store the count of each element
        unordered_map<int, int> hash;

        // Traverse the array and populate the hash map with element counts
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        // Traverse the array again to find the first element with a count greater than 1
        for (int i = 0; i < n; i++) {
            if (hash[arr[i]] > 1) {
                return i + 1;       // Return 1-based index of the first repeating element
            }
        }

        return -1;      // If no repeating element is found, return -1
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
