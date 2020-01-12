
//
//  algo_kakuro2.cpp
//  알고리즘 문제해결 전략 - 조합탐색
//
//  Created by Hubring on 2019. 7. ..28
//  Copyright © 2019년 Hubring. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;

#define MAXN 25

int N, Q;

// 0 = 가로방향, 1 = 세로방향
int direct[2][2] = { {0, 1}, {1, 0} };


bool inboundary(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}


// 변수의 수 = len, 합 = sum, 알고 있는 변수조합 = known 인 경우
// candidates[len][sum][known]  = 넣을 수 있는 변수의 조합
int candidates[10][46][1024];

int getSize(int set) {
	int s = 0;
	for (int i = 1; i <= 9; i++) {
		s += (set >> i) & 1;
	}
	return s;
}

int getSum(int set) {
	int s = 0;
	for (int i = 1; i <= 9; i++) {
		if ((set >> i) & 1) {
			s += i;
		}
	}
	return s;
}


void generateCandidates() {

	for (int set = 0; set < 1024; set+=2) {
		int l = getSize(set), s = getSum(set);

		int subset = set;
		while (true) {
			// 숫자 하나의 합이 s이고 이미 subset 숫자가 쓰여 있을 떄
			// 전체 숫자의 집합이 set이 되도록 나머지 숫자를 채워넣을 수 있다.
			candidates[l][s][subset] |= (set & ~subset);
			if (subset == 0)  break;
			subset = (subset - 1) & set;
		}
	}
}



//게임판 정보
//color : 각 칸의 색(0 = 검정, 1 = 흰색)
//value : 각 흰 칸의 숫자
//hint : 각 칸의  힌트 번호
int color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];

//힌트 정보
//sum : 힌트 칸에 쓰인 숫자
//length: 힌트 칸에 해당하는 흰칸의 수
//known: 힌트 칸에 해당하는 흰칸에 쓰인 숫자들의 집합
int sum[MAXN*MAXN], length[MAXN*MAXN], known[MAXN*MAXN];


// (y, x) 좌표에 값 입력
void put(int y, int x, int val) {
	for (int h = 0; h < 2; h++) {
		known[hint[y][x][h]] += (1 << val);
	}
	value[y][x] = val;
}


// (y, x) 좌표에 값 삭제
void remove(int y, int x, int val) {
	for (int h = 0; h < 2; h++) {
		known[hint[y][x][h]] -= (1 << val);
	}
	value[y][x] = 0;
}

// 힌트 번호가 주어질 떼 후보의 집합을 반환
int getCandHint(int h) {
	return candidates[length[h]][sum[h]][known[h]];
}

// (x, y) 좌표의 가로, 세로 hint를 통해 사용가능한 변수 조합을 가져옴
int getCandCoord(int y, int x) {
	return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

void printSolution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", value[i][j]);
		}
		printf("\n");
	}
}


bool search() {
	int y = -1, x = -1, minCands = 1023;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (color[i][j] == 1 && value[i][j] == 0) {
				int cands = getCandCoord(i, j);
				if (getSize(minCands) > getSize(cands)) {
					minCands = cands;
					y = i, x = j;
				}
			}
		}
	}
	//빈칸은 있는데 들어갈 숫자가 없으면 실패
	if (minCands == 0) return false;
	//모든 칸이 채워져 있다면 성공
	if (minCands == 1023) {
		printSolution();
		return true;
	}

	//숫자 하나씩 넣어보기
	for (int val = 1; val <= 9; val++) {
		if (minCands & 1 << val) {
			put(y, x, val);
			if (search()) return true;
			remove(y, x, val);
		}
	}

	return false;

}



void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			length[i*N + j]  = sum[i*N + j] = known[i*N + j] = 0;
			value[i][j] = hint[i][j][0] = hint[i][j][1] = 0;
		}
	}
}

void solve() {


	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &color[i][j]);
		}
	}

	scanf("%d", &Q);

	for (int i = 0; i < Q; i++) {
		int y, x, dir, s;
		scanf("%d %d %d %d", &y, &x, &dir, &s);
		y -= 1; x -= 1;
		sum[i] = s;

		int  goy = y, gox = x;
		int l = 0;
		//힌트에 해당하는 빈칸 찾기
		while (true) {
			goy += direct[dir][0];
			gox += direct[dir][1];

			if (!inboundary(goy, gox) 
				|| color[goy][gox] == 0) break;

			l++;
			hint[goy][gox][dir] = i;
		}
		length[i] = l;
	}

	search();
	init();
}



int main() {

	generateCandidates();

	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}