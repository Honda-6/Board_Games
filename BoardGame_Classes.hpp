// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    char winner = 0;
    virtual bool update_board(int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
    virtual ~Board();
};

Board::~Board()
{
    for(int i{}; i < n_rows; ++i)
        delete [] board[i];
    delete [] board;
}

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board : public Board
{
public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    ~X_O_Board() {};
};

class _5x5_TicTacToe_Board : public Board
{
private:
    int _3Xs, _3Os;
    bool check_diagonal_right(char base, short r, short c, short &counter, short i);
    bool check_diagonal_left(char base, short r, short c, short &counter, short i);
    bool check_vertical(char base, short r, short c, short &counter, short i);
    bool check_horizontal(char base, short r, short c, short &counter, short i);
public:
    _5x5_TicTacToe_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    ~_5x5_TicTacToe_Board() {};
};

class Four_in_a_row : public Board
{   
    
public:
    Four_in_a_row();
    bool update_board(int x, int y, char symbol);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    ~Four_in_a_row();
};

class PyramicTicTacToe : public Board
{
public:
    PyramicTicTacToe();
    bool update_board(int x, int y, char symbol);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    ~PyramicTicTacToe(){};
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player
{
protected:
    string name;
    char symbol;

public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player(char symbol); // Needed for computer players
    Player(int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int &x, int &y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
    ~Player() = default;
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer : public Player
{
protected:
    int dimension;

public:
    // Take a symbol and pass it to parent
    RandomPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(int &x, int &y);
    ~RandomPlayer() = default;
};

///////////////////////////////////////////
class GameManager
{
private:
    Board *boardPtr;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    void setGame(Board* game)
    {
        delete boardPtr;
        boardPtr = game;
    };
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end
    ~GameManager();
};

#endif
