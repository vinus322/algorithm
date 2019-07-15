//  
//  algo_lunchbox.cpp
//  algorithm
//  알고리즘 문제해결전략 - 문자열 합치기 (난이도 중)
//
//  Created by Hubring on 2019. 07. 11..
//  Copyright © 2019년 Hubring. All rights reserved.
//

// 문자열들의 길이가 주어질 때 문자열 연결을 위한 최소비용 찾기(탐욕)
// 시간복잡도 O(n^2)

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;


int N;
const long long INF = numeric_limits<long long> ::max();



void solve() {
	int n;
	//priority_queue<int, vector<int>, greater<int>> Q;
	priority_queue<int> Q;
	
	scanf("%d", &n);

	int input;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		Q.push(-input);
	}
	
	//최소값 우선으로 더해야 유리
	int res = 0;
	while (Q.size() > 1) {
		int a = Q.top();		Q.pop();
		int b = Q.top();		Q.pop();
		int c = -a + -b;

		res += c;
		Q.push(-c);
	}

	printf("%d\n", res);

}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}