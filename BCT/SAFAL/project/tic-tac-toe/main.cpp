#include <iostream>
#include <cctype>
using namespace std;

void capitalize(string& str)
{
    str[0] = toupper(str[0]);
    for(int i = 1; i< str.length(); i++)
    {
        if(str[i-1] == ' '){
            str[i] = toupper(str[i]);
        }
    }
}

class Board
{
public:
    int count = 0;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    void print_board()
    {
        cout << endl;
        cout << "\t" << board[0] << "|" << board[1] << "|" << board[2] << endl;
        cout << "\t" << "------" << endl;
        cout << "\t" << board[3] << "|" << board[4] << "|" << board[5] << endl;
        cout << "\t" << "------" << endl;
        cout << "\t" << board[6] << "|" << board[7] << "|" << board[8] << endl;
    }
    bool update_board(int position, char type)
    {
        if (board[position - 1] == ' ')
        {
            board[position - 1] = type;
            count++;
            return true;
        }
        else
        {
            cout << "Position already taken.." << endl;
            return false;
        }
    }
    bool check_draw()
    {
        return (count == 9);
    }

    bool check_winner(char type)
    {
        return (
            // Rows
            (board[0] == type && board[1] == type && board[2] == type) ||
            (board[3] == type && board[4] == type && board[5] == type) ||
            (board[6] == type && board[7] == type && board[8] == type) ||

            // Columns
            (board[0] == type && board[3] == type && board[6] == type) ||
            (board[1] == type && board[4] == type && board[7] == type) ||
            (board[2] == type && board[5] == type && board[8] == type) ||

            // Diagonals
            (board[0] == type && board[4] == type && board[8] == type) ||
            (board[2] == type && board[4] == type && board[6] == type));
    }
};

class Player
{
public:
    string name;
    char type;

    void set_details(char type)
    {
        string name;
        if ('x' == tolower(type))
        {
            cout << "Enter the name of Player 'X' : ";
            getline(cin, name);
            capitalize(name);
            this->name = name;
            this->type = 'X';
        }
        else
        {
            cout << "Enter the name of Player 'O' : ";
            getline(cin, name);
            capitalize(name);
            this->name = name;
            this->type = 'O';
        }
    }
};

class Game
{
public:
    Player player1;
    Player player2;
    Board board;
    Player *curr_player;
    Game()
    {
        player1.set_details('X');
        player2.set_details('O');
        curr_player = &player1;
    }
    void play()
    {
        int position;
        cout << "Need to enter position as [1 - 9]." << endl;
        while (true)
        {
            cout << endl;
            cout << curr_player->name << "'s turn: ";
            cin >> position;
            if (!(1 <= position && 9 >= position))
            {
                cout << "Invalid Position" << endl;
                continue;
            }
            bool update = board.update_board(position, curr_player->type);
            if (update)
            {
                board.print_board();
                if (board.check_draw())
                {
                    cout << "\nIt's a draw..." << endl;
                    break;
                }
                if (board.check_winner(curr_player->type))
                {
                    cout << "\nCongratulations " << curr_player->name << " for winning...." << endl;
                    break;
                }

                if (curr_player == &player1)
                    curr_player = &player2;

                else
                    curr_player = &player1;
            }
        }
    }
};
int main()
{
    Game game;
    game.play();
    return 0;
}