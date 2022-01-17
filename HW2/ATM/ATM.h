#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <cassert>
#include "BANK/bankaccount.h"


class ATM{
    public:
        //pre: none
        //post: 
        ATM(int twenty,int ten):
            twenty(twenty),ten(ten) {total=twenty*20+ten*10;} 
        ATM():
            twenty(0),ten(0) {total=0;}

        //pre: none
        //post: returns int of number of bills
        int getTwenty(){return twenty;}
        int getTen(){return ten;}

        //pre: valid bank account and 
        //post: returns a new bankaccount with the amount of 
        //money set
        BankAccount get_cash(int amount, BankAccount b);

        //pre: valid ATM
        //post: the bills from rhs is transfered to this ATM.
        //rhs doesn't lose the bills
        void operator +=(ATM& rhs);

        //pre: valid parameters
        //post: this ATM adds the bills to its own. 
        void restock(int new20s, int new10s);
    private:
        int twenty,ten,total;
};

//pre: valid parameters
//post: this ATM adds the bills to its own. 
bool operator ==(ATM lhs, ATM rhs);
        
//pre: valid parameters
//post: returns the number of bills(10,20) and the total money
std::ostream& operator <<(std::ostream& out, ATM a);
#endif
