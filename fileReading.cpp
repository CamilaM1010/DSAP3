#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream file("Video_Games.csv");
    if (!file.is_open()){ //Checks if file isn't existing/open
        cout << "File failed to open." << endl;
    }
    else{
        string line; //stores the current line in the file
        vector<vector<string>> data; //stores each data as a vector, subject to change
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
            while(getline(stream, curr_data, ',')){
                row.push_back(curr_data);
            }
            data.push_back(row); //adds the row's values to the vector
        }

//        for(int i = 0; i < data.size(); i++){
//            for (int j = 0; j < data[i].size(); j++){
//                cout << data[i][j] << ";";
//            }
//            cout << endl;
//        }
        file.close();
    }
    return 1;
}


