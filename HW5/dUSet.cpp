#include "dUSet.h"
#include <cstring>
using namespace std;

dUSet:: dUSet() : DynamicBag(){ }
dUSet:: dUSet(const DynamicBag &b): DynamicBag(b){
    //tmp -> stores the count of occurances of character
    //num -> stores the number because things will be deleted and cant get that back without tmp
    //v -> stores visited. ie only one copy will have true count(earliest)
    int cSize = b.size();
    int tmp[cSize], num[cSize];
    bool v[cSize];
    for(int i = 0; i < DynamicBag::size(); i++) v[i] = 0, num[i] = (*this)[i];

    //counts the occurances
    for(int i = 0; i < DynamicBag::size(); i++){
        tmp[i] = 1;
        if(v[i]) continue; 
        for(int j = i+1; j < DynamicBag::size(); j++){
            if((*this)[i]==(*this)[j]){
                v[j] = 1;
                tmp[i]++;
            } 
        }
    } 

    //deletes the occurances
    for(int i = 0; i < cSize; i++){
        while(!v[i] && tmp[i] > 1){
            DynamicBag::erase_one(num[i]);
            tmp[i]--;
        }
    }
}

/*
I just do a linear search
if it exist exit
if doesn't insert via parent
exit
*/
void dUSet::insert(int target){
    for(int i = 0; i < DynamicBag::size(); i++){
        if((*this)[i] == target) return;
    } 
    DynamicBag::insert(target);
}
