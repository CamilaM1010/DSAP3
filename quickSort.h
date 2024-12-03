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


class quickSort {
public:
    void quicksort(vector<int> array, int size, vector<videoGame> &data);
    void quicksortWords(vector<string> array, int size, vector<videoGame> &data);

private:
    void quickSortPriv(vector<int> array, int low, int high, vector<videoGame> &data);
    int partition(vector<int> array, int low, int high, vector<videoGame> &data);
    void swap(int* a, int* b, videoGame* c, videoGame* d);
    void quicksortPrivWords(vector<string> array, int low, int high, vector<videoGame> &data);
    int partitionWords(vector<string> array, int low, int high, vector<videoGame> &data);
    void swapWords(string* a, string* b, videoGame* c, videoGame* d);
};


#endif //DSAP3_QUICKSORT_H
