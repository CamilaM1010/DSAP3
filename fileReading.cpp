#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "mergeSort.h"
#include "quickSort.h"
#include <chrono>
#include <vector>
#include <iomanip>
#include <memory>

using namespace std;

int main(){
    vector<videoGame> data; //stores each data as a vector, subject to change
    ifstream file("Video_Games.csv");
    if (!file.is_open()){ //Checks if file isn't existing/open
        cout << "File failed to open." << endl;
    }
    else{
        string line; //stores the current line in the file
        bool first_line = true;
        int count = 0;
        while(getline(file, line)) { //collects the values in every line
            if (first_line) {
                first_line = false;
                continue;
            }

            bool in_quotes = false;
            string curr_data;
            string field;
            vector<string> row;
            stringstream stream(line);

            //Read the data separated by commas. Empty values seem to be read as ''
            while (getline(stream, field, ',')) {
                if(!in_quotes){
                    if(!field.empty() && field[0] == '"'){
                        in_quotes = true;
                        curr_data = field.substr(1);
                    }
                    else{
                        if (field == "") {
                            curr_data = "N/A";
                        }
                        else{
                            curr_data = field;
                        }

                        row.push_back(curr_data);
                    }
                }
                else{
                    if(!field.empty() && field[field.size() - 1] == '"'){
                        in_quotes = false;
                        curr_data += "," + field.substr(0, field.size() - 1);
                        row.push_back(curr_data);
                        curr_data.clear();
                    }
                    else{
                        curr_data += "," + field;
                    }
                }
            }
            curr_data = field;

            if (curr_data == "") {
                curr_data = "N/A";
                row.push_back(curr_data);
            }
            videoGame game(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14], row[15]);
            data.push_back(game);
            count++;
        }
        file.close();
    }

