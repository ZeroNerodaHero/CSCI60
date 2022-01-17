#include "Rational.h"
using namespace std;//Note:  the error at the end of class 1/12 was caused by a missing semicolon after the forward declaration of the << overload in Rational.h
void hello();
int main(){
  int a[4] = {1, 2, 3, 4};
  string s = "hi";
  s="hello";
  Rational r1 = Rational(1, 2), r2(3, 4);
  Rational r;
  //cout<<hello();//error
  Rational r3 = r1 * r2;//r1.mult(r2);
  cout<<4*5<<endl;
  double x=4.5, y=9.8;
  cout<<x*y<<endl;
  x*=y;//x = x*y;
  cout<<x<<endl;
  Rational r5 = r1+r3;
  cout<<r3<<endl;
  cout<<r3;
  cout<<endl;


  cout<<r3.numer()<<"/"<<r3.denom();
  r1*=r2;//r1 should hold the result of multiplying r1 and r2

}

void hello(){
  cout<<"hello"<<endl;
}
