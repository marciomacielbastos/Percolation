#ifndef LEATH_H
#define LEATH_H
#include "hashing.h"
#include "vertice.h"
#include <queue>


class Leath{
private:
    Hashing h;
    Vertice seed;
    std::queue<Vertice> occupiedQueue;


public:
    Leath(long int m, unsigned long long int * seed);
    unsigned long long int setMask(int i);
    bool run();
};

#endif // LEATH_H
