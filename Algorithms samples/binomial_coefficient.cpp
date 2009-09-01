#include <iostream>

#define MAXN     100          
/*
  From n elements what posibilities are to combine 
  if i choose m elements at time?

  largest n or m 
*/
long binomial_coefficient(int n,int m)
                         /* computer n choose m */
{
  int i,j;                 /* counters */
  long bc[MAXN][MAXN];     /* table of binomial coefficients */
  for (i=0; i<=n; i++) bc[i][0] = 1;
  for (j=0; j<=n; j++) bc[j][j] = 1;
  for (i=1; i<=n; i++)
    for (j=1; j<i; j++)
      bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
  return( bc[n][m] );
}

int main(){
  int n,m;
  while(std::cin >> n >> m){
    std::cout << binomial_coefficient(n,m) <<std::endl;
  }
  return 0;
}
