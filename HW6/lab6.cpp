#include "lab6.h"
#include <iostream>
#include <cmath>
using namespace std;

// default constructor
template <typename T>
npoint<T>::npoint() {
    dimension = 0;
}
// takes in the dimension
template <typename T>
npoint<T>::npoint(int xDimension) {
    dimension = xDimension;
}
// takes all parameters
template <typename T>
npoint<T>::npoint(int xDimension, T xArray[]) {
    dimension = xDimension;
    for(int i = 0; i < xDimension; i++)
        array[i] = xArray[i];
}

// A single getter that returns the ith item in the tuple
template <typename T>
T npoint<T>::geti(int xDimension) {
    return array[xDimension];
}

// A getter for the size
template <typename T>
int npoint<T>::getSize() {
    return dimension;
}

// overload = operator
// the type variable needs to support the = operator
template <typename T>
void npoint<T>::operator=(const npoint<T> &other) {
  dimension = other.dimension;
  for(int i = 0; i < dimension; i++)
    array[i] = other.geti(i);
}

//void print function
template <typename T>
void print(npoint<T> np){
    for(int i = 0; i< np.getSize(); i++){
        cout << np.geti(i) << " ";
    } cout << endl;
}
/////////////////////////////////////////////////////////
//HW6 starts here
/////////////////////////////////////////////////////////

template <typename T>
void npoint<T>::operator +=(npoint<T> &other){
    int i = 0;
    for(; i < dimension && i <other.getSize(); i++){
        array[i] += other.geti(i);
    }
    for(; i <other.getSize(); i++){
        array[i] = other.geti(i);
    }
    dimension = max(dimension,other.getSize());
}

template <typename T>
bool npoint<T>::operator ==(npoint<T> &other){
    if(dimension != other.getSize()) return false;
    for(int i = 0; i < dimension; i++){
        if(array[i] != other.geti(i)) return false;
    }
    return 1;
}

//non-member functions

template <typename T>
npoint<T> npoint<T>::operator +(npoint<T> &other){
    npoint<T> tmp = *this;
    tmp += other;
    return tmp;
}

template <typename T>
int dist(npoint<T> a, npoint<T> b){
    if(a.getSize() != b.getSize()) return -1;
    int tot = 0;
    for(int i = 0; i < a.getSize(); i++){
        tot += (a.geti(i) - b.geti(i))*(a.geti(i) - b.geti(i));
    }
    return sqrt(tot);
}

int operator-(string a,string b){
    return a[0]-b[0];
}
