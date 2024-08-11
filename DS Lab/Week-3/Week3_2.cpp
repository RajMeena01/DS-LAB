#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Student
{
    string name;
    int age;
};
void insertionSort(vector<Student> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].name > key.name)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertionsort_age(vector<Student> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        Student key = arr[i];
        int ii = i - 1;
        while (ii >= 0 && arr[ii].age > key.age)
        {
            arr[ii + 1] = arr[ii];
            ii = ii - 1;
        }
        arr[ii + 1] = key;
    }
}
int main()
{
    vector<Student> students = {{"Avneet", 20}, {"selena", 19}, {"sonamBajwa", 21}};
    insertionSort(students);
    cout << "Sorted students by name:\n";
    for (const Student &student : students)
    {
        cout << student.name << " " << student.age << endl;
    }
    cout << "\n";
    insertionsort_age(students);
    cout << "Sorted students by age:\n";
    for (const Student &student : students)
    {
        cout << student.name << " " << student.age << endl;
    }
    return 0;
}
