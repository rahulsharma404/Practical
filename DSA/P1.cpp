#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int rollno;
    char name[20];
    double SGPA;
};

class Student_Data
{
public:
    int n, l, u;
    Student a[20], temp, pivot;
    void display();
    void getData();
    void rollcall();
    void name_data();
    int partition_of_SGPA(int, int);
    void quickSort(int, int);
    void searchLinear();
    void searchBinary();
};
void Student_Data::getData()
{
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Roll number: ";
        cin >> a[i].rollno;
        cout << "Enter Name of Student: ";
        cin >> a[i].name;
        cout << "Enter SGPA: ";
        cin >> a[i].SGPA;
        if (a[i].SGPA > 10)
        {
            cout << "Please enter less than 10 again " << endl;
            cin >> a[i].SGPA;
        }
        cout << "--------------------------------" << endl;
    }
}

void Student_Data::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].rollno << "\t" << a[i].name << "\t" << a[i].SGPA << endl;
    }
}

void Student_Data::rollcall()
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].rollno > a[j + 1].rollno)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    cout << "\nOutput data:\n"
         << endl;
    cout << "RollNo\t"
         << "Name\t"
         << "SGPA" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i].rollno << "\t" << a[i].name << "\t" << a[i].SGPA << endl;
    }
}

void Student_Data::name_data()
{
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        string key = a[i].name;
        int j = i - 1;
        while (j >= 0 && a[j].name > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    cout << "\nOutput Data" << endl;
    display();
}

int Student_Data::partition_of_SGPA(int s, int e)
{
    int pivot = a[e].SGPA;
    int pi = s;
    for (int i = s; i < e; i++)
    {
        if (a[i].SGPA >= pivot)
        {
            temp = a[i];
            a[i] = a[pi];
            a[pi] = temp;
            pi++;
        }
    }
    temp = a[e];
    a[e] = a[pi];
    a[pi] = temp;
    return pi;
}

void Student_Data::quickSort(int s, int e)
{
    if (s < e)
    {
        int p = partition_of_SGPA(s, e);

        quickSort(s, (p - 1));
        quickSort((p + 1), e);
    }
}

void Student_Data::searchLinear()
{
    string dataElement;
    cout << "\nEnter Data Element which u want to find in Array::";
    cin >> dataElement;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].name == dataElement)
        {
            cout << "\nElement found at position: " << i << endl;
            cout << a[i].rollno << " " << a[i].name << " " << a[i].SGPA;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "Element not found" << endl;
    }
}

void Student_Data::searchBinary()
{
    int l = 0, r = n - 1, mid, data;
    cout << "Enter SGPA to find students: ";
    cin >> data;
    int flag = 0;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (data == a[mid].SGPA)
        {
            cout << "Element found at position: " << mid << endl;
            cout << a[mid].rollno << " " << a[mid].name << " " << a[mid].SGPA;
            flag = 1;
            break;
        }
        else if (data < a[mid].SGPA)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (flag == 0)
        cout << "Element not found." << endl;
}

int main()
{

    Student_Data obj;
    obj.getData();
    int choice;
    do
    {
        cout << "\nWhat you want to do? \n1.Display list by roll number wise. \n2.Display list in alphabetical order.\n3.Topper students of class. \n4.To search student by name. \n5.To search student by SGPA." << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            cout << "Roll number wise list" << endl;
            obj.rollcall();
            break;
        }
        case 2:
        {
            cout << "List in Alphabetical order." << endl;
            obj.name_data();
            break;
        }
        case 3:
        {
            cout << "Rank wise list of Toppers" << endl;
            obj.quickSort(0, 14);
            obj.display();
            break;
        }
        case 4:
        {
            cout << "Searching student by name: " << endl;
            obj.searchLinear();
            break;
        }
        case 5:
        {
            cout << "Searching student by SGPA: " << endl;
            obj.searchBinary();
            break;
        }
        default:
        {
            cout << "Wrong choice." << endl;
            break;
        }
        }
    } while (choice != 0);
    return 0;
}
