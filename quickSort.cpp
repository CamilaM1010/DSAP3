//
// Created by paobe on 11/29/2024.
//

#include "quickSort.h"
#include <vector>

//function that sorts a vector of floats and updates the videoGame vector
void quickSort::quicksort(vector<float> &values, int size, vector<videoGame> &data) {
    quickSortPriv(values, 0, size - 1, data);
}

// recursively sorts floats using quickSort
void quickSort::quickSortPriv(vector<float> &values, int low, int high, vector<videoGame> &data) {
    if (low < high) {
        int pivot = partition(values, low, high, data); // chooses the pivot used in quickSort
        // recursively sorts the elements by putting them before or after the pivot
        quickSortPriv(values, low, pivot - 1, data);
        quickSortPriv(values, pivot + 1, high, data);
    }
}

// function that correctly chooses the pivot and rearranges the elements accordingly
int quickSort::partition(vector<float> &values, int low, int high, vector<videoGame> &data) {
    float pivot = values[low]; // first element is pivot
    int up = low, down = high;

    // repositions floats before and after the pivot
    while (up < down) {
        while (up < high && values[up] <= pivot) {
            up++; // pointer moves up until a float is greater than pivot
        }
        while (down > low && values[down] > pivot) {
            down--; // pointer moves down until float is smaller than pivot
        }
        if (up < down) {
            // swaps the videoGame objects to correct order around the pivot
            swap(&values[up], &values[down], &data[up], &data[down]);
        }
    }
    // swaps pivot with down pointer
    swap(&values[low], &values[down], &data[low], &data[down]);
    return down;
}

// function that swaps the videoGame and its float to ensure that the data and values are synced
void quickSort::swap(float *a, float* b, videoGame* c, videoGame* d) {
    float temp = *a; // float swap
    *a = *b;
    *b = temp;

    videoGame temp2 = *c; // videoGame swap
    *c = *d;
    *d = temp2;
}

//function that sorts a vector of strings and updates the videoGame vector
void quickSort::quicksortWords(vector<string> &array, int size, vector<videoGame> &data) {
    quicksortPrivWords(array, 0, size - 1, data);
}

// recursively sorts strings using quickSort
void quickSort::quicksortPrivWords(vector<string> &array, int low, int high, vector<videoGame> &data) {
    if (low < high) {
        int pivot = partitionWords(array, low, high, data);// chooses the pivot used in quickSort
        // recursively sorts the elements by putting them before or after the pivot
        quicksortPrivWords(array, low, pivot - 1, data);
        quicksortPrivWords(array, pivot + 1, high, data);
    }
}

// function that correctly chooses the pivot and rearranges the elements accordingly for strings
int quickSort::partitionWords(vector<string> &array, int low, int high, vector<videoGame> &data) {
    string pivot = array[low];
    int up = low + 1, down = high;

    // repositions strings before and after the pivot
    while (up < down) {
        while (up < high && array[up] <= pivot) {
            up++; // pointer moves up until a string is greater than pivot
        }
        while (down > low && array[down] > pivot) {
            down--; // pointer moves up until a string is smaller than pivot
        }
        if (up < down) {
            // swaps the videoGame objects to correct order around the pivot
            swapWords(&array[up], &array[down], &data[up], &data[down]);
        }
    }
    // swaps pivot with down pointer
    swapWords(&array[low], &array[down], &data[low], &data[down]);
    return down;
}

// function that swaps the videoGame and its string to ensure that the data and values are synced
void quickSort::swapWords(std::string *a, std::string *b, videoGame* c, videoGame* d) {
    string temp = *a; // string swap
    *a = *b;
    *b = temp;

    videoGame temp2 = *c; // videoGame swap
    *c = *d;
    *d = temp2;
}
