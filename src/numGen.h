#ifndef NUMGEN_H
#define NUMGEN_H
#include <algorithm>
#include <vector>
#include <random>

std::vector<int> gerador(int n,bool ordenado, bool reverse){
    std::vector<int> data;
    data.reserve(n);
    if(reverse){
        for(int i = n; i != 0; i--){
            data.push_back(i);
        }
    }
    else{
        for(int i = 0; i < n; i++)
        data.push_back(i);
    }

    if(!ordenado){
        std::random_device rd;
        std::shuffle(data.begin(),data.end(),rd);
    }

    return data;
}
#endif // NUMGEN_H
