// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include "BoardGame_Classes.hpp"

// Set the board
X_O_Board::X_O_Board()
{
   n_rows = n_cols = 3;
   board = new char *[n_rows];
   for (int i = 0; i < n_rows; i++)
   {
      board[i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark)
{
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0))
   {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board()
{
   cout << "    " << 0;
   for (int i{1}; i < 3; ++i)
   {
      cout << setw(4) << i;
   }
   cout << "\n"
        << setw(15) << "-------------";
   for (int i : {0, 1, 2})
   {
      cout << "\n"
           << i << " |";
      for (int j : {0, 1, 2})
      {
         // cout << "(" << i << "," << j << ")";
         cout << setw(2) << ((board[i][j]) ? board[i][j] : ' ')  << " |";
      }
      cout << "\n"
           << setw(15) << "-------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner()
{
   char row_win[3], col_win[3], diag_win[2];
   for (int i : {0, 1, 2})
   {
      row_win[i] = board[i][0] & board[i][1] & board[i][2];
      col_win[i] = board[0][i] & board[1][i] & board[2][i];
   }
   diag_win[0] = board[0][0] & board[1][1] & board[2][2];
   diag_win[1] = board[2][0] & board[1][1] & board[0][2];

   for (int i : {0, 1, 2})
   {
      if ((row_win[i] && (row_win[i] == board[i][0]) && (winner = row_win[i])) ||
          (col_win[i] && (col_win[i] == board[0][i]) && (winner = col_win[i])))
      {
         return true;
      }
   }
   if ((diag_win[0] && diag_win[0] == board[1][1] && (winner = diag_win[0])) ||
       (diag_win[1] && diag_win[1] == board[1][1] && (winner = diag_win[1])))
   {
      return true;
   }
   return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw()
{
   return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over()
{
   return n_moves >= 9;
}
