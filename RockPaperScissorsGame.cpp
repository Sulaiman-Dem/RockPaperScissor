#include <iostream>
#include <string>
#include <limits> // // for "cin.ignore(numeric_limits<streamsize>::max(), '\n');". For only integer input from user
#include <cctype> // This header declares a set of functions to classify and transform individual characters. For example, isupper() checks whether a character is uppercase or not.
using namespace std;

// Constant variables
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

char getCpuOption()
{
    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;

    if (num == 1)
        return 'r';
    if (num == 2)
        return 'p';
    if (num == 3)
        return 's';
    else
    {
        return 0;
    }
}

char getUserOption()
{
    char input;
    cout << "(r) for rock " << endl
         << "(p) for paper" << endl
         << "(s) for scissors " << endl;
    cout << "Input your choice: ";
    cin >> input;

    while (input != 'r' && input != 'p' && input != 's')
    {
        if (isupper(input)) // checks input to see if it is in upper case
        {
            cout << "                         " << endl;
            cout << "Your Input is in Uppercase. Only lowercase. Try Again! " << endl;
            cout << "(r) for rock " << endl
                 << "(p) for paper" << endl
                 << "(s) for scissors " << endl;
            cout << "Input your choice: " << endl;
            cin >> input;
        }
        else if (!isupper(input)) // if its no uppercase but is something else besides r, p or s then retry
        {
            cout << "                         " << endl;
            cout << "Please enter one of the following options only. " << endl;
            cout << "(r) for rock " << endl
                 << "(p) for paper" << endl
                 << "(s) for scissors " << endl;
            cout << "Input your choice: " << endl;
            cin >> input;
        }
        else
        {
            return input;
        }
    }
    return input;
}

// string getLetters()
// {
//     string input;
//     bool valid;

//     do
//     {
//         getline(cin, input);  // get line of input
//         valid = true;         // assume its valid
//         for (auto &i : input) // check each character in the input string
//         {

//             if (!isalpha(i)) // is it alphabetical character?
//             {
//                 valid = false; // if not, mark it as invalid
//                 // print an error to the user
//                 cout << " Invalid input. Please input only alphabetical characters." << endl;
//                 break; // break out of the for() loop, as we already established the input is invalid
//             }
//         }
//     } while (!valid); // Keep going until we get input that's valid

//     return input; // Once we have valid input, return it
// }

// string getCharacters()
// {
//     string input;

//     getline(cin, input);
//     if (input.length() != 1) // user input less/more than 1 character
//     {
//         cout << "You need to input only 1 letter (r, p or s).";
//         cout << "\nTry Again!";
//     }
//     else
//     {
//         return input;
//     }
//     return input;
// }

// string seeWinner(const string userOption, const string cpuOption)
// {
//     if (userOption == cpuOption)
//     {
//         cout << "Draw!";
//         return 0;
//     }
//     else if (userOption != cpuOption)
//     {
//         ((userOption[0] == 's' && cpuOption[0] == 'p') || (userOption[0] == 'p' && cpuOption[0] == 'r') || (userOption[0] == 'r' && cpuOption[0] == 's'));

//         cout << "You Win!";
//         return 0;
//     }
//     else
//     {
//         cout << "You Lose!";
//         return 0;
//     }
// }

void seeWinner(const char userOption, const char cpuOption)
{

    if (userOption == 'p' && cpuOption == 'r')
    {
        cout << "Paper beats Rock! You Win!";
        cout << "\n                                       ";
    }
    if (userOption == 'r' && cpuOption == 's')
    {
        cout << "Rock beats Scissors! You Win!";
        cout << "\n                                       ";
    }
    if (userOption == 's' && cpuOption == 'p')
    {
        cout << "Scissors beats Paper! You Win!";
        cout << "\n                                       ";
    }
    if (userOption == cpuOption)
    {
        cout << "You drew with the Computer! No Winner!";
        cout << "\n                                      ";
    }
    if (cpuOption == 'p' && userOption == 'r')
    {
        cout << "Paper beats Rock! You Lost!";
        cout << "\n                                       ";
    }
    if (cpuOption == 'r' && userOption == 's')
    {
        cout << "Rock beats Scissors! You Lost!";
        cout << "\n                                       ";
    }
    if (cpuOption == 's' && userOption == 'p')
    {
        cout << "Scissors beats Paper! You Lost!";
        cout << "\n                                       ";
    }
    // if (userOption == 'p' && cpuOption == 'p')
    // {
    //     cout << "You drew with the Computer! No Winner!";
    //     cout << "\n                                       ";
    // }
    // if (userOption == 'r' && cpuOption == 'r')
    // {
    //     cout << "You drew with the Computer! No Winner!";
    //     cout << "\n                                       ";
    // }
    // if (userOption == 's' && cpuOption == 's')
    // {
    //     cout << "You drew with the Computer! No Winner!";
    //     cout << "\n                                       ";
    // }
}

void showSelectedOption(char option)
{
    if (option == 'r')
        cout << "Rock" << endl;
    if (option == 'p')
        cout << "Paper" << endl;
    if (option == 's')
        cout << "Scissors" << endl;
}

int main()
{
    char userOption;
    char cpuOption;

    cout << "                                       " << endl;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t     Rock-Paper-Scissors Game" << endl;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    userOption = getUserOption();
    cout << "                  " << endl;
    cout << "Your choice is: ";
    showSelectedOption(userOption);

    cpuOption = getCpuOption();
    cout << "                  " << endl;
    cout << "Computer choice is: ";
    showSelectedOption(userOption);

    seeWinner(userOption, cpuOption);

    int choice;
    int i;

    cout << "                               ";
    cout << "\nDo you wish to play again? (1 for yes or press any key for no): ";
    cin >> choice;

    for (i = 0; choice != 10000000; i++)
    {

        if (choice == 1)
        {
            userOption = getUserOption();
            cout << "                  " << endl;
            cout << "Your choice is: ";
            showSelectedOption(userOption);

            cpuOption = getCpuOption();
            cout << "                  " << endl;
            cout << "Computer choice is: ";
            showSelectedOption(cpuOption);

            seeWinner(userOption, cpuOption);
            cout << "                               ";
            cout << "\nDo you wish to play again? (1 for yes or press any key for no): ";
            cin >> choice;
        }
        else
        {
            cerr << "\nThank you for Playing!"
                 << "\n  Have a Great Day"
                 << "\n                      " << endl;

            return 0;
        }
    }
}

/*
To-Do list! -
1. Try adding more user functionality
2. Maybe add animation of you winning or losing
*/

/*
Improvements
1. Doesn't read strings so it chooses any option.
2. When you run the program not from terminal it doesn't show goodbye message when user is finished with the program
*/
