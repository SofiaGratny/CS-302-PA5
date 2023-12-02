#include <iostream>

Bubble::Bubble() { }

vector<int> Bubble::bubbleSort(int arrayNums[], int arrSize) {

    int tempVariable;
    int bubbleSwaps = 0;
    int bubbleComparisons = 0;

    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = 0; j < arrSize - 2; j++) {
            if (arrayNums[j] > arrayNums[j + 1]) {
                tempVariable = arrayNums[j];
                arrayNums[j] = arrayNums[j + 1];
                arrayNums[j + 1] = tempVariable;
                bubbleSwaps++;
            }
            bubbleComparisons++;
        }
    }

    vector<int> compSwaps;
    compSwaps.push_back(selectionComparisons);
    compSwaps.push_back(selectionSwaps);
    
    std::cout << std::endl << "Comparisons: " << bubbleComparisons;
    std::cout << std::endl << "Swaps: " << bubbleSwaps << std::endl;

    return compSwaps;
}
