#include<iostream>
using namespace std;

// Function to find the element that occurs an odd number of times in a sorted array.
// The function uses a binary search approach to achieve O(log n) time complexity.
int findOddTimesOccurringNumber(int arr[], int size){

    // Initialize start and end pointers for binary search
    int start = 0;
    int end = size - 1;

    // Perform binary search
    while(start <= end){
        // Calculate the middle index
        int mid = start + (end - start) / 2;

        // If start equals end, the odd occurring element is found
        if(start == end)
            return start; // Return the index at start
        
        // Check if mid is odd or even
        if(mid & 1){
            // If the element at mid is the same as the previous element, the odd-occurrence element must be on the right side
            if(arr[mid] == arr[mid - 1])
                start = mid + 1;
            // Otherwise, it must be on the left side
            else
                end = mid - 1;
        }
        else{
            // If mid is an even index and the element at mid is the same as the next element, the odd-occurrence element must be on the right side
            if(arr[mid] == arr[mid + 1])
                start = mid + 2;
            // Otherwise, it must be on the left side or is the element at mid
            else
                end = mid;
        }
    }
    
    // If no odd occurring element is found, return -1 (this case should not occur if input is valid)
    return -1;
}


int main(){
    int arr[] = {1, 2, 2, 3, 3};
    int size = 5;

    int index = findOddTimesOccurringNumber(arr, size);

    cout << "Odd times occurring element is : " << arr[index] << endl;
    cout << "Odd times occurring element index is : " << index << endl;

    return 0;
}

// Time Complexity = O(logn)
// Space Complexity = O(1)