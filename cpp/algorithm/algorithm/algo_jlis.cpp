#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

//시간복잡도 O(N^2);

const int NEGINF = numeric_limits<int> ::min();

int n, m;
int A[101], B[101];
int dp[101][101];

void init() {
	A[0] = B[0] = NEGINF;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = -1;
		}
	}
}


int findJLIS(int aIdx, int bIdx) {
	int& ret = dp[aIdx][bIdx]; 
	if (ret != -1) return ret;
	ret = 0;

	int maxValue = max(A[aIdx], B[bIdx]);

	for (int next= aIdx+1; next <= n; next++) {
		if (maxValue < A[next])  ret = max(ret, findJLIS(next, bIdx)+1);
	}

	for (int next = bIdx + 1; next <= m; next++) {
		if (maxValue < B[next])  ret = max(ret, findJLIS(aIdx, next) + 1);
	}

	return ret;
}

void solve() {

	scanf("%d %d", &n, &m);

	init();

	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &B[i]);
	}

	int result = findJLIS(0,0);
	printf("%d\n", result );
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}