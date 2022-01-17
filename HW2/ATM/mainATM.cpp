#include "ATM.h"
using namespace std;

int main(){
    ATM empty = ATM();            
    ATM atm1 = ATM(10,10);            
    cout << "TESTING CONSTRUCTOR" <<endl;
    cout << empty << endl;
    cout << "GETTERS: " <<empty.getTwenty() << " - " << empty.getTen() << endl;
    cout << endl;
    cout << atm1 << endl;
    cout << "GETTERS: " <<atm1.getTwenty() << " - " << atm1.getTen() << endl;
    cout << endl;

    //test get_cash
    cout << "" <<endl;
    cout << "BANK CASH" <<endl;
    BankAccount b(1,1,1,"b");
    BankAccount c(10,10,10,"c");
    cout << c << endl;
    cout << endl;

    cout << "" <<endl;
    cout << "TESTING GETCASH" <<endl;
    b=atm1.get_cash(10000,b);
    cout << b << endl;
    cout << endl;

    c=atm1.get_cash(100,c);
    c=atm1.get_cash(150,c);

    //test restock
    cout << "" <<endl;
    cout << "TESTING RESTOCK ON EMPTY 20,20" <<endl;
    empty.restock(20,20);
    cout << empty << endl << endl;
    
    //test +=
    cout << "" <<endl;
    cout << "TESTING +=" <<endl;
    cout << atm1<< "+="<<empty << "=>"<< endl;
    atm1+=empty;
    cout << atm1 << endl;

    //test == 
    cout << endl;
    cout << "TESTING ==" <<endl;
    cout << atm1 << "=="<< empty << " ? " <<endl<<(atm1==empty) << endl;
    ATM atm2 = ATM(20,25);
    cout << atm1 << "=="<<atm2 << " ? " <<endl<<(atm1==atm2) << endl;
    //ostream already tested
}
