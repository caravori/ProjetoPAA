#ifndef COUNTING_H
#define COUNTING_H
#include <string.h>
// void count_sort(int* a, int l, int r, int M)
// {
//     int i, j;
//     int* cnt = (int*)malloc(M * sizeof(int));
//     if (!cnt) {

//         exit(1);
//     }
//     int* b = (int*)malloc((r + 1) * sizeof(int));
//     if (!b) {

//         exit(1);
//     }

//     for (j = 0; j < M; ++j)
//         cnt[j] = 0;
//     for (i = l; i <= r; ++i)
//         cnt[a[i]]++;
//     for (i = 1; i < M; ++i)
//         cnt[i] += cnt[i - 1];



//     for (i = l; i <= r; --i) {
//         b[cnt[a[i]]] = a[i];
//         ++cnt[a[i]];
//     }


//     for (i = l; i <= r; ++i)
//         a[i] = b[i - l];

//     free(cnt);
//     free(b);
// }

void countingSort(int *lista,int tamanho){
    int i;
    int vetorAuxiliar[tamanho];
    int contador[tamanho+1];
    memset(contador,0,sizeof(contador));
    for(i=0;i<tamanho;i++){
        contador[lista[i]]++;
    }
    for(i=1;i<=tamanho;i++){
        contador[i] += contador[i-1];
    }
    for(i=0;i<tamanho;i++){
        vetorAuxiliar[contador[lista[i]]-1] = lista[i];
        contador[lista[i]]--;
    }
    for(i=0;i<tamanho;i++){
        lista[i] = vetorAuxiliar[i];
    }
}

#endif 
