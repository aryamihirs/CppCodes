#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> weight, vector<int> val, int W){
  int i, j, wt, W, N = val.size();
  int K[N][W];
  for(i = 0; i <= N; i++){
    for(wt = 0; wt <= W; j++){
      if(i == 0 || wt == 0)
        K[i][wt] = 0;

      else if(weight[i-1] <= wt)
        K[i][wt] = max(K[i-1][wt], val[i-1] + K[i-1][wt-weight[i-1]];

      else
        K[i][wt] = K[i-1][wt];
    }
  }
}

int main(){
  vector<int> wt = {10, 20, 30};
  vector<int> val = {60, 100, 120};
  int W = 50;
  cout << "Max val of knapsack: " <<knapsack(wt, val, W) << "\n";
  return 0;
}
