#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
El input debe ir asi:
n r
n1 n2
n1 n3
n3 n2
n2 n3
. 
.
. Hasta r

donde r es el numero de relaciones y n el numero de grafos, seguido de cada grafo con el que se relaciona, asi
3 3
1 2
2 3
1 3

Imprime una linea para cada nodo recorrido en profundidad
*/


//Implementacion de dfs (deepth first search)
void dfs(vector<int>*graph, int *visited, int pos){
  if(visited[pos] != 0)
    return;

  visited[pos] = 1;
  printf("Recorrido : %d\n", pos);
  
  for(int i = 0; i < graph[pos].size(); i++){  
    dfs(graph, visited, graph[pos][i]);
  }
}

int main(){
  int size, numRel;
  int n1, n2;
  
  while(scanf("%d%d", &size, &numRel) != EOF){
    vector<int> vGraph[size+1];
    int visited[size+1];
    memset(visited, 0, sizeof visited);
    for(int i = 0; i < numRel; i++){
      scanf("%d%d", &n1, &n2);
      vGraph[n1].push_back(n2);
      vGraph[n2].push_back(n1);
    }
    dfs(vGraph, visited, 1);
  }

  return 0;
}
