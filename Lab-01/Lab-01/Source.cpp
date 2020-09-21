#include <iostream>
#include <string>
using namespace std;

// Function that checks if the given number is prime and outputs a boolean value

bool checkIfPrime(int userNum) {

    bool isPrimeNum = true;

    for (int i = 2; i <= userNum / 2; i++) {

        if (userNum % i == 0) {

            isPrimeNum = false;
            break;
        }
    }

    return isPrimeNum;

}

// Display the menu function with user input and outputs based off input

void displayMenu() {

    char userChoice;

    do
    {

        cout << endl;
        cout << "List of edit operations:" << endl << endl;
        cout << "D = Delete a substring." << endl;
        cout << "F = Find a string." << endl;
        cout << "I = Insert a string." << endl;
        cout << "R = Replace a substring." << endl;
        cout << "Q = Quit" << endl << endl;
        cout << "Enter D, F, I, R, or Q as your selection: " << endl << endl;
        cin >> userChoice;
        cout << endl;

        switch (userChoice)
        {

        case 'D':

            cout << "Delete a substring." << endl << endl;

            break;

        case 'F':

            cout << "Find a string." << endl << endl;

            break;

        case 'I':

            cout << "Insert a string." << endl << endl;

            break;

        case 'R':

            cout << "Replace a substring." << endl << endl;

            break;

        }


    } while (userChoice != 'Q');


}


int main() {

    displayMenu();

    int userNum = 0;

    // User enters a number
    
      cout << "Enter a number: " << endl << endl;
      cin >> userNum;
   
    cout << endl << endl;

    cout << "All Prime Numbers Till " << userNum << ": " << endl << endl;

    // Loop that sends number to a function and outputs numbers that are prime (specified by function)

    for (int i = 2; i <= userNum; i++) {

       bool primeBool = checkIfPrime(i);

       if (primeBool) {

           cout << i << endl;
       }
      

    }


    return 0;
}