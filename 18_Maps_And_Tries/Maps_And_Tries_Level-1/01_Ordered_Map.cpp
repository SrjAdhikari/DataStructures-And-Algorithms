#include <iostream>
#include <map>
using namespace std;

int main() {
    // Declaring an ordered map: keys are strings, and values are integers
    map<string, int> mp;

    // Inserting elements into the map using the [] operator
    mp["Suraj"] = 100;              // Insert "Suraj" with value 100
    mp["Ankit"] = 200;              // Insert "Ankit" with value 200
    
    // Inserting elements using the insert() method
    mp.insert({ "Rohit", 300 });    // Insert "Rohit" with value 300
    mp.insert({ "Srj", 500 });      // Insert "Srj" with value 500


    // Recommended way of accessing elements using the [] operator
    cout << "The value of 'Suraj' is: " << mp["Suraj"] << endl;
    cout << "The value of 'Ankit' is: " << mp["Ankit"] << endl;


    // Accessing elements using the at() method (throws an exception if key doesn't exist)
    cout << "The value of 'Rohit' is: " << mp.at("Rohit") << endl;
    cout << "The value of 'Srj' is: " << mp.at("Srj") << endl;


    // Accessing "Ram" using [] operator (adds it with value 0 if not present)
    cout << "The value of 'Ram' is : " << mp["Ram"] << endl;
    cout << endl;


    // Checking if an element is present using count() function
    // count() returns 1 if the key is present, otherwise 0
    cout << "Is 'Suraj' present in the map? : " << mp.count("Suraj") << endl;
    cout << "Is 'Rohit' present in the map? : " << mp.count("Rohit") << endl;
    cout << "Is 'Srj' present in the map? : " << mp.count("Srj") << endl;
    cout << endl;


    // Recommended way of checking if an element is present using find()
    if(mp.find("Suraj") != mp.end()) {
        // If "Suraj" is found in the map, print its value
        cout << "The value of 'Suraj' is : " << mp["Suraj"] << endl;
    }
    else {
        // If "Suraj" is not found, print a message
        cout << "The key 'Suraj' is not present in the map" << endl;
    }
    cout << endl;


    // Checking the size of the map (number of key-value pairs)
    cout << "The size of the map is : " << mp.size() << endl;
    cout << endl;


    // Checking if the map is empty using empty() function
    if(mp.empty()) {
        cout << "The map is empty" << endl;
    }
    else {
        cout << "The map is not empty" << endl;
    }

    return 0;
}