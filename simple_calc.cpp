#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Get user input for two numbers and the operation
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter operation (+ for addition, - for subtraction, * for multiplication, / for division): ";
    cin >> operation;

    // Perform the selected operation and display the result
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error: Cannot divide by zero.\n";
            }
            break;
        default:
            cout << "Invalid operation. Please enter +, -, *, or /.\n";
            break;
    }

    return 0;
}
