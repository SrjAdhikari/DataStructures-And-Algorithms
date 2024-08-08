#include <iostream>
#include <vector>
using namespace std;

// Function to print all subsequences of the given array
void printSubsequences(int arr[], int index, int size, vector<vector<int>>& ans, vector<int> temp) {
    // Base case: if index reaches the size of the array, add the current subsequence to the result
    if (index == size) {
        ans.push_back(temp);    // Store the current subsequence
        return;                 // Exit the function
    }

    // Recursive call to explore the subsequence that does not include the current element
    printSubsequences(arr, index + 1, size, ans, temp);

    // Include the current element in the subsequence
    temp.push_back(arr[index]);

    // Recursive call to explore the subsequence that includes the current element
    printSubsequences(arr, index + 1, size, ans, temp);
}


int main() {
    int array[] = {1, 2, 3};
    int size = sizeof(array) / sizeof(int);
    int index = 0;
    vector<vector<int>> ans;
    vector<int> temp;

    printSubsequences(array, index, size, ans, temp);

    cout << "Subsequences of array : " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//* **********************************************
//* Time Complexity : O(2^n)
//* Space Complexity : O(n * 2^n)
//* **********************************************