#include<iostream>
#include<vector>
using namespace std;

void greaterNumberCount(vector<int>arr, int num){

    int size = arr.size();
    int count =0;

    for(int i = 0; i < size; i++){
        if(arr[i] > num){
            count++;
        }
    }
    cout << "Greater number count is : " << count << endl;
}

//* *********************************************
    //* Time Complexity = O(size)
    //* Space Complexity = O(1)
//* *********************************************


int main(){
    vector<int> array = {3, 4, 5, 10, 15, 20};
    int num = 5;

    greaterNumberCount(array, num);

    return 0;
}