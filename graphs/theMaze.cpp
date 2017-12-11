#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 10

bool isValid(int i, int j){
  return (i >= 0 && i < ROW && j >= 0 && j < COL);
}

int BFS(vector<vector<int> > g, pair<int,int> src, pair<int,int> dest){
  // int d = 0;
  queue<pair< pair<int,int>, int> > q;
  vector<vector<bool> > visited;
  vector<bool> tmp(COL, false);

  for(int i = 0; i < ROW; i++){
    visited.push_back(tmp);
  }

  q.push(make_pair(src,0));
  int iWala[] = {0, 1, 0, -1};
  int jWala[] = {-1, 0, 1, 0};
  visited[src.first][src.second] = true;
  while(!q.empty()){
    pair<pair<int,int>, int> front = q.front();
    q.pop();

    if(front.first == dest)
      return front.second;

    for(int i = 0; i < 4; i++){
      if(isValid(front.first.first+iWala[i], front.first.second+jWala[i]) && g[front.first.first+iWala[i]][front.first.second+jWala[i]] && !visited[front.first.first+iWala[i]][front.first.second+jWala[i]])
      {
        visited[front.first.first+iWala[i]][front.first.second+jWala[i]] = true;
        q.push(make_pair(make_pair(front.first.first+iWala[i],front.first.second+jWala[i]),front.second+1));
      }
    }
  }
  return INT_MAX;
}

int main()
{
    int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

    vector<int> temp(COL);
    vector<vector<int> > g(ROW, temp);

    for(int i = 0; i < ROW; i++){
      for(int j = 0; j < COL; j++){
        // temp[j] = mat[i][j];
        g[i][j] = mat[i][j];
      }
    }
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(3, 4);

    int dist = BFS(g, src, dest);

    if (dist != INT_MAX)
        cout << "Shortest Path is " << dist << "\n";
    else
        cout << "Shortest Path doesn't exist";

    return 0;
}
