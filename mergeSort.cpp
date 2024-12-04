//
// Created by paobe on 11/29/2024.
// using code from Sorting slides by Aman
//
#include "mergeSort.h"
#include "videoGames.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// function that merges two sub-arrays of floats into one sorted array
void mergeSort::merge(vector<float> &values, int left, int mid, int right, vector<videoGame> &data) {
    // creates two sub-arrays
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid; // size of right subarray

    // creates sub-arrays for values
    vector<float> leftK(n1);
    vector<float> rightK(n2);

    // creates sub-arrays for videoGames
    vector<videoGame> test1(n1);
    vector<videoGame> test2(n2);

    // stores data from original arrays into the temps
    for (int i = 0; i < n1; i++) {
        leftK[i] = values[left + i];
        test1[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightK[j] = values[mid + 1 + j];
        test2[j] = data[mid + 1 + j];
    }

    // merges temp arrays back into the originals
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftK[i] <= rightK[j]) {
            values[k] = leftK[i];
            data[k] = test1[i];
            i++;
        } else {
            values[k] = rightK[j];
            data[k] = test2[j];
            j++;
        }
        k++;
    }

    // when needed it copies remaining elements from left subarray
    while (i < n1) {
        values[k] = leftK[i];
        data[k] = test1[i];
        i++;
        k++;
    }

    // when needed it copies remaining elements from right subarray
    while (j < n2) {
        values[k] = rightK[j];
        data[k] = test2[j];
        j++;
        k++;
    }
}

// function that recursively implements mergeSort for floats
void mergeSort::mergeSortHelper(vector<float> &values, int left, int right, vector<videoGame> &data) {
    if (left < right) {
        // mid is the point where the array is divided into two sub-arrays
        int mid = left + (right - left) / 2;

        // recursively sorts the left and right sub-arrays
        mergeSortHelper(values, left, mid, data);
        mergeSortHelper(values, mid + 1, right, data);

        // merges the two sorted halves
        merge(values, left, mid, right, data);
    }
}

// function used to input original arrays and sort them when using floats
void mergeSort::mergeSorter(vector<float> &values, int left, int right, vector<videoGame> &data) {
    mergeSortHelper(values, left, right, data);
}

// function that merges two sub-arrays of words into one sorted array
void mergeSort::mergeWords(vector<string> &arr, int left, int mid, int right, vector<videoGame> &data) {
    // creates two sub-arrays
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid; // size of right subarray

    // creates left and right subarray for strings dynamically
    string *X = new string[n1];
    string *Y = new string[n2];

    // creates left and right subarray for videoGames
    vector<videoGame> test1(n1);
    vector<videoGame> test2(n2);

    // stores data from original arrays into the temps
    for (int i = 0; i < n1; i++) {
        X[i] = arr[left + i];
        test1[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = arr[mid + 1 + j];
        test2[j] = data[mid + 1 + j];
    }

    // merges temp arrays back into the originals
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (X[i] <= Y[j]) {
            arr[k] = X[i];
            data[k] = test1[i];
            i++;
        } else {
            arr[k] = Y[j];
            data[k] = test2[j];
            j++;
        }
        k++;
    }

    // when needed it copies remaining elements from left subarray
    while (i < n1) {
        arr[k] = X[i];
        data[k] = test1[i];
        i++;
        k++;
    }

    // when needed it copies remaining elements from right subarray
    while (j < n2) {
        arr[k] = Y[j];
        data[k] = test2[j];
        j++;
        k++;
    }

    // frees dynamically allocated memory to avoid memory leaks
    delete[] X;
    delete[] Y;
}

// function that recursively implements mergeSort for strings
void mergeSort::mergeSortHelperWords(vector<string> &arr, int left, int right, vector<videoGame> &data) {
    if (left < right) {
        // mid is the point where the array is divided into two sub-arrays
        int mid = left + (right - left) / 2;

        // recursively sorts the left and right sub-arrays
        mergeSortHelperWords(arr, left, mid, data);
        mergeSortHelperWords(arr, mid + 1, right, data);

        // merges the sorted halves
        mergeWords(arr, left, mid, right, data);
    }
}

// function used to input original arrays and sort them when using strings
void mergeSort::mergeSorterWords(vector<string> &arr, int left, int right, vector<videoGame> &data) {
    mergeSortHelperWords(arr, left, right, data);
}
