#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "mergeSort.h"
#include "quickSort.h"
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    vector<videoGame> data; //Stores each video game information per row in a vector of VideoGame class
    ifstream file("Video_Games.csv"); //Open the file for the dataset
    if (!file.is_open()){ //Checks if file isn't existing/open
        cout << "File failed to open." << endl;
    }
    else{ //Only happens if file opens successfully
        string line;
        bool first_line = true;
        int count = 0;
        while(getline(file, line)) { //Goes through every line in the file and stores them in line
            if (first_line) { //Ignore the first line of the file
                first_line = false;
                continue;
            }

            bool in_quotes = false;
            string curr_data;
            string field;
            vector<string> row;
            stringstream stream(line);

            while (getline(stream, field, ',')) { //Gets the field of the current line up until a comma appears
                if(!in_quotes){ //Checks if the current field is not in quotes
                    if(!field.empty() && field[0] == '"'){ //Checks if the field isn't empty and has a quote in the start
                        in_quotes = true;
                        curr_data = field.substr(1); //Copies into current data the field without the quote
                    }
                    else{ //Happens if the field isn't with quote
                        if (field == "") {
                            curr_data = "N/A"; //Stores empty values as N/A
                        }
                        else{
                            curr_data = field;
                        }

                        row.push_back(curr_data); //Current data is pushed back into the row vector
                    }
                }
                else{ //Happens when the current field is in quotes
                    if(!field.empty() && field[field.size() - 1] == '"'){ //Checks if the field isn't empty and has a quote at the end
                        in_quotes = false;
                        curr_data += "," + field.substr(0, field.size() - 1); //Adds the comma to the field and stores the field without the quote
                        row.push_back(curr_data);
                        curr_data.clear(); //Clear out the string to prevent errors later on
                    }
                    else{ //If the field doesn't have a quote at the end, still add the comma to the field because it was inside the quote
                        curr_data += "," + field;
                    }
                }
            }

            curr_data = field; //Takes care of the final field in the row

            if (curr_data == "") {
                curr_data = "N/A";
                row.push_back(curr_data); //If the value of the current data is blank, store N/A
            }

            //Create a videoGame variable with the fields read in the line
            videoGame game(row[0], row[1], row[2], row[3], row[4],
                           row[5], row[6], row[7], row[8], row[9],
                           row[10], row[11], row[12], row[13],
                           row[14], row[15]);

            data.push_back(game);
            count++;
        }
        file.close();
    }

    int sort_option; //Stores the user's desired sorting category
    char cap_games; //Stores a y or Y if a user wants to cap the number of games shown
    string sort_order; //Stores if the user wants numerical values sorted from greatest to least or backwards
    while(sort_option != -1) {
        std::cout << "-----------============================o0()0o==============================-----------\n"
                     "Welcome to the Video Game Analyzer Program! We analyze a variety of unique video games\n"
                     "and compare the data across each of them in order to analyze the video game market and\n"
                     "                     order the data to the user's content!\n"
                     "-----------============================o0()0o==============================-----------\n\n";
        std::cout << "                    How would you like to sort the Video Games?\n\n"
                     "               1.Name | 2.Year of Release | 3.North American Sales\n"
                     "               4.European Sales | 5.Japanese Sales | 6.Other Sales\n"
                     "                 7.Global Sales | 8.Critic Score | 9.Critic Count\n"
                     "                      10.User Score | 11.User Count | -1. Quit\n\n"
                     "Input:";

        cin >> sort_option;

        if(cin.fail()){ //Deals with invalid input
            cout << "Invalid input entered. Please try again" << endl << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        if(sort_option == -1){ //Ends the app
            cout << "Thank you for using this application!" << endl;
            break;
        }

        if(sort_option > 11 || sort_option < 1){ //Invalid nums
            cout << "Invalid input entered. Please try again" << endl << endl;
            continue;
        }

        if (sort_option >= 1 && sort_option <= 11) { //Making sure the option chosen is valid
            vector<string> stringGames;
            vector<float> floatGames;

            for (int i = 0; i < data.size(); i++) { //For loop stores all the values to be sorted into another vector to sort them quicker
                if (sort_option == 1) {
                    stringGames.push_back(data[i].getName()); //Stores all the names in a vector
                } else {
                    string value;
                    float updated_value;

                    if (sort_option == 2) { //Stores the years in a vector as floats
                        value = data[i].getYear();

                        if (value == "N/A") {
                            value = "-1";
                        }
                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 3) { //Stores the North American sales in a vector as floats
                        value = data[i].getNAS();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 4) { //Stores the European sales in a vector as floats

                        value = data[i].getEUS();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 5) { //Stores the Japanese sales in a vector as floats
                        value = data[i].getJPS();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 6) { //Stores the other sales in a vector as floats
                        value = data[i].getOTS();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 7) { //Stores the global sales in a vector as floats
                        value = data[i].getGBS();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 8) { //Stores the critics score in a vector as floats
                        value = data[i].getCriticS();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 9) { //Stores the critics count in a vector as floats
                        value = data[i].getCriticC();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 10) { //Stores the user score in a vector as floats
                        value = data[i].getUserS();

                        if (value == "N/A" || value == "tbd") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    } else if (sort_option == 11) { //Stores the user count in a vector as floats
                        value = data[i].getUserC();

                        if (value == "N/A") {
                            value = "-1";
                        }

                        updated_value = std::stof(value);
                        floatGames.push_back(updated_value);
                    }
                }
            }

            int cap_num = data.size(); //Stores the cap number if a user wants to show a capped number of games

            vector<string> stringGames2;
            vector<float> floatGames2;

            int size;
            mergeSort merge_sorter;
            quickSort quick_sorter;

            float mergeTime;
            float quickTime;

            int counter = 1;

            vector<videoGame> data2;
            data2 = data; //Creating two versions of the vectors to sort both of them and compare the times

            if (sort_option == 1) { //The only sorting of strings
                size = stringGames.size();
                stringGames2 = stringGames;

                const clock_t clock_merge_start = clock();
                merge_sorter.mergeSorterWords(stringGames, 0, size - 1, data); //Does mergesort
                const clock_t clock_merge_end = clock();

                const clock_t clock_quick_start = clock();
                quick_sorter.quicksortWords(stringGames2, size, data2); //Does quicksort
                const clock_t clock_quick_end = clock();

                mergeTime = clock_merge_end - clock_merge_start; //Keeps track of the mergesort time
                quickTime = clock_quick_end - clock_quick_start; //Keeps track of the quicksort time
            } else { //Sorting floats
                size = floatGames.size();
                floatGames2 = floatGames;

                const clock_t clock_merge_start = clock();
                merge_sorter.mergeSorter(floatGames, 0, size - 1, data); //Does mergesort
                const clock_t clock_merge_end = clock();

                const clock_t clock_quick_start = clock();
                quick_sorter.quicksort(floatGames2, size, data2); //Does quicksort
                const clock_t clock_quick_end = clock();

                mergeTime = clock_merge_end - clock_merge_start; //Keeps track of the mergesort time
                quickTime = clock_quick_end - clock_quick_start; //Keeps track of the quicksort time
            }

            if (quickTime < mergeTime) {
                data = data2; //Display the fastest one of the two sorts
            }

            //Prompt the capping games question and take input
            cout
                    << "Would you like to cap the amount of games we display?\nType 'y' or 'Y' for yes, anything else for no."
                    << endl;
            cin >> cap_games;

            if (cap_games == 'y' or cap_games == 'Y') {
                //Prompt asking how much to cap and take input
                cout << "Enter the amount of games you would like to see sorted (as an int): " << endl;
                cin >> cap_num;
            }

            while(cin.fail()){
                cout << "Invalid input. Please try again." << endl;
                cin.clear();
                cin.ignore();
                cout << "New value:";
                cin >> cap_num;
            }

            if (sort_option == 1) {
                cout << "Here are the games sorted by their names in alphabetical order!" << endl;
                int end = stringGames.size();
                if (cap_num > 0 && cap_num <= end) {
                    end = cap_num; //Set the cap number ready for the for loop
                }

                if(cap_num == 0){ //Cap number 0 shows no games
                    cout << "No games shown." << endl;
                    continue;
                }

                for (int i = 0; i < end; i++) { //Display the games using the cap number
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                         << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                         << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                         << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                         << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                         << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            } else if (sort_option == 2) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from oldest to newest or newest to oldest?" << endl;
                cout << "Enter 'nto' for new to old, anything else for old to new: " << endl;
                cin >> sort_order;

                if (sort_order == "nto") {
                    cout << "Here are the games sorted by their year of release, newest to oldest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their year of release, oldest to newest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 3) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their North American sales, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their North American sales, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 4) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their European sales, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their European sales, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 5) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their Japanese sales, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their Japanese sales, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 6) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their other sales, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their other sales, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 7) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their global sales, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their global sales, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 8) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest score or greatest to least score?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their critics score, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their critics score, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 9) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest count or greatest to least count?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their critic count, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their critic count, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 10) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest score or greatest to least score?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their user score, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their user score, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            } else if (sort_option == 11) {
                //Prompt how to order the numerical value and take input
                cout << "Would you like to sort from least to greatest count or greatest to least count?" << endl;
                cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
                cin >> sort_order;

                if (sort_order == "gtl") {
                    cout << "Here are the games sorted by their user count, greatest to least!" << endl;
                    int end = floatGames.size() - 1;
                    int ind_sub;
                    if (cap_num > 0 && cap_num <= end) { //Sets the cap number for the for loop
                        ind_sub = cap_num;
                    } else {
                        ind_sub = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = end;
                         i > end - ind_sub; i--) { //Backwards for loop to give reverse order of stored values
                        if (floatGames[i] == -1) { //Ignores empty values
                            end = end - 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                } else {
                    cout << "Here are the games sorted by their user count, least to greatest!" << endl;
                    int end = floatGames.size() - 1;
                    int ind;
                    if (cap_num > 0 && cap_num <= end) {
                        ind = cap_num;
                    } else {
                        ind = end;
                    }

                    if(cap_num == 0){ //Cap number 0 shows no games
                        cout << "No games shown." << endl;
                        continue;
                    }

                    for (int i = 0; i < ind; i++) {
                        if (floatGames[i] == -1) { //Ignores empty values
                            ind = ind + 1;
                            continue;
                        }
                        cout << "============------------__________------------============" << endl;
                        cout << "Game " << counter << ": " << data[i].getName() << endl;
                        cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear()
                             << ", Genre: " << data[i].getGenre() << endl;
                        cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS()
                             << ", European Sales: " << data[i].getEUS() << endl;
                        cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS()
                             << ", Global Sales: " << data[i].getGBS() << endl;
                        cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC()
                             << ", User Score: " << data[i].getUserS() << endl;
                        cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper()
                             << ", Rating: " << data[i].getRating() << endl;
                        counter++;
                    }
                    cout << "============------------__________------------============" << endl;
                }
            }

            //Displays the times for mergesort and quicksort
            cout << fixed << setprecision(2) << "CPU time used doing MergeSort: "
                 << 1000.0 * (mergeTime) / CLOCKS_PER_SEC << " ms\n";
            cout << fixed << setprecision(2) << "CPU time used doing QuickSort: "
                 << 1000.0 * (quickTime) / CLOCKS_PER_SEC << " ms\n";
        }
    }
    return 0;
}