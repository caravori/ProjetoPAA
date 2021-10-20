#ifndef INSERTION_H
#define INSERTION_H
#include <vector>
void insertion(int *vector, int size){
    int i, j;
    int key;
        for (i = 1; i < size; i++)
        {
            key = vector[i];
            j = i - 1;
            while (j >= 0 && vector[j] > key)
            {
                vector[j + 1] = vector[j];
                j = j - 1;
            }
            vector[j + 1] = key;
        }
}

#endif
