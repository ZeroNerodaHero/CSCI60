#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//pre: needs an input file
//post: prints a histogram and asks for usr input
//for number of people
//assumes:
//proper format, file contains at least 1 person
void read(string file){
    ifstream in(file);
    int maxS = INT_MIN, minS = INT_MAX;

    map<int,pair<int,vector<string> > > m;

    //assumes format:
    //integer for score and then a space and then a string
    //score name
    while(!in.eof()){
        string name;
        int score = 0;

        getline(in,name);
        if(name == "") continue;

        //iterate to get number. stops at first ' '
        int ll = 0;
        for(; ll < name.size() && name[ll] != ' '; ll++){
            score = score*10+(name[ll]-'0');
        }
        name = name.substr(ll+1); 
//cout << score << " " << name << endl;
            

        minS = min(minS,score);
        maxS = max(maxS,score);

        if(m.find(score) == m.end()){
            m[score]={1,vector<string>()};
            m[score].second.push_back(name);
        } else{
            m[score].first++;
            m[score].second.push_back(name);
        }
    }

    for(int i = minS; i <= maxS; i++){
        cout << i << " ";
        if(m.find(i) != m.end())
            for(int j = 0; j < m[i].first; j++) cout << "x";
        cout << endl;
    }

    cout << endl <<endl;
    while(1){
        cout << "Enter Number: " << endl;
        int num;
        cin >> num;
    
        if(m.find(num) != m.end()){
            for(int i = 0; i< m[num].second.size();i++) 
                cout <<((i == 0) ? "":",")<< m[num].second[i];
            cout << endl;
        }
    }
}

int main(){
    read("in2");
}
