<br/>
<p align="center">
  <a href="https://github.com/AhmedA007/tictactoe">
    <img src="source\image.png"" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Tic Tac Toe Game</h3>

  <p align="center">
    This is a simple implementation of the classic Tic Tac Toe game in C++. It supports both player vs. player and player vs. computer modes, providing an entertaining and challenging gaming experience.
    <br/>
    <br/>
  </p>
</p>


## Table of Contents
- [Game Overview](#game-overview)
- [Features](#features)
- [How to Play](#how-to-play)

## Game Overview

Tic Tac Toe, also known as Noughts and Crosses, is a two-player game where the objective is to be the first to mark a horizontal, vertical, or diagonal line with your symbol (either 'X' or 'O') on a 3x3 grid.

## Features

This implementation of Tic Tac Toe comes with several features and game modes:

- **Player vs. Player Mode:** Two players can take turns to play against each other, marking their symbols 'X' and 'O' on the game board.

- **Player vs. Computer Mode:** Challenge yourself against the computer, which can be set to different difficulty levels, including a "hard mode."

- **Customizable Player Names:** In two-player mode, players can enter their names for a personalized gaming experience.

- **Hard Mode for Player vs. Computer:** The computer AI in hard mode makes strategic decisions, providing a more challenging game for experienced players.

- **Game Statistics:** Keep track of the number of rounds won by each player in both two-player and single-player modes.

## How to Play

### Player vs. Player Mode

In this mode, two players take turns to play. Here's how it works:

1. Enter the name for each player.
2. The game displays a 3x3 grid with positions labeled from 1 to 9.

    ```
     1 | 2 | 3
    ---|---|---
     4 | 5 | 6
    ---|---|---
     7 | 8 | 9
    ```

3. Players take turns entering the position number where they want to place their symbol ('X' or 'O').
4. The game ends when one player successfully creates a line of their symbols or when the grid is full, resulting in a tie.

## Player vs. Computer Mode

In this mode, you can play against the computer, which offers two difficulty levels: Easy and Hard. The game initializes with your mark as 'X' and the computer's mark as 'O'. Here's how the gameplay and the code work for this mode:

### Gameplay Instructions:

1. When you start the game, you'll be prompted to enter your name. This is a one-time requirement as long as you keep playing.

2. Next, you'll choose the difficulty level: Easy (1) or Hard (2).

3. The game board will be displayed, and you can take your turn. Enter a number corresponding to the position where you want to place your 'X'.

4. The computer will then make its move based on the chosen difficulty level, and the game continues until there's a winner or a draw.

### Game Logic (Code Explanation):

- The game code handles both player and computer moves using `human` and `computer` variables, where `human` is set to 1 for the player and 2 for the computer.

- In Easy mode, the computer makes random moves, ensuring it doesn't select an already occupied spot.

- In Hard mode, the computer employs a more strategic approach:
  - It aims for the center (position 5) if it's available.
  - If corners (positions 1, 3, 7, 9) are available, the computer selects one randomly.
  - If none of the above conditions apply, the computer makes a random move.

- The code also checks for winning or blocking moves:
  - It checks diagonals, rows, and columns for two marks next to each other or marks one space apart.

- The game continues until there's a win or a draw, as determined by the `checkGameOver()` function.

### Ending the Game:

- Once the game is over, the result is displayed. If you win, the program congratulates you. If the computer wins, it acknowledges the computer's victory. In case of a draw, it informs you that the game ended in a tie.

- The program keeps track of the number of games played and the number of games won by the player and the computer.

### Additional Features:

- The program provides options to continue playing or exit after each game.

## Running the Program:

1. Launch the program and choose the "Player vs. Computer Mode."
2. Enter your name and select the difficulty level.
3. Enjoy playing against the computer with your 'X' mark.

After playing, the program offers the option to continue playing or exit. It also provides a summary of the games played and won by you and the computer.

