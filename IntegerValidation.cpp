#include <iostream>
#include <limits>   // needed for numeric_limits
using namespace std;
int main() {
    cout << "Enter an integer value between 5 and 10" << std::endl;

    int number;

    while (true) {
        if (cin >> number) {                 // successfully read an integer
            if (number >= 5 && number <= 10) {    // valid range?
                cout << "Your input value(" << number << ") has been accepted." << std::endl;
                break;                            // exit the loop – program ends
            }
            else {
                // integer but outside 5–10
                cout << "You entered " << number 
                          << ". Please enter a number between 5 and 10." << std::endl;
            }
        }
        else {
            // not a valid integer (e.g. "three")
            cout << "Sorry, you entered an invalid number, please try again" << std::endl;

            // clear the error flag and discard the bad input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
