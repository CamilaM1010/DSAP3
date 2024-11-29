//
// Created by paobe on 11/29/2024.
//

#ifndef DSAP3_QUICKSORT_H
#define DSAP3_QUICKSORT_H


class quickSort {
public:
    void quicksort(int array[], int size);

private:
    void quickSortPriv(int array[], int low, int high);
    int partition(int array[], int low, int high);
    void swap(int* a, int* b);
};


#endif //DSAP3_QUICKSORT_H
