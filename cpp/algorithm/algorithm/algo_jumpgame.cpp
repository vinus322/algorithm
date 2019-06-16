#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

//시간복잡도 : O(N^2)
int dp[101][101];
int map[101][101];
int N;

bool inboundary(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}

bool isFinish(int x, int y) {
	int f = N - 1;
	return (x == f) && (y == f);
}

int jumpGame(int x, int y) {
	int& ret = dp[x][y];
	if (ret!=0) return ret;
	if (isFinish(x, y)) return 1;
	int jumpCnt = map[x][y];

	ret = -1;
	if (inboundary(x + jumpCnt, y)) {
		ret = jumpGame(x+ jumpCnt, y);
	}
	
	if ((ret==-1)&& inboundary(x, y+ jumpCnt)) {
		ret = jumpGame(x, y+ jumpCnt);
	}

	return ret;
}


void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
	}
}

void solve() {
	scanf("%d", &N);
	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int result = jumpGame(0, 0);
	printf("%s\n", (result==1)? "YES" : "NO");
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}
