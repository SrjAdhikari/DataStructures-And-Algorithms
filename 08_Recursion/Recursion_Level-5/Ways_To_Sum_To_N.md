# Question : [Ways to sum to N - GFG](https://www.geeksforgeeks.org/problems/ways-to-sum-to-n5759/1)

Given a set of m distinct positive integers and a value ‘N’. Count the total number of ways we can form ‘N’ by adding the array elements. Repetitions and different arrangements are allowed.
**Note**: Answer can be quite large output the answer modulo 109+7.

### Example 1

```
Input:
m = 3 , N = 7
Arr[] = {1,5,6}
Output: 6
Explanation: The different ways are:
1+1+1+1+1+1+1
1+1+5
1+5+1
5+1+1
1+6
6+1
```

### Example 2

```
Input:
m = 3 , N = 3
Arr[] = {1,2,3}
Output: 4
Explanation: The different ways are:
1+1+1
1+2
2+1
3
```

### Your Task:

You don't need to read input or print anything. Your task is to complete the function **countWays()** which accepts array arr[], its size m and integer N and returns the total number of ways we can form ‘N’ by adding array elements.

```
Expected Time Complexity: O(N*m)
Expected Auxiliary Space: O(N)
```

### Constraints

`1 <= N , m <= 10^3`

## Solution

```Cpp

class Solution {
public:
    int totalWays(int arr[], int m, int sum) {
        // Base case: If the sum is 0, there is one way to achieve it (by not choosing any element)
        if (sum == 0) return 1;

        // If the sum becomes negative, there are no valid ways to achieve it
        if (sum < 0) return 0;

        long long ans = 0;

        // Iterate over each element in `arr` and recursively calculate the number of ways
        for (int i = 0; i < m; i++) {
            ans += totalWays(arr, m, sum - arr[i]);
        }

        // Return the result modulo 1000000007 to avoid overflow
        return ans % 1000000007;
    }

    int countWays(int arr[], int m, int N) {
        return totalWays(arr, m, N);
    }
};

Time Complexity = O(N^m)
Space Complexity = O(N)
```
