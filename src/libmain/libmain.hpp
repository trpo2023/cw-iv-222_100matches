#ifndef LIBMAIN_H
#define LIBMAIN_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>


class Game {
public:
    int remainingMatches, currentMatches, repeat, gameMode, totalMatches, mode = 0, game;
    bool isFirstPlayer;
    std::string str, firstPlayerName, secondPlayerName;

    int selectGameMode(); // протестировано
    int getMatchesCount(int totalMatches, std::string playerName, int game); // протестировано
    int getRandomMatchesCount(int totalMatches, int game); // протестировано
    bool checkInput(int count, int totalMatches, int game); // протестировано
    std::string getPlayerName(int game);// протестировано

public:
    Game();
    void start();
};


#endif