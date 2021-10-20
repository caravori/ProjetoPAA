#ifndef BUCKET_H
#define BUCKET_H
#include <vector>
#include <algorithm>

void bucketSort(int *array, int size) {
   int i, j;
   int count[size]; 
   for (i = 0; i < size; i++)
       count[i] = 0;

   for (i = 0; i < size; i++)
       (count[array[i]])++;

   for (i = 0, j = 0; i < size; i++)
       for(; count[i] > 0; (count[i])--)
           array[j++] = i;

}
#endif 
