#include "heap.h"
#include <vector>

Heap::Heap(std::vector<long>& d){
    this->pq.push_back(-1);
    this->dist = d;
}

long Heap::size(){
    return this->pq.size()-1;
}

bool Heap::bigger(long i, long j){
    return this->dist[this->pq[i]] > this->dist[this->pq[j]];
}

void Heap::exch(long i, long j){
    long temp = this->pq[i];
    this->pq[i] = this->pq[j];
    this->pq[j] = temp;
}

void Heap::swim(long k){
    while (k > 1 && this->bigger(k/2, k)) {
        this->exch(k/2, k);
        k = k/2;
    }
}

void Heap::sink(long k){
    long j;
    while (2*k < (this->size())) {
        j = 2*k;
        if ((j < this->size()) && this->bigger(j, j+1)) {
            j++;
        }
        if (this->bigger(j, k)){
            break;
        }
        this->exch(k, j);
        k = j;
    }
}

void Heap::insert(long v){
    this->pq.push_back(v);
    this->swim(this->size());
}

long Heap::get_min(){
    long min = this->pq[1];
    this->exch(1, this->size());
    this->pq.erase(this->pq.end()-1);
    this->sink(1);
    return min;
}
