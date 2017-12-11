#include <bits/stdc++.h>

using namespace std;

int main()
{
  list<int> l,ll;
  int t = 5;
  for(int i = 0; i < 10; ++i){
    l.push_back(i*2);
  }

  list<int> :: iterator it = l.begin();
  while(t--){
    ++it;
  }

  for(int i = 0; i < 5; ++i){
    ll.push_back(i*3);
  }


  l.insert(it, ll.begin(), ll.end());

  std::cout << "Modified List: ";
  for(it = l.begin(); it != l.end(); ++it){
    std::cout << *it << ' ';
  }
  std::cout << '\n';



  return 0;
}
