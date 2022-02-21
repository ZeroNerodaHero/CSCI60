#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//pre: two valid files' string name and a bool for
// character counter for the file
//post: reads file and writes out the inputs file's words and count
void read(string file, string outfile, bool opt=0){
    ifstream in(file); 
    ofstream out(outfile); 

    vector<pair<string,int>> v; 

    while(!in.eof()){
        string tmp;
        in >> tmp;
        if(tmp == "" || tmp == " " || tmp == "\n") {
            continue;
        }

        int i =0;
        for(; i < v.size(); i++){
            if(tmp == v[i].first){
                v[i].second++;
                break;
            }
        }

        if(i == v.size()){
            v.push_back(pair<string,int>(tmp,1));
        }
    }
    sort(v.begin(),v.end());

    for(auto it:v){
        if(opt) out << it.first << "\t" << it.second << endl;
        else out << it.first << endl;
    }
}

void readwSet(string file, string outfile){
    ifstream in(file); 
    ofstream out(outfile); 

    
    set<string> s; 

    while(!in.eof()){
        string tmp;
        in >> tmp;
        if(tmp == "" || tmp == " " || tmp == "\n") {
            continue;
        }
        if(s.find(tmp) == s.end())s.insert(tmp);
    }
    for(auto it:s){
        out << it << endl;
    }
}
int main(){
    //no count
    read("in","out");
    readwSet("in","out2");
    //with count
    read("in","outExtraCredit",1);
}

//PROBLEM 3
//If you don't need to count the counter, i would just use a set. Namely because it is simpler. 
//You ask the set if this or that exists, if it doesn't u just add it. You don't have to write a
//search function by yourself. Similarly, the question asked for it to be in sorted order. So if
//you use a vector, then you would have to manually call the sort function. But for a ordered set
//it is already done for you.
//However, since i need the extra credit, the vector is the only one available for the maping. A set
//can't do it. 
