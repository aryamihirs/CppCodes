#include<bits/stdc++.h>

using namespace std;

class SplStack
{
  private:
    stack<int> st;
    int minEle;
  public:
    void pushS(int x);
    int getMin();
    int popS();
};

void SplStack::pushS(int x){
  if(st.empty())
  {
    st.push(x);
    minEle = x;
  }
  else
  {
    if(x >= minEle)
    {
      st.push(x);
    }
    else
    {
      minEle = x;
      st.push(2*x - minEle);
    }
  }
}

int SplStack::getMin()
{
  return (st.empty())?(-1):minEle;
}

int SplStack::popS()
{
  int popVal = st.top();
  minEle = 2*minEle - popVal;
  st.pop();
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
