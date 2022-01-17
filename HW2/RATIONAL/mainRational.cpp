#include "Rational.h"
using namespace std;
int main(){
    Rational r1(1,2);
    Rational r2(1,3);
    Rational r3(9,18);

    cout << r1 << "==" << r2 << " ? " << (r1 == r2) << endl;
    cout << r1 << "==" << r3 << " ? " << (r1 == r3) << endl;
    cout << r1 << "==" << r1 << " ? " << (r1 == r1) << endl;

    cout << r3 << " reduced ";r3.reduce(); cout<<r3<< endl;
    Rational r4(91,18);
    cout << r4 << " reduced ";r4.reduce(); cout<<r4<< endl;
    Rational r5(81,18);
    cout << r5 << " reduced ";r5.reduce(); cout<<r5<< endl;

    cout << r1 << "+=" << r3 << "=>";r1+=r3; cout<<r1<< endl;
    r2=Rational(4,10);
    cout << r2 << "*=" << r3 << "=>";r2*=r3; cout<<r2<< endl;
    cout << r1 << "+" << r3 << "=" << (r1+r3)<< endl;
    cout << r1 << "*" << r3 << "=" << (r1*r3)<< endl;
}
