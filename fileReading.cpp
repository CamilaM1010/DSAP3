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
    vector<videoGame> data; //stores each data as a vector, subject to change
    ifstream file("Video_Games.csv");
    if (!file.is_open()){ //Checks if file isn't existing/open
        cout << "File failed to open." << endl;
    }
    else{
        string line; //stores the current line in the file
        bool first_line = true;
        while(getline(file, line)){ //collects the values in every line
            if (first_line){
                first_line = false;
                continue;
            }

            stringstream stream(line);
            string curr_data;
            vector<string> row;

            //Read the data separated by commas. Empty values seem to be read as ''
            int i = 0;
            while(getline(stream, curr_data, ',')){
                if (curr_data == ""){
                    curr_data = "N/A";
                }
                row.push_back(curr_data);
            }
            videoGame game(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14], row[15]);
            data.push_back(game); //adds the row's values to the vector
        }

//        for(int i = 0; i < data.size(); i++){
//            for (int j = 0; j < data[i].size(); j++){
//                cout << data[i][j] << ";";
//            }
//            cout << endl;
//        }
        file.close();
    }
    int sortOption;
    std::cout << "Welcome to the Video Game Analyzer Program, where we analyze a variety of unique video games and compare the data across each of them in order to analyze the video game market and order the data to the user's content!" << std::endl;
    std::cout << "How would you like to sort the Video Games?\n1.Name\n2.Platform\n3.Year of Release\n4.Genre\n5.Publisher\n6.North American Sales\n7.European Sales\n8.Japanese Sales\n9.Other Sales\n10.Global Sales\n11.Critic Score\n12.Critic Count\n13.User Score\n14.User Count\n15.Developer\n16.Rating\nInput: ";
    cin >> sortOption;

    if (sortOption >= 1 && sortOption <= 16){
        vector<string> games;
        for (int i = 0; i < data.size(); i++){
            if (sortOption == 1){
                games.push_back(data[i].getName());
            }
            else if(sortOption == 2){
                games.push_back(data[i].getPlatform());
            }
            else if(sortOption == 3){
                games.push_back(data[i].getYear());
            }
            else if(sortOption == 4){
                games.push_back(data[i].getGenre());
            }
            else if(sortOption == 5){
                games.push_back(data[i].getPublisher());
            }
            else if(sortOption == 6){
                games.push_back(data[i].getNAS());
            }
            else if(sortOption == 7){
                games.push_back(data[i].getEUS());
            }
            else if(sortOption == 8){
                games.push_back(data[i].getJPS());
            }
            else if(sortOption == 9){
                games.push_back(data[i].getOTS());
            }
            else if(sortOption == 10){
                games.push_back(data[i].getGBS());
            }
            else if(sortOption == 11){
                games.push_back(data[i].getCriticS());
            }
            else if(sortOption == 12){
                games.push_back(data[i].getCriticC());
            }
            else if(sortOption == 13){
                games.push_back(data[i].getUserS());
            }
            else if(sortOption == 14){
                games.push_back(data[i].getUserC());
            }
            else if(sortOption == 15){
                games.push_back(data[i].getDeveloper());
            }
            else if(sortOption == 16){
                games.push_back(data[i].getRating());
            }
        }
        int size = games.size();
        vector<string> games2 = games;

        mergeSort sorter1;
        quickSort sorter2;

        cout << "Does Merge" << endl;
        const clock_t clock_merge_start = clock();
        sorter1.mergeSorterWords(games, 0, size - 1, data);
        const clock_t clock_merge_end = clock();
        cout << "No merge" << endl;

        cout << "Does Quick" << endl;
        const clock_t clock_quick_start = clock();
        sorter2.quicksortWords(games2, games2.size(), data);
        const clock_t clock_quick_end = clock();
        cout << "Does Quicke" << endl;

        float mergeTime = clock_merge_end - clock_merge_start;
        float quickTime = clock_quick_end - clock_quick_start;

        if(mergeTime < quickTime) {
            cout << "Merge Sort Printed the Following Data: " << endl;
            for (int i = 0; i < games.size(); i++){
                cout << data[i].getName() << endl;
            }
            cout << fixed << setprecision(2) << "CPU time used: "
                 << 1000.0 * (mergeTime) / CLOCKS_PER_SEC << " ms\n";
        }
        else if(mergeTime > quickTime){
            cout << "Quick Sort Printed the Following Data: " << endl;
            cout << fixed << setprecision(2) << "CPU time used: "
                 << 1000.0 * (quickTime) / CLOCKS_PER_SEC << " ms\n";
        }
    }
    else{
        std::cout << "Invalid option chosen!" << std::endl;
        return 0;
    }
    return 0;
}


