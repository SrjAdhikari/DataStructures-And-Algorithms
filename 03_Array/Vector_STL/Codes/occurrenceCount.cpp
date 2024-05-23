#include<iostream>
#include<vector>
using namespace std;

void totalOccurrence(vector<int>arr, int num){
    int size = arr.size();
    int occurrence = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == num){
            occurrence++;
        }
    }
    cout << "Total occurrence is : " << occurrence << endl;
}

//* *********************************************
    //* Time Complexity = O(size)
    //* Space Complexity = O(1)
//* *********************************************


int main(){
    vector<int> array = {1, 2, 1, 2, 1, 3, 1};
    int num = 1;

    totalOccurrence(array, num);

    return 0;
}