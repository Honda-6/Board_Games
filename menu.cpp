#include"Player.cpp"
#include"GameManager.cpp"
#include"RandomPlayer.cpp"
#include "X_O_Board.cpp"
#include "Four_in_a_row_Board.cpp"
#include "5x5_TicTacToe_Board.cpp"
#include <bits/stdc++.h>
using namespace std;

int choices()
{
    cout<<"Please choose a choice from the above:\n";
    cout<<"1- Play X-O Game\n";
    cout<<"2- Play Pyramic Tic-Tac-Toe Game\n";
    cout<<"3- Play Four in-a-row Game\n";
    cout<<"4- 5x5 Tic-Tac-Toe Game\n";
    cout<<"5- Exit\n";  
    int c;
    cin>>c;
    return c;
}

void menu()
{
    int choice = -1;
    while (true){
        choice = choices();
        if (choice == 5)
            break;

        int n;
        Player* players[2];
        players[0] = new Player (1, 'x');
        cout << "Press 1 if you want to play with computer: ";
        cin >> n;
        if (n != 1)
            players[1] = new Player (2, 'o');
        else
            players[1] = new RandomPlayer ('o', 3);

        /* switch (choice)
        {
            case 1:
                cout << "Welcome to X-O Game. :)\n";
                GameManager x_o_game (new X_O_Board(), players);
                x_o_game.run();
                break;
            
            case 2:
                break;

            case 3:
                cout << "Welcome to Four in-a-row Game. :)\n";
                GameManager x_o_game (new Four_in_a_row(), players);
                x_o_game.run(); 
                break; 
                
            case 4:
                cout << "Welcome to 5x5 Tic-Tac-Toe Game. :)\n";
                GameManager x_o_game (new _5x5_TicTacToe_Board(), players);
                x_o_game.run(); 
                break;

            default:
                cout<<"Invalid choice\n";
                choice = choices();
                break;
        } */

        if (choice == 1)
        {
            cout << "Welcome to X-O Game. :)\n";
            GameManager x_o_game (new X_O_Board(), players);
            x_o_game.run();
        }
        else if (choice == 2)
        {
            continue;
        }
        else if (choice == 3)
        {
            cout << "Welcome to Four in-a-row Game. :)\n";
            GameManager x_o_game (new Four_in_a_row(), players);
            x_o_game.run();
        }
        else if (choice == 4)
        {
            cout << "Welcome to 5x5 Tic-Tac-Toe Game. :)\n";
            GameManager x_o_game (new _5x5_TicTacToe_Board(), players);
            x_o_game.run();
        }
        else
        {
            cout<<"Invalid choice\n";
            choice = choices();
        }
    }
}