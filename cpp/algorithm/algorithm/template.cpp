
//
//  algo_brackets2.cpp
//  알고리즘 문제해결전략 - 조세푸스 문제
//
//  Created by Hubring on 2020. 2. 1.
//  Copyright © 2020년 Hubring. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;

#define MOD 1000000000

int N;
const long long NEGINF = numeric_limits<long long> ::min();
const long long INF = numeric_limits<long long> ::max();
const long long  minValue = LLONG_MIN;

bool inboundary(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}


/// <summary>
///	조세푸스 문제 : 포위당한 N명이 원형으로 둘러선 뒤 
/// 1번부터 차례로 자살하며 자살한 사람으로부터 시계방향으로 K번쨰 있는 사람이 죽을 경우 마지막 남은 두명의 위치 출력
/// </summary>
///<param name = 'n'>포위당한 병사수< / param>
///<param name = 'k'> k: 시계방향으로 k번째 살아있는 사람< / param>
void solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

		}
	}
	//priority_queue<int, vector<int>, greater<int>> Q; <-오름차순
	/*sort(tsList.begin(), tsList.end(),
		[](TimeSpan a, TimeSpan b) -> bool { return a.eatTime < b.eatTime;  }); 오름차순 */

}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}