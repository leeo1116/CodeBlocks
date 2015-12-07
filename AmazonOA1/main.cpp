#include <iostream>
#include "SortingFunctions.h"

using namespace std;

int main(int argc, char** argv)
{
    int unsortedNums1[] = {3, 2, 4, 9, 1, 5, 8, 6, 7};
    int unsortedNums2[] = {3, 2, 4, 9, 1, 5, 8, 6, 7};
    int unsortedNums3[] = {3, 2, 4, 9, 1, 5, 8, 6, 7};
    int unsortedNums4[] = {3, 2, 4, 9, 1, 5, 8, 6, 7};
    int inputList[] = {4, 2, 12, 11, -5};

    int *sortedNums1, *sortedNums2, *sortedNums3, *sortedNums4, *winList;
    int n = sizeof(unsortedNums1)/sizeof(*unsortedNums1);
    int m = sizeof(inputList)/sizeof(*inputList);
    int winSize = 2;

    Print1DimArray(unsortedNums1, n);
    sortedNums1 = SelectionSort(unsortedNums1, n);
    sortedNums2 = InsertionSort(unsortedNums2, n);
    sortedNums3 = BubbleSort(unsortedNums3, n);
    sortedNums4 = QuickSort(unsortedNums4, 0, n-1);

    Print1DimArray(sortedNums1, n);
    Print1DimArray(sortedNums2, n);
    Print1DimArray(sortedNums3, n);
    Print1DimArray(sortedNums4, n);

    winList = WindowMin(inputList, m, winSize);
    Print1DimArray(winList, m-winSize+1);

    return 0;
}
