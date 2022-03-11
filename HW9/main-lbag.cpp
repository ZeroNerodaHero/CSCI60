#include <iostream>
#include "lbag.h"
using namespace std;

int main(int argc, char *argv[])
{
  LBag<int> b, d;
  b.insert(5);
  b.insert(2);
  b.insert(7);
  b.insert(1);
  d = b;
  d.insert(5);
  LBag<int> a(d);

/* HOMEWORK */
    cout << "b ->" << b << endl;
    cout << "d ->" << d << endl;
    cout << "b + d = " << (b+d) << endl;
    b+=d;
    cout << "b += d ->" << b << endl;
    cout << "empty case" << endl;;
    LBag<int> c;
    cout << "nada + b = " << (c+b) << endl;
    
    cout << endl << endl << endl;
    
    for(int i = 0; i < 6; i++){
        LBag<int> tmp(b);
        cout << "erase " << i << "----- \t" << b << endl;
        cout << b.erase_one(i) << " : ";
        cout << b << endl;

        cout << "erase all" << endl; 
        cout << tmp.erase(i) << " : " << tmp << endl << endl;
    }



    return 0;
}
