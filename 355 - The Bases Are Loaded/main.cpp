/*
Daniel Gomez Rico
danielgomezrico@gmail.com
September 23 2009

355 - The Bases Are Loaded
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=5&page=show_problem&problem=291
Status: Accepted
*/

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>


using namespace std;

int getNumValue(char c);
unsigned long long int toBase10(string n, int b);
string itos(int n);
string toBaseB(unsigned long long int n, int b, int size);
bool isLegal(string n, int b);

/*
  Return the number value of A or a like 10, of B or b like 11, etc... 
  (only letters and numbers)
*/

int getNumValue(char c){
  if(c >= 'A'){
    return c - 55;
  }
  else{ return c - '0';}
}

//return the number n base b in base 10
unsigned long long int toBase10(string n, int b){
  unsigned long long res = 0;
  int size = n.size();
  for(int i = 0; i < size; i++) {
    res += getNumValue(n[size-1-i])*pow(b,i);
  }
  return res;
}


string itos(int n){
  stringstream ss;
  ss << n;
  return ss.str();
}


//return n in base b (where n is decimal base) and size is the number of digits of n
string toBaseB(unsigned long long int n, int b, int size){
  string res;
  unsigned long long int div = n;
  
  for(int i = 0; div != 0; i++){
    int dTemp = div%b;
    if(dTemp >= 10){
      res += (char)(dTemp+55);
    }
    else{
      res += itos(dTemp);
    }
    div = div/b;
  }
  return res;
}

//Returns true if n is a legal base b number, else otherwise
bool isLegal(string n, int b){
  int size = n.size();
  for(int i = 0; i <size; i++ ){
    if(getNumValue(n[i]) >= b) return false;
  }
  return true;
}



int main(){
  string n; 
  int b1, b2;
  unsigned long long  int decimal = 0;
  string res;

  while(cin >>b1>>b2>>n){

    if(isLegal(n, b1)) {
      decimal =  toBase10(n, b1);
     
      if(b1 != b2){ 
	
	res = toBaseB(decimal, b2, n.size());

	if(res == "") res = "0";

	cout << n << " base "<< b1 << " = "; 
	for(int i = res.size()-1; i>= 0; i--){
	  cout << res[i];
	}
	cout << " base "<<b2<<endl;

      }
      else{ 
	cout << n << " base "<< b1 << " = " << n << " base "<<b2<<endl;
      }

      
    }
    else cout << n << " is an illegal base "<<b1 << " number"<<endl;

  }
  return 0;
}
