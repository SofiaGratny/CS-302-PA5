// Author: Sofia Gratny//
// Date: 10/24/22//
// Purpose: Sorting and Time Complexity//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <numeric>
#include <vector>

using namespace std;
using namespace std::chrono;

#include "selection.h"
#include "bubble.h"
#include "merge.h"



void sortSelection1k(int arr[], int arrSize);
void sortBubble1k(int arr[], int arrSize);
void sortMerge1k(int arr[], int arrSize);

void sortSelection10k(int arr[], int arrSize);
void sortBubble10k(int arr[], int arrSize);
void sortMerge10k(int arr[], int arrSize);

void sortSelection100k(int arr[], int arrSize);
void sortBubble100k(int arr[], int arrSize);
void sortMerge100k(int arr[], int arrSize);

ofstream selection1k ("selection1000.csv");
ofstream selection10k ("selection10000.csv");
ofstream selection100k ("selection100000.csv");

ofstream bubble1k ("bubble1000.csv");
ofstream bubble10k ("bubble10000.csv");
ofstream bubble100k ("bubble100000.csv");

ofstream merge1k ("merge1000.csv");
ofstream merge10k ("merge10000.csv");
ofstream merge100k ("merge100000.csv");


int main() {

    size_t arraySize1k = 1000;
    size_t arraySize10k = 10000;
    size_t arraySize100k = 100000;

    int array1k[arraySize1k];
    int array10k[arraySize10k];
    int array100k[arraySize100k];

    int exit = 0;
    while (exit != 10) {
        srand((unsigned) time(0));
        int randomNumber;

        for (int i = 0; i < 1000; i++) {
            randomNumber = (rand() % (int)(1e6)) + 1;
            array1k[i] = randomNumber;
        }

        for (int i = 0; i < 10000; i++) {
            randomNumber = (rand() % (int)(1e6)) + 1;
            array10k[i] = randomNumber;
        }

        for (int i = 0; i < 100000; i++) {
            randomNumber = (rand() % (int)(1e6)) + 1;
            array100k[i] = randomNumber;
        }

        sortSelection1k(array1k, arraySize1k);
        sortBubble1k(array1k, arraySize1k);
        sortMerge1k(array1k, arraySize1k);

        sortSelection10k(array10k, arraySize10k);
        sortBubble10k(array10k, arraySize10k);
        sortMerge10k(array10k, arraySize10k);

        sortSelection100k(array100k, arraySize100k);
        sortBubble100k(array100k, arraySize100k);
        sortMerge100k(array100k, arraySize100k);

        exit++;
    }

    return 0;
}

void sortSelection1k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start1kSel = high_resolution_clock::now();
    cout << "Selection 1k: ";
    vector<int> sel1kcompSwaps = Selection::selectionSort(arr, arrSize, 0, 0);
    high_resolution_clock::time_point end1kSel = high_resolution_clock::now();

    auto duration<double> duration1kSel = end1kSel-start1kSel;
    cout << "time taken by function: " << duration1kSel.count() << " seconds" << endl;
    // selection sort 1000 random integers

    selection1k.open("selection1000.csv");
    selection1k << "," << duration1kSel.count() << sel1kcompSwaps.at(0) << "," << sel1kcompSwaps.at(1) << "\n" << endl;
    selection1k.close();

}

void sortBubble1k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber; 

    high_resolution_clock::time_point start1kBub = high_resolution_clock::now();
    cout << endl << "Bubble 1k: ";
    vector<int> bub1kcompSwaps = Bubble::bubbleSort(arr, arrSize);
    high_resolution_clock::time_point end1kBub = high_resolution_clock::now();

    auto duration<double> duration1kBub = end1kBub-start1kBub;
    cout << "time taken by function: " << duration1kBub.count() << " seconds" << endl;
    // bubble sort 1000 random integers

    bubble1k.open("bubble1000.csv");
    bubble1k << "," << duration1kBub.count() << bub1kcompSwaps.at(0) << "," << bub1kcompSwaps.at(1) << "\n" << endl;
    bubble1k.close();
}

void sortMerge1k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start1kMer = high_resolution_clock::now();
    cout << endl << "Merge 1k: " << endl;
    Merge::mergeSort(arr, 0, arrSize - 1, 0, 0);
    high_resolution_clock::time_point end1kMer = high_resolution_clock::now();
    cout << "Comparisons: " << mergeComparisons << endl;
    cout << "Swaps: " << mergeSwaps << endl;

    std::chrono::duration<double> duration1kMer = end1kMer-start1kMer;
    cout << "time taken by function: " << duration1kMer.count() << " seconds" << endl << endl;
    // merge sort 1000 random integers

    // merge1k.open("merge1000.csv");
    // merge1k << "," << duration1kMer.count() << mer1kcompSwaps.at(0) << "," << mer1kcompSwaps.at(1) << "\n" << endl;
    // merge1k.close();
}

