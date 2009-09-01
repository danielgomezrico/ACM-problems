/*
     Primary Arithmetic
     PC/UVa IDs: 110501/10035

     http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=63&problem=976&mosmsg=Submission+received+with+ID+7360442

     Daniel Gómez Rico
*/

#include <iostream>
#include <string>

using namespace std;

/*Lo que hace es sumar n1 con n2, y va contando los carries que van dando, al final los retorna*/
int getNumCarries(string n1, string n2){
  string num1; //Contiene el string con menos o igual digitos de n2 con respecto a n1
  string num2;//Contiene el string con mas digitos de n2 con respecto a n1
  
  string resultado;//Contiene un string con el resutado total de la suma
  int sizeNum2;//Contiene el tamanio del numero mas grande
  
  int contCarries = 0;//EL RESULTADO QUE NECESITAMOS
  int carry = 0;//Contiene el carry de la suma
  int diff = 0;//Sabe la diferencia de tamanios entre num2 y num1 para el recorrido
  int nTemp1;//Contiene el numero para cada posicion del string num1
  int nTemp2;///Contiene el numero para cada posicion del string num2
  int rTemp;//Contiene el resultado de la suma de nTemp1 y nTemp2 para cada posicion
  
  if(n1.size() <= n2.size()){//Asignamos en num2 el numero con mayor digitos
    num1 = n1;
    num2 = n2;
  }
  else{
    num2 = n1;
    num1 = n2;
  }
  
  sizeNum2 = num2.size();
  
  resultado.resize(num2.size(), ' ');//Queda con un tamaño igual al numero con mas digitos(num2)
  diff = num2.size()  - num1.size();
    
  for(int i = sizeNum2 -1; i >= 0; i--){//Desde el tamaño mas grande hasta el minimo
    if(i-diff >= 0){
      //Dado que num1 es igual o menor de tamaño, el recorrido se nesesita que sea lineal
      nTemp1 = num1[i-diff] - 48;//se le resta -48 para obtener el valor numero y no el ascii del caracter
    }
    else{
      nTemp1 = 0;//Si ya recorrio todo el num1 entonces este ya no tiene caracteres para sumar, y se sumara 0 +  el caracter de num2
    }
    nTemp2 = num2[i] - 48;//Se obtiene el valor real y no el ascii del caracter en num2 pos i
    rTemp = nTemp1 + nTemp2 + carry; 
    
    if(rTemp >= 10){//Si es mayor a 10 hay carry
      //Le restamos 10 para obtener el primer digito, + 48 para el valor ascii y le damos el valor de 1 al carry
      resultado[i] = (rTemp - 10 )+ 48 ;
      carry = 1;
      contCarries++;
    }
    else{//No hay carry
      resultado[i] = rTemp + 48 ;
      carry = 0;
    }
  }
  //Hubo un carry al final y no hay mas numeros para sumar entonces le pone un uno al principio del resultado
  if(carry == 1){
    string uno = " ";//Va a contener el caracter con el numero 1
    uno[0] = 49;//ascii de 1 es 49
    resultado = uno + resultado;
  }
  return contCarries;
}

int main(){
  string a = "";
  string b = "";
  while(cin >>a>>b && (a != "0" || b != "0")){
    int c = 0;
    c = getNumCarries(a,b);

    if(c == 0){
      cout << "No carry operation."<<endl;
    }
    else if (c == 1){
      cout << c<<" carry operation."<<endl;
    }
    else{
      cout << c<<" carry operations."<<endl;
    }
  }
}
