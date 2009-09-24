/*

  Status:Accepted 0.00
  374 - Big Mod
  
  http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=5&problem=310&mosmsg=Submission+received+with+ID+7427368
*/

#include <iostream>
#include <math.h>

using namespace std;

long bigmod(long b,long p,long m) {
  if (p == 0)
    return 1;
  else if (p%2 == 0)
    return ((long)pow(bigmod(b,p/2,m), 2)) % m; // square(x) = x * x
  else
    return ((b % m) * bigmod(b,p-1,m)) % m;
}

int main(){
  int b,p,m;
  
  while(cin >> b >> p >> m){
    cout << bigmod(b,p,m)<<endl;;
  }
  
  return 0;
}
