#include <iostream>
#include <time.h>
using namespace std;

// This is for the check game over function
// Number of moves played
int numOfMoves;

// This is for computer gamemode
// 'H' for human and 'C' for computer
char HumanOrComputerWin;

// This is for two player game mode
// "1" for player 1 and "2" for player 2
int player1or2Win;

// Array for the Tic-Tac-Toe grid
char tictactoeGrid[3][3];

// Number of rounds won for player 1
int player1Wins = 0;
// Number of rounds won for player 2
int player2Wins = 0;
// Number of rounds won for single player
int playerWins = 0;
// Number of rounds won for computer
int computerWins = 0;
// Total number of rounds for two player game
int twoPlayerGameWins = 0;
// Total number of rounds for single player game
int singlePlayerGameWins = 0;

// Stores name of player 1
string firstplayername;
// Stores name of player 2
string secondplayername;

// This is for the player vs. computer game mode
// This will hold the name of the player
string PlayaName;

// Used for player vs. computer hard mode
// Stores a random number between 1 and 4 to use for if statements
int randNum;

// These boolean variables are for the player vs. computer hard mode
// These help check if each corner spot has been played
bool corner1Checked;
bool corner2Checked;
bool corner3Checked;
bool corner4Checked;

// These boolean variables show whether each game mode has been played more than once
// This is used so that the game only asks the names of the players once
bool twoPlayerGamePlayedMoreThanOnce = false;
bool singlePlayerGamePlayedMoreThanOnce = false;

// Function that checks if the game is over
int checkGameOver()
{
    for (int i = 0; i < 3; i++)
    {
        // Checks rows
        if (tictactoeGrid[i][0] == 'X' && tictactoeGrid[i][1] == 'X' && tictactoeGrid[i][2] == 'X')
        {
            player1or2Win = 1;
            HumanOrComputerWin = 'H';
            return 1;
        }
        else if (tictactoeGrid[i][0] == 'O' && tictactoeGrid[i][1] == 'O' && tictactoeGrid[i][2] == 'O')
        {
            player1or2Win = 2;
            HumanOrComputerWin = 'C';
            return 1;
        }
        // Checks columns
        else if (tictactoeGrid[0][i] == 'X' && tictactoeGrid[1][i] == 'X' && tictactoeGrid[2][i] == 'X')
        {
            player1or2Win = 1;
            HumanOrComputerWin = 'H';
            return 1;
        }
        else if (tictactoeGrid[0][i] == 'O' && tictactoeGrid[1][i] == 'O' && tictactoeGrid[2][i] == 'O')
        {
            player1or2Win = 2;
            HumanOrComputerWin = 'C';
            return 1;
        }
    }
    // Checks diagonals
    // '7','5','3'
    if (tictactoeGrid[2][0] == 'X' && tictactoeGrid[1][1] == 'X' && tictactoeGrid[0][2] == 'X')
    {
        player1or2Win = 1;
        HumanOrComputerWin = 'H';
        return 1;
    }
    else if (tictactoeGrid[2][0] == 'O' && tictactoeGrid[1][1] == 'O' && tictactoeGrid[0][2] == 'O')
    {
        player1or2Win = 2;
        HumanOrComputerWin = 'C';
        return 1;
    }
    // '1','5','9'
    else if (tictactoeGrid[0][0] == 'X' && tictactoeGrid[1][1] == 'X' && tictactoeGrid[2][2] == 'X')
    {
        player1or2Win = 1;
        HumanOrComputerWin = 'H';
        return 1;
    }
    else if (tictactoeGrid[0][0] == 'O' && tictactoeGrid[1][1] == 'O' && tictactoeGrid[2][2] == 'O')
    {
        player1or2Win = 2;
        HumanOrComputerWin = 'C';
        return 1;
    }
    // Checks for tie
    numOfMoves = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((tictactoeGrid[i][j] == 'X') || (tictactoeGrid[i][j] == 'O'))
            {
                numOfMoves++;
            }
        }
    }
    if (numOfMoves == 9)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// Grid for player vs. player mode
