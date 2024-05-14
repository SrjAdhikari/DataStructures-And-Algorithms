#include <iostream>
using namespace std;

// Function  to print the grade of students based on  their scores.
void printGrade()
{
    int marks;
    while (true)
    {
        cout << "Enter the marks : ";
        cin >> marks;

        if (marks >= 0 && marks <= 100)
            break; // Exit the loop if marks are valid
        else
            cout << "Invalid input. Marks should be between 0 and 100." << endl;
    }

    // Check the grade based on valid marks.
    if (marks >= 90)
        cout << "Grade is : A";

    else if (marks >= 75)
        cout << "Grade is : B";

    else if (marks >= 50)
        cout << "Grade is : C";

    else
        cout << "Grade is : D";
}

int main()
{
    printGrade();
    return 0;
}