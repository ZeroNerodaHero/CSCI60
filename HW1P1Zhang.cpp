#include <iostream>
#include <fstream> 
using namespace std;

#define debug 0

/*---------------PROBLEM 1 ---------------------*/
void writeletter(string ns[], int s, char l, ostream& out){
    for(int i =0; i < s; i++){
#if debug
        if(ns[i][0] == l+'a' || ns[i][0] == l+'A'){
            cout << l+'A' << " " << ns[i] << endl;
        }
#endif
        if(ns[i][0] == l+'a' || ns[i][0] == l+'A')
            out << ns[i] << endl;
    }
}

void problem1(string file, string fileout){
    ifstream in(file);
    ofstream out(fileout);
    string ns[50];

    int size = 0;

    while(!in.eof()){
        in >> ns[size++];
#if debug
        cout << ns[size-1] << endl;
#endif
    } 

    //tis right? first letter cap?
    for(char i = 0; i < 26; i++){
        writeletter(ns,size,i,out);
    }
}


/*---------------PROBLEM 2 ---------------------*/
struct Animal{
    string name, gender,dorc;
    int age,price;
};

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

bool livetogether(Animal a, Animal b){
    return a.dorc == b.dorc;
}

void problem2(string file, string fileout){
    /*
    input format
    N
    type price
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
    problem1("in","out");
    problem2("in2","out2");
}
