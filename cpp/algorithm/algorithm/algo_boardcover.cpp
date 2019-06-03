#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int block[4][3][2] = {
	{ {0,0}, {0, 1}, {1, 1} }, //¤¡
	{ {0,0}, {1, 0}, {1, -1} }, // ~¤¤ 
	{ {0,0}, {1, 0}, {1, 1} }, // ¤¤ 
	{ {0,0}, {0, 1}, {1, 0} } //~¤¡
};

int board[20][20];
int h, w;


bool inboundary(int x, int y) {
	return x >= 0 && x < h&&y >= 0 && y < w;
}

bool checkBlock(int i, int j, int k) {
	bool canCover = true;
	for (int c = 0; c < 3; c++) {
		if (!inboundary(i + block[k][c][0], j + block[k][c][1])) {
			canCover = false; break;
		}
		if (board[i + block[k][c][0]][j + block[k][c][1]] == 1) {
			canCover = false; break;
		}
	}
	return canCover;
}

int coverBlock() {
	int ret = 0;

	bool isAll = true;

	for (int i = 0; i <h ; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 1) continue;
			isAll = false;

			for (int k = 0; k < 4; k++) {
				if (!checkBlock(i, j, k)) continue;

				for (int c = 0; c < 3; c++) 
					board[i + block[k][c][0]][j + block[k][c][1]] = 1;
		
				ret += coverBlock();

				for (int c = 0; c < 3; c++) 
					board[i + block[k][c][0]][j + block[k][c][1]] = 0;

			}
			break;
		}
		if (!isAll) break;
	}

	if (isAll)
		return 1;

	return ret;

}


void solve() {
	scanf("%d %d", &h, &w);
	int result = 0, cnt = 0;

	string input;
	for (int i = 0; i < h; i++) {
		cin >> input;
		for (int j = 0; j < w; j++) {
			board[i][j] = input[j]=='#'? 1 : 0;
			if (board[i][j] == 0) cnt++;
		}
	}
		
	if (cnt % 3 == 0) {
		result = coverBlock();
	}

	printf("%d\n", result);
}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}