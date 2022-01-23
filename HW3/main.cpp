#include "biguint.h"
using namespace std;

int main(){
    biguint empty = biguint();
    string num = "12345";
    biguint n1 = biguint(num);
    num = "99999";
    biguint n2 = biguint(num);

    cout << empty << endl;
    cout << n1<< endl;

//    cout << n1[200] << endl;

    empty += n2;
    cout << empty << endl;
    empty += n2;
    cout << empty << endl;
    cout << empty + empty << endl;

    cout << n1 << " < " << n2 << "\t ->" << (n1 < n2) << endl;
    cout << n1 << " > " << n2 << "\t ->" << (n1 > n2) << endl;
    cout << n1 << " <= " << n2 << "\t ->" << (n1 <= n2) << endl;
    cout << n1 << " >= " << n2 << "\t ->" << (n1 >= n2) << endl;
    cout << n1 << " != " << n2 << "\t ->" << (n1 != n2) << endl;

    cout << n1 << " == " << n2 << "\t ->" << (n1 == n2) << endl;
    cout << n1 << " == " << n1 << "\t ->" << (n1 == n1) << endl;

    cout << n1 << " >= " << n1 << "\t ->" << (n1 >= n1) << endl;

    cout << "BEFORE " << empty << "\t-= " << n2 << "->";
    empty -= n2;
    cout << empty << endl;
    empty -= empty;
    cout << empty << endl;
    cout << n2 << "-" << n1 << "=" << n2-n1<< endl;
    cout << "TO STRING " << n2.toString() << endl;;
    cout << "TO STRING " << (n2-n1).toString() << endl;;
}
