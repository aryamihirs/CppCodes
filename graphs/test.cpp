#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int> > &G, int v, int u){
  G[v].push_back(u);
}

void dfs_visit(int v, vector<vector<int> >G, vector<bool> &visited){
  visited[v] = true;
  cout << v << " ";
  for(int j = 0; j < G[v].size(); j++){
    if(!visited[G[v][j]])
      dfs_visit(G[v][j], G, visited);
  }
}

void dfs(int v, vector<vector<int> > G){
  vector<bool> visited(G.size(), false);
  // for(int i = 0; i < G.size(); i++){
    // if(!visited[i]){
      dfs_visit(v , G, visited);
      // std::cout << i;
      // std::cout << '\n';

}

void topoSortVisit(int v, vector<vector<int> > G, vector<bool> &visited, stack<int> &st)
{
  visited[v] = true;
  for(int j = 0; j < G[v].size(); j++){
    if(!visited[G[v][j]])
      topoSortVisit(G[v][j], G, visited, st);
  }
  st.push(v);
}

void topoSort(vector<vector<int> > G){
  // bool visited* = new bool[G.size()];
  vector<bool> visited(G.size(),false);
  stack<int> st;

  for(int i = 0; i < G.size(); i++){
    if(!visited[i])
      topoSortVisit(i, G, visited, st);
  }

  while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
  }
}

void bfs(int v, vector<vector<int> > G){
  vector<bool> visited(G.size(),false);
  deque<int> dq;

  dq.push_back(v);
  visited[v] = true;

  while(!dq.empty()){
    int front = dq.front();
    dq.pop_front();
    std::cout << front << ' ';

    for(int j = 0; j < G[front].size(); j++){
      if(!visited[G[front][j]]){
        visited[G[front][j]] = true;
        dq.push_back(G[front][j]);
      }
    }
  }
}

void printPathsVisit(int v, int u, vector<vector<int> > G, vector<bool> &visited, vector<int> &path){
  visited[v] = true;
  path.push_back(v);
  if(path[path.size()-1] == u)
  {
    for(int i = 0; i < path.size(); i++){
      cout << path[i] << ' ';
    }
    std::cout << '\n';
  }

  for(int j = 0; j < G[v].size(); j++){
    if(!visited[G[v][j]]){
      printPathsVisit(G[v][j], u, G, visited, path);
    }
  }
  path.pop_back();
  visited[v] = false;
}


void printPaths(int u, int v, vector<vector<int> > G){
  vector<bool> visited(G.size(), false);
  vector<int> path;
  printPathsVisit(u, v, G, visited, path);
}


// TR
void dfsVisit(int v, vector<vector<int> > g, vector<bool> &visited, int &maxa, int &mina){
    visited[v] = true;
    //cout << v << ' ';
    maxa = max(maxa, v);
    mina = min(mina, v);

    for(int i = 0; i < g[v].size(); i++){
        if(!visited[g[v][i]])
            dfsVisit(g[v][i], g, visited, maxa, mina);

    }
}

void dfs_q(vector<vector<int> > g, int &ans){
    vector<bool> visited(g.size(),false);
    int max_diff, maxa = INT_MIN, mina = INT_MAX;
    for(int i = 1; i <= g.size(); i++){
        if(!visited[1]){
            dfsVisit(1, g, visited, maxa, mina);
            cout << "\n";
            max_diff = maxa - mina;
            ans = max(ans, max_diff);
        }
    }
}

int maximumDifference(int g_nodes, vector <int> g_from, vector <int> g_to) {
    //cout << "HELLO\n";
    int ans = INT_MIN;
    vector<int> v;
    // v.push_back(1);
    vector<vector<int> > g(g_nodes);

    for(int i = 0; i < g_nodes; i++){
       g.push_back(v);
     }
     int a, b;
    for(int i = 0; i < g_from.size(); i++){
      a = g_from[i];
      b = g_to[i];
      // cout << "gfrom" << a << "\n";
      // cout << "gto" << b << "\n";
      // g[a].push_back(b);
      addEdge(g, a, b);
    }

    dfs_q(g, ans);
    return ans;
}

vector<int> dijkstra(vector<vector<int> > G, int v){
  vector<bool> sptSet(G.size(), false);
  vector<int> dist(G.size());

  dist[v] = 0;
  for(int i = 0; i < G.size(); i++){
    if(i != v){
      dist[i] = INT_MAX;
    }
  }
  
}

int main()
{
	//we have n vertices and m edges
	// int n, m;
  // std::cout << "Enter num of vertices, num of edges: " << '\n';
	// cin>>n>>m;

	//G is the adjacency list
	vector< vector<int> > G(5);


  addEdge(G, 0, 1);
  addEdge(G, 0, 2);
  addEdge(G, 1, 3);
  addEdge(G, 2, 3);
  addEdge(G, 3, 4);
  addEdge(G, 4, 2);
  addEdge(G, 4, 1);
  addEdge(G, 3, 4);

	//this prints the vertices in the same connected components in separate lines
	// dfs(0,G);

  // topo Sort
  // topoSort(G);

  //bfs
  // bfs(0,G);

  //print all Paths
  // printPaths(0, 4, G);

  // TR question: Maximum difference bw vertices of a connected component.

  // int n = 5;
  // vector<int> v1, v2;

  // v1.push_back(1);
  // v1.push_back(1);
  // v1.push_back(2);
  // v1.push_back(2);
  // v1.push_back(3);
  // v1.push_back(4);
  //
  // v2.push_back(2);
  // v2.push_back(3);
  // v2.push_back(3);
  // v2.push_back(4);
  // v2.push_back(4);
  // v2.push_back(5);
  //
  // cout << "Max Diff" << maximumDifference(5, v1, v2) << "\n";
}
