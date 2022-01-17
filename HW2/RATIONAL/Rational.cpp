#include "Rational.h"

int Rational::gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void Rational::reduce(){
    int dd = gcd(numer_,denom_);
    numer_ /= dd;
    denom_ /= dd;
}



Rational::Rational(int n, int d){//ADT Style:Constructors and getters don't need comments unless there is a precondition
  assert(d!=0);//Enforce preconditions with assert
  //If this condition is violated, stop program,
  //give error message
  numer_ = n;
  denom_ = d;
}
Rational::Rational(){
  numer_ = 0;
  denom_ = 1;
}


//pre: none
//post: Modifies this rational so it is the result of multiplying this
//Rational and the Rational passed in.
//The result is not reduced; the denominator will be the product
//of the denominators of the operands.
void Rational::operator *=(Rational b){
    numer_ = (numer_*b.numer_);
    denom_ = (denom_*b.denom_);
    reduce();
}



void Rational::operator +=(Rational b){
  numer_ = (numer_*b.denom_+b.numer_*denom_);
  denom_ = (denom_*b.denom_);
    reduce();
}


Rational operator +(Rational a, Rational b){
  Rational ans = Rational((a.numer()*b.denom()+b.numer()*a.denom()),
                      (a.denom()*b.denom()));
  ans.reduce();
  return ans;
}


Rational operator *(Rational a, Rational b){
    int d, n;
    n = (a.numer()*b.numer());
    d = (a.denom()*b.denom());
    Rational ans(n, d);
  ans.reduce();
    return ans;
}

std::ostream& operator<<(std::ostream&  out, const Rational & r){
  out<<r.numer()<<"/"<<r.denom();
  return out;

}

bool operator==(const Rational & l,const Rational & r){
    return l.numer() * r.denom() == r.numer() * l.denom();
}

