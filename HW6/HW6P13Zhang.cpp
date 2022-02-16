#include <iostream>
using namespace std;

//PART 1
template<typename T>
//Pre: valid parameters
//Post: returns + difference
//in order for abs to run, it needs to 
//support (-) and (>)
T abs(T a, T b){
    return (a-b > b-a) ? a-b : b-a;
}

//PART 3
template<typename T1>
//Pre: valid array
//Post: return most frequent element
//returns the first thing in the list if none
//
//in order to support this function, you need
// a == operator only
T1 frequent(T1 a[], std::size_t size){
    //visited array
    bool v[size]; 
    int cnt = 0;
    T1 ret = a[0];
    for(int i = 0; i < size; i++){
       v[i] = 0; 
    }

    for(int i = 0; i < size; i++){
        if(v[i]) continue;
        int tmpCnt = 0;
        for(int j = i+1; j < size; j++){
            if(a[i] == a[j]){
               tmpCnt++; 
                //if visited never touch again
                v[j] = 1;
            }
        }

        if(cnt < tmpCnt){
            cnt = tmpCnt;
            ret = a[i];
        }
    }
    return ret;
}


template<typename T>
//prints stuff
void print(T a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << ' ';
    } cout << endl;
}

int main(){
    cout << abs(1,2) << endl;
    cout << abs(2.0,3.67) << endl;
    cout << abs(20.08,3.67) << endl;
    
    cout << endl << endl;
    cout << "Testing Freq " << endl;
    srand(time(NULL));
    
    int size = 20;
    int tint[size];
    double tdou[size];

    for(int i = 0; i < size; i++){
        tint[i] = rand()%15;
        tdou[i] = rand()%15+0.1*(rand()%10);
    }
    print(tint,size); 
    cout << "tint freq: " << frequent(tint,size) << endl;
    print(tdou,size); 
    cout << "tdou freq: " << frequent(tdou,size) << endl;

    string tstr[6] = {"a","a","a","b","b","c"};
    print(tstr,6); 
    cout << "tstr freq: " << frequent(tstr,6) << endl;
    string tstr2[8] = {"a","a","a","b","b","c","b","b"};
    print(tstr2,8); 
    cout << "tstr freq: " << frequent(tstr2,8) << endl;
}

