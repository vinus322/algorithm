//  
//  algo_lunchbox.cpp
//  algorithm
//  알고리즘 문제해결전략 - 도시락 데우기 (난이도 하)
//
//  Created by Hubring on 2019. 07. 11..
//  Copyright © 2019년 Hubring. All rights reserved.
//

// 점심을 먹는데 걸리는 최소 시간 구하기(탐욕)
// 시간복잡도 O(N)

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;

const long long INF = numeric_limits<long long> ::max();

struct TimeSpan {
	int cookTime;
	int eatTime;
};

void solve() {
	int n;
	vector<TimeSpan> tsv;

	scanf("%d", &n);

	int time;
	// 입력 :  i번째 음식의 조리시간
	for (int i = 0; i < n; i++) {
		scanf("%d", &time);
		tsv.push_back({ time, -1 });
	}
	// 입력 :  i번째 음식의 먹는시간
	for (int i = 0; i < n; i++) {
		scanf("%d", &time);
		tsv[i].eatTime = time;
	}

	// 먹는 시간 기준으로 정렬 
	// 조리시간과 무관, 
	// 먹는 시간이 긴 사람이 나중에 나오면 다 먹을 때까지 대기해야 하므로 먼저 먹는 것이 유리
	// 따라서 먹는 시간 기준 내림 차순으로 정렬
	sort(tsv.begin(), tsv.end(),
		[](TimeSpan a, TimeSpan b) -> bool { return a.eatTime > b.eatTime;  });

	// 해당 순서대로 데워먹는 과정을 시뮬레이션
	int lunchTime = 0, cookTime = 0;
	for (int i = 0; i < n; i++) {
		cookTime += tsv[i].cookTime;
		lunchTime = max(lunchTime, cookTime+tsv[i].eatTime);
	}

	printf("%d\n", lunchTime);

}




int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}