# Question : [Height of Heap - GFG](https://www.geeksforgeeks.org/problems/height-of-heap5025/1)

Given a Binary Heap of size `N` in an array `arr[]`. Write a program to calculate the height of the Heap.

**Note**: Return 1 if the N is 1.

### Example 1

```
Input: N = 6
arr = {1, 3, 6, 5, 9, 8}
Output: 2
Explaination: The tree is like the following
        (1)
       /   \
    (3)    (6)
    / \     /
  (5) (9) (8)
```

### Example 2

```
Input: N = 9
arr = {3, 6, 9, 2, 15, 10, 14, 5, 12}
Output: 3
Explaination: The tree looks like following
           (2)
        /      \
      (3)      (9)
     /  \     /   \
   (5) (15) (10) (14)
   / \
 (6) (12)
```

### Your Task:

You do not need to read input or print anything. Your task is to complete the function `heapHeight()` which takes the value N and the array arr as input parameters and returns the height of the heap.

```
Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)
```

### Constraints

- `1 ≤ N ≤ 10^4`
- `1 ≤ arr[i] ≤ 10^6`

## Solution

```Cpp
class Solution {
public:
    int heapHeight(int N, int arr[]) {
        // Initialize the height variable to store the height of the heap.
        int height = 0;

        // If the heap contains only one element, its height is 1.
        if(N == 1)
            return 1;

        // The loop continues until N reduces to 1, dividing N by 2 at each step.
        // This simulates moving up one level in the binary heap because 
        // each level has approximately half the number of nodes as the previous one.
        while(N > 1) {
            // Each time we divide N by 2, we increment the height by 1.
            height++;
            
            // Move to the parent node of the current node.
            N /= 2;
        }

        // Return the total height of the heap.
        return height;
    }
};

Time Complexity = O(logN)
Space Complexity = O(1)
```