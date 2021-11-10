#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int roll_no;
    string name;
    double SGPA;
};
class Student_Data
{
public:
    int n;
    Student v[20];
    Student temp;
    void get_data();
    void display();
    void roll_call();
    void alpha_name();
    int partition(int low, int high);
    void quickSort(int low, int high);
    void linearSearch();
    void binarySearch();
};
void Student_Data ::get_data()
{
    cout << "-------------------------------------------" << endl;
    cout << "Enter number of students : ";
    cin >> n;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "::"
             << "Data Entry for Student " << i + 1 << "::" << endl;
        cout << "Enter Roll Number : ";
        cin >> v[i].roll_no;

        cout << "Enter name of Student : ";
        cin >> v[i].name;

        cout << "Enter SGPA of Student : ";
        cin >> v[i].SGPA;
        while (v[i].SGPA > 10)
        {
            cout << "Please enter less than 10 again" << endl;
            cout << "Enter the SGPA of Student: ";
            cin >> v[i].SGPA;
        }
        cout << "-------------------------------------------" << endl;
    }
}
void Student_Data ::display()
{
    cout << "ROLL NO"
         << "\t\t\t\t\t\t"
         << "NAME"
         << "\t\t\t\t\t\t"
         << "SGPA" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i].roll_no << "\t\t\t\t\t\t" << v[i].name << "\t\t\t\t\t\t" << v[i].SGPA << endl;
    }
    cout << "-------------------------------------------" << endl;
}
void Student_Data ::roll_call()
{
    bool flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j].roll_no > v[j + 1].roll_no)
            {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }

        if (flag == false)
        {
            break;
        }
    }
    cout << "Data according to roll call : " << endl;
    display();
}
void Student_Data ::alpha_name()
{
    for (int i = 1; i < n; i++)
    {
        temp = v[i];
        string key = v[i].name;
        int j = i - 1;
        while (j >= 0 && v[j].name > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
    cout << "Data according to name : " << endl;
    display();
}
int Student_Data ::partition(int low, int high)
{
    int pivot = v[low].SGPA;
    int i = low;
    int j = high;
    while (i < j)
    {
        while (v[i].SGPA >= pivot)
        {
            i++;
        }
        while (v[j].SGPA < pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}
void Student_Data ::quickSort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}
void Student_Data ::linearSearch()
{
    string str;
    cout << "Enter the name of the student : ";
    cin >> str;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (str == v[i].name)
        {
            flag = true;
            cout << "-------------------------------------------" << endl;
            cout << "DataSet of " << str << endl;
            cout << "ROLL NO"
                 << "\t\t\t\t\t\t"
                 << "NAME"
                 << "\t\t\t\t\t\t"
                 << "SGPA" << endl;
            cout << v[i].roll_no << "\t\t\t\t\t\t" << v[i].name << "\t\t\t\t\t\t" << v[i].SGPA << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    if (flag == false)
    {
        cout << "Element not found" << endl;
    }
}
void Student_Data ::binarySearch()
{
    double key;
    cout << "Enter the SGPA : ";
    cin >> key;

    while (key > 10)
    {
        cout << "Please enter less than 10 again" << endl;
        cout << "Enter the SGPA : ";
        cin >> key;
    }
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    bool flag = false;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        if (key == v[i].SGPA)
        {
            flag = true;
            cout << "ROLL NO :   " << v[i].roll_no << "\t\t\t\t\t\t NAME :   " << v[i].name << "\t\t\t\t\t\t  SGPA :   " << v[i].SGPA << endl;
        }
    }
    if (flag == false)
    {
        cout << "Element not found" << endl;
    }
    cout << "-------------------------------------------" << endl;
}
int main()
{
    Student_Data obj;
    obj.get_data();
    int x = 1;
    while (x)
    {
        int choice;
        cout << "-----------------------------------------" << endl;
        cout << "1. Sort data by Roll Call" << endl;
        cout << "2. Sort data by Alphabetical order" << endl;
        cout << "3. Sort data by SGPA" << endl;
        cout << "4. Access data by name" << endl;
        cout << "5. Access data by SGPA" << endl;
        cout << "0. To exit" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            x = 0;
            cout<<"Exit..."<<endl;
            break;
        case 1:
            obj.roll_call();
            break;
        case 2:
            obj.alpha_name();
            break;
        case 3:
            obj.quickSort(0, obj.n - 1);
            obj.display();
            break;
        case 4:
            obj.linearSearch();
            break;
        case 5:
            obj.binarySearch();
            break;
        default:
            cout<<"Wrong choice"<<endl;
            break;
        }
    }

    return 0;
}
