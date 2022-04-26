#include <iostream>
#include <string>
using namespace std;

#include <string>

string rps(const string p1, const string p2)
{
    if (p1 == p2)
        return "Draw!";

    if ((p1[0] == 's' && p2[0] == 'p') || (p1[0] == 'p' && p2[0] == 'r') || (p1[0] == 'r' && p2[0] == 's'))
        return "Player 1 Wins!";
    else
        return "Player 2 Wins!";
}

int main()
{
    const string p1;
    const string p2;

    string input{0};

    input = rps(p1, p2);
    cout << "                                       " << endl;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\t     Rock-Paper-Scissors Game" << endl;
    cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                                       " << endl;
    cout << "Please type in '1' for Rock, '2' for Scissors and '3' for paper to play the game\n";
    cout << "Type your choice here:  ";
    cin >> input;

    // Test hello
}