void display_grid()
{
    system("cls");
    cout << endl
         << endl
         << "   TIC-TAC-TOE" << endl;

    cout << "-----------------" << endl;

    cout << firstplayername << " [X]" << endl;
    cout << secondplayername << " [O]" << endl
         << endl;

    cout << "     |     |     " << endl;
    cout << "  " << tictactoeGrid[0][0] << "  |  " << tictactoeGrid[0][1] << "  |  " << tictactoeGrid[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tictactoeGrid[1][0] << "  |  " << tictactoeGrid[1][1] << "  |  " << tictactoeGrid[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tictactoeGrid[2][0] << "  |  " << tictactoeGrid[2][1] << "  |  " << tictactoeGrid[2][2] << endl;

    cout << "     |     |     " << endl
         << endl;
}

// Grid for player vs. computer mode
void display_VSCompgrid()
{
    system("cls");
    cout << endl
         << endl
         << "   TIC-TAC-TOE" << endl;

    cout << "-----------------" << endl;

    cout << PlayaName << " [X]" << endl;
    cout << "Computer [O]" << endl
         << endl;

    cout << "     |     |     " << endl;
    cout << "  " << tictactoeGrid[0][0] << "  |  " << tictactoeGrid[0][1] << "  |  " << tictactoeGrid[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tictactoeGrid[1][0] << "  |  " << tictactoeGrid[1][1] << "  |  " << tictactoeGrid[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << tictactoeGrid[2][0] << "  |  " << tictactoeGrid[2][1] << "  |  " << tictactoeGrid[2][2] << endl;

    cout << "     |     |     " << endl
         << endl;
}

// Player vs. player mode
void twoplayerstictactoe()
{
    int player = 1; // This alternates between 1 and 2 to switch turns. Player 1 will always go first
    char choice;    // This holds the input from each player
    char mark;      // Mark is either X or 0, depending on whose turn is it

    if (twoPlayerGamePlayedMoreThanOnce == false)
    {
        // This allows players to set a custom name and displays it to the screen
        cout << "Player 1, enter your name: " << firstplayername;
        cin >> firstplayername;
        cout << endl;
        cout << "Player 2, enter your name: " << secondplayername;
        cin >> secondplayername;
        cout << endl;
    }

    do
    {
        display_grid(); // This displays the game

        if (player % 2 == 1) // This statement alternates between player 1 and 2 after each turn
        {
            player = 1;
        }
        else
        {
            player = 2;
        }

        if (player == 1)
        {
            cout << firstplayername << ", enter a number:  "; // Asks player 1 where they want to put mark on board
            cin >> choice;
        }
        else
        {
            cout << secondplayername << ", enter a number:  "; // Asks player 2 where they want to put mark on board
            cin >> choice;
        }

        if (player == 1) // Checks which player is playing and assigns the appropriate mark
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        if (choice == '1' && tictactoeGrid[0][0] == '1')
        {                               // These if statements display the input choice of the player to the
            tictactoeGrid[0][0] = mark; // game board. The " && tictactoeGrid[][] == 'x' " is used to check if the
        }                               // box the player chose is unoccupied and doesn't already have a mark
        else if (choice == '2' && tictactoeGrid[0][1] == '2')
        {
            tictactoeGrid[0][1] = mark;
        }
        else if (choice == '3' && tictactoeGrid[0][2] == '3')
        {
            tictactoeGrid[0][2] = mark;
        }
        else if (choice == '4' && tictactoeGrid[1][0] == '4')
        {
            tictactoeGrid[1][0] = mark;
        }
        else if (choice == '5' && tictactoeGrid[1][1] == '5')
        {
            tictactoeGrid[1][1] = mark;
        }
        else if (choice == '6' && tictactoeGrid[1][2] == '6')
        {
            tictactoeGrid[1][2] = mark;
        }
        else if (choice == '7' && tictactoeGrid[2][0] == '7')
        {
            tictactoeGrid[2][0] = mark;
        }
        else if (choice == '8' && tictactoeGrid[2][1] == '8')
        {
            tictactoeGrid[2][1] = mark;
        }
        else if (choice == '9' && tictactoeGrid[2][2] == '9')
        {
            tictactoeGrid[2][2] = mark;
        }
        else
        {
            cout << "Invalid move, try again!" << endl; // This part is for if the player inputted a key that's not on the board
            cout << "[Press Enter to continue]" << endl;
            player--; // Player will go again
            cin.ignore();
            cin.get();
        }

        player++; // Passes turn to other player

    } while (checkGameOver() == 0); // This will keep repeating until there is a win or draw
    display_grid();

    if (checkGameOver() == 1)
    {
        if (player1or2Win == 1)
        {
            player1Wins++;
            cout << firstplayername << " won the game!" << endl;
        }
        else
        {
            player2Wins++;
            cout << secondplayername << " won the game!" << endl;
        }
    }
    else if (checkGameOver() == 2)
    {
        cout << "Game was a tie!" << endl;
    }
    twoPlayerGameWins++;
    cout << endl;
}

// Player vs. computer mode
void computergamemode()
{
    char humanmark = 'X';    // 'X' on game board
    char computermark = 'O'; // 'O' on game board
    char humanchoice;        // What the player chooses
    int computerchoice;      // What the computer chooses
    int difficultylevel;     // Easy mode(1) or hard mode(2)

    int human = 1; // This will be 1 if the user is playing, and 2 if the computer is playing

    if (singlePlayerGamePlayedMoreThanOnce == false)
    {
        cout << "Type your name: ";
        cin >> PlayaName;
        cout << endl
             << endl;
    }

    cout << "Choose Your Difficulty: Easy mode[1] or Hard mode[2]" << endl;
    cout << "----------------------------------------------------" << endl;
    cin >> difficultylevel;

    do
    {
        if (human == 1)
        {
            display_VSCompgrid(); // Will display the gameboard for the player vs. computer mode

            cout << PlayaName << ", enter a number: "; // Asks player where they want to put the mark on the board
            cin >> humanchoice;

            if (humanchoice == '1' && tictactoeGrid[0][0] == '1')
            {                                    // These if statements display the input choice of the player to the
                tictactoeGrid[0][0] = humanmark; // game board. The " && tictactoeGrid[][] == 'x' " is used to check if the
                human = 2;                       // box the player chose is unoccupied and doesn't already have a mark
            }
            else if (humanchoice == '2' && tictactoeGrid[0][1] == '2')
            {
                tictactoeGrid[0][1] = humanmark;
                human = 2; // Passes turn to computer
            }
            else if (humanchoice == '3' && tictactoeGrid[0][2] == '3')
            {
                tictactoeGrid[0][2] = humanmark;
                human = 2;
            }
            else if (humanchoice == '4' && tictactoeGrid[1][0] == '4')
            {
                tictactoeGrid[1][0] = humanmark;
                human = 2;
            }
            else if (humanchoice == '5' && tictactoeGrid[1][1] == '5')
            {
                tictactoeGrid[1][1] = humanmark;
                human = 2;
            }
            else if (humanchoice == '6' && tictactoeGrid[1][2] == '6')
            {
                tictactoeGrid[1][2] = humanmark;
                human = 2;
            }
            else if (humanchoice == '7' && tictactoeGrid[2][0] == '7')
            {
                tictactoeGrid[2][0] = humanmark;
                human = 2;
            }
            else if (humanchoice == '8' && tictactoeGrid[2][1] == '8')
            {
                tictactoeGrid[2][1] = humanmark;
                human = 2;
            }
            else if (humanchoice == '9' && tictactoeGrid[2][2] == '9')
            {
                tictactoeGrid[2][2] = humanmark;
                human = 2;
            }
            else
            {
                cout << "Invalid move, try again!" << endl; // This part is for if the player inputted a key that's not on the board
                cout << "[Press Enter to continue]" << endl;
                human = 1; // Player will go again
                cin.ignore();
                cin.get();
            }
        }
        else if (human == 2)
        { // This part of the program is for the computer's move

            // If statement to select easy mode or hard mode
            if (difficultylevel == 1) // Easy difficulty
            {
                do
                {
                    computerchoice = ((rand() % 9) + 1);                   // The computer chooses a random move
                    if (computerchoice == 1 && tictactoeGrid[0][0] != '1') // This checks if the random move has already been played
                    {                                                      // If so, the loop restarts
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 2 && tictactoeGrid[0][1] != '2')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 3 && tictactoeGrid[0][2] != '3')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 4 && tictactoeGrid[1][0] != '4')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 5 && tictactoeGrid[1][1] != '5')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 6 && tictactoeGrid[1][2] != '6')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 7 && tictactoeGrid[2][0] != '7')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 8 && tictactoeGrid[2][1] != '8')
                    {
                        computerchoice = humanchoice;
                    }
                    else if (computerchoice == 9 && tictactoeGrid[2][2] != '9')
                    {
                        computerchoice = humanchoice;
                    }
                    else
                    {
                        break;
                    }
                } while (computerchoice == humanchoice);
            }
            else // Hard difficulty
            {
                if ((tictactoeGrid[1][1] != 'X') && (tictactoeGrid[1][1] != 'O')) // Checks if the center has already been marked
                {                                                                 // If it hasn't, the computer chooses the center
                    computerchoice = 5;
                }
                else if ((tictactoeGrid[0][0] != 'X' || tictactoeGrid[2][0] != 'X' || tictactoeGrid[0][2] != 'X' || tictactoeGrid[2][2] != 'X') &&
                         (tictactoeGrid[0][0] != 'O' || tictactoeGrid[2][0] != 'O' || tictactoeGrid[0][2] != 'O' || tictactoeGrid[2][2] != 'O'))
                { // If any of the corners haven't been marked, the computer chooses a remaining corner
                    corner1Checked = false;
                    corner2Checked = false;
                    corner3Checked = false;
                    corner4Checked = false;
                    do
                    {
                        computerchoice = humanchoice; // This causes the loop to restart if the corner that was randomly selected was already taken
                        randNum = ((rand() % 4) + 1);
                        if (randNum == 4 && tictactoeGrid[0][0] == '1') // Checks if the corner spot has already been played
                        {                                               // If not, it chooses the corner spot
                            computerchoice = 1;
                            break;
                        }
                        else if (randNum == 3 && tictactoeGrid[2][0] == '7')
                        {
                            computerchoice = 7;
                            break;
                        }
                        else if (randNum == 2 && tictactoeGrid[0][2] == '3')
                        {
                            computerchoice = 3;
                            break;
                        }
                        else if (randNum == 1 && tictactoeGrid[2][2] == '9')
                        {
                            computerchoice = 9;
                            break;
                        }
                        else if (randNum == 4 && tictactoeGrid[0][0] != '1')
                        {
                            corner1Checked = true;
                        }
                        else if (randNum == 3 && tictactoeGrid[2][0] != '7')
                        {
                            corner2Checked = true;
                        }
                        else if (randNum == 2 && tictactoeGrid[0][2] != '3')
                        {
                            corner3Checked = true;
                        }
                        else if (randNum == 1 && tictactoeGrid[2][2] != '9')
                        {
                            corner4Checked = true;
                        }
                        // If none of these if statements are satisfied, the computer will mark a random spot
                        if (corner1Checked == true && corner2Checked == true && corner3Checked == true && corner4Checked == true)
                        {
                            computerchoice = ((rand() % 9) + 1);                   // The computer chooses a random move
                            if (computerchoice == 1 && tictactoeGrid[0][0] != '1') // This checks if the random move has already been played
                            {                                                      // If so, the loop restarts
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 2 && tictactoeGrid[0][1] != '2')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 3 && tictactoeGrid[0][2] != '3')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 4 && tictactoeGrid[1][0] != '4')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 5 && tictactoeGrid[1][1] != '5')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 6 && tictactoeGrid[1][2] != '6')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 7 && tictactoeGrid[2][0] != '7')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 8 && tictactoeGrid[2][1] != '8')
                            {
                                computerchoice = humanchoice;
                            }
                            else if (computerchoice == 9 && tictactoeGrid[2][2] != '9')
                            {
                                computerchoice = humanchoice;
                            }
                            else
                            {
                                break;
                            }
                        }
                    } while (computerchoice == humanchoice);
                    randNum = 0;
                }
                else // If all of the corners have been marked, the computer chooses a random move
                {
                    do
                    {
                        computerchoice = ((rand() % 9) + 1);                   // The computer chooses a random move
                        if (computerchoice == 1 && tictactoeGrid[0][0] != '1') // This checks if the random move has already been played
                        {                                                      // If so, the loop restarts
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 2 && tictactoeGrid[0][1] != '2')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 3 && tictactoeGrid[0][2] != '3')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 4 && tictactoeGrid[1][0] != '4')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 5 && tictactoeGrid[1][1] != '5')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 6 && tictactoeGrid[1][2] != '6')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 7 && tictactoeGrid[2][0] != '7')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 8 && tictactoeGrid[2][1] != '8')
                        {
                            computerchoice = humanchoice;
                        }
                        else if (computerchoice == 9 && tictactoeGrid[2][2] != '9')
                        {
                            computerchoice = humanchoice;
                        }
                        else
                        {
                            break;
                        }
                    } while (computerchoice == humanchoice);
                }

                // Checks if player or computer is about to win and overwrites computerchoice if any of the if statements are true

                // Checks diagonals
                // '7','5','3'
                // Checks for two marks next to each other
                if (((tictactoeGrid[2][0] == 'X' && tictactoeGrid[1][1] == 'X') || (tictactoeGrid[2][0] == 'O' && tictactoeGrid[1][1] == 'O')) && tictactoeGrid[0][2] == '3')
                {
                    computerchoice = 3;
                }
                else if (((tictactoeGrid[1][1] == 'X' && tictactoeGrid[0][2] == 'X') || (tictactoeGrid[1][1] == 'O' && tictactoeGrid[0][2] == 'O')) && tictactoeGrid[2][0] == '7')
                {
                    computerchoice = 7;
                }
                // Checks for two marks that are one space apart
                else if (((tictactoeGrid[2][0] == 'X' && tictactoeGrid[0][2] == 'X') || (tictactoeGrid[2][0] == 'O' && tictactoeGrid[0][2] == 'O')) && tictactoeGrid[1][1] == '5')
                {
                    computerchoice = 5;
                }
                // '1','5','9'
                // Checks for two marks next to each other
                else if (((tictactoeGrid[0][0] == 'X' && tictactoeGrid[1][1] == 'X') || (tictactoeGrid[0][0] == 'O' && tictactoeGrid[1][1] == 'O')) && tictactoeGrid[2][2] == '9')
                {
                    computerchoice = 9;
                }
                else if (((tictactoeGrid[1][1] == 'X' && tictactoeGrid[2][2] == 'X') || (tictactoeGrid[1][1] == 'O' && tictactoeGrid[2][2] == 'O')) && tictactoeGrid[0][0] == '1')
                {
                    computerchoice = 1;
                }
                // Checks for two marks that are one space apart
                else if (((tictactoeGrid[0][0] == 'X' && tictactoeGrid[2][2] == 'X') || (tictactoeGrid[0][0] == 'O' && tictactoeGrid[2][2] == 'O')) && tictactoeGrid[1][1] == '5')
                {
                    computerchoice = 5;
                }

                // Checks rows and columns
                for (int i = 0; i < 3; i++)
                {
                    // Checks rows for two marks next to each other
                    if (((tictactoeGrid[i][0] == 'X' && tictactoeGrid[i][1] == 'X') || (tictactoeGrid[i][0] == 'O' && tictactoeGrid[i][1] == 'O')) && tictactoeGrid[i][2] != 'X' && tictactoeGrid[i][2] != 'O')
                    {
                        computerchoice = 0;                 // This is set to 0 so it bypasses the if statements below
                        tictactoeGrid[i][2] = computermark; // The array is changed directly from this if statement since the array element can change (contains a variable)
                        human = 1;
                        break;
                    }
                    else if (((tictactoeGrid[i][1] == 'X' && tictactoeGrid[i][2] == 'X') || (tictactoeGrid[i][1] == 'O' && tictactoeGrid[i][2] == 'O')) && tictactoeGrid[i][0] != 'X' && tictactoeGrid[i][0] != 'O')
                    {
                        computerchoice = 0;
                        tictactoeGrid[i][0] = computermark;
                        human = 1;
                        break;
                    }
                    // Checks rows for two marks that are one space apart
                    else if (((tictactoeGrid[i][0] == 'X' && tictactoeGrid[i][2] == 'X') || (tictactoeGrid[i][0] == 'O' && tictactoeGrid[i][2] == 'O')) && tictactoeGrid[i][1] != 'X' && tictactoeGrid[i][1] != 'O')
                    {
                        computerchoice = 0;
                        tictactoeGrid[i][1] = computermark;
                        human = 1;
                        break;
                    }
                    // Checks columns for two marks next to each other
                    else if (((tictactoeGrid[0][i] == 'X' && tictactoeGrid[1][i] == 'X') || (tictactoeGrid[0][i] == 'O' && tictactoeGrid[1][i] == 'O')) && tictactoeGrid[2][i] != 'X' && tictactoeGrid[2][i] != 'O')
                    {
                        computerchoice = 0;
                        tictactoeGrid[2][i] = computermark;
                        human = 1;
                        break;
                    }
                    else if (((tictactoeGrid[1][i] == 'X' && tictactoeGrid[2][i] == 'X') || (tictactoeGrid[1][i] == 'O' && tictactoeGrid[2][i] == 'O')) && tictactoeGrid[0][i] != 'X' && tictactoeGrid[0][i] != 'O')
                    {
                        computerchoice = 0;
                        tictactoeGrid[0][i] = computermark;
                        human = 1;
                        break;
                    }
                    // Checks columns for two marks that are one space apart
                    else if (((tictactoeGrid[0][i] == 'X' && tictactoeGrid[2][i] == 'X') || (tictactoeGrid[0][i] == 'O' && tictactoeGrid[2][i] == 'O')) && tictactoeGrid[1][i] != 'X' && tictactoeGrid[1][i] != 'O')
                    {
                        computerchoice = 0;
                        tictactoeGrid[1][i] = computermark;
                        human = 1;
                        break;
                    }
                }
            }

            // This marks the chosen spot on the board
            if (computerchoice == 1 && tictactoeGrid[0][0] == '1')
            {
                tictactoeGrid[0][0] = computermark;
                human = 1; // Passes turn to player
            }
            else if (computerchoice == 2 && tictactoeGrid[0][1] == '2')
            {
                tictactoeGrid[0][1] = computermark;
                human = 1;
            }
            else if (computerchoice == 3 && tictactoeGrid[0][2] == '3')
            {
                tictactoeGrid[0][2] = computermark;
                human = 1;
            }
            else if (computerchoice == 4 && tictactoeGrid[1][0] == '4')
            {
                tictactoeGrid[1][0] = computermark;
                human = 1;
            }
            else if (computerchoice == 5 && tictactoeGrid[1][1] == '5')
            {
                tictactoeGrid[1][1] = computermark;
                human = 1;
            }
            else if (computerchoice == 6 && tictactoeGrid[1][2] == '6')
            {
                tictactoeGrid[1][2] = computermark;
                human = 1;
            }
            else if (computerchoice == 7 && tictactoeGrid[2][0] == '7')
            {
                tictactoeGrid[2][0] = computermark;
                human = 1;
            }
            else if (computerchoice == 8 && tictactoeGrid[2][1] == '8')
            {
                tictactoeGrid[2][1] = computermark;
                human = 1;
            }
            else if (computerchoice == 9 && tictactoeGrid[2][2] == '9')
            {
                tictactoeGrid[2][2] = computermark;
                human = 1;
            }
        }
    } while (checkGameOver() == 0); // This will keep repeating until there is a win or draw

    display_VSCompgrid();

    if (checkGameOver() == 1)
    {
        if (HumanOrComputerWin == 'H')
        {
            playerWins++;
            cout << PlayaName << ", you won the game!" << endl;
        }
        else
        {
            computerWins++;
            cout << "Computer won the game!" << endl;
        }
    }
    else if (checkGameOver() == 2)
    {
        cout << "Game was a tie!" << endl;
    }

    singlePlayerGameWins++;
    cout << endl;
}