//    for(int i = 0; i < data.size(); i++){
//        cout << data[i].getName() << ";" << data[i].getPlatform() << ";" << data[i].getYear() << ";" << data[i].getGenre() << ";" << data[i].getPublisher() << ";" << data[i].getNAS() << ";" << data[i].getEUS() << ";" << data[i].getJPS() << ";" << data[i].getOTS() << ";" << data[i].getGBS() << ";" << data[i].getCriticS() << ";" << data[i].getCriticC() << ";" << data[i].getUserS() << ";" << data[i].getUserC() << ";" << data[i].getDeveloper() << ";" << data[i].getRating() << endl;
//    }

    int sort_option;
    char cap_games;
    string cap_num = "-1";
    string sort_order;
    std::cout << "-----------============================o0()0o==============================-----------\n"
                 "Welcome to the Video Game Analyzer Program! We analyze a variety of unique video games\n"
                 "and compare the data across each of them in order to analyze the video game market and\n"
                 "                     order the data to the user's content!\n"
                 "-----------============================o0()0o==============================-----------\n\n";
    std::cout << "                    How would you like to sort the Video Games?\n\n"
                 "               1.Name | 2.Year of Release | 3.North American Sales\n"
                 "               4.European Sales | 5.Japanese Sales | 6.Other Sales\n"
                 "                 7.Global Sales | 8.Critic Score | 9.Critic Count\n"
                 "                           10.User Score | 11.User Count\n\n"
                 "Input:";
    cin >> sort_option;

    if (sort_option >= 1 && sort_option <= 11){
        vector<string> games;
        for (int i = 0; i < data.size(); i++){
            if (sort_option == 1){
                games.push_back(data[i].getName());
            }
            else if(sort_option == 2){
                games.push_back(data[i].getYear());
            }
            else if(sort_option == 3){
                games.push_back(data[i].getNAS());
            }
            else if(sort_option == 4){
                games.push_back(data[i].getEUS());
            }
            else if(sort_option == 5){
                games.push_back(data[i].getJPS());
            }
            else if(sort_option == 6){
                games.push_back(data[i].getOTS());
            }
            else if(sort_option == 7){
                games.push_back(data[i].getGBS());
            }
            else if(sort_option == 8){
                games.push_back(data[i].getCriticS());
            }
            else if(sort_option == 9){
                games.push_back(data[i].getCriticC());
            }
            else if(sort_option == 10){
                games.push_back(data[i].getUserS());
            }
            else if(sort_option == 11){
                games.push_back(data[i].getUserC());
            }
        }

        int size = games.size();
        vector<string> games2 = games;

        mergeSort merge_sorter;
        quickSort quick_sorter;
        int counter = 1;

        vector<videoGame> data2;
        data2 = data;

        const clock_t clock_merge_start = clock();
        merge_sorter.mergeSorterWords(games, 0, size - 1, data);
        const clock_t clock_merge_end = clock();
        cout << "Merge sorted" << endl;

        const clock_t clock_quick_start = clock();
        quick_sorter.quicksortWords(games2, games2.size(), data2);
        const clock_t clock_quick_end = clock();
        cout << "Quick sorted" << endl;

        float mergeTime = clock_merge_end - clock_merge_start;
        float quickTime = clock_quick_end - clock_quick_start;

        cout << "Would you like to cap the amount of games we display?\nType 'y' or 'Y' for yes, anything else for no." << endl;
        cin >> cap_games;

        if(cap_games == 'y' or cap_games == 'Y'){
            cout << "Enter the amount of games you would like to see sorted (as an int): " << endl;
            cin >> cap_num;
        }

        if(sort_option == 1){
            cout << "Here are the games sorted by their names in alphabetical order!" << endl;
            int end = games.size();
            if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                end = stoi(cap_num);
            }

            for (int i = 0; i < end; i++){
                cout << "============------------__________------------============" << endl;
                cout << "Game " << counter << ": " << data[i].getName() << endl;
                cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                counter++;
            }
            cout << "============------------__________------------============" << endl;
        }
        else if(sort_option == 2){ //TODO IMPLEMENT
            cout << "Would you like to sort from oldest to newest or newest to oldest?" << endl;
            cout << "Enter 'nto' for new to old, anything else for old to new: " << endl;
            cin >> sort_order;

            if(sort_order == "nto"){
                cout << "Here are the games sorted by their year of release, newest to oldest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their year of release, oldest to newest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 3){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their North American sales, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their North American sales, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 4){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their European sales, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their European sales, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 5){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their Japanese sales, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their Japanese sales, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 6){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their other sales, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their other sales, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 7){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest sales or greatest to least sales?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their global sales, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their global sales, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 8){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest score or greatest to least score?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their critics score, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their critics score, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 9){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest count or greatest to least count?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their critic count, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their critic count, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 10){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest score or greatest to least score?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their user score, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their user score, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }
        else if(sort_option == 11){ //TODO IMPLEMENT
            cout << "Would you like to sort from least to greatest count or greatest to least count?" << endl;
            cout << "Enter 'gtl' for greatest to least, anything else for least to greatest: " << endl;
            cin >> sort_order;

            if(sort_order == "gtl"){
                cout << "Here are the games sorted by their user count, greatest to least!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = end; i >= 0; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
            else{
                cout << "Here are the games sorted by their user count, least to greatest!" << endl;
                int end = games.size();
                if(stoi(cap_num) >= 0 && stoi(cap_num) <= games.size()){
                    end = stoi(cap_num);
                }

                for (int i = 0; i < end; i++){
                    cout << "============------------__________------------============" << endl;
                    cout << "Game " << counter << ": " << data[i].getName() << endl;
                    cout << "Platform: " << data[i].getPlatform() << ", Year of Release: " << data[i].getYear() << ", Genre: " << data[i].getGenre() << endl;
                    cout << "Publisher: " << data[i].getPublisher() << ", North America Sales: " << data[i].getNAS() << ", European Sales: " << data[i].getEUS() << endl;
                    cout << "Japanese Sales: " << data[i].getJPS() << ", Other Sales: " << data[i].getOTS() << ", Global Sales: " << data[i].getGBS() << endl;
                    cout << "Critic Score: " << data[i].getCriticS() << ", Critic Count: " << data[i].getCriticC() << ", User Score: " << data[i].getUserS() << endl;
                    cout << "User Count: " << data[i].getUserC() << ", Developer: " << data[i].getDeveloper() << ", Rating: " << data[i].getRating() << endl;
                    counter++;
                }
                cout << "============------------__________------------============" << endl;
            }
        }


        cout << fixed << setprecision(2) << "CPU time used doing MergeSort: "
             << 1000.0 * (mergeTime) / CLOCKS_PER_SEC << " ms\n";
        cout << fixed << setprecision(2) << "CPU time used doing QuickSort: "
             << 1000.0 * (quickTime) / CLOCKS_PER_SEC << " ms\n";
    }
    else{
        std::cout << "Invalid option chosen! Press 1 to try again." << std::endl;
        return 0;
    }
    return 0;
}


