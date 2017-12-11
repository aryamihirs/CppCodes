#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	int N = 8, maxa = INT_MIN;
	int A[] = {1,5,8,9,10,17,17,20};
	int dp[N+1];
	dp[0] = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < i; j++){
			maxa = max(maxa, dp[i- j- 1] + A[j]);
		}
		dp[i] = maxa;
	}
	cout << "max price: " << dp[N] << "\n";
	return 0;
}
