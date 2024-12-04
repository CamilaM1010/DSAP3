//NOT PART OF FINAL PROJECT

#include <iostream>
#include "mergeSort.h"
#include "quickSort.h"
#include <chrono>
#include <iomanip>
#include "videoGames.h"

using namespace std;

int main() {
    vector<float> values = {12.2, 1.11, 6.75, 9.7};
    mergeSort sort;
    vector<videoGame> d = {videoGame("s", "1", "1", "1", "1", "1","1" ,"1", "1", "1", "1", "1", "2", "3", "3", "3")};
    sort.mergeSorter(values, 0, values.size()-1, d);

    for (int i = 0; i < values.size(); i++){
        cout << values[i] << endl;
    }

    return 0;
}
