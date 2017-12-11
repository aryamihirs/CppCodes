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

// int func(int X, unordered_set<int> S){
//   if(X == 0)
//     return 0;
//
//   unordered_set<int>::iterator it;
//   else{
//     for(it = s.begin(); it != s.end(); it++){
//       int t = *it;
//       s.pop();
//       func(X - t, s) + 1;
//     }
//   }
// }

int main(){
  int N, X;
  unordered_set<int> s;
  cin >> N;
  vector<int> cost(N);
  for(int i = 0; i < N; i++){
    cin >> cost[i];
    s.push(cost[i]);
  }
  cin >> X;

  cout << func(X, cost) << "\n";
  return 0;
}
