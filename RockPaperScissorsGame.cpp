#include <iostream>
#include <limits> // for "std::cin.ignore(numeric_limits<streamsize>::max(), '\n');".

// This is a class for rock paper scissors game
class rockPaperScissors
{
private:
    // Constant variables that are used in many functions
    char ROCK = 'r';
    char PAPER = 'p';
    char SCISSORS = 's';

public:
    // This function will generate the choice of the CPU with srand() function
    char getCpuChoice()
    {
        srand((unsigned)time(0)); // This provides random generator option for C++ (Seeding) (Not reliable but it works most of the time) (uses time of opening program and uses of program to generate random numbers)

        int cpuChoice;

        for (int index = 0; index < 3; index++)
        {
            cpuChoice = (rand() % 3) + 1;

            if (cpuChoice == 1)
                return 'r';
            if (cpuChoice == 2)
                return 'p';
            if (cpuChoice == 3)
                return 's';
        }
        return cpuChoice;
    }

    // This function will get the user's choice of either rock, paper or scissors
    char getUserChoice()
    {
        char userInput;
        std::cout << "\n(r) for rock " << std::endl
                  << "(p) for paper" << std::endl
                  << "(s) for scissors " << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> userInput;

        while ((userInput != 'r') && (userInput != 'p') && (userInput != 's'))
        {
            // bug - Will work if first character of input is r, p or s
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (userInput != 'r' && userInput != 'p' && userInput != 's')
            {
                std::cout << "\nPlease enter one of the following options only. " << std::endl;
                std::cout << "(r) for rock " << std::endl
                          << "(p) for paper" << std::endl
                          << "(s) for scissors " << std::endl;
                std::cout << "Input your choice: ";
                std::cin >> userInput;
            }
        }
        return userInput;
    }

    // This function will decide who is the winner and present the results
    void seeWinner(const char userChoice, const char cpuChoice)
    {
        if ((userChoice == 'p' && cpuChoice == 'p') || (userChoice == 'r' && cpuChoice == 'r') || (userChoice == 's' && cpuChoice == 's'))
        {
            std::cout << "You drew with the Computer! No Winner!";
            std::cout << "\n";
        }
        if ((userChoice == 'p' && cpuChoice == 'r') || (userChoice == 'r' && cpuChoice == 's') || (userChoice == 's' && cpuChoice == 'p'))
        {
            std::cout << "You Win!";
            std::cout << "\n";
        }

        if ((userChoice == 'r' && cpuChoice == 'p') || (userChoice == 's' && cpuChoice == 'r') || (userChoice == 'p' && cpuChoice == 's'))
        {
            std::cout << "You Lost!";
            std::cout << "\n";
        }
    }

    // This function will show the chosen option of the user and CPU
    void showSelectedOption(char option)
    {
        if (option == 'r')
            std::cout << "Rock" << std::endl;
        if (option == 'p')
            std::cout << "Paper" << std::endl;
        if (option == 's')
            std::cout << "Scissors" << std::endl;
    }
};

// This function will continuously loop the user's decision until the user is finished with using the program
void loopUserDecision()
{

    class rockPaperScissors rps;

    int userDecision;
    char userChoice;
    char cpuChoice;

    std::cout << "\nDo you wish to play again? (1 for yes or 0 for no): ";

    while (!(std::cin >> userDecision) || (userDecision > 1) || (userDecision < 0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input. Try again!";
        std::cout << "\nEnter Choice here: ";
    }

    if (userDecision == 1)
    {
        userChoice = rps.getUserChoice();
        std::cout << "\nYour choice is: ";
        rps.showSelectedOption(userChoice);

        cpuChoice = rps.getCpuChoice();
        std::cout << "\nComputer choice is: ";
        rps.showSelectedOption(cpuChoice);

        rps.seeWinner(userChoice, cpuChoice);

        loopUserDecision();
    }
    if (userDecision == 0)
    {
        std::cout << "\nThank you for Playing!";
        std::cout << "\n  Have a Great Day!";
        std::cout << "\n\t";
    }
}

int main()
{
    char userChoice;
    char cpuChoice;

    class rockPaperScissors rps;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "     Rock-Paper-Scissors Game" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    userChoice = rps.getUserChoice(); // This will store the user's choice in "userChoice"
    std::cout << "\nYour choice is: ";
    rps.showSelectedOption(userChoice); // This will present the user's choice with the stored value of "userChoice"

    cpuChoice = rps.getCpuChoice(); // This will store the CPU's choice in "cpuChoice"
    std::cout << "\nComputer choice is: ";
    rps.showSelectedOption(cpuChoice); // This will present the CPU's choice with the stored value of "cpuChoice"

    rps.seeWinner(userChoice, cpuChoice); // This will use both stored values and determine the winner and present results

    loopUserDecision(); // This will loop the program until the user is finished
}

// bug - If user input the correct input like r, p or s as the first character of the input then junk afterward. The program would read it as correct and work accordingly then when coming to the loop it will show invalid input the ask for correct input line 47