#include<bits/stdc++.h>
using namespace std;

// Structure to represent a Car
struct Car {
    int car_ID;
    string make;
    string model;
    int year;
    double rental_price_per_day;
    string from_date;
    string to_date;
};

const int MAX_CARS = 100; // Maximum number of cars

// Function to calculate the total rental cost for a particular car over a specified number of days
double calculateRentalCost(const Car& car, int numDays) {
    return car.rental_price_per_day * numDays;
}

int main() {
    Car cars[MAX_CARS]; // Array of structures to store rental car data
    int numCars;

    cout << "Enter the number of rental cars: ";
    cin >> numCars;

    // Input rental car data
    for (int i = 0; i < numCars; ++i) {
        cout << "Enter Car ID: ";
        cin >> cars[i].car_ID;
        cout << "Enter Make: ";
        cin >> cars[i].make;
        cout << "Enter Model: ";
        cin >> cars[i].model;
        cout << "Enter Year: ";
        cin >> cars[i].year;
        cout << "Enter Rental Price per Day: ";
        cin >> cars[i].rental_price_per_day;
        cout << "Enter From Date (YYYY-MM-DD): ";
        cin >> cars[i].from_date;
        cout << "Enter To Date (YYYY-MM-DD): ";
        cin >> cars[i].to_date;
    }

    // Select a car to calculate rental cost
    int carID;
    cout << "Enter Car ID to calculate rental cost: ";
    cin >> carID;

    // Find the selected car in the array
    Car selectedCar;
    bool found = false;
    for (int i = 0; i < numCars; ++i) {
        if (cars[i].car_ID == carID) {
            selectedCar = cars[i];
            found = true;
            break;
        }
    }

    if (found) {
        // Calculate rental cost based on the number of days
        int numDays;
        cout << "Enter number of rental days: ";
        cin >> numDays;
        double totalCost = calculateRentalCost(selectedCar, numDays);
        cout << "Total rental cost for Car ID " << selectedCar.car_ID << ": $" << totalCost << endl;
    } else {
        cout << "Car with ID " << carID << " not found." << endl;
    }

    return 0;
}
