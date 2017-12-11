#include<iostream>
#include<stdio.h>

using namespace std;

bool isCycleUtil(int v, int **G, int N, bool *visited, bool *recStk)
{
  if(!visited[v]){
    visited[v] = true;
    recStk[v] = true;

    for(int i = 0; i < N; i++){
      if(G[v][i] && !visited[i] && isCycleUtil(i, G, N, visited, recStk)){
        return true;
      }
      else if(recStk[i])
        return true;
    }
  }
  recStk[v] = false;
  return false;
}

bool isCycle(int **G, int N){
  bool *visited, *recStk;
  visited = new bool[N];
  recStk = new bool[N];

  for(int i = 0; i < N; i++){
    visited[i] = false;
    recStk[i] = false;
  }
  for(int i = 0; i < N; i++){
    if(isCycleUtil(i, G, N, visited, recStk))
      return true;
  }
  return false;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int N, M, in, out;
    cin >> N >> M;
    int **G;
    G = new int *[N];
    for(int i = 0; i < N; i++){
      G[i] = new int [N];
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        G[i][j] = 0;
      }
    }
    for(int i = 0; i < M; i++){
      cin >> in >> out;
      G[in][out] = 1;
    }
    //printInAscending(G, N, M);
    (isCycle(G, N))?cout << "cycle present\n":cout << "Cycle Not present\n";
  }
  return 0;
}
