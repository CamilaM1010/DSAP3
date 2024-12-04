#include <iostream>
#include <string>
#include <algorithm>
#pragma once
using namespace std;

class videoGame {
private:
    //private attributes of the videoGame class
    string name;
    string platform;
    string year_of_release;
    string genre;
    string publisher;
    string na_sales;
    string eu_sales;
    string jp_sales;
    string other_sales;
    string global_sales;
    string critic_score;
    string critic_count;
    string user_score;
    string user_count;
    string developer;
    string rating;
public:
    //Public functions of the class, such as parameterized constructor and getter functions
    videoGame();
    videoGame(string name, string platform, string year_of_release, string genre, string publisher, string na_sales, string eu_sales, string jp_sales, string other_sales, string global_sales, string critic_score, string critic_count, string user_score, string user_count, string developer, string rating);
    string getName();
    string getPlatform();
    string getYear();
    string getGenre();
    string getPublisher();
    string getNAS();
    string getEUS();
    string getJPS();
    string getOTS();
    string getGBS();
    string getCriticS();
    string getCriticC();
    string getUserS();
    string getUserC();
    string getDeveloper();
    string getRating();

};
