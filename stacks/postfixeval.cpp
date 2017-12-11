#include<bits/stdc++.h>

using namespace std;

bool isOp(char c){
  return (c == '/' || c == '^' || c == '*' || c == '+' || c == '-')? true : false;
}

int do_op(char op, int a, int b){
    switch(op)
    {
    case '+':
       return a+b;
    break;
    case '-':
       return a-b;
    break;
    case '*':
       return a*b;
    break;
    case '/':
       return a/b;
    break;
    case '^':
       return a^b;
    break;
    default:
        throw std::runtime_error("unknown op");
    }
}

int evalpostfix(string in){
    stack<int> st;
    // st.push('N');
    int a,b,out;
    string::iterator it;
    for(it = in.begin(); it < in.end(); it++){
      if(isOp(*it)){
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        st.push(do_op(*it,b,a));
        // std::cout << st.top() << '\n';
      }
      else
        st.push(*it - '0');
    }
    out = st.top();
    return out;
}

int main()
{
  // int t;
  // std::cin >> t;
  // while(t--)
  // {
    // std::cin >> s;
    // string s = "123*+3+";
    string s = "52/1*5+";
    int out = evalpostfix(s);
    std::cout << out << '\n';
  // }
  return 0;
}
