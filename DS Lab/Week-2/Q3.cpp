// #include<iostream>
#include <bits/stdc++.h>
#include <vector> 
#include <algorithm>
using namespace std;
struct Employee {
    int employeeID;
    string name;
    string department;
    string designation;
    string dateOfBirth;
    string dateOfJoining;
    double salary;
};
vector<Employee> employees;

void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.employeeID;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(cin, emp.dateOfBirth);
    cout << "Enter Date of Joining (YYYY-MM-DD): ";
    getline(cin, emp.dateOfJoining);
    cout << "Enter Salary: ";
    cin >> emp.salary;
    employees.push_back(emp);
    cout << "Employee added successfully." << endl;
}
void displayAllEmployees() {
    cout << "Employee Records:" << endl;
    for (const auto& emp : employees) {
        cout << "Employee ID: " << emp.employeeID << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Department: " << emp.department << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Date of Birth: " << emp.dateOfBirth << endl;
        cout << "Date of Joining: " << emp.dateOfJoining << endl;
        cout << "Salary: " << emp.salary << endl << endl;
    }
}
void displayEmployeesByDate(bool before) {
    string date;
    cout << "Enter the specific date (YYYY-MM-DD): ";
    cin >> date;

    cout << "Employees joined ";
    if (before)
        cout << "before ";
    else
        cout << "after ";
    cout << date << ":" << endl;

    for (const auto& emp : employees) {
        if (before && emp.dateOfJoining < date)
            cout << emp.name << endl;
        else if (!before && emp.dateOfJoining > date)
            cout << emp.name << endl;
    }
}
void searchEmployeeByID() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.employeeID == id;
    });
    if (it != employees.end()) {
        cout << "Employee found:" << endl;
        cout << "Name: " << it->name << endl;
        cout << "Department: " << it->department << endl;
        cout << "Designation: " << it->designation << endl;
        cout << "Date of Birth: " << it->dateOfBirth << endl;
        cout << "Date of Joining: " << it->dateOfJoining << endl;
        cout << "Salary: " << it->salary << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}
void updateSalary() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.employeeID == id;
    });

    if (it != employees.end()) {
        cout << "Enter new salary: ";
        cin >> it->salary;
        cout << "Salary updated successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}
void deleteEmployee() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    auto it = find_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.employeeID == id;
    });

    if (it != employees.end()) {
        employees.erase(it);
        cout << "Employee deleted successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}
void calculateStatistics() {
    double totalSalary = 0.0;
    double highestSalary = -1.0;
    double lowestSalary = -1.0;

    for (const auto& emp : employees) {
        totalSalary += emp.salary;
        if (highestSalary == -1.0 || emp.salary > highestSalary)
            highestSalary = emp.salary;
        if (lowestSalary == -1.0 || emp.salary < lowestSalary)
            lowestSalary = emp.salary;
    }
    int totalEmployees = employees.size();
    double averageSalary = totalSalary / totalEmployees;
    cout << "Total number of employees: " << totalEmployees << endl;
    cout << "Average salary: " << averageSalary << endl;
    cout << "Highest salary: " << highestSalary << endl;
    cout << "Lowest salary: " << lowestSalary << endl;
}
int main() {
    int choice;
    do {
        cout << "Employee Management System" << endl;
        cout << "1. Add new employee" << endl;
        cout << "2. Display all employees" << endl;
        cout << "3. Display employees joined before a specific date" << endl;
        cout << "4. Display employees joined after a specific date" << endl;
        cout << "5. Search for an employee by ID" << endl;
        cout << "6. Update employee salary" << endl;
        cout << "7. Delete an employee" << endl;
        cout << "8. Calculate and display statistics" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                displayEmployeesByDate(true);
                break;
            case 4:
                displayEmployeesByDate(false);
                break;
            case 5:
                searchEmployeeByID();
                break;
            case 6:
                updateSalary();
                break;
            case 7:
                deleteEmployee();
                break;
            case 8:
                calculateStatistics();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
   return 0;
}
