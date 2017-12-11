
#include <stdio.h>
#include <limits.h>

#define V 9
using namespace std;

//int findMin
void dijkstra(int graph[][V], int src){
  bool sptSet[V];
  int dist[V];
  //dist[src] = 0;
  for(int i = 0; i < N; i++){
    dist[i] = (i != src) ? INT_MAX : 0;
    sptSet[i] = false;
  }

  for(int count = 0; count < N; count++){
    int curr = findMin(sptSet, dist);

    sptSet[curr] = true;

    for(int j = 0; j < V; j++){

    }
  }
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
