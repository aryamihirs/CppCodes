#include<bits/stdc++.h>

using namespace std;

int foo(int &a, int &b)
{
    a += 2;
    b += 3;

    return a+b;
}

int main()
{
    int a,b,i,count = 10;
    vector< pair <int,int> > p;
    vector< pair <int,int> >::iterator it;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "q.front(): " << q.front() << '\n';
    q.pop();
    cout << "[after a pop] q.front(): " << q.front() << '\n';

    for (i = 0; i < count; i++) {
      p.push_back( make_pair(i,i+1));
//    WRONG APPROACH
//      std::cout << "(*p)->first" << (*p)->first <<  '\n';
//      p++;

//    RIGHT APPROACH
//    cout << "p[i].first" << p[i].first << "\n";

    }

    for (it = p.begin(); it != p.end(); it++) {
      std::cout << "it->first: " << it->first<< '\n';
      std::cout << "(*it).first: " << (*it).first<< '\n'<<'\n';
    }
  //  cout << "p->first" << p->first << "\n";
    cout << "p[0].second: " << p[0].second << "\n";
    a = 1;
    b = 2;
    cout << foo(a,b) << "\n";
    return 0;
}
