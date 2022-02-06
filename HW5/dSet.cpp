#include "dSet.h"

dSet::dSet() : dUSet(){ }
dSet::dSet(const DynamicBag &b): dUSet(){
    for(int i = 0; i < b.size(); i++){
        insert(b[i]);
    }    
}

void dSet::insert(int target){
    int pos = 0;
    while(pos < DynamicBag::size() && (*this)[pos] <= target) {
        if( (*this)[pos] == target) return;
        pos++;
    }

    DynamicBag::insertAt(target,pos);
}


