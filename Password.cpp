/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib> // to use functions like srand to generate password randomly
#include <string>
#include <ctime> // to use functions like time to get current time
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

    int totalLength = length; // to select variables correctly 

    cout << "Do you want to add capital letters to your password? (Y/N): ";
    cin >> answerCapital;
    if (answerCapital == "Y" || answerCapital == "y")
        totalLength += 26; // to count the quantity of selected varaible correctly

    cout << "Do you want to add symbols to your password? (Y/N): ";
    cin >> answerSymbols;
    if (answerSymbols == "Y" || answerSymbols == "y")
        totalLength += 13; // to count the quantity of selected varaible correctly

    cout << "Do you want to add numbers to your password? (Y/N): ";
    cin >> answerNumbers;
    if (answerNumbers == "Y" || answerNumbers == "y")
        totalLength += 10; // to count the quantity of selected varaible correctly

    srand(time(0));
    cout << "Generated password: ";
    for (int i = 0; i < length; i++) {
        int option = rand() % totalLength; // to randomize selected certain varaible

        if (option < length)
            cout << low[rand() % (sizeof(low) - 1)];
        else if (option < length + 26 && (answerCapital == "Y" || answerCapital == "y"))
            cout << capital[rand() % (sizeof(capital) - 1)];
        else if (option < length + 39 && (answerSymbols == "Y" || answerSymbols == "y"))
            cout << symbols[rand() % (sizeof(symbols) - 1)];
        else if (option < length + 49 && (answerNumbers == "Y" || answerNumbers == "y"))
            cout << numbers[rand() % (sizeof(numbers) - 1)];
    }
    return 0;
}
