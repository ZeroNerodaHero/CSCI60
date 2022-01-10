#include <iostream>
#include <fstream> 
using namespace std;

#define debug 0

/*---------------PROBLEM 2 ---------------------*/

/*
This is the animal structure
*/
struct Animal{
    string name, gender,dorc;
    int age,price;
};

/*
returns the cheapest animal. the string t is the condition
for what type of animal. 
pre: none
post: returns animal
*/
Animal cheapest(string t, Animal a[], int s){
    int minP = INT_MAX, pos = -1;
    for(int i = 1; i < s; i++){
        if(a[i].dorc == t && a[i].price < minP){
            minP = a[i].price;
            pos = i;
        }
    }
    //we assume there is always answer
    //return (pos == -1) ? NULL : a[pos];
    return a[pos];
}

/*
returns whether or not the animal can live together.
pre: none
post: a boolean
*/
bool livetogether(Animal a, Animal b){
    return a.dorc == b.dorc;
}

void problem2(string file, string fileout){
    /*
    input format
    N
    type price

    where N is the number of animals and price is listed
    also type. see file if include?
    */

    ifstream in(file);
    ofstream out(fileout);

    int N;
    in >> N; 

    Animal oo[N];
    
    for(int i = 0; i < N; i++){
        in >> oo[i].dorc >> oo[i].price;
#if debug
        cout << oo[i].dorc << " " << oo[i].price;
#endif
    }
    
    
    Animal aaa = cheapest("Cat", oo,N);
    out << "Cheap cat " << aaa.price << endl;
    Animal bbb = cheapest("Dog", oo,N);
    out << "Cheap dog " << bbb.price << endl;

    
    //test opposite case
    out << livetogether(aaa,bbb) << endl;
    //test same case
    out << livetogether(aaa,aaa) << endl;
}

int main(){
    problem2("in2","out2");
}
