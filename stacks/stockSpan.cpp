#include<bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> v){
  stack<int> st;
  st.push(0);
  int i;
  int l = v.size();
  vector<int> sp(l,0);
  sp[0] = 1;
  for (i = 1; i < l; i++) {
    while(!st.empty() && v[st.top()] < v[i])
    {
      st.pop();
    }
    sp[i] = (st.empty())?(i-1):(i - st.top());
    st.push(i);
  }
  return sp;
}

int main(){
  vector<int> prices;
  int i;
  prices.push_back(100);
  prices.push_back(80);
  prices.push_back(60);
  prices.push_back(70);
  prices.push_back(60);
  prices.push_back(75);
  prices.push_back(85);
  int l = prices.size();
  vector<int> span = stockSpan(prices);

  for (i = 0; i < l; i++) {
    std::cout << "span array: " << span[i] << '\n';
  }
}
