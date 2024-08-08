#include <iostream>
#include <vector>
using namespace std;

// Function to compute the sum of all possible subsets of an array
void subsetSum(int arr[], int index, int size, int sum, vector<int>& ans) {
    // Base case: If we've considered all elements in the array
    if(index == size) {
        // Add the computed sum of the current subset to the result vector
        ans.push_back(sum);
        return;
    }

    // Recursive case 1: Exclude the current element and move to the next element
    subsetSum(arr, index + 1, size, sum, ans);

    // Recursive case 2: Include the current element in the subset and move to the next element
    subsetSum(arr, index + 1, size, sum + arr[index], ans);
}


int main() {
    int array[] = {1, 2, 3, 4};
    int index = 0;
    int size = sizeof(array) / sizeof(int);
    int sum = 0;
    vector<int> ans;

    subsetSum(array, index, size, sum, ans);

    cout << "Printing all subsets sum : " << endl;
    for(int sum : ans) {
        cout << sum << endl;
    }

    return 0;
}

//* **********************************************
//* Time Complexity : O(2^n)
//* Space Complexity : O(n)
//* **********************************************