#include <iostream>
#include <queue>
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

Imprime una linea para cada nodo recorrido en profundidad y en amplitud
*/

//Implementacion de dfs (deepth first search)
void dfs(vector<int>*graph, bool *visited, int node){
  if(visited[node] != 0)
    return;

  visited[node] = 1;
  printf("Nodo : %d\n", node);
  
  for(int i = 0; i < graph[node].size(); i++){  
    dfs(graph, visited, graph[node][i]);
  }
}

//Implementacion de bfs (breadth first search)
void bfs(vector<int>*graph, bool *visited){
  queue <int>q;
  q.push(1);
  
  visited[1] = true;
  
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    
    printf("Nodo : %d\n", node);
    
    
    for(int i = 0; i < graph[node].size(); i++){  
      int to = graph[node][i];
      
      if(!visited[to]){
	visited[to] = 1;
	q.push(to);
      }
    } 
  }
}



int main(){
  
  int size, numRel;
  int n1, n2;
  
  while(scanf("%d%d", &size, &numRel) != EOF){
    vector<int> vGraph[size+1];
    bool visited[size+1];

    memset(visited, 0, sizeof visited);
    
    for(int i = 0; i < numRel; i++){
      scanf("%d%d", &n1, &n2);
      vGraph[n1].push_back(n2);
      vGraph[n2].push_back(n1);
    }

    printf("BFS TRAVEL: \n");
    bfs(vGraph, visited);

    memset(visited, 0, sizeof visited);//Restart values
    
    printf("\nDFS TRAVEL: \n");
    dfs(vGraph, visited, 1);
  }
  
  return 0;
}
