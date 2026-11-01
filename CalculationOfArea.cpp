#include <iostream>
#include <limits>
using namespace std;

// Function to calculate area of a square
double areaSquare(double side) {
    return side * side;
}

// Function to calculate area of a rectangle
double areaRectangle(double length, double width) {
    return length * width;
}

// Function to calculate area of a triangle
double areaTriangle(double base, double height) {
    return (base * height) / 2.0;
}

// Function to display the menu
void showMenu() {
    cout << "Please select the area of the shape to calculate" << endl;
    cout << "1. Square" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;
    cout << "4. Quit Program" << endl;
    cout << "Enter selection: ";
}

int main() {
    int choice;

    while (true) {
        showMenu();

        // Read menu choice
        if (!(cin >> choice)) {
            // Non-integer input
            cout << "\nYour input was: invalid which is an invalid input" << endl;
            cout << "Please enter a valid input!!!" << endl << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 4) {
            cout << "Program terminated." << endl;
            break;   // Exit the program
        }

        if (choice < 1 || choice > 4) {
            // Invalid menu choice
            cout << "\nYour input was: " << choice << " which is an invalid input" << endl;
            cout << "Please enter a valid input!!!" << endl << endl;
            continue;
        }

        // Valid choice – ask for dimensions and calculate
        if (choice == 1) {          // Square
            double side;
            cout << "Enter the side of the square: ";
            cin >> side;
            cout << "Area of the square = " << areaSquare(side) << endl << endl;
        }
        else if (choice == 2) {     // Rectangle
            double length, width;
            cout << "Enter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the width of the rectangle: ";
            cin >> width;
            cout << "Area of the rectangle = " << areaRectangle(length, width) << endl << endl;
        }
        else if (choice == 3) {     // Triangle
            double base, height;
            cout << "Enter the base of the triangle: ";
            cin >> base;
            cout << "Enter the height of the triangle: ";
            cin >> height;
            cout << "Area of the triangle = " << areaTriangle(base, height) << endl << endl;
        }
    }

    return 0;
}