#include <ctest.h>
#include <libmain/libmain.hpp>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>




CTEST(game_suite, getRandomMatchesCount1) {
    int totalMatches = 20;
    int game = 0;
    Game obj;
    int count = obj.getRandomMatchesCount(totalMatches, game);
    ASSERT_TRUE(count <= 10 && count > 0);
}

CTEST(game_suite, getRandomMatchesCount2) {
    int totalMatches = 20;
    int game = 0;
    Game obj;
    int count = obj.getRandomMatchesCount(totalMatches, game);
    ASSERT_TRUE(count <= totalMatches && count > 0);
}


CTEST(game_suite, getMatchesCount1) {
    int totalMatches = 1;
    std::string playerName = "Player One";
    // Тест ввода корректного значения пользователя
    std::stringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    Game obj;
    int count = obj.getMatchesCount(totalMatches, playerName, 0);
    ASSERT_EQUAL(1, count);

} 


CTEST(game_suite, getMatchesCount2) {
    int totalMatches = 1;
    std::string playerName = "Player One";

    // Тест ввода корректного значения пользователя
    std::stringstream input("1");
    std::cin.rdbuf(input.rdbuf());

    Game obj;
    int count = obj.getMatchesCount(totalMatches, playerName,0);
    ASSERT_NOT_EQUAL(count, 2);

} 

CTEST(game_suite, selectGameMode1) {

    std::stringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    Game obj;
    int mode = obj.selectGameMode(0);   
    ASSERT_EQUAL(1, mode);

} 


CTEST(game_suite, selectGameMode2) {

    std::stringstream input("2");
    std::cin.rdbuf(input.rdbuf());
    Game obj;
    int mode = obj.selectGameMode(0);   
    ASSERT_NOT_EQUAL(3, mode);

} 



CTEST(game_suite, checkInput1) {


    Game obj;
    int count = 5, totalMatches = 10;
    bool check_input = obj.checkInput(count, totalMatches, 0);   
    ASSERT_EQUAL(1, check_input);

} 

CTEST(game_suite, checkInput2) {

    Game obj;
    int count = 11, totalMatches = 10;
    bool check_input = obj.checkInput(count, totalMatches, 0);   
    ASSERT_NOT_EQUAL(1, check_input);

} 



CTEST(game_suite, getPlayerName1) {

    Game obj;
    std::string name = obj.getPlayerName(0);   
    std::string res = "Harry";

    bool flag = name == res;
    ASSERT_NOT_EQUAL(1, flag);

} 
