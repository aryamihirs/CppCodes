#include<bits/stdc++.h>

using namespace std;

class SplStack
{
  private:
    stack<int> st;
    stack<int> aux;

  public:
    // SplStack(){
    //
    // }
    void pushS(int x);
    int getMin();
    int popS();
};

void SplStack::pushS(int x){
  st.push(x);
  // int top = aux.top();
  (aux.empty())?aux.push(x):((aux.top() > x)?aux.push(x):aux.push(aux.top()));
}

int SplStack::getMin()
{
  return (aux.empty())?(-1):aux.top();
}

int SplStack::popS()
{
  int popVal = st.top();
  st.pop();
  aux.pop();
  return popVal;
}

int main()
{
  SplStack sta;
  sta.pushS(1);
  sta.pushS(2);
  sta.pushS(3);
  std::cout << sta.getMin() << '\n';
  sta.pushS(0);
  std::cout << sta.getMin() << '\n';
  return 0;
}
