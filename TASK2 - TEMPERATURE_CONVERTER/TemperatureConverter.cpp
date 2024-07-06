#include <iostream>
using namespace std;

// Function prototypes
double celsiusToFahrenheit(double celsius);
double celsiusToKelvin(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double fahrenheitToKelvin(double fahrenheit);
double kelvinToCelsius(double kelvin);
double kelvinToFahrenheit(double kelvin);

int main() {
    int choice;
    double temperature;

    cout << "Temperature Conversion Program\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Celsius to Kelvin\n";
    cout << "3. Fahrenheit to Celsius\n";
    cout << "4. Fahrenheit to Kelvin\n";
    cout << "5. Kelvin to Celsius\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter temperature in Celsius: ";
            cin >> temperature;
            cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(temperature) << endl;
            break;
        case 2:
            cout << "Enter temperature in Celsius: ";
            cin >> temperature;
            cout << "Temperature in Kelvin: " << celsiusToKelvin(temperature) << endl;
            break;
        case 3:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> temperature;
            cout << "Temperature in Celsius: " << fahrenheitToCelsius(temperature) << endl;
            break;
        case 4:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> temperature;
            cout << "Temperature in Kelvin: " << fahrenheitToKelvin(temperature) << endl;
            break;
        case 5:
            cout << "Enter temperature in Kelvin: ";
            cin >> temperature;
            cout << "Temperature in Celsius: " << kelvinToCelsius(temperature) << endl;
            break;
        case 6:
            cout << "Enter temperature in Kelvin: ";
            cin >> temperature;
            cout << "Temperature in Fahrenheit: " << kelvinToFahrenheit(temperature) << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            break;
    }

    return 0;
}

// Function definitions
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

