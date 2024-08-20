#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to print all permutations of the given string `str`
// starting from the given index `index`
void printPermutation(string &str, int index)
{
    // Base case: If the current index is equal to the size of `nums`, it means we have a complete permutation
    if (index >= str.length())
    {
        // Print the current permutation of the string and return
        cout << str << "  ";
        return;
    }

    // Recursive case: Generate permutations
    for (int i = index; i < str.length(); i++)
    {
        // Swap the current element with the element at `index` to create a new permutation
        swap(str[index], str[i]);

        // Recursively generate permutations for the remaining characters
        printPermutation(str, index + 1);

        // Backtrack by swapping the elements back to their original positions
        swap(str[index], str[i]);
    }
}

int main()
{
    string str = "abc";
    int index = 0;

    // Call the function to print all permutations of the string
    printPermutation(str, index);

    return 0;
}
