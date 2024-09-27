#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }  
    return true;
}

int main(){

    int num;

    cout << "Enter the number: " << endl;
    cin >> num; 

    for(int i = 2; i <= num; i++){
        bool findPrime = isPrime(i);
        if(findPrime){
            cout << i << " ";
        }
    }

    return 0;
}