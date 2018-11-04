/*******************************************************************************
 *     This program is wiritten folowing along the book "Programming Principles
 * and Practice using C++" by Bjarne Stroustrup.
 * Starting at part 1, chapter 2.
 *
 *     This program is not meant for any purpose but to complete, test and
 * experiment with the various drills, exercises and examples provided in said
 * book.
 ******************************************************************************/

//this should heep us covered until chapter 5 vvv
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
//this should heep us covered until chapter 5 ^^^

//homebrew
#include "drill_1_3.hpp"
#include "exercises_1_3.hpp"

using namespace std;

void main_menu();
void greetings();
void age_calculation();
void operations_double();
void operations_int();
void repeated_words();
void experiment();
void consts(); //unused and not meant to be used, just a compilation experiment

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
        cout << "\n\n"
             << "*** MAIN MENU ***\n"
             << "1 - Greetings\n"
             << "2 -   Age calculation\n"
             << "3 -   Operations exampe: double precicioin\n"
             << "4 -   Operations exampe: integer\n"
             << "5 -   Repeated words\n"
             << "6 -   Drill from chapter I part 3\n"
             << "7 -   Miles to Kilometers (ex I-3-2)\n"
             << "8 -   Integer relationships (ex I-3-4)\n"
             << "9 -   Double precision float relationships (ex I-3-5)\n"
             << "10 -  Three int sort (ex I-3-6)\n"
             << "11 -  Three string sort (ex I-3-7)\n"
             << "12 -  Words to numbers (ex I-3-9)\n"
             << "13 -  Simple calculator (ex I-3-10)\n"
             << "14 -  Cent counter (ex I-3-11)\n"
             << "777 - Experiment\n"
             << "\n"
             << "0 - Quit\n"
             << "\n"
             << "> ";

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
        case 6:
            drill_1_3();
            break;
        case 7:
            miles_to_km();
            break;
        case 8:
            int_relations();
            break;
        case 9:
            double_relations();
            break;
        case 10:
            three_int_sort();
            break;
        case 11:
            three_str_sort();
            break;
        case 12:
            words_to_numbers();
            break;
        case 13:
            simple_calc();
            break;
        case 14:
            cent_counter();
            break;
        case 777:
            experiment();
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
    string previous(" "); //using space because cin drops them
    string current;
    unsigned repetitions {0};
    unsigned word_counter {0};

    cout << "Pass an end of input character (Ctrl+d on unix) to finish.\n";
    cout << "Input sentence: ";

    while(cin >> current) {
        ++word_counter;
        if(previous == current) {
            ++repetitions;
            cout << "repeated word: " << current << " (" << word_counter << ")\n"
                 << "repetitions so far: " << repetitions << "\n";
        }

        previous = current;
    }
}

void experiment()
{
    cout << "nothing to look at here today\n";

    //int i {20000};
    /* char c = i does not produce a warning on most compilers, while
     * char c {i} does. (this initialization notation introduced in c++11) */
    //char c {i};
    //int i2 {c};

    //if(i != i2) {
    //    cout << "A narrowing conversion happened.\n"
    //         << "i == " << i << "\n"
    //         << "i2 == " << i2 << "\n";
    //}
    //else {
    //    cout << "Wow, we have large chars.\n";
    //}
}

/* just testing out constexpr vs const,
 * this procedure is not meant to be used in code*/
void consts()
{
    int i {22}; __attribute__((unused))
    const int c {i}; __attribute__((unused)) //OK
    const int cc {33};
    constexpr int cx {77};
    //constexpr int cx_from_i {i}; //err: i is not usable as constant expression
    //constexpr int cx_from_c {c}; //err: c was not initialised from constant ex
    constexpr int cx_from_c {cc};

    i = cx;
    i = cx_from_c;
}
