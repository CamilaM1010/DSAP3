//
// Created by ojtra on 11/30/2024.
//

#include <iostream>
using namespace std;

class videoGame {
private:
    string name;
    string platform;
    string yearOfRelease;
    string genre;
    string publisher;
    string na_sales;
    string eu_sales;
    string jp_sales;
    string other_sales;
    string global_sales;
    string criticScore;
    string criticCount;
    string userScore;
    string userCount;
    string developer;
    string rating;
public:
    videoGame(string name, string platform, string yearOfRelease, string genre, string publisher, string na_sales, string eu_sales, string jp_sales, string other_sales, string global_sales, string criticScore, string criticCount, string userScore, string userCount, string developer, string rating);
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
