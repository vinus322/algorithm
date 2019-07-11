#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;
/*
* 시간복잡도 : O(N^2*S)
*/
#define MAX 10000001

int N, S;
int inputNum[110];
int sumArr[110],  sqSumArr[110];
int dp[11][110];


void setSumArr() {
	for (int i = 1; i <= N; i++) {
		sumArr[i] = sumArr[i - 1] + inputNum[i-1];
	}
}

void setSqSumArr() {
	for (int i = 1; i <= N; i++) {
		sqSumArr[i] = sqSumArr[i - 1] + (inputNum[i-1]* inputNum[i-1]);
	}
}


void init() {
	for (int i = 0; i <= S; i++) {
		for (int j = 0; j <= N; j++)
			dp[i][j] = MAX;
	}

	sort(inputNum, inputNum+N);
	
	setSumArr();
	setSqSumArr();
}


//시간복잡도 : O(1)
int calMinError(int idx, int size) {
	int sum = sumArr[idx + size] - sumArr[idx];
	int sqSum = sqSumArr[idx + size] - sqSumArr[idx] ;

	int m =int( 0.5+(double)sum / size);

	int res = sqSum - (2*m*sum) + (m*m*size);
	return res;
}

int quantization(int s, int idx) {
	if (idx == N) return 0;
	if (s == S) return MAX;

	int& ret =  dp[s][idx];
	if (ret < MAX) return ret;

	for (int size = 1;  idx+size<= N; size++ ) {
		int tmp = calMinError(idx, size)+quantization(s+1, idx+size);
		ret = min(ret, tmp);
	}

	return ret;
}


void solve() {

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inputNum[i]);
	}
	init();
	
	printf("%d\n", quantization(0, 0));

}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}