//
// Created by paobe on 11/29/2024.
// using code from Sorting slides by Aman
//
#include "mergeSort.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void mergeSort::merge(vector<float> &values, int left, int mid, int right, vector<videoGame> &data) {
    // Create X ← values[left..mid] & Y ← values[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<float> leftK(n1);
    vector<float> rightK(n2);

    std::vector<videoGame> test1(n1);
    std::vector<videoGame> test2(n2);

    for (int i = 0; i < n1; i++) {
        leftK[i] = values[left + i];
        test1[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightK[j] = values[mid + 1 + j];
        test2[j] = data[mid + 1 + j];
    }

    // Merge the arrays X and Y into values
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

    // Append remaining elements of X, if any
    while (i < n1) {
        values[k] = leftK[i];
        data[k] = test1[i];
        i++;
        k++;
    }

    // Append remaining elements of Y, if any
    while (j < n2) {
        values[k] = rightK[j];
        data[k] = test2[j];
        j++;
        k++;
    }
}

void mergeSort::mergeSortHelper(vector<float> &values, int left, int right, vector<videoGame> &data) {
    if (left < right) {
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;

        // Sort the two halves
        mergeSortHelper(values, left, mid, data);
        mergeSortHelper(values, mid + 1, right, data);

        // Merge the sorted halves
        merge(values, left, mid, right, data);
    }
}

void mergeSort::mergeSorter(vector<float> &values, int left, int right, vector<videoGame> &data) {
    //Calls the helper function
    mergeSortHelper(values, left, right, data);
}

void mergeSort::mergeWords(vector<string> &arr, int left, int mid, int right, vector<videoGame> &data) {
    // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string *X = new string[n1];
    string *Y = new string[n2];

    std::vector<videoGame> test1(n1);
    std::vector<videoGame> test2(n2);

    for (int i = 0; i < n1; i++) {
        X[i] = arr[left + i];
        test1[i] = data[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = arr[mid + 1 + j];
        test2[j] = data[mid + 1 + j];
    }

    // Merge the arrays X and Y into arr
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

    // Append remaining elements of X, if any
    while (i < n1) {
        arr[k] = X[i];
        data[k] = test1[i];
        i++;
        k++;
    }

    // Append remaining elements of Y, if any
    while (j < n2) {
        arr[k] = Y[j];
        data[k] = test2[j];
        j++;
        k++;
    }

    delete[] X;
    delete[] Y;
}

void mergeSort::mergeSortHelperWords(vector<string> &arr, int left, int right, vector<videoGame> &data) {
    if (left < right) {
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;

        // Sort the two halves
        mergeSortHelperWords(arr, left, mid, data);
        mergeSortHelperWords(arr, mid + 1, right, data);

        // Merge the sorted halves
        mergeWords(arr, left, mid, right, data);
    }
}

void mergeSort::mergeSorterWords(vector<string> &arr, int left, int right, vector<videoGame> &data) {
    //calls helper function
    mergeSortHelperWords(arr, left, right, data);
}