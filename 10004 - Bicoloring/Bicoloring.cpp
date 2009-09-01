/* 
   Daniel Gomez Rico
   danielgomezrico@gmail.com
   2009

   10050 - Hartals10004 - Bicoloring

   http://icpcres.ecs.baylor.edu/onlinejudge/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=12&problem=945&mosmsg=Submission+received+with+ID+7104377

*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool coloriable = true;//Says if the graph is coloriable or not

//Implementacion de dfs (deepth first search)
void dfs(vector<int>*vGraph, char *arrayColor, int pos, char color){

  int sizeNodes = vGraph[pos].size();

  if (arrayColor[pos] == color){//If this node color is iqual to the last node is not coloriable
    coloriable = false;
  }
  if (arrayColor[pos] != ' '){//If is different from ' ' it means that this node has been already painted
    return;
  }

  arrayColor[pos] = (color == 'w') ? 'b' : 'w';  //Paint this node with the other color that it recives from the last

  for(int i = 0; i < sizeNodes; i++){  
    if(coloriable){
      dfs(vGraph, arrayColor, vGraph[pos][i], arrayColor[pos]);
    }
    else{
      return;
    }
  }
}

int main(){
  int size, numRel;
  int n1, n2;

  while(scanf("%d%d", &size, &numRel) && size){

    vector<int> vGraph[size];
    char arrayColor[size];//It had the nodes colors,to the color in position a correspond to the node in vGraph pos a
    coloriable = true;

    for(int i = 0; i < size; i++){
      arrayColor[i] = ' ';
    }

    for(int i = 0; i < numRel; i++){
      scanf("%d%d", &n1, &n2);
      vGraph[n1].push_back(n2);
      vGraph[n2].push_back(n1);
    }

    dfs(vGraph, arrayColor, 0, 'w');

    if(coloriable){
      printf("BICOLORABLE.\n");
    }
    else{
      printf("NOT BICOLORABLE.\n");
    }
  }
  return 0;
}
