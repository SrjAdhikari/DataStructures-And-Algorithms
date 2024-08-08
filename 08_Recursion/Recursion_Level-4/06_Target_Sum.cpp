#include <iostream>
using namespace std;

// Recursive function to determine if there's a subset with the given target sum
bool foundTarget(int arr[], int index, int size, int target) {
    // Base case 1: If the target sum is zero, return true (a valid subset is found)
    if(target == 0) {
        return true;
    }

    // Base case 2: If we've considered all elements or the target becomes negative, return false
    if(index == size || target < 0) {
        return false;
    }

    // Recursive case 1: Exclude the current element and check the rest of the array
    bool exclude = foundTarget(arr, index + 1, size, target);

    // Recursive case 2: Include the current element in the subset and check the rest of the array
    bool include = foundTarget(arr, index + 1, size, target - arr[index]);

    // Return true if either including or excluding the current element results in a valid subset
    return exclude || include;
}


int main() {
    int array[] = {3, 6, 4, 5};
    int index = 0;
    int size = sizeof(array) / sizeof(int);
    int target = 12;

    bool isFound = foundTarget(array, index, size, target);

    if(isFound) {
        cout << "Target found." << endl;
    }
    else {
        cout << "Target not found." << endl;
    }

    return 0;
}

//* **********************************************
//* Time Complexity : O(2^n)
//* Space Complexity : O(n)
//* **********************************************