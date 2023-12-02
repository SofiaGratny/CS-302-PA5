#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>
#include <string>

class Selection
{
    private:
        int smallVariable;
        int tempVariable;
        int arrSize;
        int selectionSwaps;
        int selectionComparisons;
    public:
        Selection();
        static vector<int> selectionSort(int arrayNums[], int length, int selectionComparisons, int selectionSwaps);
        
        ~Selection();
};
  
#include "selection.cpp"
#endif
