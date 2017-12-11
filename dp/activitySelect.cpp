#include<bits/stdc++.h>

using namespace std;

// void qsort(int A[], int n){
//
// }

bool comp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2){
  return (p1.first.second < p2.first.second);
}

int LastValidIdx(int i, vector<pair<pair<int,int>,int> > v){
  for(int j = i - 1; j >= 0; j--){
    if(v[j].first.second <= v[i].first.first)
      return j;
  }
  return -1;
}

int main(){
  int start[] = {1,3,6,2};
  int finish[] = {2,5,19,100};
  int profit[] = {50,20,100,200};
  int n = 4;
  std::vector<pair<pair<int,int>,int> > v;

  for(int i = 0; i < n; i++){
    v.push_back(make_pair(make_pair(start[i],finish[i]),profit[i]));
  }
  sort(v.begin(), v.end(), comp);
  int dp[n];
  dp[0] = v[0].second;

  for(int i = 1; i < n; i++){
    int maxCurrProf = v[i].second;
    int j = LastValidIdx(i , v);

    if(j != -1){
      maxCurrProf += dp[j];
    }
    dp[i] = max(maxCurrProf, dp[i-1]);
  }
  cout << "Max Profit: " << dp[n-1] << "\n";
  return 0;
}
