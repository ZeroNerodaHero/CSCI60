#include <iostream>
#include <fstream> 
using namespace std;

#define debug 0

/*---------------PROBLEM 1 ---------------------*/
/*
This iterates through the array and returns the occurance of the 
names with the starting letter of l.
I don't know what the conditions are for the name. Can it be lower 
case or not? If yes is lower case larger or smaller than upper or the same?
For my case, i think lower case names and upper case names are the same.

pre: nothing
post: outputs all occurance to the stream
*/
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

/*
this reads the problem file. call the function with
an input file and output file.

pre: needs file names
post: nothing
*/
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


int main(){
    problem1("in","out");
}
