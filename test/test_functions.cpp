#include <ctest.h>
#include <libmain/libmain.hpp>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>




CTEST(game_suite, getRandomMatchesCount1) {
    //Перенаправляем stdout
    FILE *f = freopen("test_stdout.txt", "w", stdout);
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int totalMatches = 20;
    int game = 1;
    Game obj;
    int count = obj.getRandomMatchesCount(totalMatches, game);
    ASSERT_TRUE(count <= 10 && count > 0);
    fflush(stdout);
    //Восстанавливаем stdout
    fclose(f);
    stdout = fopen("/dev/tty", "w"); // Linux
}

// CTEST(game_suite, getRandomMatchesCount2) {
//     // Перенаправляем stdout
//     //freopen("test_stdout.txt", "w", stdout);
//     int totalMatches = 20;
//     int game = 0;
//     Game obj;
//     int count = obj.getRandomMatchesCount(totalMatches, game);
//     ASSERT_TRUE(count <= totalMatches && count > 0);
//     //fclose(stdout);
//     //stdout = fopen("/dev/tty", "w"); // Linux
// }


// CTEST(game_suite, getMatchesCount1) {
//     freopen("test_stdout.txt", "w", stdout);
//     int totalMatches = 1;
//     std::string playerName = "Player One";

//     // Тест ввода корректного значения пользователя
//     std::stringstream input("1");
//     std::cin.rdbuf(input.rdbuf());
//     Game obj;
//     int count = obj.getMatchesCount(totalMatches, playerName, 1);
//     ASSERT_EQUAL(1, count);
//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 


// CTEST(game_suite, getMatchesCount2) {
//     freopen("test_stdout.txt", "w", stdout);
//     int totalMatches = 1;
//     std::string playerName = "Player One";

//     // Тест ввода корректного значения пользователя
//     std::stringstream input("1");
//     std::cin.rdbuf(input.rdbuf());

//     Game obj;
//     int count = obj.getMatchesCount(totalMatches, playerName, 1);
//     ASSERT_NOT_EQUAL(count, 2);
//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 

// CTEST(game_suite, selectGameMode1) {
//     freopen("test_stdout.txt", "w", stdout);
//     std::stringstream input("1");
//     std::cin.rdbuf(input.rdbuf());
//     Game obj;
//     int mode = obj.selectGameMode();   
//     ASSERT_EQUAL(1, mode);
//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 


// CTEST(game_suite, selectGameMode2) {
//     freopen("test_stdout.txt", "w", stdout);
//     std::stringstream input("2");
//     std::cin.rdbuf(input.rdbuf());
//     Game obj;
//     int mode = obj.selectGameMode();   
//     ASSERT_NOT_EQUAL(3, mode);
//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 



// CTEST(game_suite, checkInput1) {
//     freopen("test_stdout.txt", "w", stdout);

//     Game obj;
//     int count = 5, totalMatches = 10;
//     bool check_input = obj.checkInput(count, totalMatches, 1);   
//     ASSERT_EQUAL(1, check_input);


//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 

// CTEST(game_suite, checkInput2) {
//     freopen("test_stdout.txt", "w", stdout);

//     Game obj;
//     int count = 11, totalMatches = 10;
//     bool check_input = obj.checkInput(count, totalMatches, 1);   
//     ASSERT_NOT_EQUAL(1, check_input);


//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 


// CTEST(game_suite, getPlayerName1) {
//     freopen("test_stdout.txt", "w", stdout);
//     std::stringstream input("Harry");
//     std::cin.rdbuf(input.rdbuf());
//     Game obj;
//     std::string name = obj.getPlayerName(1);   
//     std::string res = "Harry";

//     bool flag = name == res;
//     ASSERT_EQUAL(1, flag);
//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 


// CTEST(game_suite, getPlayerName2) {
//     freopen("test_stdout.txt", "w", stdout);
//     std::stringstream input("Dimon");
//     std::cin.rdbuf(input.rdbuf());
//     Game obj;
//     std::string name = obj.getPlayerName(1);   
//     std::string res = "Harry";

//     bool flag = name == res;
//     ASSERT_NOT_EQUAL(1, flag);
//     fclose(stdout);
//     stdout = fopen("/dev/tty", "w"); // Linux
// } 
