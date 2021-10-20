#ifndef MERGESORT_H
#define MERGESORT_H
#include <stdlib.h>

int* slice(int *arr, int start, int end)
{
    int *result = (int *) malloc((end - start) * sizeof(int));
    int i;
    for (i = start; i < end; i++)
    {
        result[i - start] = arr[i];
    }
    return result;
}

/** Merge left and right into result, overwriting everything in result. */
void merge(int *result, int *left, int *right, int leftLen, int rightLen)
{
    int i = 0, j = 0;
    while(i < leftLen && j < rightLen)
    {
        if (left[i] < right[j])
        {
            result[i + j] = left[i];
            i++;
        }
        else
        {
            result[i + j] = right[j];
            j++;
        }
    }

    for(; i < leftLen; i++)
    {
        result[i + j] = left[i];
    }
    for(; j < rightLen; j++)
    {
        result[i + j] = right[j];
    }

    free(left);
    free(right);
}

// in-place merge sort
void mergeSort(int *arr, int len)
{
    if (len <= 1)
    {
        return;
    }
    int *left = slice(arr, 0, len / 2 + 1);
    int *right = slice(arr, len / 2, len);


    mergeSort(left, len / 2);
    mergeSort(right, len - (len / 2));

    merge(arr, left, right, len / 2, len - (len / 2));
}



#endif
