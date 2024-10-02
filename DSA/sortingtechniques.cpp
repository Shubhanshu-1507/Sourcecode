#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int rollNumber;
    float SGPA;
};

void StudentInput(int count, string studentName, int roll, float SGPA, Student *s[])
{
    s[count] = new Student;
    s[count]->name = studentName;
    s[count]->rollNumber = roll;
    s[count]->SGPA = SGPA;
    cout << "inserted" << endl;
}

void DisplayStruct(struct Student *s[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Student Name: " << s[i]->name << endl;
        cout << "Roll Number: " << s[i]->rollNumber << endl;
        cout << "SGPA: " << s[i]->SGPA << endl;
        cout << "---------------" << endl;
    }
}
void bubbleSort(struct Student *s[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (s[j]->rollNumber < s[i]->rollNumber)
            {
                swap(s[i], s[j]);
            }
        }
    }

    DisplayStruct(s, length);
}
void InsertionSort(struct Student *s[], int length)
{
    for (int i = 1; i < length; i++)
    {
        Student *key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j]->name > key->name)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }

    DisplayStruct(s, length);
}
int partition(struct Student *s[], int low, int high)
{
    float pivot = s[low]->SGPA;
    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= high && s[i]->SGPA <= pivot)
            i++;
        while (j >= low && s[j]->SGPA > pivot)
            j--;
        if (i < j)
            swap(s[i], s[j]);
        else
            break;
    }
    swap(s[low], s[j]);
    return j;
}

void QuickSort(struct Student *s[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(s, low, high);
        QuickSort(s, low, pivot - 1);
        QuickSort(s, pivot + 1, high);
    }
}

void operation(int input, Student *s[], int length)
{
    switch (input)
    {
    case 0:
        DisplayStruct(s, length);
        break;
    case 1:
        bubbleSort(s, length);
        break;
    case 2:
        InsertionSort(s, length);
        break;
    case 3:
        QuickSort(s, 0, length - 1);
        DisplayStruct(s, length);
        break;
    default:
        cout << "Invalid input. Please select a valid option." << endl;
        break;
    }
}
void DisplayUserOption(Student *s[], int lengthOfArr)
{
    int input;
    cout << "Select Sorting Option:" << endl;
    cout << "0. display the Struct" << endl;
    cout << "1. Sort by Roll Number" << endl;
    cout << "2. Sort by Student Name" << endl;
    cout << "3. Sort by SGPA" << endl;
    cin >> input;
    operation(input, s, lengthOfArr);
}

// Driver Code
int main()
{
    Student *s[20];
    int count = 0, response = 0;
    do
    {

        cout << "Enter the name of Student: ";
        string studentName;
        cin >> studentName;
        cout << "Enter the roll number: ";
        int roll;
        cin >> roll;
        cout << "Enter the SGPA of student: ";
        float SGPA;
        cin >> SGPA;
        StudentInput(count, studentName, roll, SGPA, s);
        count++;
        cout << "To continue inserting student records, enter 1. To exit, enter 0: ";
        cin >> response;
    } while (response != 0);

    DisplayUserOption(s, count);

    // Free allocated memory
    for (int i = 0; i < count; i++)
    {
        delete s[i];
    }

    return 0;
}
