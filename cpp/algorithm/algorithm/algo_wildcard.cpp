#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

string key, inputString;
int dp[111][111], keyLen, inputLen;

int matchString(int keyIdx, int inputIdx) {
	int& ret = dp[keyIdx][inputIdx];
	if (ret != 0) return ret;
	ret = -1;

	if (keyIdx < keyLen && inputIdx < inputLen && 
		(key[keyIdx] == '?' || key[keyIdx] == inputString[inputIdx])) {
		return ret = matchString(keyIdx + 1, inputIdx + 1);
	}

	if (keyIdx == keyLen) {
		return ret = (inputIdx == inputLen) ? 1 : -1;
	}

	if (key[keyIdx] == '*') {
		ret = matchString(keyIdx + 1, inputIdx);
		if(ret==-1 && inputIdx < inputLen) 
			ret = matchString(keyIdx, inputIdx+1);
	}
	return ret;
}

void init() {

	for (int i = 0; i <= keyLen; i++) {
		for (int j = 0; j <= inputLen; j++) {
			dp[i][j] = 0;
		}
	}
}

void solve() {
	int n;
	cin >> key >> n;

	keyLen = key.length();

	vector<string> result;

	for (int i = 0; i < n; i++) {
		cin >> inputString;
		inputLen = inputString.length();
		if (matchString(0, 0)==1) {
			result.push_back(inputString);
		}
		init();
	}
	sort(result.begin(), result.end());

	int len = result.size();
	for (int i = 0; i < len; i++) {
		cout << result[i] << endl;
	}
}

int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}