#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;

#define MOD 1000000007

/*
* 시간복잡도 O(N)
*/

int N;
int tiledp[110];

void init() {
	for (int i = 0; i <= N; i++) 
		tiledp[i] = -1;
}

int tiling(int idx) {
	if (idx == N) return 1;

	int& ret = tiledp[idx];
	if (ret != -1) return ret;
	ret = 0;

	if (idx < N) ret = tiling(idx + 1);
	if (idx < (N-1)) ret = (ret+tiling(idx + 2))% MOD;

	return ret;
}


void solve() {

	scanf("%d", &N);
	
	if (N <= 2) {
		printf("0\n");
		return;
	}

	init();

	int res = tiling(0);

	if (N % 2 == 0) res = (res - tiledp[N / 2]+MOD)%MOD;
	res = (res - tiledp[N / 2 +1] + MOD) % MOD;

	printf("%d\n", res);
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}