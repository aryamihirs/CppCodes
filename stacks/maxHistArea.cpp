#include<bits/stdc++.h>

using namespace std;

vector<int> calWidths(vector<int> v){
  stack<int> st;
  st.push(0);
  int i;
  int l = v.size();
  vector<int> sp(l,0);
  sp[0] = 1;
  for (i = 1; i < l; i++) {
    while(!st.empty() && v[st.top()] >= v[i])
    {
      st.pop();
    }
    sp[i] = (st.empty())?(i+1):(i - st.top());
    st.push(i);
  }
  for (i = 0; i < l; i++) {
    std::cout << "v: " << v[i] << '\n';
  }
  return sp;
}


int maxarea(vector<int> w, vector<int> rw, vector<int> vals){
  int l = vals.size();
  int i;
  vector<int> areas;
  for (i = 0; i < l; i++) {
    areas.push_back((w[i] + rw[l-i-1] - 1)*vals[i]);
  }
  make_heap(areas.begin(), areas.end());
  // for (i = 0; i < l; i++) {
  //   std::cout << "areas: " << areas[i] << '\n';
  // }
  // for (i = 0; i < l; i++) {
  //   std::cout << "w: " << w[i] << '\n';
  // }
  // for (i = 0; i < l; i++) {
  //   std::cout << "rw: " << rw[i] << '\n';
  // }
  // for (i = 0; i < l; i++) {
  //   std::cout << "vals: " << vals[i] << '\n';
  // }
  return areas.front();
}


int main(){
  vector<int> vals;
  int i;
  vals.push_back(10);
  vals.push_back(40);
  vals.push_back(30);
  vals.push_back(60);
  vals.push_back(70);
  int l = vals.size();
  vector<int> widths = calWidths(vals);
  reverse(vals.begin(), vals.end());
  vector<int> revwidths = calWidths(vals);
  reverse(vals.begin(), vals.end());

  for (i = 0; i < l; i++) {
    std::cout << "rw: " << revwidths[i] << '\n';
  }
  int max_area = maxarea(widths, revwidths, vals);
  std::cout << "max_area: " << max_area <<'\n';
  return 0;
}
