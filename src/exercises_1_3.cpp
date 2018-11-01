#include "exercises_1_3.hpp"

void miles_to_km()
{
    cout << "Miles to kilometers converter.\n"
         << "\n";

    cout << "Please enter the number of miles: ";
    double miles {0};
    cin >> miles;

    double kilometers {miles * 1.609};

    cout << miles << " mile(s) equal(s) to " << kilometers << " kilometers.\n";
}

void int_relations()
{
    cout << "Enter value for integer #1: ";
    int i1 {0};
    cin >> i1;

    cout << "Enter value for integer #2: ";
    int i2 {0};
    cin >> i2;

    cout << "\n*** Integer Results ***\n"
         << "The smallest value is: " << ((i1 > i2)? i2 : i1) << "\n"
         << "The largest value is: " << ((i1 < i2)? i2 : i1) << "\n"
         << "The sum of both values is: " << i1 + i2 << "\n"
         << "The difference between #1 and #2 is: " << i1 - i2 << "\n"
         << "The product of both values is: " << i1 * i2 << "\n"
         << "The ratio of #1 against #2 is: " << i1 / i2;
}


void double_relations()
{
    cout << "Enter value for double #1: ";
    double d1 {0};
    cin >> d1;

    cout << "Enter value for double #2: ";
    double d2 {0};
    cin >> d2;

    cout << "\n*** Double Floating Point Results ***\n"
         << "The smallest value is: " << ((d1 > d2)? d2 : d1) << "\n"
         << "The largest value is: " << ((d1 < d2)? d2 : d1) << "\n"
         << "The sum of both values is: " << d1 + d2 << "\n"
         << "The difference between #1 and #2 is: " << d1 - d2 << "\n"
         << "The product of both values is: " << d1 * d2 << "\n"
         << "The ratio of #1 against #2 is: " << d1 / d2;
}

void three_int_sort()
{
    cout << "Pleasy type in three integer numbers separated by space.\n"
         << ">";

    size_t array_size {3};
    int initial_val {0};
    vector<int> ints(array_size, initial_val);

    for(size_t i {0}; i < ints.size(); ++i) {cin >> ints[i];}

    cout << "Received integers: ";
    for(size_t i {0}; i < ints.size(); ++i) {
        cout << ints[i];
        if(i < ints.size() - 1) { cout << ", "; }
    }
    cout << "\n";

    sort(ints.begin(), ints.end());
    cout << "Sorted integers: ";
    for(size_t i {0}; i < ints.size(); ++i) {
        cout << ints[i];
        if(i < ints.size() - 1) { cout << ", "; }
    }
    cout << "\n";
}

void three_str_sort()
{
    cout << "Pleasy type in three character strings separated by space.\n"
         << ">";

    size_t array_size {3};
    vector<string> strings(array_size, string());

    for(size_t i {0}; i < strings.size(); ++i) {cin >> strings[i];}

    cout << "Received strings: ";
    for(size_t i {0}; i < strings.size(); ++i) {
        cout << strings[i];
        if(i < strings.size() - 1) { cout << ", "; }
    }
    cout << "\n";

    sort(strings.begin(), strings.end());
    cout << "Sorted integers: ";
    for(size_t i {0}; i < strings.size(); ++i) {
        cout << strings[i];
        if(i < strings.size() - 1) { cout << ", "; }
    }
    cout << "\n";
}

void words_to_numbers()
{
    cout << "Spell out an integer number from zero up to four.\n"
         << "Type in \"exit\" if you want to leave.\n\n";

    string word;
    while(word != "exit") {
        cout << "> ";
        cin >> word;

        if(word == "exit") {break;}
        else if(word == "zero") {cout << "0";}
        else if(word == "one") {cout << "1";}
        else if(word == "two") {cout << "2";}
        else if(word == "three") {cout << "3";}
        else if(word == "four") {cout << "4";}
        else {cout << "not a number I understand";}
        cout << "\n";
    }
}

void simple_calc()
{
    cout << "Please enter an operator (e.g. +, -, etc) followed by two"
        "variables\n"
         << "Or, if you wish to leave this sub-program - type in \"exit\".\n";

    string operation;
    cin >> operation;
    if(operation == "exit") {return;}

    double var1 {0.0}, var2 {0.0};
    cin >> var1 >> var2;

    double result {0.0};
    if(operation == "+") {result = var1 + var2;}
    else if(operation == "-") {result = var1 - var2;}
    else if(operation == "*") {result = var1 * var2;}
    else if(operation == "/") {result = var1 / var2;}

    cout << "\n"
         << var1 << " " << operation << " " << var2 << " = " << result << "\n"
         << "\n";
        
}

void cent_counter()
{
    cout << "please input the number of pennies: ";
    unsigned pennies {0};
    cin >> pennies;
    cout << "please input the number of nickels: ";
    unsigned nickels {0};
    cin >> nickels;
    cout << "please input the number of dimes: ";
    unsigned dimes {0};
    cin >> dimes;
    cout << "please input the number of quarters: ";
    unsigned quarters {0};
    cin >> quarters;
    cout << "please input the number of half dollars: ";
    unsigned half_dollars {0};
    cin >> half_dollars;

    unsigned total_cents = pennies +
                           (nickels * 5) +
                           (dimes * 10) +
                           (quarters * 25) +
                           (half_dollars * 50);

    //deciding on correct suffixes (plural or singular)
    string pennies_str = (pennies == 1)? "penny" : "pennies";
    string nickels_str = (nickels == 1)? "nickel" : "nickels";
    string dimes_str = (dimes == 1)? "dime" : "dimes";
    string quarters_str = (quarters == 1)? "quarter" : "quarters";
    string half_dollars_str = (half_dollars == 1)?
        "half dollar" : "half dollars";

    //the final print out
    cout << "\n"
         << "You have " << pennies << " " << pennies_str << ".\n"
         << "You have " << nickels << " " << nickels_str << ".\n"
         << "You have " << dimes << " " << dimes_str << ".\n"
         << "You have " << quarters << " " << quarters_str << ".\n"
         << "You have " << half_dollars << " " << half_dollars_str << ".\n"
         << "The value of all your coins is $"
             << total_cents / 100 << "." << total_cents % 100 << ".\n";
}
