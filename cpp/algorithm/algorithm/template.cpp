
//
//  CDJ_Alphabet_Cake.cpp
//  algorithm
//
//  Created by Hubring on 2019. 2. 14..
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

#define MOD 1000000000

int N;
const long long NEGINF = numeric_limits<long long> ::min();
const long long INF = numeric_limits<long long> ::max();
const long long  minValue = LLONG_MIN;

bool inboundary(int x, int y) {
	return x >= 0 && x < N&&y >= 0 && y < N;
}



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