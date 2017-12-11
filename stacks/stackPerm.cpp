#include<bits/stdc++.h>

using namespace std;

bool isPerm(vector<int> invec, vector<int> outvec){
  vector<int>::iterator iti;
  vector<int>::iterator ito;
  ito = outvec.begin();

  queue<int> outq;
  queue<int> inq;
  stack<int> st;
  // st.push(-1);
  for(iti = invec.begin(); iti < invec.end(); iti++){
      inq.push(*iti);
  }

  while(!inq.empty()){
    st.push(inq.front());
    inq.pop();
    while(st.top() == *ito){
      outq.push(st.top());
      st.pop();
      ito++;
      if(st.empty())
        break;
    }
  }
  return (st.empty())?true:false;
}


int main()
{
  vector<int> invec;

  invec.push_back(1);
  invec.push_back(2);
  invec.push_back(3);

  vector<int> outvec;

  outvec.push_back(3);
  outvec.push_back(2);
  outvec.push_back(1);
  (isPerm(invec, outvec))?(std::cout << "YESS!" << '\n'):(std::cout << "NO :(" << '\n');
  return 0;
}
