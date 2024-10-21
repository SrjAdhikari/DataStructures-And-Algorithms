# Question : [At Least K Occurrences - GFG](https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1)

Given an array of n integers. Return the element that occurs at least `k` number of times.

*Note*:
- If there are multiple answers, please return the first one.
- If there is no element found, return -1.

### Example 1

```
Input: n = 7, k = 2, arr[] = [1, 7, 4, 3, 4, 8, 7]
Output: 4
Explanation: Both 7 and 4 occur 2 times. But 4 is first that occurs twice. 
As the index = 4, is the first element.
```

### Example 2

```
Input: n = 10, k = 3, arr[] = [3, 1, 3, 4, 5, 1, 3, 3, 5, 4]
Output: 3
Explanation: Here, 3 is the only number that appeared atleast 3 times in the array.
```

### Example 3

```
Input: n = 3, k = 10, arr[] = [10, 8, 2]
Output: -1
Explanation: Here no element is returning atleast 10 number of times, so -1.
```

```
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
```

### Constraints

- `1 <= n <= 10^4`
- `1 <= k <= 100`
- `0 <= arr[i] <= 200`

## Solution

```Cpp
class Solution {
public:
    int firstElementKTime(int n, int k, int arr[]) {
        // Declare an unordered map to store the frequency of elements.
        unordered_map<int, int> ump;

        // Traverse through the array to count occurrences of each element.
        for(int i = 0; i < n; i++) {
            int num = arr[i];   // Get the current element.
            ump[num]++;         // Increment the frequency of the current element in the unordered map.
            
            // Check if the frequency of the current element becomes equal to k, return the element
            if(ump[num] == k)
                return num;     // Return the element if it appears `k` times.
        }
        
        // Return -1 if no element appears exactly `k` times.
        return -1;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```