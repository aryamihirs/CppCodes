#include <bits/stdc++.h>
using namespace std;


int queuePop(stack<int> st){
  stack<int> aux;
  while(!st.empty()){
    aux.push(st.top());
    st.pop();
  }
  return aux.top();
}

int main()
{
  stack<int> st1;

  st1.push(1);
  st1.push(2);
  st1.push(3);
  st1.push(4);
  st1.push(5);

  std::cout << "qPOP: " << queuePop(st1) << "\n";
}
