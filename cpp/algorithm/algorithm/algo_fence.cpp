#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	stack<pair<int, int>> board;
	int maxArea = 0;

	for (int i = 0; i <= n; i++) {
		int height = -1;

		if(i<n)	scanf("%d", &height);

		int left = i;
		if (!board.empty()) {
			while (board.top().second>height) {
				int beforeIdx = board.top().first;
				int bheifht = board.top().second;
				int diff = i - beforeIdx;

				maxArea = max(maxArea, diff*bheifht);
				left = board.top().first;
				board.pop();

				if (board.empty()) 	break;
			}
		}
		board.push({left, height });
	}
	printf("%d\n", maxArea);

}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}