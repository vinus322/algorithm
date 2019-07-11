#include<stdio.h>
#include <iomanip>
#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int N, D, P, Q;
int connect[55][55];
double dp[101][55];
int cnnCnt[55];


void init() {
	for (int i = 0; i <= D; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = -1.0;
		}
	}
}

double calRateOfFindDoctor(int day, int curr) {
	if (day == 0) {
		return curr==P? 1.0 : 0.0;
	}

	double& ret = dp[day][curr];
	if (ret > -0.5) return ret;
	ret = 0.0;

	for (int next = 0; next < N; next++) {
		if (connect[curr][next] != 1) continue;
		ret += calRateOfFindDoctor(day - 1, next )/cnnCnt[next];
	}
	
	return ret;
}

void solve() {
	scanf("%d %d %d", &N, &D, &P);

	init();
	for (int i = 0; i < N; i++) {
		cnnCnt[i] = 0;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &connect[i][j]);
			cnnCnt[i] += connect[i][j];
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &Q);
		double ans = calRateOfFindDoctor(D, Q);
		cout << setprecision(8) << ans << " "; 
	}

	printf("\n");
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}