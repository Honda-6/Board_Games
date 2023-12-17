#include "BoardGame_Classes.hpp"

PyramicTicTacToe::PyramicTicTacToe()
{
    n_moves = 0;
    n_rows = 3 + 4;
    n_cols = 5 + 4;
    board = new char *[n_rows] {};
    for (int i{}; i < n_rows; ++i)
    {
        board[i] = new char[n_cols];
        for (int j{}; j < n_cols; ++j)
        {
            board[i][j] = ' ';
        }
    }
}
bool PyramicTicTacToe::update_board(int x, int y, char symbol)
{
    if (x == 0)
    {
        if (y == 2 && board[x+2][y + 2] == ' ')
        {
            board[x+2][y+2] = toupper(symbol);
            return true;
        }
    }
    if (x == 1)
    {
        if (y < 4 && y > 0 && board[x+2][y+2] == ' ')
        {
            board[x+2][y+2] = toupper(symbol);
            return true;
        }
    }
    if (x == 2)
    {
        if (y < 5 && y > -1 && board[x+2][y+2] == ' ')
        {
            board[x+2][y+2] = toupper(symbol);
            return true;
        }
    }
    return false;
}
void PyramicTicTacToe::display_board()
{
    cout << "\n    " << 0;
    for (int i{1}; i < 5; ++i)
        cout << setw(4) << i;
    cout << "\n"
         << setw(16) << "-----\n";
    cout << 0 << setw(11) << "| " << board[2][4] << " |\n";
    cout << setw(20) << "-------------\n";
    cout << 1 << setw(7) << "| ";
    for (int i{3}; i < 6; ++i)
    {
        cout << board[3][i] << " | ";
    }
    cout << "\n"
         << setw(24) << "---------------------\n";
    cout << 2 << " | ";
    for (int i{2}; i < 7; ++i)
    {
        cout << board[4][i] << " | ";
    }
    cout << "\n"
         << setw(24) << "---------------------\n";
}
bool PyramicTicTacToe::is_winner()
{
    short counter{};
    for (short r{2}; r < 5; ++r)
    {
        for (short c{2}; c < 7; ++c)
        {
            if (board[r][c] == ' ')
                continue;
            for (short i = r - 2; i < r + 3; i++)
            {
                if (board[i][c] == board[r][c])
                    counter++;
            }
            if (counter == 3)
            {
                winner = toupper(board[r][c]);
                return true;
            }
            counter = 0;
            for (short i = c - 2; i < c + 3; i++)
            {
                if (board[r][i] == board[r][c])
                    counter++;
            }
            if (counter == 3)
            {
                winner = toupper(board[r][c]);
                return true;
            }
            counter = 0;
            for (short x{-2}; x < 3; x++)
            {
                if (board[r + x][c + x] == board[r][c])
                    counter++;
            }
            if (counter == 3)
            {
                winner = toupper(board[r][c]);
                return true;
            }
            counter = 0;
            for (short x{-2}; x < 3; x++)
            {
                if (board[r + x][c - x] == board[r][c])
                    counter++;
            }
            if (counter == 3)
            {
                winner = toupper(board[r][c]);
                return true;
            }
            counter = 0;
        }
    }
    return false;
}
bool PyramicTicTacToe::is_draw()
{
    return n_moves >= 9 && !winner;
}
bool PyramicTicTacToe::game_is_over()
{
    return n_moves >= 9;
}