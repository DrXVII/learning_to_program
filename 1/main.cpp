/*******************************************************************************
 * This program is wiritten folowing along the book "Programming Principles
 * and Practice using C++" by Bjarne Stroustrup.
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

void main_menu();
void greetings();
void age_calculation();
void operations_double();
void operations_int();
void repeated_words();

int main()
{
    main_menu();

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
             << "3 - Operations exampe: double precicioin\n"
             << "4 - Operations exampe: integer\n"
             << "5 - Repeated words\n"
             << "\n"
             << "0 - Quit\n";

        //break if we have an end-of-input or IO errors
        if(!(cin >> sel)) {break;}

        switch(sel) {
        case 0:
            break;
        case 1:
            greetings();
            break;
        case 2:
            age_calculation();
            break;
        case 3:
            operations_double();
            break;
        case 4:
            operations_int();
            break;
        case 5:
            repeated_words();
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

    cout << "Please enter your name: ";
    string name;
    cin >> name;

    cout << "Please enter your age in years: ";
    int age {0};
    cin >> age;

    cout << "Hello " << name << " (age: " << age << "), nice to meet you.\n";

}

void age_calculation()
{
    cout << "Welcome to age calculation, please input your exact age.\n";

    cout << "Age: ";
    double age {0.0};
    cin >> age;

    double age_in_months = age * 12.0;

    cout << "Your age is " << age << " years or "
         << age_in_months << " months.\n";
}

void operations_double()
{
    cout << "please enter a floating-point value.\n";
    cout << "n: ";
    double n;
    cin >> n;

    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nthree times n == " << 3*n
         << "\ntwice n == " << n+n
         << "\nn squared == " << n*n
         << "\nhalf of n == " << n/2
         << "\nsquare root of n == " << sqrt(n)
         << "\n";
}

void operations_int()
{
    cout << "please enter an integer value.\n";
    cout << "n: ";
    int n;
    cin >> n;

    cout << "n == " << n
         << "\nn+1 == " << n+1
         << "\nthree times n == " << 3*n
         << "\ntwice n == " << n+n
         << "\nn squared == " << n*n
         << "\nhalf of n == " << n/2
         << "\nsquare root of n == " << sqrt(static_cast<double>(n))
         << "\nmodulo of half of n == " << n%2
         << "\n";
}

void repeated_words()
{
    unsigned repetitions {0};
    string previous(" "); //using space because cin drops them
    string current;

    cout << "Pass an end of input character (Ctrl+d on unix) to finish.\n";
    cout << "Input sentence: ";

    while(cin >> current) {
        if(previous == current) {
            cout << "repeated word: " << current << "\n";
            ++repetitions;
            cout << "repetitions so far: " << repetitions << "\n";
        }

        previous = current;
    }
}
