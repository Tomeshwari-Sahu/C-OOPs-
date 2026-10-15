#include <iostream>
using namespace std;


void swapReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void swapPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void calculateResults(const int* marks, int n,
                      double& average, int& highest)
{
    int total = 0;
    highest = *marks;

    for (int i = 0; i < n; i++)
    {
        total += *(marks + i);

        if (*(marks + i) > highest)
        {
            highest = *(marks + i);
        }
    }

    average = (double)total / n;
}

int main()
{
    int a, b;

    cout << "STUDENT MARKS MANAGEMENT SYSTEM" << endl;

    
    cout << "\nEnter marks of two students: ";
    cin >> a >> b;

    cout << "Original marks: " << a << " " << b << endl;

    swapReference(a, b);
    cout << "After swapping using references: "
         << a << " " << b << endl;

    
    swapPointer(&a, &b);
    cout << "After swapping using pointers: "
         << a << " " << b << endl;

    
    int *p = new int;

    cout << "\nEnter marks for a dynamically allocated variable: ";
    cin >> *p;

    cout << "Dynamically allocated marks: " << *p << endl;

    delete p;
    p = NULL;

    
    int n;

    cout << "\nEnter number of students: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of students!" << endl;
        return 0;
    }

    int *marks = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];

        if (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks! Enter marks between 0 and 100."
                 << endl;

            delete[] marks;
            return 0;
        }
    }

    double average;
    int highest;

    calculateResults(marks, n, average, highest);

    cout << "\n--- STUDENT RESULTS ---" << endl;
    cout << "Marks of students: ";

    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    cout << "\nAverage marks: " << average << endl;
    cout << "Highest marks: " << highest << endl;

    delete[] marks;
    marks = NULL;

    
    int *student = new int[2];

    cout << "\nEnter student roll number: ";
    cin >> student[0];

    cout << "Enter student marks: ";
    cin >> student[1];

    cout << "\n--- DYNAMIC STUDENT RECORD ---" << endl;
    cout << "Roll number: " << student[0] << endl;
    cout << "Marks: " << student[1] << endl;

    delete[] student;
    student = NULL;

    cout << "\nDynamic memory released successfully." << endl;

    return 0;
}

