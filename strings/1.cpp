#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,len;
    string s,temp;
    // std::cin >> t;
    // while(t--){
      std::cin >> s;
      std::cin >> temp;
      len = s.size();
      if(temp.compare(s) == 0)
      {
        cout << "Hey compare works. Yay!";
      }
      else{
        std::cout << "shugs, it doesn't :(" << '\n';
      }
      temp.insert(4,s);
      cout << temp << "\n";
    // }
    return 0;
}
