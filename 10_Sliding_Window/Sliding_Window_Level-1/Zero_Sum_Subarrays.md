# Question : [Zero Sum Subarrays - GFG](https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1)

You are given an array `arr[]` of size `n`. Find the total count of sub-arrays having their sum equal to 0.

### Example 1

```
Input: n = 6, arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
```

### Example 2

```
Input: n = 10, arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4], [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]
```

```
Expected Time Complexity: O(n*log(n))
Expected Auxilliary Space: O(n)
```

### Constraints

- `1 <= n <= 10^6`
- `-10^9 <= arr[ i ] <= 10^9`

## Solution 1 : Brute Force Approach I

```Cpp
class Solution {
public:
    // Function to count subarrays with sum equal to 0
    long long int findSubarray(vector<long long int>& arr, int n) {
        int total = 0; // This variable keeps track of the total count of subarrays whose sum is 0

        // Outer loop runs from the 0th element to the (n-1)th element.
        for (int i = 0; i < n; i++) {
            // For each starting index 'i', iterate through possible ending indices 'j'
            for (int j = i; j < n; j++) {
                int sum = 0;        // Variable to store the sum of elements from index 'i' to 'j'

                // Inner loop to calculate the sum of elements between 'i' and 'j'
                for (int k = i; k <= j; k++) {
                    sum += arr[k];  // Accumulate the sum of elements in the current subarray
                }

                // If the sum of the current subarray is 0, increment the total count
                if (sum == 0) {
                    total++;
                }
            }
        }

        // Return the total number of subarrays with sum equal to 0
        return total;
    }
};

Time Complexity = O(N^3)
Space Complexity = O(1)
```

## Solution 2 : Brute Force Approach II

```Cpp
class Solution {
public:
    // Function to count subarrays with sum equal to 0
    long long int findSubarray(vector<long long int>& arr, int n) {
        int total = 0;  // Variable to store the total number of subarrays with sum 0

        // This loop runs from the 0th element to the (n-1)th element.
        for (int i = 0; i < n; i++) {
            int sum = 0;  // Initialize sum for the current subarray

            // This loop runs from the current starting index (i) to the end of the array.
            for (int j = i; j < n; j++) {
                // Add the current element to the cumulative sum
                sum += arr[j];

                // Check if the current sum is 0
                if (sum == 0) {
                    total++;  // Increment the count if a subarray with sum 0 is found
                }
            }
        }

        // Return the total number of subarrays whose sum is equal to 0
        return total;
    }
};

Time Complexity = O(N^2)
Space Complexity = O(1)
```

## Solution 3 : Optimized Approach

```Cpp
class Solution {
public:
    // Function to count subarrays with sum equal to 0
    long long int findSubarray(vector<long long int>& arr, int n) {
        // Stores the total count of subarrays with sum 0
        long long int total = 0;

        // Map to store prefix sums and their frequencies
        unordered_map<long long int, long long int> map;   

        // This variable keeps track of the prefix sum up to the current index 
        long long int prefixSum = 0;

        // Initialize the map with prefix sum 0, as a subarray starting from index 0 can be a valid subarray with sum 0
        map[0] = 1;

        // Loop through the array to calculate prefix sums and count subarrays
        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];  // Update the prefix sum with the current element

            // If the current prefix sum has been seen before, it means there are subarrays with sum 0
            if (map.find(prefixSum) != map.end()) {
                // Add the number of times this prefix sum has been seen to the total
                total += map[prefixSum];

                // Increment the count of this prefix sum in the map
                map[prefixSum]++; 
            }
            // If this is the first occurrence of the prefix sum, add it to the map
            else {
                map[prefixSum]++; 
            }
        }

        // Return the total count of subarrays with sum 0
        return total;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```