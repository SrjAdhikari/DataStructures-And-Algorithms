# Question : [Largest Rectangle in Histogram - (LeetCode : 84)](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return *the area of the largest rectangle in the histogram*.

### Example 1
![](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)
```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

### Example 2
![](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)
```
Input: heights = [2,4]
Output: 4
```

### Constraints

-   `1 <= heights.length <= 10^5`
-   `0 <= heights[i] <= 10^4`

## Solution 1

```Cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Get the number of elements in the heights array
        int n = heights.size();
        
        // Vectors to store the indices of the next smallest element to the right and left of each bar
        vector<int> nextSmallestRight(n);  // Stores the index of the next smaller element on the right
        vector<int> nextSmallestLeft(n);   // Stores the index of the next smaller element on the left
        
        // Stack to assist in finding the next smallest element in a single pass for both directions
        stack<int> st;

        // Step 1: Find the next smallest element to the right of each bar
        for (int i = 0; i < n; i++) {
            // As long as the stack is not empty and the current height is smaller than the height of the bar at the index on top of the stack
            while (!st.empty() && heights[i] < heights[st.top()]) {
                // The next smaller element to the right of the bar at index st.top() is at index i
                nextSmallestRight[st.top()] = i;
                st.pop();   // Remove the index from the stack since we've found its next smaller element
            }
            st.push(i);     // Push the current index onto the stack
        }

        // After processing all elements, for those remaining in the stack, there is no smaller element on the right
        while (!st.empty()) {
            nextSmallestRight[st.top()] = n;    // Use 'n' to indicate there is no smaller element to the right
            st.pop();                           // Remove the processed element
        }

        // Step 2: Find the next smallest element to the left of each bar
        for (int i = n - 1; i >= 0; i--) {
            // As long as the stack is not empty and the current height is smaller than the height of the bar at the index on top of the stack
            while (!st.empty() && heights[i] < heights[st.top()]) {
                // The next smaller element to the left of the bar at index st.top() is at index i
                nextSmallestLeft[st.top()] = i;
                st.pop();   // Remove the index from the stack since we've found its next smaller element
            }
            st.push(i);     // Push the current index onto the stack
        }

        // After processing all elements, for those remaining in the stack, there is no smaller element on the left
        while (!st.empty()) {
            nextSmallestLeft[st.top()] = -1;    // Use '-1' to indicate there is no smaller element to the left
            st.pop();                           // Remove the processed element
        }

        // Step 3: Calculate the largest rectangular area
        int area = INT_MIN;     // Variable to store the maximum area
        for (int i = 0; i < n; i++) {
            // The height of the rectangle is given by the height of the current bar
            int length = heights[i];

            // The width of the rectangle is calculated as the difference between the indices of the next smaller elements to the left and right of the current bar, Subtract 1 to exclude the current bar itself from the width
            int breadth = nextSmallestRight[i] - nextSmallestLeft[i] - 1;

            // Calculate the area of the rectangle with heights[i] as the smallest bar and update the maximum area
            area = max(area, (length * breadth));
        }
        
        // Return the maximum rectangular area found
        return area;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```


## Solution 2

```Cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // Get the number of elements in the heights array
        int index;              // Variable to store the current index being processed
        stack<int> st;          // Stack to store the indices of the heights in increasing order
        int area = INT_MIN;     // Variable to store the maximum area found, initialized to the smallest possible value

        // Step 1: Traverse through the heights array to process each bar
        for (int i = 0; i < n; i++) {
            // Check if the current height is smaller than the height at the top of the stack
            // This means we have found a boundary where the rectangle can end
            while (!st.empty() && heights[i] < heights[st.top()]) {
                index = st.top(); // Get the index of the top element in the stack
                st.pop();         // Pop the top element as we are processing it

                // Calculate the area with heights[index] as the smallest height
                if (!st.empty()) {
                    // If the stack is not empty, calculate the width as (i - st.top() - 1)
                    area = max(area, heights[index] * (i - st.top() - 1));
                } else {
                    // If the stack is empty, this means heights[index] is the smallest so far
                    // So, the width is 'i' itself (i.e., from index 0 to i-1)
                    area = max(area, heights[index] * i);
                }
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Step 2: Process any remaining bars in the stack (After processing all elements, some bars may still be in the stack. We calculate areas for these.)
        while (!st.empty()) {
            index = st.top(); // Get the index of the top element in the stack
            st.pop();         // Pop the top element as we are processing it

            // Calculate the area with heights[index] as the smallest height
            if (!st.empty()) {
                // If the stack is not empty, calculate the width as (n - st.top() - 1)
                area = max(area, heights[index] * (n - st.top() - 1));
            } else {
                // If the stack is empty, the width is 'n' (i.e., the entire array)
                area = max(area, heights[index] * n);
            }
        }

        // Return the maximum area found
        return area;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
