#include<iostream>
#include<stdio.h>

#define INT_MIN -999999999
using namespace std;

bool areIdentical(int A[], int B[], int M){
  for(int i = 0; i < M; i++){
    if(A[i] != B[i]){
      return false;
    }
  }
  return true;
}

int maxOf(int cnt[], int N){
  int maxa = INT_MIN;
  for(int i = 0; i < N; i++){
    maxa = max(maxa, cnt[i]);
    //cout << maxa << "\n";
  }
  return maxa;
}

int findMax(int **A ,int N, int M, int k){
  int numOfZeros;
  bool validClm[N];
  int cnt[N];
  //memset(cnt, 0, sizeof(cnt));
  // for(int i = 0; i < N; i++){
  //   cnt[i] = 1;
  // }

  for(int i = 0; i < N; i++){
    numOfZeros = 0;
    for(int j = 0; j < M; j++){
      if(A[i][j] == 0)
        numOfZeros++;
    }
    cout << "No of zeros: " << numOfZeros << "\n";
    ((k - numOfZeros)%2 == 0)?cout << "cond\n": cout << "nups\n";
    if(numOfZeros <= k && (k - numOfZeros)%2 == 0)
    {
      cout << "Its truee!" << "\n";
      validClm[i] = true;
      cnt[i] = 1;
    }
    else
    {
      validClm[i] = false;
      cnt[i] = 0;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      if(validClm[i] && validClm[j] && areIdentical(A[i],A[j], M))
      {
        cout << "Valid and identical!" << "\n";
        cnt[i]++;
      }
    }
  }
  return maxOf(cnt, N);
}

int main(){
  int t;
  cin >> t;

  while(t--){
    int N,M,k;
    cin >> N >> M >> k;

    int **A = new int *[N];
    for(int i = 0; i < N; i++){
      A[i] = new int [M];
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        cin >> A[i][j];
      }
    }
    int count = findMax(A, N, M, k);
    cout << "Max Number of Rows: " << count << endl;
  }
  return 0;
}
