#ifndef DUSET_H
#define DUSET_H

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "dynamicbag.h"

class dUSet : public DynamicBag
{
public:
    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty dUSet
    dUSet();

    // constructor by DynamicBag object
    // pre: none
    // post: creates a new dUSet which is a copy of the bag
    dUSet(const DynamicBag &b);

    //pre: valid parameters
    //post: updated set 
    //insert target into the object if it doesn't exit
    //if exist nothing happens
    void insert(int target);

};

#endif 
