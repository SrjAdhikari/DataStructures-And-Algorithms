# Question : [Tower Of Hanoi - GFG](https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1)

The tower of Hanoi is a famous puzzle where we have three rods and **n** disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs **n**. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

You only need to complete the function toh() that takes following parameters: n (number of discs), **from** (The rod number from which we move the disc), **to** (The rod number to which we move the disc), **aux** (The rod that is used as an auxiliary rod) and prints the required moves inside function body (See the example for the format of the output) as well as return the count of total moves made.

**Note**: The discs are arranged such that the **top disc is numbered 1** and the **bottom-most disc is numbered n**. Also, all the discs have **different sizes** and a bigger disc **cannot** be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

### Example 1

```
Input:
n = 2
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
Explanation: For N=2 , steps will be as follows in the example and total 3 steps will be taken.
```

### Example 2

```
Input:
n = 3
Output:
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
7
Explanation: For N=3 , steps will be as follows in the example and total 7 steps will be taken.
```

```
Expected Time Complexity: O(2^n).
Expected Auxiliary Space: O(n).
```

### Constraints

`0 <= n <= 16`

## Solution

```Cpp
class Solution {
public:
    void towerOfHanoi(int n, int src, int help, int dest) {
        // Base case: If there's only one disk, move it directly from source to destination
        if (n == 1) {
            cout << "move disk " << n << " from rod " << src << " to rod " << dest << endl;
            return;
        }

        // Recursive case:
        // Step 1: Move `n-1` disks from source to helper using destination as auxiliary
        towerOfHanoi(n - 1, src, dest, help);

        // Step 2: Move the nth disk from source to destination
        cout << "move disk " << n << " from rod " << src << " to rod " << dest << endl;

        // Step 3: Move the `n-1` disks from helper to destination using source as auxiliary
        towerOfHanoi(n - 1, help, src, dest);
    }

    long long toh(int n, int from, int to, int aux) {
        // Solve the Tower of Hanoi problem
        towerOfHanoi(n, from, aux, to);

        // Return the total number of moves required, which is 2^n - 1
        return pow(2, n) - 1;
    }
};

Time Complexity = O(2^n)
Space Complexity = O(n)
```
