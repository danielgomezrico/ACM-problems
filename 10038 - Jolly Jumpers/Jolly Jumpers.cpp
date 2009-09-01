/* 
   Daniel Gomez Rico
   danielgomezrico@gmail.com
   2009

   10038 - Jolly Jumpers

   http://icpcres.ecs.baylor.edu/onlinejudge/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979
*/

#include <iostream>
#include <math.h>
#include <set>

using namespace std;

int main(){
  int numNumeros;
  while(cin >> numNumeros){

    int numeros[numNumeros+1];
    set<int> vResult;//Solo se deja guardar elementos unicos


    for(int i = 0; i < numNumeros; i++){
      cin >> numeros[i];
    }

    for(int i = 0; i + 1 < numNumeros; i++){
     //fabs saca valorAbsoluto
      int result = fabs(numeros[i] - numeros[i+1]);
      if(result >= 1 && result < numNumeros){
         vResult.insert(result);
      }
    }

    if(vResult.size()== numNumeros - 1){
      cout << "Jolly" << endl;
    }
    else{
      cout << "Not jolly" << endl;
    }
  
  }
     return 0;
}
