#include <iostream>
#include <ctime>
#include <cctype>
using namespace std;

void toLower(string *str)
{
    for (char &ch : *str)
    {
        ch = tolower(ch);
    }
}

class Game
{
private:
    string user_choice;
    string computer_choice;

public:
    int score;
    bool result;

    Game() : score(0), result(true){}

    void get_computer_choice()
    {
        int random_num = rand() % 3;
        switch (random_num)
        {
        case 0:
            this->computer_choice = "rock";
            break;
        case 1:
            this->computer_choice = "paper";
            break;
        case 2:
            this->computer_choice = "scissors";
            break;
        default:
            break;
        }

    }
    void get_user_choice()
    {
        string user_input;
        cout << "\nEnter your choice [rock, paper, scissors, exit]:" << endl;
        cin >> user_input;
        toLower(&user_input);

        if (user_input == "rock" || user_input == "r")
            this->user_choice = "rock";
        else if (user_input == "paper" || user_input == "p")
            this->user_choice = "paper";
        else if (user_input == "scissors" || user_input == "s")
            this->user_choice = "scissors";
        else if (user_input == "exit" || user_input == "e")
        {
            cout << "You scored: " << this->score << endl;
            cout<< "Exiting......" << endl;
            result = false;
        }
        else
        {
            cout << "Invalid input! Try again." << endl;
            get_user_choice();
        }
    }

    void check_result()
    {
        cout << "User's choice: "<< this->user_choice << endl ;
        cout << "Computer's choice: " << this->computer_choice << endl ;

        if (this->user_choice == this->computer_choice){
            cout << "Its a draw"<<endl;
            return ;
        }

        else if((this->user_choice == "rock" && this->computer_choice == "scissors") || (this->user_choice == "paper" && this->computer_choice == "rock") || (this->user_choice == "scissors" && this->computer_choice == "paper"))
        {
            cout << "User wins !"<<endl;
            score ++;
        }
        else{
            cout << "Computer wins !" << endl;
        }
    }
};
int main()
{
    srand(time(NULL));
    Game game;
    while(true)
    {
        game.get_user_choice();
        if(!game.result)break;
        game.get_computer_choice();
        game.check_result();
    }
    return 0;
}