#include "dUSet.h"
#include "dSet.h"
#include "dynamicbag.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

using namespace std;

int main(){
    dUSet empty;
    cout << "EMPTY set "<< empty << endl;
    empty.insert(10);
    cout << "EMPTY set "<< empty << endl;

    DynamicBag emptyBag;
    cout << "EMPTY bag "<<emptyBag << endl;

    int size = 80;
    int tmp[size];

    for(int i = 0; i< size; i++) tmp[i] = rand() %20;
    
    DynamicBag randbag(tmp,size);
    dUSet randSet(randbag);
    cout << "bag " <<  randbag << endl;
    cout << "set " <<randSet << endl;

    cout << "INSERT tmp[0] into bag/set" << endl;
    randbag.insert(randbag[0]); 
    randSet.insert(randSet[0]); 
    randSet.insert(10); 
    randSet.insert(100); 
    randSet.insert(-100); 
    cout << "bag " <<  randbag << endl;
    cout << "set " <<randSet << endl;

    /////////////////////////////////////////////
    cout << endl << endl;
    
    dSet emptyOset;    
    dSet randOSet(randbag);
    cout << "EMPTY ordered set "<< emptyOset << endl;
    cout << "ordered set " << randOSet << endl;

    emptyOset.insert(40);
    randOSet.insert(randOSet[0]);
    randOSet.insert(100);
    randOSet.insert(-100); 
    randOSet.insert(randOSet[0]);
    cout << "EMPTY ordered set "<< emptyOset << endl;
    cout << "ordered set " << randOSet << endl;
}
