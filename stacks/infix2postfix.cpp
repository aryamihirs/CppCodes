#include<bits/stdc++.h>

using namespace std;

int priority(char c){
  if(c == '^')
    return 3;
  else if(c == '*' || c == '/')
    return 2;
  else if(c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infixTopostfix(string inxS){
  int prior;
  char err='x';
  string out;
  string::iterator it;
  stack<char> st;
  st.push('N');
  for(it = inxS.begin(); it < inxS.end(); it++){

    if(isalpha(*it))
      out += *it;

    else{
      if(*it == '(')
        st.push(*it);

      else if(*it == ')'){
          while(st.top() != '(' && st.top() != 'N'){
            out += st.top();
            st.pop();
          }

          if(st.top() == '(')
            st.pop();
      }

      else{
        while(st.top() != 'N' && priority(*it) <= priority(st.top())){
          out += st.top();
          st.pop();
        }
        st.push(*it);
      }
      // Redundent piece of code

      // else if(prior > priority(st.top()) || st.empty()){
      //   st.push(*it);
      // }
      //
      // else
      // {
      //   while(prior >= priority(st.top()) && !st.empty()){
      //     out += st.top();
      //     st.pop();
      //   }
      // }
    }
  }
  while(st.top() != 'N')
  {
    out += st.top();
    st.pop();
  }
  return out;
}

int main(){
  string inxS, postxS;
  inxS = "a+b*c+d";
  postxS = infixTopostfix(inxS);
  //reverse(postxS.begin(), postxS.end());
  cout << postxS << "\n";
  return 0;
}
