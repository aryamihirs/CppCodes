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

int priority(char c){
  if(c == '^')
    return 5;
  else if(c == '/')
    return 4;
  else if(c == '*')
    return 3;
  else if(c == '+')
    return 2;
  else if(c == '-')
    return 1;
  else
    return -1;
}

int evalinfix(string in){

}
int main()
{
  // int t;
  // std::cin >> t;
  // while(t--)
  // {
    // std::cin >> s;
    // string s = "123*+3+";
    string s = "5/2*1+5";
    int out = evalinfix(s);
    std::cout << out << '\n';
  // }
  return 0;
}
