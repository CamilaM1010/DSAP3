//
// Created by paobe on 11/29/2024.
//
#include <string>
#ifndef DSAP3_QUICKSORT_H
#define DSAP3_QUICKSORT_H
using namespace std;


class quickSort {
public:
    void quicksort(int array[], int size);
    void quicksortWords(string array[], int size);

private:
    void quickSortPriv(int array[], int low, int high);
    int partition(int array[], int low, int high);
    void swap(int* a, int* b);
    void quicksortPrivWords(string array[], int low, int high);
    int partitionWords(string array[], int low, int high);
    void swapWords(string* a, string* b);
};


#endif //DSAP3_QUICKSORT_H
