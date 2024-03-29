#include <iostream>
#include <limits> // for "std::cin.ignore(numeric_limits<streamsize>::max(), '\n');".

// This is a class for rock paper scissors game
class rockPaperScissors
{
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
    std::string getUserChoice()
    {
        std::string userInput;
        std::cout << "\n(r) for rock " << std::endl
                  << "(p) for paper" << std::endl
                  << "(s) for scissors " << std::endl;
        std::cout << "Input your choice: ";
        std::cin >> userInput;

        while ((userInput != "r") && (userInput != "p") && (userInput != "s"))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (userInput != "r" && userInput != "p" && userInput != "s")
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
    void seeWinner(std::string userChoice, const char cpuChoice)
    {
        if ((userChoice == "p" && cpuChoice == 'p') || (userChoice == "r" && cpuChoice == 'r') || (userChoice == "s" && cpuChoice == 's'))
        {
            std::cout << "You drew with the Computer! No Winner!";
            std::cout << "\n";
        }
        if ((userChoice == "p" && cpuChoice == 'r') || (userChoice == "r" && cpuChoice == 's') || (userChoice == "s" && cpuChoice == 'p'))
        {
            std::cout << "You Win!";
            std::cout << "\n";
        }

        if ((userChoice == "r" && cpuChoice == 'p') || (userChoice == "s" && cpuChoice == 'r') || (userChoice == "p" && cpuChoice == 's'))
        {
            std::cout << "You Lost!";
            std::cout << "\n";
        }
    }

    // This function will show the chosen option of the user and CPU
    void showSelectedOptionUser(std::string option)
    {
        if (option == "r")
            std::cout << "Rock" << std::endl;
        if (option == "p")
            std::cout << "Paper" << std::endl;
        if (option == "s")
            std::cout << "Scissors" << std::endl;
    }

    void showSelectedOptionCPU(char option)
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

    std::string userDecision;
    std::string userChoice;
    char cpuChoice;

    std::cout << "\nDo you wish to play again? (1 for yes or 0 for no): ";
    std::cin >> userDecision;

    while ((userDecision != "1") && (userDecision != "0"))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input. Try again!";
        std::cout << "\nEnter Choice here: ";
        std::cin >> userDecision;
    }

    if (userDecision == "1")
    {
        userChoice = rps.getUserChoice();
        std::cout << "\nYour choice is: ";
        rps.showSelectedOptionUser(userChoice);

        cpuChoice = rps.getCpuChoice();
        std::cout << "\nComputer choice is: ";
        rps.showSelectedOptionCPU(cpuChoice);

        rps.seeWinner(userChoice, cpuChoice);

        loopUserDecision();
    }
    if (userDecision == "0")
    {
        std::cout << "\nThank you for Playing!";
        std::cout << "\n  Have a Great Day!";
        std::cout << "\n\t";
    }
}

int main()
{
    std::string userChoice;
    char cpuChoice;

    class rockPaperScissors rps;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "     Rock-Paper-Scissors Game" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    userChoice = rps.getUserChoice(); // This will store the user's choice in "userChoice"
    std::cout << "\nYour choice is: ";
    rps.showSelectedOptionUser(userChoice); // This will present the user's choice with the stored value of "userChoice"

    cpuChoice = rps.getCpuChoice(); // This will store the CPU's choice in "cpuChoice"
    std::cout << "\nComputer choice is: ";
    rps.showSelectedOptionCPU(cpuChoice); // This will present the CPU's choice with the stored value of "cpuChoice"

    rps.seeWinner(userChoice, cpuChoice); // This will use both stored values and determine the winner and present results

    loopUserDecision(); // This will loop the program until the user is finished
}

// improvements - Maybe add animation of you winning or losing