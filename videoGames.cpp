#include <iostream>
#include "videoGames.h"
using namespace std;

videoGame::videoGame(){
    //Initialize all values to 0 if no parameters are given
    name = "0";
    platform = "0";
    year_of_release = "0";
    genre = "0";
    publisher = "0";
    na_sales = "0";
    eu_sales = "0";
    jp_sales = "0";
    other_sales = "0";
    global_sales = "0";
    critic_score = "0";
    critic_count = "0";
    user_score = "0";
    user_count = "0";
    developer = "0";
    rating = "0";
}
videoGame::videoGame(string name, string platform, string year_of_release, string genre, string publisher, string na_sales, string eu_sales, string jp_sales, string other_sales, string global_sales, string critic_score, string critic_count, string user_score, string user_count, string developer, string rating){
    //If parameters are given, update attributes accordingly
    this->name = name;
    this->platform = platform;
    this->year_of_release = year_of_release;
    this->genre = genre;
    this->publisher = publisher;
    this->na_sales = na_sales;
    this->eu_sales = eu_sales;
    this->jp_sales = jp_sales;
    this->other_sales = other_sales;
    this->global_sales = global_sales;
    this->critic_score = critic_score;
    this-> critic_count = critic_count;
    this->user_score = user_score;
    this->user_count = user_count;
    this->developer = developer;
    this->rating = rating;
}

string videoGame::getName(){
    //Return the name of the game
    return name;
}

string videoGame::getPlatform(){
    //Return the platform of the game
    return platform;
}

string videoGame::getYear(){
    //Return the year of release of the game
    return year_of_release;
}

string videoGame::getGenre(){
    //Return the genre of the game
    return genre;
}

string videoGame::getPublisher(){
    //Return the publisher of the game
    return publisher;
}

string videoGame::getNAS(){
    //Return the North America sales of the game
    return na_sales;
}

string videoGame::getEUS(){
    //Return the European sales of the game
    return eu_sales;
}

string videoGame::getJPS(){
    //Return the Japanese sales of the game
    return jp_sales;
}

string videoGame::getOTS(){
    //Return the other sales of the game
    return other_sales;
}

string videoGame::getGBS(){
    //Return the global sales of the game
    return global_sales;
}

string videoGame::getCriticS(){
    //Return the critic score of the game
    return critic_score;
}

string videoGame::getCriticC(){
    //Return the critic count of the game
    return critic_count;
}

string videoGame::getUserS(){
    //Return the user score of the game
    return user_score;
}

string videoGame::getUserC(){
    //Return the user count of the game
    return user_count;
}

string videoGame::getDeveloper(){
    //Return the developer of the game
    return developer;
}

string videoGame::getRating(){
    //Return the rating of the game
    return rating;
}

