#include "lab6.h"
using namespace std; 

int main() {
  int array1[4] = {1, 2, 3, 4};
  npoint<int> testOne;
  npoint<int> testTwo(5);
  npoint<int> testThree(4, array1);
  string ar2[5] = {"a","a","a","a","b"};
  npoint<string> testFour(5, ar2);

    cout << "one: empty\t"; print(testOne); 
    cout << "two: only dimensions\t"; print(testTwo); 
    cout << "three: double para\t"; print(testThree); 
    cout << "four: string\t"; print(testFour); 
  npoint<string> testFive = testFour;
  npoint<int> testSix = testThree;
    cout << "five: equal string\t"; print(testThree); 
    cout << "six: equal int\t"; print(testFour); 

    //+= 
    testFour += testFour;
    cout << "testing += on str of same cap \t"; print(testFour);
    string ar3[6] = {"a","a","a","a","b","z"};
    npoint<string> test7(6, ar3);
    testFour += test7;
    cout << "testing += on str of diff cap \t"; print(testFour);
    test7 += testFour;
    cout << "testing += on str of diff cap, small first \t"; print(test7);
    
    //test + and == 
    cout << " testing + \t";print(test7+testFour);
    cout << " testing + double\n";print(test7);print(test7+test7);
    cout << endl;
    cout << "t7 == t7 ? ==>"<<((test7) == (test7)) << endl;
    cout << "t7 == t4 ? ==>"<<(test7 == testFour) << endl;

    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    npoint<int> t1(10, a1);
    int a2[10];
    for(int i = 0; i < 10; i++){
        a2[i] = 0;    
    }
    npoint<int> t2(10, a2);
    cout << dist(t1,t2) << endl;
    cout << dist(test7,testFour) << endl;
    cout << dist(test7,test7) << endl;

    //test str
    string ar5[6] = {"a","b","c","d","e","f"};
    npoint<string> d1(6, ar5);
    string ar6[6] = {"b","c","d","e","f","g"};
    npoint<string> d2(6, ar6);
    //should be sqrt(6) = 2
    cout << dist(d1,d2) << endl;
      return 0;
}

