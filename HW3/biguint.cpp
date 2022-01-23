#include "biguint.h"

biguint::biguint(){
    for(int i = 0; i < CAPACITY; i++) data_[i] = 0;
}

biguint::biguint(const std::string &str){
    for(int i = 0; i < CAPACITY; i++){
        if(i < str.size()) data_[i] = str[str.length()-i-1]-'0';
        else
            data_[i] = 0;
    }
}

unsigned short biguint::operator [](std::size_t pos) const{
    assert(pos < CAPACITY);
    return data_[pos];
}

std::ostream& operator <<(std::ostream& out, const biguint& b){
    for(int i = biguint::CAPACITY-1; i >= 0; i--){
        out << b[i];
    }
    return out;
}

void biguint::operator += (const biguint & b){
    bool carry = 0;
    for(int i = 0; i < CAPACITY; i++){
        data_[i] += b[i] + carry;
        if(data_[i] > 9){
            data_[i] -= 10;
            carry = 1;
        } else{
            carry = 0;
        }
    }
}

biguint operator + (const biguint &l, const biguint &r){
    biguint nnum = l;
    nnum += r;
    return nnum;
}

// pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
int biguint::compare(const biguint & b) const{
    for(int i = CAPACITY-1; i >= 0; i--){
        if(b[i] != data_[i]){
            return (data_[i] > b[i]) ? 1 : -1;
        }
    }
    return 0;
}

bool operator < (const biguint &l, const biguint &r)
{return l.compare(r) == -1 ? true : false;}
bool operator <= (const biguint &l, const biguint &r)
{return l.compare(r) <= 0 ? true : false;}
bool operator != (const biguint &l, const biguint &r)
{return l.compare(r) == 0 ? false : true;}
bool operator == (const biguint &l, const biguint &r)
{return l.compare(r) == 0 ? true : false;}
bool operator >= (const biguint &l, const biguint &r)
{return l.compare(r) >= 0 ? true : false;}
bool operator > (const biguint &l, const biguint &r)
{return l.compare(r) == 1 ? true : false;}

void biguint::operator -= (const biguint & b){
    assert(*this >= b);
    int last = 0;
    for(int i = CAPACITY-1; i >= 0; i--){
        if(data_[i] < b[i]){
            data_[last]--;
            data_[i] += 10;
            for(int j = last-1; j > i; j--) data_[j]=9;
        }
        data_[i] -= b[i];
        if(data_[i] != 0) last = i;
    }
}

biguint operator - (const biguint &l, const biguint &r){
    biguint tmp = l;
    tmp -= r;
    return tmp;
}

std::string biguint::toString(){
    std::string tmp ="";
    for(int i = biguint::CAPACITY-1; i >= 0; i--){
        tmp += '0'+data_[i];
    }
    return tmp;
}
