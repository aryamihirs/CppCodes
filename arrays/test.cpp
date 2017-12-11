#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

int bsearch(int A[], int key, int start, int end){
  int mid = start + (end - start + 1)/2;

  if(start <= end){
    if(key < A[mid])
      return bsearch(A, key, start, mid-1);
    else if(key == A[mid])
      return mid;
    else
      return bsearch(A, key, mid+1, end);
  }

  else if(end < start)
    return -1;
}
int maxRepetitions(int A[], int n){
  unordered_map<int, int> mp;
  int maxi = 0;
  for(int i = 0; i < n; i++){
    mp[A[i]]++;
  }
  for(int i = 0; i < n; i++){
    if(mp[A[i]] > maxi)maxi = A[i];
  }
  return maxi;
}

// int maxIdxDiff(int A[], int n){
//   int diff = 0, i;
//   pair<int,int> min;
//   min->first = A[0];
//   min->second = 0;
//   for(i = 0; i < n; i++){
//     if(A[i] < min->first)
//     {
//       min->first = A[i];
//       min->second = i;
//     }
//     // if(min)
//   }
// }
vector<int> maxSlidingWindow(vector<int>& A, int k) {
        deque<int> dq(k);
        vector<int> ans;

        // if(!A.size())
        //     return A;

//         else if(k > A.size())
//             return findMax(A);

        // else
        // {
            //dq.push_back(0);
            for(int i = 0; i < k; i++){
                cout << i << " ";
                if(A[dq.back()] <= A[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
           }



            for(int i = k; i < A.size(); i++){
                cout <<i <<" ";
                ans.push_back(A[dq.front()]);
                while(dq.front() < i - k + 1 && !dq.empty()){
                    dq.pop_front();
                }

                while(A[i] >= A[dq.back()] && !dq.empty())
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            ans.push_back(A[dq.front()]);
            // for(int i = 0; i < ans.size(); i++){
            //     cout << ans[i] << " ";
            // }
            return ans;
        // }
    }
int main() {

  int A[8] = {1,3,-1,-3,5,3,6,7}, idx, a;
  std::cout << "maxRepetitions, element: " <<  maxRepetitions(A, 8) << '\n';
  std::vector<int> v(A,A + sizeof A / sizeof A[0]);

  std::vector<int> maxSlide = maxSlidingWindow(v, 3);

  for (int i = 0; i < maxSlide.size(); i++) {
    std::cout << maxSlide[i] << " ";
  }
  // string s = "abcdefghijk";
  // a = s[0] - 'a';
  // std::cout << "a: " << a << '\n';
  // idx = bsearch(A,2,0,7);
  // if(idx == -1)
  //   std::cout << "Element not found! " << '\n';
  // else
  //   std::cout << "Element idx val: " << idx <<'\n';

  return 0;
}
