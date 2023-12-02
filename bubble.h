#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>
#include <string>

class Bubble
{
    private:
        int initialVariable;
        int arrSize;
        int bubbleSwaps;
        int bubbleComparisons;
    public:
        Bubble();
        static vector<int> bubbleSort(int arrayNums[], int arrSize);

        ~Bubble();
};
  
#include "bubble.cpp"
#endif
