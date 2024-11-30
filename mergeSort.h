//
// Created by paobe on 11/29/2024.
//
#include <string>
#ifndef DSAP3_MERGESORT_H
#define DSAP3_MERGESORT_H
using namespace std;

class mergeSort {
    public:
        void mergeSorter(int arr[], int left, int right);
        void mergeSorterWords(string arr[], int left, int right);


    private:
        void mergeSortHelper(int arr[], int left, int right);
        void merge(int arr[], int left, int mid, int right);
        void mergeSortHelperWords(string arr[], int left, int right);
        void mergeWords(string arr[], int left, int mid, int right);
};

#endif //DSAP3_MERGESORT_H
