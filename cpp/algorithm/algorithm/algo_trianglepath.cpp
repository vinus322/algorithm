#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int n;
int map[101][101];
int dp[101][101];


void calMaxSum(int x, int y, int cnt) {
	int& ret = dp[x][y];
	if (ret > cnt) return;
	dp[x][y] = cnt;

	if(map[x+1][y] != -1) calMaxSum(x + 1, y, cnt + map[x+1][y]);
	if (map[x+1][y+1] != -1) calMaxSum(x+1, y+1, cnt + map[x+1][y+1]);
}


void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <=n; j++) {
			map[i][j] = -1;
			dp[i][j] = 0;
		}
	}
}

void solve() {
	scanf("%d", &n);
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	calMaxSum(0, 0, map[0][0]);

	int max = 0;
	for (int i = 0; i < n; i++) {
		max = (max > dp[n - 1][i]) ? max : dp[n - 1][i];
	}
	printf("%d\n", max);
}

int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}