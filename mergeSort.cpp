//
// Created by paobe on 11/29/2024.
// using code from Sorting slides by Aman
//
#include "mergeSort.h"
#include <iostream>
using namespace std;

void mergeSort::merge(int arr[], int left, int mid, int right) {
    // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* X = new int[n1];
    int* Y = new int[n2];

    for (int i = 0; i < n1; i++)
        X[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Y[j] = arr[mid + 1 + j];

    // Merge the arrays X and Y into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (X[i] <= Y[j]) {
            arr[k] = X[i];
            i++;
        } else {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    // Append remaining elements of X, if any
    while (i < n1) {
        arr[k] = X[i];
        i++;
        k++;
    }

    // Append remaining elements of Y, if any
    while (j < n2) {
        arr[k] = Y[j];
        j++;
        k++;
    }

    delete[] X;
    delete[] Y;
}

void mergeSort::mergeSortHelper(int arr[], int left, int right) {
        if (left < right) {
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;

        // Sort the two halves
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void mergeSort::mergeSorter(int arr[], int left, int right) {
    //Calls the helper function
    mergeSortHelper(arr, left, right);
}

void mergeSort::mergeWords(string *arr, int left, int mid, int right) {
    // Create X ← arr[left..mid] & Y ← arr[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string *X = new string[n1];
    string *Y = new string[n2];

    for (int i = 0; i < n1; i++)
        X[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Y[j] = arr[mid + 1 + j];

    // Merge the arrays X and Y into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (X[i] <= Y[j]) {
            arr[k] = X[i];
            i++;
        } else {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    // Append remaining elements of X, if any
    while (i < n1) {
        arr[k] = X[i];
        i++;
        k++;
    }

    // Append remaining elements of Y, if any
    while (j < n2) {
        arr[k] = Y[j];
        j++;
        k++;
    }

    delete[] X;
    delete[] Y;
}

void mergeSort::mergeSortHelperWords(string *arr, int left, int right) {
    if (left < right) {
        // m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;

        // Sort the two halves
        mergeSortHelperWords(arr, left, mid);
        mergeSortHelperWords(arr, mid + 1, right);

        // Merge the sorted halves
        mergeWords(arr, left, mid, right);
    }
}

void mergeSort::mergeSorterWords(string *arr, int left, int right) {
    //calls helper function
    mergeSortHelperWords(arr, left, right);
}

