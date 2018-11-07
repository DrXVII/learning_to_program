#include "try_this.hpp" //header for this implementation file

void coin_converter()
{
    constexpr double copper_val {2};
    constexpr double silver_val {5};
    constexpr double gold_val {32};
    constexpr double platinum_val {48};
    constexpr double mythril_val {392};

    cout << "\n"
    << "Please type the number of coins followed by a letter to denote\n"
    << "the type of the coin in order to convert your coin value to\n"
    << "an equivalent in imperial credits.\n"
    << "(Provide an ammount of zero to quit)\n"
    << "c - copper; s - silver; g - gold; p - platinum; m - mythril.\n";

    double ammount {0.0};
    do {
        cout << "\n> ";

        char material {' '};
        cin >> ammount >> material;

        double converted_amt {0};
        switch(material) {
        case 'c':
            converted_amt = ammount * copper_val;
            break;
        case 's':
            converted_amt = ammount * silver_val;
            break;
        case 'g':
            converted_amt = ammount * gold_val;
            break;
        case 'p':
            converted_amt = ammount * platinum_val;
            break;
        case 'm':
            converted_amt = ammount * mythril_val;
            break;
        default:
            cout << "Sorry, you have entered an unknown material.\n"
                 << "Please try again.\n";
            continue;
        }

        cout << ammount << material << " equals " << converted_amt
                 << " imperial credits.\n";
    }while(ammount > 0.0001);
}
