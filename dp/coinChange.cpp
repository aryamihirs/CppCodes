#include<bits/stdc++.h>

using namespace std;

int count(vector<int> coins, int X){
  int N = coins.size();
  int dp[X+1][N];

  for(int i = 0; i < N; i++){
    dp[0][i] = 1;
  }

  for(int i = 1; i <= X; i++){
    for(int j = 0; j < N; j++){
        int x = (i >= coins[j])?dp[i - coins[j]][j]:0;
        int y = (j >= 1)?dp[i][j-1]:0;
        dp[i][j] = x + y;
    }
  }
  return dp[X][N-1];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);

    vector<int> coins(arr , arr + m);

    int n = 4;
    cout << "Number of ways: " << count(coins, n) << "\n";
    return 0;
}
