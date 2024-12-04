//
// Created by paobe on 11/29/2024.
//
#include <string>
#ifndef DSAP3_QUICKSORT_H
#define DSAP3_QUICKSORT_H
#include <vector>
#include "videoGames.h"
#include <memory>
#pragma once
using namespace std;

// the quickSort class implements the QuickSort algorithm
class quickSort {
public:
    void quicksort(vector<float> &values, int size, vector<videoGame> &data);
    void quicksortWords(vector<string> &array, int size, vector<videoGame> &data);

private:
    void quickSortPriv(vector<float> &values, int low, int high, vector<videoGame> &data);
    int partition(vector<float> &values, int low, int high, vector<videoGame> &data);
    void swap(float* a, float* b, videoGame* c, videoGame* d);
    void quicksortPrivWords(vector<string> &array, int low, int high, vector<videoGame> &data);
    int partitionWords(vector<string> &array, int low, int high, vector<videoGame> &data);
    void swapWords(string* a, string* b, videoGame* c, videoGame* d);
};


#endif //DSAP3_QUICKSORT_H
