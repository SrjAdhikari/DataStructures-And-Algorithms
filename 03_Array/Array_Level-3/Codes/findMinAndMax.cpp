#include<iostream>
using namespace std;

// Function to find minimum element in array
int findMinElement(int arr[3][3], int rowSize, int colSize){

    int minValue = INT_MAX;

    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            if(arr[row][col] < minValue)
                minValue = arr[row][col];
        }
    }
    return minValue;
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


// Function to find maximum element in array
int findMaxElement(int arr[3][3], int rowSize, int colSize){

    int maxValue = INT_MIN;

    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            if(arr[row][col] > maxValue)
                maxValue = arr[row][col];
        }
    }
    return maxValue;
}

//* *********************************************
    //* Time Complexity = O(rowSize * colSize)
    //* Space Complexity = O(1)
//* *********************************************


int main(){

    int array[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };
    int rowSize = 3;
    int colSize = 3;

    int minNum = findMinElement(array, rowSize, colSize);
    int maxNum = findMaxElement(array, rowSize, colSize);

    cout << "Minimum Elements is : " << minNum << endl;
    cout << "Maximum Elements is : " << maxNum << endl;
    
    return 0;
}