void sortSelection10k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start10kSel = high_resolution_clock::now();
    cout << "Selection 10k: ";
    vector<int> sel10kcompSwaps = Selection::selectionSort(arr, arrSize, 0, 0);
    high_resolution_clock::time_point end10kSel = high_resolution_clock::now();

    auto duration<double> duration10kSel = end10kSel-start10kSel;
    cout << "time taken by function: " << duration10kSel.count() << " seconds" << endl;
    // selection sort 10000 random integers

    selection10k.open("selection10000.csv");
    selection10k << "," << duration10kSel.count() << sel10kcompSwaps.at(0) << "," << sel10kcompSwaps.at(1) << "\n" << endl;
    selection10k.close();
}

void sortBubble10k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start10kBub = high_resolution_clock::now();
    cout << endl << "Bubble 10k: ";
    vector<int> bub10kcompSwaps = Bubble::bubbleSort(arr, arrSize);
    high_resolution_clock::time_point end10kBub = high_resolution_clock::now();

    auto duration<double> duration10kBub = end10kBub-start10kBub;
    cout << "time taken by function: " << duration10kBub.count() << " seconds" << endl;
    // bubble sort 10000 random integers

    bubble10k.open("bubble10000.csv");
    bubble10k << "," << duration10kBub.count() << bub10kcompSwaps.at(0) << "," << bub10kcompSwaps.at(1) << "\n" << endl;
    bubble10k.close();
}

void sortMerge10k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start10kMer = high_resolution_clock::now();
    cout << endl << "Merge 10k: " << endl;
    Merge::mergeSort(arr, 0, arrSize - 1, 0, 0);
    high_resolution_clock::time_point end10kMer = high_resolution_clock::now();
    cout << "Comparisons: " << mergeComparisons << endl;
    cout << "Swaps: " << mergeSwaps << endl;

    auto duration<double> duration10kMer = end10kMer-start10kMer;
    cout << "time taken by function: " << duration10kMer.count() << " seconds" << endl << endl;
    // merge sort 10000 random integers

    // merge10k.open("merge10000.csv");
    // merge10k << "," << duration10kMer.count() << mer10kcompSwaps.at(0) << "," << mer10kcompSwaps.at(1) << "\n" << endl;
    // merge10k.close();

}

void sortSelection100k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start100kSel = high_resolution_clock::now();
    cout << "Selection 100k: ";
    vector<int> sel100kcompSwaps = Selection::selectionSort(arr, arrSize, 0, 0);
    high_resolution_clock::time_point end100kSel = high_resolution_clock::now();

    auto duration<double> duration100kSel = end100kSel-start100kSel;
    cout << "time taken by function: " << duration100kSel.count() << " seconds" << endl;
    // bubble sort 10000 random integers

    selection100k.open("selection100000.csv");
    selection100k << "," << duration100kSel.count() << sel100kcompSwaps.at(0) << "," << sel100kcompSwaps.at(1) << "\n" << endl;
    selection100k.close();
}

void sortBubble100k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start100kBub = high_resolution_clock::now();
    cout << endl << "Bubble 100k: ";
    vector<int> bub100kcompSwaps = Bubble::bubbleSort(arr, arrSize);
    high_resolution_clock::time_point end100kBub = high_resolution_clock::now();

    auto duration<double> duration100kBub = end100kBub-start100kBub;
    cout << "time taken by function: " << duration100kBub.count() << " seconds" << endl;
    // bubble sort 10000 random integers

    bubble100k.open("bubble100000.csv");
    bubble100k << "," << duration100kBub.count() << bub100kcompSwaps.at(0) << "," << bub100kcompSwaps.at(1) << "\n" << endl;
    bubble100k.close();
}

void sortMerge100k(int arr[], int arrSize) {
    srand((unsigned) time(0));
    int randomNumber;

    high_resolution_clock::time_point start100kMer = high_resolution_clock::now();
    cout << endl << "Merge 100k: " << endl;
    Merge::mergeSort(arr, 0, arrSize - 1, 0, 0);
    high_resolution_clock::time_point end100kMer = high_resolution_clock::now();
    cout << "Comparisons: " << mergeComparisons << endl;
    cout << "Swaps: " << mergeSwaps << endl;

    auto duration<double> duration100kMer = end100kMer-start100kMer;
    cout << "time taken by function: " << duration100kMer.count() << " seconds" << endl << endl;
    // bubble sort 10000 random integers

    // merge100k.open("merge100000.csv");
    // merge100k << "," << duration100kMer.count() << mer100kcompSwaps.at(0) << "," << mer100kcompSwaps.at(1) << "\n" << endl;
    // merge100k.close();

}
