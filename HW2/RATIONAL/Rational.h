#ifndef RATIONAL_H
#define RATIONAL_H


#include <string>//ADT Style:  no using namespace std
#include <iostream>
#include <cassert>
class Rational{
public:
    //pre:  this has to be a valid rational class 
    //post: Reduces the rational fraction down to lowest denominator possible
    void reduce();

    //Pre-condition:  d is not 0
    Rational(int n, int d);
    Rational();

    int numer() const{  return numer_; }//ADT Style:give the getter the variable name minus the _
    int denom() const{  return denom_; }

    //pre: none
    //post: Modifies this rational so it is the result of multiplying this
    //Rational and the Rational passed in.
    //The result is not reduced; the denominator will be the product
    //of the denominators of the operands.
    void operator *=(Rational b);

    //pre: none
    //post: Modifies this rational so it is the result of adding this
    //Rational and the Rational passed in.
    //The result is not reduced; the denominator will be the product
    //of the denominators of the operands.
    void operator +=(Rational b);


  private:
      int numer_;//ADT Style: trailing _ means this is a private variable
      int denom_;

    static int gcd(int a, int b);
};
//pre: none
//post: returns a Rational that is the result of adding this
//Rational and the Rational passed in.
//The result is not reduced; the denominator will be the product
//of the denominators of the operands.
Rational operator +(Rational a, Rational b);

//pre: none
//post: returns a Rational that is the result of multiplying this
//Rational and the Rational passed in.
//The result is not reduced; the denominator will be the product
//of the denominators of the operands.
Rational operator *(Rational a, Rational b);

//pre:  none
//post:  Prints out the Rational as numerator/denominator
std::ostream& operator<<(std::ostream&  out, const Rational & r);


//pre:  both l and r must be Rational objects
//post:  returns a bool of wehther or not the two objects are equal
bool operator ==(const Rational & l,const Rational & r);

#endif
