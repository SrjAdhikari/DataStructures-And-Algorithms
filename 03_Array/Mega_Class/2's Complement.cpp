#include<iostream>
#include <vector>
using namespace std;

vector<int> find2sComplement(vector<int> binary) {
    int n = binary.size();          // Get the size of the binary vector
    vector<int> twosComp(n, 0);     // Initialize the two's complement vector with zeros

    // Step 1 : Flip all bits (0 to 1 and 1 to 0) -> 1's Complement
    for (int i = 0; i < n; i++) {
        if (binary[i] == 0)
            twosComp[i] = 1;        // Flip 0 to 1
        else
            twosComp[i] = 0;        // Flip 1 to 0
    }

    // Step 2 : Add 1 to the flipped bits -> 2's Complement
    int carry = 1;                      // Initialize carry to 1 (for adding 1)
    for (int i = twosComp.size() - 1; i >= 0; i--) {
        int sum = twosComp[i] + carry;  // Calculate sum of current bit and carry
        twosComp[i] = sum % 2;          // Update the bit with sum modulo 2
        carry = sum / 2;                // Update carry

        if (carry == 0) {
            // Optimization: If carry becomes 0, no need to propagate further
            break;
        }
    }

    return twosComp;                // Return the two's complement vector
}


int main(){

    vector<int> binary = {0, 1, 1, 0, 1};
    vector<int> twosComp = find2sComplement(binary);

    cout << "2's complements is : " << endl;
    for (int i = 0; i < twosComp.size(); i++){
        cout << twosComp[i] << " ";
    }
    cout << endl;

    return 0;
}