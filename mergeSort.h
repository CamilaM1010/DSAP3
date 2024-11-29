//
// Created by paobe on 11/29/2024.
//

#ifndef DSAP3_MERGESORT_H
#define DSAP3_MERGESORT_H

class mergeSort {
    public:
        void mergeSortHelper(int arr[], int left, int right);

    private:
        void merge(int arr[], int left, int mid, int right);
};

#endif //DSAP3_MERGESORT_H
