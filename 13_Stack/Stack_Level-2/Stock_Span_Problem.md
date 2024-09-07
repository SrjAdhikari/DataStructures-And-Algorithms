# Question : [Stock span problem - GFG](https://www.geeksforgeeks.org/problems/next-greater-element/1)

The stock span problem is a financial problem where we have a series of `n` daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span `Si` of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

### Example 1

```
Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span 
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6. 
Hence the output will be 1 1 1 2 1 4 6.
```

### Example 2

```
Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span 
10 is greater than equal to 10 and there are no more elements behind it so the span is 1,
4 is greater than equal to 4 and smaller than 10 so the span is 1,
5 is greater than equal to 4,5 and smaller than 10 so the span is 2,
90 is greater than equal to all previous elements so the span is 4,
120 is greater than equal to all previous elements so the span is 5,
80 is greater than equal to 80 and smaller than 120 so the span is 1,
Hence the output will be 1 1 2 4 5 1.
```

### Your Task:

The task is to complete the function `calculateSpan()` which takes two parameters, an array `price[]` denoting the price of stocks, and an integer `N` denoting the size of the array and number of days. This function finds the span of stock's price for all N days and returns an array of length `N` denoting the span for the i-th day.

```
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `1 ≤ N ≤ 10^5`
-   `1 ≤ C[i] ≤ 10^5`

## Solution

```Cpp
class Solution {
public:
    // Function to calculate the span of stock’s price for all n days.
    vector<int> calculateSpan(int price[], int n) {
        // Stack to store indices of stock prices. 
        // This helps track how far back the current price is greater than the previous prices.
        stack<int> st;
        
        // Vector to store the result (span of each day).
        vector<int> ans(n);
        
        // Traverse the prices from the last day to the first day (right to left).
        for(int i = n - 1; i >= 0; i--) {

            // While the stack is not empty and the current price is greater than the price at the index stored at the top of the stack, 
            // it means the price[i] is higher, so we calculate the span for price[st.top()].
            while(!st.empty() && price[i] > price[st.top()]) {
                // Calculate the span for the day at st.top() as the difference between the current day i and st.top().
                ans[st.top()] = st.top() - i;

                // Pop the index from the stack as we have computed its span.
                st.pop();
            }

            // Push the current index i onto the stack to find its span in future iterations.
            st.push(i);
        }

        // For the remaining elements in the stack, it means they don't have any greater price on their left,
        // so their span is simply their index + 1 (i.e., they span back to the first day).
        while(!st.empty()) {
            ans[st.top()] = st.top() + 1;
            st.pop();
        }

        // Return the result vector containing the stock span for each day.
        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
