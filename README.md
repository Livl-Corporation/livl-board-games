<h1 align="center"><img src="https://user-images.githubusercontent.com/62793491/209164462-fc75b654-15e8-47ac-9fa0-4bd006de8d02.png" width="224px"/><br/>
  Board Game Livl
</h1>
<p align="center">In the Livl Board Game, you will be able to play Othello, Checkers, Tic Tac Toe and Power 4 !</p>

# 📃 Table of content

- [🧑‍💻 Installation](#-compiling-the-code-with-cmake)  
    - [🛠 Compiling the code with CMake](#-compiling-the-code-with-cmake)
    - [🛠 Installation Locally](#-installation-locally)
- [🎮 How to Play](#-how-to-play)
    - [❌ Tic Tac Toe](#-tic-tac-toe)
    - [⭕ Power4](#-power4)
    - [⚪ Othello](#-othello)
    - [♟ Checkers](#-checkers)

# 🧑‍💻 Installation

> As you may be aware, in order to compile and run C++ programs, you will need to have a compiler installed on your system. Some popular compilers for C++ include g++ and gcc.

- On Windows:
  - Installing the MinGW compiler, which includes gcc and g++.
  - Installing the Visual C++ Build Tools, which includes cl.exe, the Microsoft C++ compiler.
  
- On Linux:
    - Installing the gcc and g++ packages using your distribution's package manager (e.g., apt-get, yum, etc.).

- On macOS:
  - Installing the gcc and g++ packages using Homebrew.
  - Installing the Xcode command line tools, which includes clang, the LLVM C++ compiler.

## 🛠‍ Compiling the code with CMake
1. Make sure you have CMake installed on your system. If you do not have CMake, you can download it from the CMake website.
2. Open a terminal and navigate to the directory where you have the CMakeLists.txt file.
3. Run the following command to create a build directory:
    ```bash
    $ mkdir build
    ```
4. Navigate to the build directory:
    ```bash
    $ cd build
    ```
5. Run CMake to generate the build files:
    ```bash
    $ cmake ..
    ```
6. Run make to build the code:
    ```bash
    $ make
    ```

## 🛠 Installation Locally

- To install our project locally, `fork` our repository, and in an empty directory,
  type the following command to `clone` your fork :

```console
$> git clone git@gitlab.com:cours-franck-g/cplusplus.git
```

# 🎮 How to Play

- Run the othello executable from the build directory:

```bash
$ ./boardgame
```

## ❌ Tic Tac Toe

1. The game will prompt you to choose which player goes first (X or O). Choose your desired player by entering X or O.
2. The game will then display the current state of the board, with empty squares represented by _, and player moves represented by X or O.
3. To make a move, enter the row and column where you want to place your symbol. For example, to place an X in the top left corner, you would enter 0 0.
4. The game will then update the board and switch to the other player's turn.
5. The game continues until one player gets three of their symbols in a row (horizontally, vertically, or diagonally), or the board is full and the game is a draw.

## ⭕ Power4

1. The game will prompt you to choose which player goes first (X or O). Choose your desired player by entering X or O.
2. The game will then display the current state of the board, with empty squares represented by _, and player moves represented by X or O.
3. To make a move, enter the column where you want to place your symbol. The symbol will be placed in the lowest empty square in the chosen column.
4. The game will then update the board and switch to the other player's turn.
5. The game continues until one player gets four of their symbols in a row (horizontally, vertically, or diagonally), or the board is full and the game is a draw.

## ⚪ Othello

1. The game will prompt you to choose which player goes first (X or O). Choose your desired player by entering X or O.
2. The game will then display the current state of the board, with empty squares represented by _, player X's moves represented by X, and player O's moves represented by O.
3. To make a move, enter the row and column where you want to place your symbol. For example, to place an X in the top left corner, you would enter 0 0.
4. The game will then update the board and switch to the other player's turn.
5. The game continues until one player gets the majority of the board filled with their symbols, or the board is full and no more moves can be made.
6. The player with the most symbols on the board at the end of the game wins.

> Note: In Othello, players can also capture their opponent's pieces by sandwiching them between their own pieces. When this occurs, the opponent's pieces are flipped to the current player's color.

## ♟ Checkers

1. Once the program is running, you should see a graphical interface for the game of Checkers.
2. The game is played on a 8x8 board, with each player starting with 12 pieces of their own color (typically red and white).
3. The objective of the game is to capture all of the opponent's pieces, or to block them so that they cannot make any more moves.
4. Pieces can only move diagonally forward, and can only capture other pieces by jumping over them. A player can capture multiple pieces in a single turn by jumping over them in sequence.
5. The player with the red pieces moves first, and players take turns making moves until the game is over.
6. To make a move, select a piece by clicking on it, then click on the desired destination square. The game will automatically handle capturing pieces and displaying the updated board.
7. The game ends when one player has captured all of the opponent's pieces, or when the board is blocked and no more moves can be made.
