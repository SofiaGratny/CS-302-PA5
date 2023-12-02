#ifndef MERGE_H
#define MERGE_H

#include <iostream>
#include <string>

class Merge
{
    private:
        int startIndex;
        int middleIndex;
        int endIndex;
        int leftIndex;
        int rightIndex;
        int intermediateArrayOne;
        int intermediateArrayTwo;
        int indexOfIntArrayOne;
        int indexOfIntArrayTwo;
    public:
        Merge();
        static void mergeSort(int arr[], int startIndex, int endIndex, int mergeComparisons, int mergeSwaps);
        static void merge(int arr[], int startIndex, int middleIndex, int endIndex, int mergeComparisons, int mergeSwaps);

        ~Merge();
};
  
#include "merge.cpp"
#endif
