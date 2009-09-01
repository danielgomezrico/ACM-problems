
/* 
   Daniel Gomez Rico
   danielgomezrico@gmail.com
   2009

//10050 - Hartals
//http://icpcres.ecs.baylor.edu/onlinejudge/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=991

*/

#include <iostream>
#include <set>
using namespace std;

int main (int argc, char * const argv[]) {
  int numCasos;
  cin >> numCasos;
  
  for(int i = 0; i < numCasos; i++){
    int numDias = 0;
    int numPartidos = 0;
    int numDiasPerdidos = 0;
    int diaViernes = 6;//Contiene la fecha que corresponde al dia viernes
    set <int>sHartals;//Dado que no nesesitamos repetidos
    cin >> numDias >> numPartidos;
 
    for(int i = 0; i < numPartidos; i++){
      int hart;
      cin >> hart;
      sHartals.insert(hart);
    }   
        

    for(int dia = 1; dia <= numDias; dia++){
      if(dia != diaViernes && dia != diaViernes +1 ){//Si no es el dia viernes o el sabado(viernes +1)
	bool diaContado = false;
	for(set<int>::iterator it = sHartals.begin(); it != sHartals.end();it++){
	  int num = *it;  
	  if(dia % num == 0){
	    diaContado = true;
	    break;
	  }
	}
	
	if(diaContado){
	  numDiasPerdidos++;
	}
      }
      else if(dia == diaViernes + 1){	
	diaViernes += 7;
      }
    }
       cout << numDiasPerdidos << endl;
  }
}
