#include<iostream>
#include<vector>
using namespace std;

// Method : 1
void lastOccurrence(vector<int>arr, int num){
    int size = arr.size();
    int occurrence = -1;

    for(int i = 0; i < size; i++){
        if(arr[i] == num){
            occurrence = i;
        }
    }
    cout << "Last occurrence is : " << occurrence << endl;
}

//* *********************************************
    //* Time Complexity = O(size)
    //* Space Complexity = O(1)
//* *********************************************

// Method : 2
void lastOccurrence2(vector<int>arr, int num){
    int size = arr.size();
    int occurrence = -1;

    for(int i = size - 1; i >= 0; i--){
        if(arr[i] == num){
            occurrence = i;
            break;
        }
    }
    cout << "Last occurrence is : " << occurrence << endl;
}

//* *********************************************
    //* Time Complexity = O(size)
    //* Space Complexity = O(1)
//* *********************************************


int main(){
    vector<int> array = {1, 2, 3, 2, 1, 3, 1};
    int num = 1;

    lastOccurrence(array, num);
    lastOccurrence2(array, num);

    return 0;
}