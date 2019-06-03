#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define SIZE 10

int n, m; // 학생 수, 친구 쌍의 수
bool arr[SIZE][SIZE];
bool cnn[SIZE];


void init() {
	for (int i = 0; i < SIZE; i++) {
		cnn[i] = 0;
		for (int j = 0; j < SIZE; j++) {
			arr[i][j] = 0;
		}
	}
}

int connectFriends(int idx) {
	int ret = 0;
	if (idx >= n) {
		return 1;
	}

	if (cnn[idx]) return connectFriends(idx+1);

	for (int i = idx+1; i < n;  i++) {
		if (cnn[i]) continue;
		if (!arr[idx][i]) continue;
		cnn[i] = true;
		ret+=connectFriends(idx+1);
		cnn[i] = false;
	}

	return ret;
}


void solve() {
	init();
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int f1, f2;
		scanf("%d %d", &f1, &f2);
		arr[f1][f2] = arr[f2][f1] =  1;
	}

	printf("%d\n", connectFriends(0));
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}