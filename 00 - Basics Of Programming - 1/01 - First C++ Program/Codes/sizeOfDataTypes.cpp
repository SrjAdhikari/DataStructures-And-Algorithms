#include<iostream>
using namespace std;

int main(){

    //char -> 1 byte
    char ch = 'k';
	cout << "Value of ch is : " << ch << endl;
	cout << "Size of char is : " << sizeof(ch) << "bytes" << endl;
    cout << endl;

    //int -> 4 byte
    int num = 10;
	cout << "Value of num is : " << num << endl;
	cout << "Size of int is : " << sizeof(num) << "bytes" << endl;
    cout << endl;

	//float -> 4 byte
	float point = 1.69;
	cout << "Value of point is : " << point << endl;
	cout << "Size of float is : " << sizeof(point) << "bytes" << endl;
    cout << endl;

	//long -> 4 byte
	long number = 23;
	cout << "Value of number is : " << number << endl;
	cout << "Size of long is : " << sizeof(number) << "bytes" << endl;
    cout << endl;

    //boolean -> 1 byte
	bool flag = true;
	cout << "Value of flag is : " << flag << endl;
	cout << "Size of boolean is : " << sizeof(flag) << "bytes" << endl;

    return 0;
}