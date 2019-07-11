#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;
#define MOD 10000000

/*
* 시간 복잡도 O(N^3)
*/

int N;
int dp[101][101];

void init() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) dp[i][j] = -1;
	}
}


int poly(int use,  int first) {
	if (use == N) return 1;
	
	//dp[사용블록 수][이전 블록 수]
	int& ret = dp[use][first];
	if (ret != -1) return ret;
	ret = 0;

	for (int second = 1; second <= N - use; second++) {
		int res = second + first - 1;
		res = (res*poly(use + second, second))%MOD;
		ret = (ret+res) % MOD;
	}

	return ret;
}

void solve() {
	scanf("%d", &N);

	init();

	int ans = 0;
	for (int first = 1; first <= N; first++) {
		ans = (ans+poly(first, first)) % MOD;
	}

	printf("%d\n", ans);
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}