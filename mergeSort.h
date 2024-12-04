//
// Created by paobe on 11/29/2024.
//
#include <string>
#ifndef DSAP3_MERGESORT_H
#define DSAP3_MERGESORT_H
#include <vector>
#include "videoGames.h"
#pragma once
using namespace std;

class mergeSort {
    public:
        void mergeSorter(vector<float> values, int left, int right, vector<videoGame> &data);
        void mergeSorterWords(vector<string> &arr, int left, int right, vector<videoGame> &data);


    private:
        void mergeSortHelper(vector<float> values, int left, int right, vector<videoGame> &data);
        void merge(vector<float> values, int left, int mid, int right, vector<videoGame> &data);
        void mergeSortHelperWords(vector<string> &arr, int left, int right, vector<videoGame> &data);
        void mergeWords(vector<string> &arr, int left, int mid, int right, vector<videoGame> &data);
};

#endif //DSAP3_MERGESORT_H
