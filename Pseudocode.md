# Rock, Paper, Scissors Game

## Pseudocode

### User Interface =

### Code Interface =

0. The user will decide what option they want to choose with rock, paper and scissors
1. Then the user will get a choice of using the program again or exiting it

#### Functions :

0. A class (rockPaperScissor) that contains all the functions to create the rock paper scissor game
1. A function within the class (rockPaperScissor) which will generate the choice of the CPU with srand() function
2. A function within the class (rockPaperScissor) will get the user's choice of either rock, paper or scissors
3. A function within the class (rockPaperScissor) will decide who is the winner and present the results
4. A function within the class (rockPaperScissor) will show the chosen option of the user and CPU
5. A function within the class (rockPaperScissor) will continuously loop the user's decision until the user is finished with using the program

#### Int main () :

0. Present what is program is about
1. Function that will ask for user's choice and to present that choice
2. Function that will get CPU's choice and present that choice
3. Function that will decide who is the winner and present the result
4. The function that will loop the program until the user is finished using it

### Issue

1. When the user would put a string input the program would have issues reading the input and malfunction
   Solution = I used cin.clear and cin.ignore with a if statement which has the same args as the while args then returned userInput when the user inputs the correct option
2. If user input the correct input like r, p or s as the first character of the input then junk afterward. The program would read it as correct and work accordingly then when coming to the loop it will show invalid input the ask for correct input. Then the user can decide if they want to continue using program
   Solution = So I changed the user input to a string input instead of char. So, the program will read a string input and if it isn't r, p or s then the program will say wrong input
