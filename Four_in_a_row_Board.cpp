// File name: Four_in_a_row_Board
// Purpose: four in a row game for two players
// Author(s): Nada Gamal
// ID(s): 20220359
// Section: s3
// Date: 17-12-2023
// Version: 1

#include "BoardGame_Classes.hpp"
#include <bits/stdc++.h>
using namespace std;

Four_in_a_row::Four_in_a_row()
{
    n_cols = 7;
    n_rows = 6;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
   }
}

bool Four_in_a_row::update_board(int x, int y, char mark)
{
    if (x-1 < 0 || x-1 > 6)
        return false;
    for (int i = 5; i >= 0; i--)
    {
        if (board[i][x-1] == 0)
        {
            board[i][x-1] = toupper(mark);
            n_moves++;
            return true;
        }
    }
    return false;    
}

void Four_in_a_row::display_board()
{
    cout<<"| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    for (int i = 0; i < 6; i++)
    {
        cout<<"| ";
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j])
                cout<<board[i][j]<<" | ";
            else
                cout<<"  | ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

bool Four_in_a_row::is_winner()
{ 
    if (n_moves < 7)
        return false;
    int x_counter{}, o_counter{}; 
    // checks horizontally
    for (int i = 0; i < 6; i++)
    {
        x_counter = o_counter = 0;
        for (int j = 0; j < 7; j++)
        {
            if (!board[i][j])
            {
                x_counter = o_counter = 0;
            }
            else if (board[i][j] == 'X')
            {
                o_counter = 0, x_counter++;
            }
            else if (board[i][j] == 'O')
            {
                o_counter++, x_counter = 0;
            }
            if (x_counter == 4 || o_counter == 4)
            {
                if (o_counter)
                    winner = 'o';
                else
                    winner = 'x';
                return true;
            }
        }
    }
    //checks vertically
    x_counter = o_counter = 0;
    for (int i = 0; i < 7; i++)
    {
        x_counter = o_counter = 0;
        for (int j = 0; j < 6; j++)
        {
            if (!board[j][i])
            {
                x_counter = o_counter = 0;
            }
            else if (board[j][i] == 'X')
            {
                o_counter = 0, x_counter++;
            }
            else if (board[j][i] == 'O')
            {
                o_counter++, x_counter = 0;
            }
            if (x_counter == 4 || o_counter == 4)
            {   
                //winner = tolower(board[i][j]);
                winner = board[j][i];
                return true;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] && board[i][j] == board[i+1][j+1]
                && board[i][j] == board[i+2][j+2]
                && board[i][j] == board[i+3][j+3])
            {
                winner = tolower(board[i][j]);
                return true;
            }
        }
    }
     
    for (int i = 0; i < 3; i++)
    {
        for (int j = 6; j >= 3; j--)
        {
            if (board[i][j] && board[i][j] == board[i+1][j-1]
                && board[i][j] == board[i+2][j-2]
                && board[i][j] == board[i+3][j-3])
            {
                winner = tolower(board[i][j]);
                return true;
            }
        }
        
    }
    return false;
}

bool Four_in_a_row::is_draw()
{
    if (n_moves == 42 && !is_winner())
        return true;
    return false;
}

bool Four_in_a_row::game_is_over()
{
    return n_moves >= 42;
}

Four_in_a_row::~Four_in_a_row()
{

}
