#include<iostream>
using namespace std;

int main() {
    
    // Outer loop
    for (int i = 1; i <= 3; ++i) {
        // Inner loop 
        for (int j = 1; j <= 3; ++j) {
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;
    }

    return 0;
}