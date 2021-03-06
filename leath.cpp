#include "leath.h"
#include "lattice.h"
#include "pseudodes.h"

Leath::Leath(unsigned long int m, unsigned long long int * seed, double p): h(Hashing(m)), seed(Vertice(seed, 0)){
    h.insert(& (this->seed));
    occupiedQueue.push(this->seed);
    this->p = p;
}

unsigned long long int Leath::setMask(unsigned int mask_shift){
    unsigned long long int mask = 1;
    mask = mask << (Lattice::getD() -1);
    mask = mask >> mask_shift;
    return mask;
}

void Leath::visit(Vertice v, bool plusorminus){
    unsigned long long int R_bar;
    unsigned long long * x = v.getX();
    for(unsigned int i = 0; i < Lattice::getD(); i++){
        if(x[i]+1 >= Lattice::getL()[i] && x[i]+1 <= 0) break;
        if(plusorminus) x[i] += 1;
        else x[i] -= 1;
        Vertice node = Vertice(x, v.getCS()+1);
        node.setBitmap(setMask(i));
        if(h.insert(&node)){
            R_bar = PseudoDES::psdes(((PseudoDES::psdes(v.getN()) * Lattice::getD()) + i) * MAX + Leath::m);
            if(R_bar < Hashing::pow2(63)*(2*this->p)){
                this->occupiedQueue.push(v);
            }
        }
        if(plusorminus) x[i] -= 1;
        else x[i] += 1;
    }
}




unsigned long long Leath::getM(){
    return Leath::m;
}

void Leath::addM(){
    Leath::m++;
}
unsigned long long int Leath::m = 0;
