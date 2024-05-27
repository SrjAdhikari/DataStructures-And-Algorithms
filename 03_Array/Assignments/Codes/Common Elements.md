# Question : [Common Elements - GFG](https://www.geeksforgeeks.org/problems/common-elements1132/1)

Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

### Example 1

```plaintext
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
```

### Your Task

You don't need to read input or print anything. Your task is to complete the function commonElements() which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs and returns an array containing the common element present in all the 3 arrays in sorted order.
If there are no such elements return an empty array. In this case the output will be printed as -1.

```plaintext
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

`1 <= n1, n2, n3 <= 10^5`

`The array elements can be both positive or negative integers.`

## Solution 1

```Cpp

class Solution {
public:
    vector<int> commonElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
        int i = 0;  // Pointer for arr1
        int j = 0;  // Pointer for arr2
        int k = 0;  // Pointer for arr3
        vector<int> result;  // To store common elements

        // Traverse all three arrays while elements are left in each
        while (i < n1 && j < n2 && k < n3) {
            // Check if the current elements in all arrays are the same
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                result.push_back(arr1[i]);  // Add common element to result

                // Move to the next distinct elements to avoid duplicates
                int currElement = arr1[i];
                while (i < n1 && arr1[i] == currElement) i++;
                while (j < n2 && arr2[j] == currElement) j++;
                while (k < n3 && arr3[k] == currElement) k++;
            }
            // If current element in arr1 is smaller, move pointer i to next element
            else if (arr1[i] < arr2[j])
                i++;
            // If current element in arr2 is smaller, move pointer j to next element
            else if (arr2[j] < arr3[k])
                j++;
            // If current element in arr3 is smaller, move pointer k to next element
            else
                k++;
        }
        return result;  // Return the list of common elements
    }
};

Time Complexity = O(arr1 + arr2 + arr3)
Space Complexity = O(arr1)
```
