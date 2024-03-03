/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib> // to randomize password
#include <string>
#include <ctime> // to get current time and generate different password each time
using namespace std;

const char low[] = "abcdefghijklmnopqrstuvwxyz";
const char capital[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char symbols[] = "_*&^%$#@!?№-";
const char numbers[] = "0123456789";

int main() {
    string answerCapital, answerSymbols, answerNumbers;
    int length = 0;
    cout << "Enter length of the password: ";
    cin >> length;

    cout << "Do you want to add capital letters to your password? (Y/N): ";
    cin >> answerCapital;

    cout << "Do you want to add symbols to your password? (Y/N): ";
    cin >> answerSymbols;

    cout << "Do you want to add numbers to your password? (Y/N): ";
    cin >> answerNumbers;

    srand(time(0));
    
    // To get al options with the same frequency
    bool capitalIncluded = false, symbolsIncluded = false, numbersIncluded = false;
    
    // Randomly select positions for each character type
    int capitalPosition = rand() % length;
    int symbolsPosition = rand() % length;
    int numbersPosition = rand() % length;
    
    cout << "Generated password: ";
    for (int i = 0; i < length; i++) {
        // To ne sure that at least one character from each type is included
        if (i == capitalPosition && (answerCapital == "Y" || answerCapital == "y")) {
            cout << capital[rand() % (sizeof(capital) - 1)];
            capitalIncluded = true;
        } else if (i == symbolsPosition && (answerSymbols == "Y" || answerSymbols == "y")) {
            cout << symbols[rand() % (sizeof(symbols) - 1)];
            symbolsIncluded = true;
        } else if (i == numbersPosition && (answerNumbers == "Y" || answerNumbers == "y")) {
            cout << numbers[rand() % (sizeof(numbers) - 1)];
            numbersIncluded = true;
        } else {
            // Fill remaining positions randomly
            int option = rand() % 3;
            if (option == 0 && (answerCapital == "Y" || answerCapital == "y") && !capitalIncluded) {
                cout << capital[rand() % (sizeof(capital) - 1)];
                capitalIncluded = true;
            } else if (option == 1 && (answerSymbols == "Y" || answerSymbols == "y") && !symbolsIncluded) {
                cout << symbols[rand() % (sizeof(symbols) - 1)];
                symbolsIncluded = true;
            } else if (option == 2 && (answerNumbers == "Y" || answerNumbers == "y") && !numbersIncluded) {
                cout << numbers[rand() % (sizeof(numbers) - 1)];
                numbersIncluded = true;
            } else {
                // Fill with lowercase letters if none of the other conditions are met
                cout << low[rand() % (sizeof(low) - 1)];
            }
        }
    }
    return 0;
}
