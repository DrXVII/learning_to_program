#include "drill_1_3.hpp" //header for this implementation

void drill_1_3()
{
    cout << "starting drill ch I - part 3\n\n\n";

    cout << "Hi, in order to generate e-mail text for you, I have to ask you\n"
         << "to provide some informaion first.\n";

    cout << "your first name: ";
    string sender_name;
    cin >> sender_name;

    cout << "first name of recipient: ";
    string first_name;
    cin >> first_name;

    enum {min_age = 0, max_age = 110};
    int recipient_age {0};
    while(1) {
        cout << "age of recipient: ";
        cin >> recipient_age;

        if(recipient_age < min_age || recipient_age > max_age) {
            cout << "You're kidding!\n";
            continue;
        }
        else {break;}
    }
    cout << "first name of a mutual friend: ";
    string friend_name;
    cin >> friend_name;

    char friend_sex {0};
    while(friend_sex != 'm' && friend_sex != 'f') {
        cout << "sex of mutual friend (m/f): ";
        cin >> friend_sex;
    }
    string sex_pronoun = (friend_sex == 'm')? "him" : "her";


    cout << "\n\n";
    //letter body begins here

    cout << "    Dear " << first_name << ",\n"
         << "\n"
         << "    How are you doing?\n"
         << "\n"
         << "    Have you seen " << friend_name << " lately?\n"
         << "If you see " << friend_name << " please ask " << sex_pronoun
             << " to call me.\n"
         << "\n"
         << "    I hear you just had a birthday and you are now "
             << recipient_age << " years old, congrats!.\n";

    if(recipient_age < 12) {
        cout << "Next year you will be " << recipient_age + 1 << ".\n";
    }
    else if (recipient_age == 17) {
        cout << "Next year you will be able to vote.\n";
    }
    else if (recipient_age > 70) {
        cout << "I hope you are enjoying retirement.\n";
    }

    cout << "\n"
         << "    Yours sincerely, \n"
         << "\n"
         << "\n"
         << "    " << sender_name << "\n";

    cout << "\n\nend of drill ch I - part 3\n";
}
