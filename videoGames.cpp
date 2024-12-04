#include <iostream>
#include "videoGames.h"
using namespace std;

videoGame::videoGame(){
    name = "0";
    platform = "0";
    yearOfRelease = "0";
    genre = "0";
    publisher = "0";
    na_sales = "0";
    eu_sales = "0";
    jp_sales = "0";
    other_sales = "0";
    global_sales = "0";
    criticScore = "0";
    criticCount = "0";
    userScore = "0";
    userCount = "0";
    developer = "0";
    rating = "0";
}
videoGame::videoGame(string name, string platform, string yearOfRelease, string genre, string publisher, string na_sales, string eu_sales, string jp_sales, string other_sales, string global_sales, string criticScore, string criticCount, string userScore, string userCount, string developer, string rating){
    this->name = name;
    this->platform = platform;
    this->yearOfRelease = yearOfRelease;
    this->genre = genre;
    this->publisher = publisher;
    this->na_sales = na_sales;
    this->eu_sales = eu_sales;
    this->jp_sales = jp_sales;
    this->other_sales = other_sales;
    this->global_sales = global_sales;
    this->criticScore = criticScore;
    this-> criticCount = criticCount;
    this->userScore = userScore;
    this->userCount = userCount;
    this->developer = developer;
    this->rating = rating;
}

string videoGame::getName(){
    return name;
}

string videoGame::getPlatform(){
    return platform;
}

string videoGame::getYear(){
    return yearOfRelease;
}

string videoGame::getGenre(){
    return genre;
}

string videoGame::getPublisher(){
    return publisher;
}

string videoGame::getNAS(){
    return na_sales;
}

string videoGame::getEUS(){
    return eu_sales;
}

string videoGame::getJPS(){
    return jp_sales;
}

string videoGame::getOTS(){
    return other_sales;
}

string videoGame::getGBS(){
    return global_sales;
}

string videoGame::getCriticS(){
    return criticScore;
}

string videoGame::getCriticC(){
    return criticCount;
}

string videoGame::getUserS(){
    return userScore;
}

string videoGame::getUserC(){
    return userCount;
}

string videoGame::getDeveloper(){
    return developer;
}

string videoGame::getRating(){
    return rating;
}

