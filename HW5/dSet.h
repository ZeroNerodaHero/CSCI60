#ifndef DSET_H
#define DSET_H

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "dUSet.h"

class dSet : public dUSet
{
public:
    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty dSet
    dSet();

    // constructor by DynamicBag object
    // pre: none
    // post: creates a new dSet which is a copy of the bag
    dSet(const DynamicBag &b);

    //pre: valid parameters
    //post: updated set 
    //insert target into the object if it doesn't exit
    //if exist nothing happens
    void insert(int target);
};

#endif 
