//
// Created by paobe on 11/29/2024.
//

#include "quickSort.h"

void quickSort::quicksort(int array[], int size) {
    quickSortPriv(array, 0, size - 1);
}

void quickSort::quickSortPriv(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSortPriv(array, low, pivot - 1);
        quickSortPriv(array, pivot + 1, high);
    }
}

int quickSort::partition(int array[], int low, int high) {
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
            swap(&array[up], &array[down]);
        }
    }
    swap(&array[low], &array[down]);
    return down;
}

void quickSort::swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
