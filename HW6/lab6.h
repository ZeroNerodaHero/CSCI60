// lab 6 pt 2 HEADER FILE
// Benny Garver & Billy Zhang
#ifndef NPOINT_H
#define NPOINT_H
#include <iostream>
#include <cmath>

template <typename T>
class npoint {
private:
  T array[10];
  int dimension;
public:
  // default constructor
  // pre: nada
  // post: new npoint object
  npoint();

  // pre: dimensions
  // post: new npoint object with right dimensions
  npoint(int xDimension);

  // pre: dimensions and array size
  // post: new npoint object with right parameters

  npoint(int xDimension, T xArray[]);

  // pre: valid other npoint object
  // post: sets everything to other object
  void operator=(const npoint<T> &other);

  // pre: valid  npoint object
  // post: return ith item
  T geti(int xDimension);

  // pre: valid  npoint object
  // post: returns size
  int getSize();

    //bad tabbing incoming
    //pre: valid parameters
    //post: edits this array so that this includes
    //other's items in sequential order. behavior follows lab
    //types must support + operation
    void operator +=(npoint<T> &other);

    //pre: valid parameters
    //post: returns a new npoint that copies behavior of += listed in
    //lab
    //types must support + and = operation
    npoint<T> operator +(npoint<T> &other);
    //pre: valid parameters
    //post: returns whether or not dimensions are equal and each element
    //is also equal
    //type T must support ==
    bool operator ==(npoint<T> &other);
};

//non-member functions


//pre: two npointers of the same size
//post: returns the distance forumla of the two pointers
//types need to support subtraction only.
template <typename T>
int dist(npoint<T> a, npoint<T> b);

//pre: valid strings with size > 0
//post: returns the difference between a[0] and a[1];
int operator-(std::string a, std::string b);

#endif

