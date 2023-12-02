#include <iostream>
#include <vector>

int selectionComparisons;
int selectionSwaps;

Selection::Selection() { }

vector<int> Selection::selectionSort(int arrayNums[], int arrSize, int selectionComparisons, int selectionSwaps) {

    int smallVariable;
    int tempVariable;
    int smallVariableIndex;

    for (int i = 0; i < arrSize - 1; i++) {

        smallVariable = arrayNums[i];

        for (int j = i + 1; j < arrSize - 1; j++) {
            if (arrayNums[j] < smallVariable) {
                smallVariable = arrayNums[j];
                smallVariableIndex = j;
            }
            selectionComparisons++;
        }
        tempVariable = arrayNums[i];
        arrayNums[i] = smallVariable;
        arrayNums[smallVariableIndex] = tempVariable;
        selectionSwaps++;
    }

    vector<int> compSwaps;
    compSwaps.push_back(selectionComparisons);
    compSwaps.push_back(selectionSwaps);

    std::cout << std::endl << "Comparisons: " << selectionComparisons;
    std::cout << std::endl << "Swaps: " << selectionSwaps << std::endl;

    return compSwaps;


}
