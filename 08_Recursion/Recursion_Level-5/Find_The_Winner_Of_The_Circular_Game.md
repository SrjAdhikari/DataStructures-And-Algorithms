# Question : [Find the Winner of the Circular Game - (LeetCode : 1823)](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.

The rules of the game are as follows:

1. **Start** at the`1st` friend.
2. Count the next `k` friends in the clockwise direction **including** the friend you started at. The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4. If there is still more than one friend in the circle, go back to step `2` **starting** from the friend **immediately clockwise** of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.

Given the number of friends, `n`, and an integer `k`, return _the winner of the game_.

### Example 1

![](https://assets.leetcode.com/uploads/2021/03/25/ic234-q2-ex11.png)

```
Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
```

### Example 2

```
Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
```

### Constraints

-   `1 <= k <= n <= 500`

## Solution 1

```Cpp
Brute-Force Approach :

class Solution {
public:
    int findWinner(vector<bool>& visited, int n, int index, int leftPerson, int k) {
        // Base case: If only one person is left, return their index as the winner
        if (leftPerson == 1) {
            for (int i = 0; i < n; i++) {
                if (!visited[i])
                    return i;
            }
        }

        // Calculate the position of the person to be eliminated
        int personToKill = (k - 1) % leftPerson;

        // Move index to the person to be killed
        while (personToKill--) {
            index = (index + 1) % n;
            while (visited[index]) {
                index = (index + 1) % n; // Skip the already eliminated person
            }
        }

        // Mark the selected person as eliminated
        visited[index] = true;

        // Find the next alive person to start the next round
        while (visited[index]) {
            index = (index + 1) % n;
        }

        // Recurse to find the next person to eliminate until one person is left
        return findWinner(visited, n, index, leftPerson - 1, k);
    }

    int findTheWinner(int n, int k) {
        // Initialize the visited vector with all false (no one is eliminated at the start)
        vector<bool> visited(n, false);

        // Start the game with the first person (index 0) and all n people still in the game
        return findWinner(visited, n, 0, n, k) + 1; // +1 to convert from 0-based to 1-based index
    }
};

Time Complexity = O(n^2)
Space Complexity = O(n)
```

## Solution 2

```Cpp
Recursive Approach :

class Solution {
public:
    /*
    * This function recursively determines the winner of the Josephus Problem.
    *
    * Parameters:
    * - n: The current number of people in the circle.
    * - k: The step count to determine the person to eliminate.
    *
    * Returns:
    * - The 0-based index of the last remaining person in the current recursive state.
    */
    int findWinner(int n, int k) {
        // Base case: If there's only one person left, their index is 0 (0-based index)
        if (n == 1) {
            return 0;
        }

        // Recursive case:
        // The function returns the position of the survivor in the reduced problem (n-1 people)
        // and adjusts it using the modulus operation to account for the current number of people.
        return (findWinner(n - 1, k) + k) % n;
    }

    /*
    * This function determines the 1-based index of the last remaining person.
    *
    * Returns:
    * - The 1-based index of the last remaining person.
    */
    int findTheWinner(int n, int k) {
        // Call findWinner and adjust the result to be 1-based index
        return findWinner(n, k) + 1;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```
