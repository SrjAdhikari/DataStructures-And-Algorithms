#include <iostream>
using namespace std;

//* Note: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

// Function to count the number of derangements for n items
// A derangement is a permutation where no element appears in its original position
int countDerangement(int n)
{
    // Base case: There are no derangements possible for a single item
    if (n == 1)
        return 0;

    // Base case: There is exactly one derangement for a set of size 2
    if (n == 2)
        return 1;

    // Recursive case: The number of derangements for n items can be calculated using the formula:
    // D(n) = (n - 1) * (D(n - 1) + D(n - 2))
    // This formula works by considering the first element. There are (n - 1) positions it can be placed in.
    // If it is placed in position i (where i is not its original position), then:
    //   - The i-th element must go to the original position of the first element (leaving us with D(n - 2) derangements).
    //   - Or the i-th element does not go to the original position of the first element (leaving us with D(n - 1) derangements).
    return (n - 1) * (countDerangement(n - 1) + countDerangement(n - 2));
}

int main()
{
    int n = 4;
    int totalDerangement = countDerangement(n);

    // Output the total number of derangements
    cout << "Total Derangements is : " << totalDerangement << endl;

    return 0;
}

//* **********************************************
//* Time Complexity : O(2^N)
//* Space Complexity : O(N)
//* **********************************************