#include <iostream>

int mergeComparisons;
int mergeSwaps;

Merge::Merge() { }

void Merge::mergeSort(int initialArray[], int startIndex, int endIndex, int mergeComparisons, int mergeSwaps) {
    if (startIndex >= endIndex) {
        return;
    }

    int middleIndex = startIndex + (endIndex - startIndex) / 2;
    mergeSort(initialArray, startIndex, middleIndex, mergeComparisons, mergeSwaps);
    mergeSort(initialArray, middleIndex + 1, endIndex, mergeComparisons, mergeSwaps);
    merge(initialArray, startIndex, middleIndex, endIndex, mergeComparisons, mergeSwaps);
    
}

void Merge::merge(int initialArray[], int leftIndex, int middleIndex, int rightIndex, int mergeComparisons, int mergeSwaps) {
    int intermediateArrayOne = middleIndex - leftIndex + 1;
    int intermediateArrayTwo = rightIndex - middleIndex;

    int leftArray[intermediateArrayOne];
    int rightArray[intermediateArrayTwo];

    int indexOfIntArrayOne = 0;
    int indexOfIntArrayTwo = 0;
    int indexOfFinalArray = leftIndex;

    for (int i = 0; i < intermediateArrayOne; i++) {
        leftArray[i] = initialArray[leftIndex + i];
    }
    for (int i = 0; i < intermediateArrayTwo; i++) {
        rightArray[i] = initialArray[middleIndex + 1 + i];
    }

    while (indexOfIntArrayOne < intermediateArrayOne && indexOfIntArrayTwo < intermediateArrayTwo) {
        if (leftArray[indexOfIntArrayOne] <= rightArray[indexOfIntArrayTwo]) {
            initialArray[indexOfFinalArray] = leftArray[indexOfIntArrayOne];
            indexOfIntArrayOne++;
            mergeComparisons++;
            mergeSwaps++;
        } else {
            initialArray[indexOfFinalArray] = rightArray[indexOfIntArrayTwo];
            indexOfIntArrayTwo++;
            mergeComparisons++;
            mergeSwaps++;
        }
        indexOfFinalArray++;
    }

    while (indexOfIntArrayOne < intermediateArrayOne) {
        initialArray[indexOfFinalArray] = leftArray[indexOfIntArrayOne];
        indexOfIntArrayOne++;
        indexOfFinalArray++;
        mergeComparisons++;
        mergeSwaps++;
    }

    while (indexOfIntArrayTwo < intermediateArrayTwo) {
        initialArray[indexOfFinalArray] = rightArray[indexOfIntArrayTwo];
        indexOfIntArrayTwo++;
        indexOfFinalArray++;
        mergeComparisons++;
        mergeSwaps++;
    }
}
