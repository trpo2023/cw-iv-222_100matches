#include "libmain.hpp"




Game::Game()
{
    totalMatches = 100;
    isFirstPlayer = true;
}


void Game::start() 
{
    srand(time(0));
    while (true) 
    {
        gameMode = selectGameMode(1);
        remainingMatches = totalMatches;

        if (gameMode == 1) 
        {
            firstPlayerName = getPlayerName(1);
            secondPlayerName = getPlayerName(2);
            std::cout << "First mode: " <<  firstPlayerName << " starts\n\n";
        } else 
        {
            std::cout << "PC mode:\n\n";
        }

        while (remainingMatches > 0) 
        {
            printf("\E[H\E[2J");
            if (gameMode == 1) 
            {
                if (isFirstPlayer) 
                {
                    currentMatches = getMatchesCount(remainingMatches, firstPlayerName, gameMode);
                } else 
                {
                    currentMatches = getMatchesCount(remainingMatches, secondPlayerName, gameMode);
                }
            }
            if (gameMode == 2) 
            {
                if (isFirstPlayer) 
                {
                    currentMatches = getMatchesCount(remainingMatches, "Your", gameMode);
                } else 
                {
                    currentMatches = getRandomMatchesCount(remainingMatches, gameMode);
                }
            }

            remainingMatches -= currentMatches;
            isFirstPlayer = !isFirstPlayer;
        }
        
        if (gameMode == 1) 
        {
            if (isFirstPlayer) 
            {
                std::cout << "Winner is " << firstPlayerName << std::endl;
            } else 
            {
                std::cout << "Winner is " << secondPlayerName << std::endl;
            }
        }
        if (gameMode == 2) 
        {
            if (isFirstPlayer) 
            {
                std::cout << "Winner is You" << std::endl;
            } else 
            {
                std::cout << "Winner is PC" << std::endl;
            }
        }

        std::cout << "\n\nDo you want to play again?\n1. Yes\n2. No\n";
        std::cin >> repeat;
        std::cout << "\n";

        if (repeat == 1)
        {
            continue;
        } 
        else if (repeat == 2) 
        {
            std::cout << "That was a good game\n";
            break;
        }
    }
}


int Game::selectGameMode(int game) {
    mode = 0;
    if (game)
    {
        std::cout << "\nChoose a mode:\n";
        std::cout << "1. Let's play together\n";
        std::cout << "2. Game with a computer\n";
        std::cout << "\n";
    }

        while (true) {
            std::getline(std::cin, str);
            if (isdigit(str[0])) {
                mode = str[0] - '0';
                if ((mode == 1) || (mode == 2)) {
                    break;
                } else {
                    std::cout << "Error mode. Try again!\n";
                    continue;
                }
            } else {
                std::cout << "Error mode. Try again!\n";
                continue;
            }
        }
    
    return mode;
}

int Game::getMatchesCount(int totalMatches, const std::string playerName, int game) {
    bool isValidInput;
    int count = 1;
    if (game) {
        do {
            std::cout << playerName << " turn. Current quantity: " << totalMatches << ".\nEnter the number of matches: ";
            std::cin >> count;
            if (!count) {
                std::cout << "Error\n";
                exit(0);
            }

            isValidInput = checkInput(count, totalMatches, game);
        } while (!isValidInput);
    }
    return count;
}


int Game::getRandomMatchesCount(int totalMatches, int game) {
    int count = rand() % 10 + 1;
    if (count >= totalMatches) 
    {
        count = totalMatches - 1;
    }
    if (game) 
    {
        std::cout << "Computer Turn. I take " << count << " matches\n";
    }
    return count;
}


bool Game::checkInput(int count, int totalMatches, int game) {
    bool isValid;
    if ((count >= 1) && (count <= 10) && (count <= totalMatches)) {
        isValid = true;
    } else {
        if (game == 1) {
            std::cout << "Incorrect. Try again!\n";
        }
        isValid = false;
    }
    return isValid;
}



std::string Game::getPlayerName(int game) {
    std::string name = "default";
    if (game) {
        std::cout << "Enter a name: ";
        std::cin >> name;
        std::cout << "Hello, " << name << std::endl;
    }
    return name;
}



