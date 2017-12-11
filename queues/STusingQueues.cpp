#include <bits/stdc++.h>
using namespace std;


int stackPop(queue<int> q){
  queue<int> temp;
  temp = q;
  int l = 0;
  while(!temp.empty()){
    // aux.push(q.top());
    temp.pop();
    l++;
  }

  std::cout << "l: " << l << '\n';

  l = l - 1;
  while(l--){
    q.pop();
  }
  return q.front();
}

int main()
{
  queue<int> q1;

  q1.push(1);
  q1.push(2);
  q1.push(3);
  q1.push(4);
  q1.push(5);

  std::cout << "stPOP: " << stackPop(q1) << "\n";
}
