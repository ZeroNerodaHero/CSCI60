#include "lab6.h"
using namespace std; 

int main() {
  int array1[4] = {1, 2, 3, 4};
  npoint<int> testOne;
  npoint<int> testTwo(5);
  npoint<int> testThree(4, array1);
  string ar2[5] = {"a","a","a","a","b"};
  npoint<string> testFour(5, ar2);
}

