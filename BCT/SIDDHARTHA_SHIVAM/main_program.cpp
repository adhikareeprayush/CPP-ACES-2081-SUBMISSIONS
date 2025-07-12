// This is the main program.
#include "HEADER/predictor.hpp"
#include <conio.h>
#include <windows.h>
#include <signal.h>

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";
const std::string YELLOW = "\033[33m";
const std::string MAGENTA = "\033[35m";
const std::string RED = "\033[31m";

void enableANSIColors()
{
    // simole way to enable colors in Windows console
    system("color");
}
void handleCtrlC(int signal)
{
    system("cls");
    std::cout << CYAN << BOLD << "\n.........................................\n";
    std::cout << "--> THANKS FOR USING THE PROGRAM <--\n";
    std::cout << ".........................................\n"
              << RESET;
    exit(0);
}

void showHelp()
{
    std::cout << YELLOW << BOLD << "\n--> CONTROLS <--\n";
    std::cout << " . " << GREEN << "SPACE" << YELLOW << " - Start a new word\n";
    std::cout << " . " << GREEN << "BACKSPACE" << YELLOW << " - Delete last character\n";
    std::cout << " . " << GREEN << "." << YELLOW << "     - Exit program\n\n"
              << RESET;
}

int main()
{
    enableANSIColors();
    signal(SIGINT, handleCtrlC);

    system("title Word Suggestion Program");
    system("cls");

    std::cout << CYAN << BOLD << "\n.........................................\n";
    std::cout << "--> WORD SUGGESTION PROGRAM <--\n";
    std::cout << ".........................................\n"
              << RESET;

    showHelp();
    std::cout << "Start typing to see suggestions...\n\n";

    std::string line;
    std::string word;
    std::string lastSuggestion = "";
    bool needRefresh = true;

    while (true)
    {
        char ch = _getch();

        // exit back from program
        if (ch == '.')
            break;

        // for backspace
        if (ch == 8 || ch == 127)
        {
            if (!word.empty())
                word.pop_back();

            if (!line.empty())
                line.pop_back();

            needRefresh = true;
        }
        // start a New word with sPace
        else if (ch == ' ')
        {
            line.push_back(ch);
            word.clear();
            needRefresh = true;
        }
        else if (ch != ' ' && ch != 8)
        {
            word.push_back(ch);
            line.push_back(ch);
            needRefresh = true;
        }

        // Only refresh screen when needed
        if (needRefresh)
        {
            system("cls");
            std::cout << CYAN << BOLD << "\n.........................................\n";
            std::cout << "--> WORD SUGGESTION PROGRAM <--\n";
            std::cout << ".........................................\n"
                      << RESET;

            showHelp();

            std::string suggestion = dict.get_closest_word(word);
            lastSuggestion = suggestion;

            std::cout << BLUE << "Typed: " << RESET << BOLD << word << RESET;
            std::cout << MAGENTA << "\nSuggestion: " << RESET << GREEN << BOLD << suggestion << RESET;
            std::cout << RED << "\n\nFull text: " << RESET << BOLD << line << RESET << "\n";

            needRefresh = false;
        }
    }

    system("cls");
    std::cout << CYAN << BOLD << "\n.........................................\n";
    std::cout << "--> THANKS FOR USING THE PROGRAM <--\n";
    std::cout << ".........................................\n"
              << RESET;

    return 0;
}