#include "ATM.h"
#include "BANK/bankaccount.h"


BankAccount ATM::get_cash(int amount, BankAccount b){
    if(amount%10!=0){
        std::cout <<"Cannot give less than $10bill"<< std::endl;
        return BankAccount();
    }
    if(amount > total){
        std::cout <<  "ATM doesn't have enough money" << std::endl;;
        return BankAccount();
    }   
    b.deposit(amount);
    int b20 = std::min(amount / 20,twenty);
    amount -= b20 * 20;
    int b10 = amount/10;
    
    twenty -= b20;
    ten -= b10;
    ATM tmp(b20,b10);
    std::cout << "YOU WILL RECIEVE " << tmp << std::endl;
    std::cout << b << std::endl;
    return b;
}

void ATM::operator +=(ATM& rhs){
    twenty += rhs.getTwenty();
    ten += rhs.getTen();
}

void ATM::restock(int new20s, int new10s){
    twenty += new20s;
    ten += new10s;
}


bool operator ==(ATM lhs, ATM rhs){
    return 
        lhs.getTwenty() == rhs.getTwenty() && 
        lhs.getTen() == rhs.getTen();
}
        
std::ostream& operator <<(std::ostream& out, ATM a){
    out << "ATM TWENTY: " << a.getTwenty() 
        << "\tTEN: " << a.getTen()
        << "\tAMOUNT: " << a.getTen()*10 + a.getTwenty()*20;
    return out;
}
