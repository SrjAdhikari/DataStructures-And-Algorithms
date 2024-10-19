#include <iostream>
#include <unordered_map>  // Including unordered_map instead of map
using namespace std;

int main() {
    // Declaring an unordered map: keys are strings, and values are integers
    unordered_map<string, int> ump;

    // Inserting elements into the unordered map using the [] operator
    ump["Suraj"] = 100;                 // Insert "Suraj" with value 100
    ump["Ankit"] = 200;                 // Insert "Ankit" with value 200
    
    // Inserting elements using the insert() method
    ump.insert({ "Rohit", 300 });       // Insert "Rohit" with value 300
    ump.insert({ "Srj", 500 });         // Insert "Srj" with value 500


   // Recommended way of accessing elements using the [] operator
    cout << "The value of 'Suraj' is: " << ump["Suraj"] << endl;
    cout << "The value of 'Ankit' is: " << ump["Ankit"] << endl;


    // Accessing elements using the at() method (throws an exception if key doesn't exist)
    cout << "The value of 'Rohit' is: " << ump.at("Rohit") << endl;
    cout << "The value of 'Srj' is: " << ump.at("Srj") << endl;


    // Accessing "Ram" using [] operator (adds it with value 0 if not present)
    cout << "The value of 'Ram' is : " << ump["Ram"] << endl;
    cout << endl;


    // Checking if an element is present using count() function
    // count() returns 1 if the key is present, otherwise 0
    cout << "Is 'Suraj' present in the unordered map? : " << ump.count("Suraj") << endl;
    cout << "Is 'Rohit' present in the unordered map? : " << ump.count("Rohit") << endl;
    cout << "Is 'SURAJ' present in the unordered map? : " << ump.count("SURAJ") << endl;
    cout << endl;


    // Recommended way of checking if an element is present using find()
    if(ump.find("Suraj") != ump.end()) {
        // If "Suraj" is found in the map, print its value
        cout << "The value of 'Suraj' is : " << ump["Suraj"] << endl;
    }
    else {
        // If "Suraj" is not found, print a message
        cout << "The key 'Suraj' is not present in the unordered map" << endl;
    }
    cout << endl;


    // Checking the size of the unordered map (number of key-value pairs)
    cout << "The size of the unordered map is : " << ump.size() << endl;
    cout << endl;


    // Checking if the unordered map is empty using empty() function
    if(ump.empty()) {
        cout << "The unordered map is empty" << endl;
    }
    else {
        cout << "The unordered map is not empty" << endl;
    }

    return 0;
}