/* 
   Daniel Gomez Rico
   danielgomezrico@gmail.com
   2009

   10082 - WERTYU
   
   http://icpcres.ecs.baylor.edu/onlinejudge/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=12&problem=1023&mosmsg=Submission+received+with+ID+7105843
 */


#include<iostream>
#include<string>
#include <cstring>

using namespace std;

string teclado = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//Teclas del teclado en orden
string tecReal = "21234567890-WQWERTYUIOP[]SASDFGHJKL;XZXCVBNM,. ";//Tecla a la izquierda de cada tecla
int tecladoLen = 46;

int main()
{
  string line;
  while(getline(cin, line)){
    int lineLen = line.size();
    for(int i = 0; i < lineLen; i++){
      if(line[i] == ' ') continue;

      for(int j = 0; j < tecladoLen; j++){
	if(teclado[j] == line[i]){
	  line[i] = tecReal[j];
	  break;
	}
      }
    }
    cout << line<<endl;
  }
  return 0;
}
