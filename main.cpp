/*******************************************************************************
 * This program is wiritten folowing along the book "Programming Principles
 * and Practice using C++" by Bjarne Straustrup.
 * Starting at part 1, chapter 2.
 ******************************************************************************/

//this should heep us covered until chapter 5 vvv
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
//this should heep us covered until chapter 5 ^^^
using namespace std;

inline void keep_window_open() {
    cout << "Input anything to continue.\n";
    char ch;
    cin >> ch;
}

void main_menu();
void greetings();
void age_calculation();

int main()
{
    main_menu();

    keep_window_open();
    cout << "End of program. Terminating.\n";
    return 0;
}

void main_menu()
{
    int sel {0};

    do {
        cout << "\n"
             << "*** MAIN MENU ***\n"
             << "1 - Greetings\n"
             << "2 - Age calculation\n"
             << "\n"
             << "0 - Quit\n";

        cin >> sel;

        switch(sel) {
        case 0:
            break;
        case 1:
            greetings();
            break;
        case 2:
            age_calculation();
            break;
        default:
            cout << "invalid selection, try again\n";
        }
    }while(sel != 0);
}

void greetings()
{
    cout << "Hi!\n"
         << "I would like to extend a more proper greeting, but in order\n"
         << "to be able to do so, I must know a bit more about you.\n";

    string name;
    cout << "Please enter your name: ";
    cin >> name;

    int age {0};
    cout << "Please enter your age in years: ";
    cin >> age;

    cout << "Hello " << name << " (age: " << age << "), nice to meet you.\n";

}

void age_calculation()
{
    cout << "Welcome to age calculation, please input your exact age.\n";

    double age {0.0};
    cout << "Age: ";
    cin >> age;

    double age_in_months = age * 12.0;

    cout << "Your age is " << age << " years or "
         << age_in_months << " months.\n";
}
