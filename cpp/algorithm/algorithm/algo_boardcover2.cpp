
//  미해결...
//  algo_boardcover2.cpp
//  algorithm
//  알고리즘 문제해결 전략 - 게임판 덮기2 (하)
//  
//  Created by Hubring on 2019. 7. 16..
//  Copyright © 2019년 Hubring. All rights reserved.
//
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#include<string>

using namespace std;

int H, W, R, C;

int map[12][12];
int block[4][12][12];
int blockSize = 0;
int blank = 0;
vector<vector<pair<int, int>>> rotation;
int rotationSize;
int maxCnt = 0;


bool inboundary(int x, int y) {
	return x >= 0 && x < H&&y >= 0 && y < W;
}

void init() {
	rotation.clear();
	maxCnt = blank = 0;
}

void getRotaionPoint() {
	rotation.resize(4);
	for (int r = 0; r < 4; r++) {
		int startX = -1, startY = -1;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (block[r][i][j] == 1) {
					if (startX == -1 && startY == -1) {
						startX = i, startY = j;
					}
					rotation[r].push_back({ i-startX, j-startY });
				}
			}
		}
	}
}

bool checkBlock(int i, int j, int k) {
	bool canCover = true;

	for (int c = 0; c < blockSize; c++) {
		if (!inboundary(i + rotation[k][c].first, j + rotation[k][c].second)) {
			canCover = false; break;
		}
		if (map[i + rotation[k][c].first][j + rotation[k][c].second] == 1) {
			canCover = false; break;
		}
	}
	return canCover;
}

void coverBlock(int h, int w, int cnt) {
	bool isAll = true;
	int j = w;

	if (maxCnt >= (blank/blockSize) + cnt) return;

	for (int i = h; i < H; i++) {
		for (; j < W; j++) {
			if (map[i][j] == 1) continue;
			isAll = false;
			
			for (int k = 0; k < rotationSize; k++) {
				if (!checkBlock(i, j, k)) continue;

				for (int c = 0; c < blockSize; c++)
					map[i + rotation[k][c].first][j + rotation[k][c].second] = 1;
				
				blank -= blockSize;
				coverBlock( h, w+1, cnt + 1);
				
				for (int c = 0; c < blockSize; c++)
					map[i + rotation[k][c].first][j + rotation[k][c].second] = 0;
				blank += blockSize;
			}

			map[i][j] = 1;
			blank -= 1;
			coverBlock(h, w + 1, cnt);
			map[i][j] = 0;
			blank += 1;

			break;
		}
		if (!isAll) break;
		j = 0;
	}


	if (isAll) {
		maxCnt = max(maxCnt, cnt);
	}

}


void solve() {
	init();
#pragma region  콘솔 입력
	scanf("%d %d %d %d", &H, &W, &R, &C);


	string input;
	for (int i = 0; i < H; i++) {
		cin >> input;
		for (int j = 0; j < W; j++) {
			if (input[j] == '#') map[i][j] = 1;
			else {
				map[i][j] = 0;
				blank++;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		cin >> input;
		for (int j = 0; j < C; j++) {
			if (input[j] == '#') block[0][i][j] = 1;
			else block[0][i][j] = 0;
		}
	}
#pragma endregion

#pragma region 블록 회전
	int r = R, c = C;
	for (int t = 1; t < 4; t++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				block[t][j][r-i-1] = block[t - 1][i][j];
			}
		}
		int tmp = r;
		r = c;
		c = tmp;
	}

	getRotaionPoint();

	blockSize = rotation[0].size();
#pragma endregion

	sort(rotation.begin(), rotation.end());
	rotation.erase(unique(rotation.begin(), rotation.end()), rotation.end());
	rotationSize = rotation.size();

	coverBlock(0, 0, 0);

	cout << maxCnt << endl;
}


  