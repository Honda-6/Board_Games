#include "BoardGame_Classes.hpp"

_5x5_TicTacToe_Board::_5x5_TicTacToe_Board()
    : _3Xs{}, _3Os{}
{
    n_cols = n_rows = 5 + 4;
    board = new char *[n_rows] {};
    for (int i{}; i < n_rows; ++i)
    {
        board[i] = new char[n_cols];
        for (int j{}; j < n_cols; ++j)
            board[i][j] = ' ';
    }
}

bool _5x5_TicTacToe_Board::update_board(int x, int y, char mark)
{
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x + 2][y + 2] <= 'O'))
    {
        board[x + 2][y + 2] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void _5x5_TicTacToe_Board::display_board()
{
    cout << "\n     " << 0;
    for (int i{1}; i < 5; ++i)
        cout << setw(6) << i;
    cout << "\n  -------------------------------";
    for (int i : {2, 3, 4, 5, 6})
    {
        cout << "\n"
             << i - 2;
        cout << " |";
        for (int j : {2, 3, 4, 5, 6})
        {
            cout << setw(3) << board[i][j] << "  |";
        }
        cout << "\n  -------------------------------";
    }
    cout << endl;
}

bool _5x5_TicTacToe_Board::check_horizontal(char base, short r, short c, short &counter, short i)
{
    if (i >= 3 || board[r][c] == ' ')
        return false;
    if (base == (board[r][c + i]))
    {
        counter++;
        check_horizontal(base, r, c, counter, i + 1);
        return counter >= 3;
    }
    return false;
}
bool _5x5_TicTacToe_Board::check_vertical(char base, short r, short c, short &counter, short i)
{
    if (i >= 3 || board[r][c] == ' ')
        return false;
    if (base == (board[r + i][c]))
    {
        counter++;
        check_vertical(base, r, c, counter, i + 1);
        return counter >= 3;
    }
    return false;
}
bool _5x5_TicTacToe_Board::check_diagonal_left(char base, short r, short c, short &counter, short i)
{
    if (i >= 3 || board[r][c] == ' ')
        return false;
    if (base == (board[r + i][c + i]))
    {
        counter++;
        check_diagonal_left(base, r, c, counter, i + 1);
        return counter >= 3;
    }
    return false;
}
bool _5x5_TicTacToe_Board::check_diagonal_right(char base, short r, short c, short &counter, short i)
{
    if (i >= 3 || board[r][c] == ' ')
        return false;
    if (base == (board[r + i][c - i]))
    {
        counter++;
        check_diagonal_right(base, r, c, counter, i + 1);
        return counter >= 3;
    }
    return false;
}

bool _5x5_TicTacToe_Board::is_winner()
{
    if (n_moves < 25)
        return false;
    short counter{};
    for (int i{2}; i < n_rows - 2; ++i)
    {
        for (int j{2}; j < n_cols - 2; ++j)
        {
            if (board[i][j] == 'X')
            {
                _3Xs += check_diagonal_left(board[i][j], i, j, counter, -2);
            }
            else
            {
                _3Os += check_diagonal_left(board[i][j], i, j, counter, -2);
            }
            counter = 0;
            if (board[i][j] == 'X')
            {
                _3Xs += check_diagonal_right(board[i][j], i, j, counter, -2);
            }
            else
            {
                _3Os += check_diagonal_right(board[i][j], i, j, counter, -2);
            }
            counter = 0;
            if (board[i][j] == 'X')
            {
                _3Xs += check_vertical(board[i][j], i, j, counter, -2);
            }
            else
            {
                _3Os += check_vertical(board[i][j], i, j, counter, -2);
            }
            counter = 0;
            if (board[i][j] == 'X')
            {
                _3Xs += check_horizontal(board[i][j], i, j, counter, -2);
            }
            else
            {
                _3Os += check_horizontal(board[i][j], i, j, counter, -2);
            }
            counter = 0;
        }
    }
    if (_3Xs > _3Os)
    {
        winner = 'X';
        return true;
    }
    else if (_3Os > _3Xs)
    {
        winner = 'O';
        return true;
    }
    return false;
}
bool _5x5_TicTacToe_Board::is_draw()
{
    return n_moves >= 25 && _3Xs == _3Os;
}
bool _5x5_TicTacToe_Board::game_is_over()
{
    return n_moves >= 25;
}