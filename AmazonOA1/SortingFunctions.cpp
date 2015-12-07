#include <iostream>
#include "SortingFunctions.h"


void Print1DimArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}


/** Selection sort in ascending order
 *
 * Parameters: nums[] - initial unsorted array
 * Return: sorted array
 *
 */
int *SelectionSort(int nums[], int numsLen)
{
    if(!nums || !(*nums))
    {
        return NULL;
    }
    for(int i = 0; i < numsLen-1; i++)
    {
        int iMin = i;
        for(int j = i+1; j < numsLen; j++)
        {
            if(nums[j] < nums[iMin])
            {
                iMin = j;
            }
        }
        // Swap nums[i] and nums[iMin]
        int temp = nums[i];
        nums[i] = nums[iMin];
        nums[iMin] = temp;
    }
    return nums;
}


/** Insertion sort in ascending order
 *
 * Parameters: nums[] - initial unsorted array
 * Return: sorted array
 *
 */
int *InsertionSort(int nums[], int numsLen)
{
    if(!nums || !(*nums))
    {
        return NULL;
    }
    for(int i = 0; i < numsLen; i ++)
    {
        for(int j = i; j > 0 && nums[j-1] > nums[j]; j--)
        {
            int temp = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = temp;
        }
    }
    return nums;
}


int *BubbleSort(int nums[], int numsLen)
{
    for(int i = 0; i < numsLen-1; i++)
    {
        for(int j = 0; j < numsLen-1-i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}


int *QuickSort(int nums[], int left, int right)
{
    int i = left, j = right;
    int pivot = nums[left];

    // Partition
    while(i <= j)
    {
        while(nums[i] < pivot)
            i++;
        while(nums[j] > pivot)
            j--;
        if(i <= j)
        {
            // Swap
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }

    }

    // Recursion
    if(left < j)
        QuickSort(nums, left, j);
    if(i < right)
        QuickSort(nums, i, right);
    return nums;
}


/** Find minimum value inside window
 *
 * Parameter: nums[] - input array
 * Parameter: numsLen - input array length
 * Parameter: winLen - window size
 *
 */
int *WindowMin(int nums[], int numsLen, int winLen)
{
    int rNumLen = numsLen-winLen+1;
    int *rNums = new int[rNumLen];

    // int rNums[rNumLen];
    // After returning, the rNums will be out of its storage scope;
    // only first memory address will be maintained, cause problems later

    for(int i = 0; i <= numsLen-winLen; i++)
    {
        int tempMin = nums[i];
        for(int j = 0; j < winLen; j++)
        {
            if(nums[i+j] < tempMin)
                tempMin = nums[i+j];
        }
        rNums[i] = tempMin;
    }
    return rNums;
}
