//
// Created by paobe on 11/29/2024.
//

#include "quickSort.h"
#include <vector>

void quickSort::quicksort(vector<int> array, int size, vector<videoGame> &data) {
    quickSortPriv(array, 0, size - 1, data);
}

void quickSort::quickSortPriv(vector<int> array, int low, int high, vector<videoGame> &data) {
    if (low < high) {
        int pivot = partition(array, low, high, data);
        quickSortPriv(array, low, pivot - 1, data);
        quickSortPriv(array, pivot + 1, high, data);
    }
}

int quickSort::partition(vector<int> array, int low, int high, vector<videoGame> &data) {
    int pivot = array[low];
    int up = low, down = high;

    while (up < down) {
        while (up < high && array[up] <= pivot) {
            up++;
        }
        while (down > low && array[down] > pivot) {
            down--;
        }
        if (up < down) {
            swap(&array[up], &array[down], &data[up], &data[down]);
        }
    }
    swap(&array[low], &array[down], &data[low], &data[down]);
    return down;
}

void quickSort::swap(int *a, int* b, videoGame* c, videoGame* d) {
    int temp = *a;
    *a = *b;
    *b = temp;

    videoGame temp2 = *c;
    *c = *d;
    *d = temp2;
}

void quickSort::quicksortWords(vector<string> array, int size, vector<videoGame> &data) {
    quicksortPrivWords(array, 0, size - 1, data);
}

void quickSort::quicksortPrivWords(vector<string> array, int low, int high, vector<videoGame> &data) {
    if (low < high) {
        int pivot = partitionWords(array, low, high, data);
        quicksortPrivWords(array, low, pivot - 1, data);
        quicksortPrivWords(array, pivot + 1, high, data);
    }
}

int quickSort::partitionWords(vector<string> array, int low, int high, vector<videoGame> &data) {
    string pivot = array[low];
    int up = low + 1, down = high;

    while (up < down) {
        while (up < high && array[up] <= pivot) {
            up++;
        }
        while (down > low && array[down] > pivot) {
            down--;
        }
        if (up < down) {
            swapWords(&array[up], &array[down], &data[up], &data[down]);
        }
    }
    swapWords(&array[low], &array[down], &data[low], &data[down]);
    return down;
}

void quickSort::swapWords(std::string *a, std::string *b, videoGame* c, videoGame* d) {
    string temp = *a;
    *a = *b;
    *b = temp;

    videoGame temp2 = *c;
    *c = *d;
    *d = temp2;
}
