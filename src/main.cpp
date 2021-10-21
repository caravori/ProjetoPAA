#include "bucket.h"
#include "counting.h"
#include "insertion.h"
#include "mergesort.h"
#include "numGen.h"
#include "quicksort.h"
#include "shell.h"
#include <stdio.h>
#include <chrono>
#include <vector>

int main (int argc, char **argv){
    int flag = 0;
    int num = atoi(argv[1]);
    std::vector<int> data;
    data.reserve(num);

    switch (atoi(argv[2])){
    case 1:
        data = gerador(num,false,false);
        flag = 1;
        break;
    case 2:
        data = gerador(num,true,false);
        flag = 2;
        break;
    case 3:
        data = gerador(num, true,true);
        flag = 3;
        break;
    default:
        printf("Argumento 2 é definido para, desordenado(1),ordenado(2),reverso(3)");
        exit(1);
        break;
    }

    int *datinha = data.data();

    FILE *fp = fopen("data.out", "a");

    switch (atoi(argv[3])){
        case 1:{
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            insertion(datinha,num);
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            printf("Tempo: %f\n",time_span.count());
            fprintf(fp,"Insertion;%d;%f;%d;",flag,time_span.count(),num);
             
           break;
        }
        case 2:{ 
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            shell(datinha,num);
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            printf("Tempo: %f\n",time_span.count());
            fprintf(fp,"Shell;%d;%f;%d;",flag,time_span.count(),num); 
            break;
        }
        case 3: {
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            mergeSort(datinha,num);
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();         
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            printf("Tempo: %f\n",time_span.count());
            fprintf(fp,"Merge;%d;%f;%d;",flag,time_span.count(),num);
            break;
        }
        case 4: {
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            quicksort(data,0,num-1);
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            printf("Tempo: %f\n",time_span.count());
            datinha = data.data();
            fprintf(fp,"Quick;%d;%f;%d;",flag,time_span.count(),num);
            break;
        }
        case 5:{
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            bucketSort(datinha,num);
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            printf("Tempo: %f\n",time_span.count());
            fprintf(fp,"Bucket;%d;%f;%d;",flag,time_span.count(),num);
            break;
        }
        case 6:{
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            countingSort(datinha,num);
            std::chrono::high_resolution_clock::time_point t2 =  std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            printf("Tempo: %f\n",time_span.count());
            fprintf(fp,"Counting;%d;%f;%d;",flag,time_span.count(),num);
            break;
        }
        default:
            printf("Numero inserido inválido. Argumento 3, insertion(1), shell(2), Merge(3), quick(4), bucket(5) e counting(6)");
            exit(1);
            break;
    }
    
    return 0;
}