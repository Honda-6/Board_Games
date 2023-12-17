#include"Player.cpp"
#include"GameManager.cpp"
#include"RandomPlayer.cpp"
#include"PyramicTicTacToe.cpp"
#include"5x5_TicTacToe_Board.cpp"


int main()
{
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to Pyramic X - O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new PyramicTicTacToe(), players);
    x_o_game.run();
    return 0;
}