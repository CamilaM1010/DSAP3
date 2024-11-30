#include <iostream>
#include "mergeSort.h"
#include "quickSort.h"
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 65, 93, 2, 998, 29, 49475,20, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    string words[] = {"zhegd", "babab", "abed", "chdhe", "aaed"};
    int size_words = sizeof(words) / sizeof(words[0]);

    cout << "Given array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size_words; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    mergeSort sorter;

    const clock_t clock_merge_start = clock();
    sorter.mergeSorter(arr, 0, size - 1);
    const clock_t clock_merge_end = clock();
    sorter.mergeSorterWords(words, 0, size_words - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << fixed << setprecision(2) << "CPU time used: " << 1000.0 * (clock_merge_end - clock_merge_start) / CLOCKS_PER_SEC << " ms\n";
    for (int i = 0; i < size_words; i++) {
        cout << words[i] << " ";
    }
    cout << endl;


    int arr2[] = {29, 10, 14, 37, 13, 18, 5, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    string words2[] = {"zhegd", "babab", "abed", "chdhe", "aaed"};
    int size_words2 = sizeof(words2) / sizeof(words2[0]);

    cout << "Given array: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Call quickSort
    quickSort tester;

    const clock_t clock_quick_start = clock();
    tester.quicksort(arr2, size2);
    const clock_t clock_quick_end = clock();
    tester.quicksortWords(words2, size_words2);

    cout << "Sorted array: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size_words2; i++) {
        cout << words2[i] << " ";
    }
    cout << endl;

    cout << fixed << setprecision(2) << "CPU time used: " << 1000.0 * (clock_quick_end - clock_quick_start) / CLOCKS_PER_SEC << " ms\n";
    return 0;
}