// Main function
int main()
{
    cout << "     =================================" << endl;
    cout << "     +-------------------------------+" << endl;
    cout << "      WELCOME TO THE TIC-TAC-TOE GAME " << endl;
    cout << "     +-------------------------------+" << endl;
    cout << "     =================================" << endl;
    cout << endl
         << endl;

    int playerresponse;
    char keepPlaying;

    srand(time(NULL));

    do
    {
        tictactoeGrid[0][0] = '1';
        tictactoeGrid[0][1] = '2';
        tictactoeGrid[0][2] = '3';

        tictactoeGrid[1][0] = '4';
        tictactoeGrid[1][1] = '5';
        tictactoeGrid[1][2] = '6';

        tictactoeGrid[2][0] = '7';
        tictactoeGrid[2][1] = '8';
        tictactoeGrid[2][2] = '9';

        cout << "Choose Your Opponent: Computer[1] or Player[2]" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> playerresponse;
        cout << endl;

        if (playerresponse == 2)
        {
            twoplayerstictactoe();
            twoPlayerGamePlayedMoreThanOnce = true;
        }
        else
        {
            computergamemode();
            singlePlayerGamePlayedMoreThanOnce = true;
        }

        cout << "Do you wish to continue playing? [Y or N]" << endl;
        cin >> keepPlaying;
        cout << endl;

        while (keepPlaying != 'Y' && keepPlaying != 'y' && keepPlaying != 'N' && keepPlaying != 'n')
        {
            cout << "Invalid response, try again!" << endl;
            cin >> keepPlaying;
            cout << endl;
        }

    } while (keepPlaying == 'Y' || keepPlaying == 'y');

    cout << "Thanks for playing! ;)" << endl
         << endl
         << endl;

    if (player1Wins > 0 || player2Wins > 0)
    {
        cout << firstplayername << " vs. " << secondplayername << ":" << endl
             << endl;
        if (player1Wins > player2Wins)
        {
            if (twoPlayerGameWins == 1)
            { // This if statement makes the output say "game" instead of "games" if only 1 game was played
                cout << firstplayername << " won " << player1Wins << " out of " << twoPlayerGameWins << " game!" << endl;
            }
            else
            {
                cout << firstplayername << " won " << player1Wins << " out of " << twoPlayerGameWins << " games!" << endl;
            }
        }
        else if (player2Wins > player1Wins)
        {
            if (twoPlayerGameWins == 1)
            { // This if statement makes the output say "game" instead of "games" if only 1 game was played
                cout << secondplayername << " won " << player2Wins << " out of " << twoPlayerGameWins << " game!" << endl;
            }
            else
            {
                cout << secondplayername << " won " << player2Wins << " out of " << twoPlayerGameWins << " games!" << endl;
            }
        }
        else
        {
            if (twoPlayerGameWins == 1)
            { // This if statement makes the output say "game" instead of "games" if only 1 game was played
                cout << firstplayername << " and " << secondplayername << " both won " << player1Wins << " out of " << twoPlayerGameWins << " game!" << endl;
            }
            else
            {
                cout << firstplayername << " and " << secondplayername << " both won " << player1Wins << " out of " << twoPlayerGameWins << " games!" << endl;
            }
        }
        cout << endl
             << endl;
    }
    if (playerWins > 0 || computerWins > 0)
    {
        cout << PlayaName << " vs. Computer:" << endl
             << endl;
        if (playerWins > computerWins)
        {
            if (singlePlayerGameWins == 1)
            { // This if statement makes the output say "game" instead of "games" if only 1 game was played
                cout << PlayaName << " won " << playerWins << " out of " << singlePlayerGameWins << " game!" << endl;
            }
            else
            {
                cout << PlayaName << " won " << playerWins << " out of " << singlePlayerGameWins << " games!" << endl;
            }
        }
        else if (computerWins > playerWins)
        {
            if (singlePlayerGameWins == 1)
            { // This if statement makes the output say "game" instead of "games" if only 1 game was played
                cout << "Computer won " << computerWins << " out of " << singlePlayerGameWins << " game!" << endl;
            }
            else
            {
                cout << "Computer won " << computerWins << " out of " << singlePlayerGameWins << " games!" << endl;
            }
        }
        else
        {
            if (singlePlayerGameWins == 1)
            { // This if statement makes the output say "game" instead of "games" if only 1 game was played
                cout << PlayaName << " and Computer both won " << playerWins << " out of " << singlePlayerGameWins << " game!" << endl;
            }
            else
            {
                cout << PlayaName << " and Computer both won " << playerWins << " out of " << singlePlayerGameWins << " games!" << endl;
            }
        }
        cout << endl
             << endl;
    }

    return 0;
}