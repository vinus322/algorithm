#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

// 시간복잡도 O(N) 

const int INF = 987654;

int dp[10001];

string s;
int length;

bool case1(int idx, int size) {
	int m = idx + size;
	char ch = s[idx];
	for (int i = idx+1; i < m;  i++) {
		if (ch != s[i]) return false;
	}
	return true;
}


bool case2(int idx, int size) {
	int m = idx + size;
	int gap = s[idx] - s[idx + 1];
	if (abs(gap) != 1) return false;

	for (int i = idx + 1; i < m - 1; i++) {
		if (s[i] - s[i + 1] != gap) return false;
	}
	return true;
}


bool case3(int idx, int size) {
	int m = idx + size;
	for (int i = idx + 2; i < m ; i++) {
		if (s[i] != s[i -2]) return false;
	}
	return true;
}


bool case4(int idx, int size) {
	int m = idx + size;
	int gap = s[idx] - s[idx + 1];
	
	for (int i = idx + 1; i < m - 1; i++) {
		if (s[i] - s[i + 1] != gap) return false;
	}
	return true;
}


int getLevel(int idx, int size) {
	if (case1(idx, size)) return 1;
	if (case2(idx, size)) return 2;
	if (case3(idx, size)) return 4;
	if (case4(idx, size)) return 5;
	return 10;
}

int calMinLevel( int idx) {
	if (idx == length) return 0;

	int& ret = dp[idx];
	if (ret != -1) return ret;
	ret = INF;

	for (int size = 3; size <= 5; size++) {
		if (length < (idx + size)) break;
		int level = getLevel(idx, size);
		ret = min(ret, calMinLevel(idx + size) + level);
	}

	return ret;
}


void init() {
	for (int i = 0; i < length; i++) {
		dp[i] = -1;
	}
}

void solve() {
	cin >> s;
	length = s.length();
	init();
	cout << calMinLevel(0) << endl;
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}