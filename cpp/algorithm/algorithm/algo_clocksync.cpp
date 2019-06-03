#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

#define MAX_SIZE 100000000

int _clock[16];

string canTurn[10] = {
	//  "0123456789012345"
		"1110000000000000",
		"0001000101010000",
		"0000100000100011",
		"1000111100000000",
		"0000001110101000",
		"1010000000000011",
		"0001000000000011",
		"0000110100000011",
		"0111110000000000",
		"0001110001000100"
};

int result = MAX_SIZE;


void turnClock(int depth, int cnt) {
	if (cnt > result) return;

	if (depth >= 10) {
		for (int i = 0; i < 16; i++) {
			if (_clock[i] != 0) 	return;
		}
		result = cnt;
		return;
	}

	for (int i = 0; i < 4;  i++) {
		turnClock(depth + 1, cnt + i);
		for (int j = 0; j < 16; j++) {
			_clock[j] = (_clock[j] + (canTurn[depth][j] == '1' ? 3 : 0)) % 12;
		}
	}

}


void solve() {
	result = MAX_SIZE;

	for (int i = 0; i < 16; i++) {
		scanf("%d", &_clock[i]);
		_clock[i] = _clock[i] % 12;
	}

	turnClock(0, 0);

	printf("%d\n", result == MAX_SIZE ? -1 : result);

}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}