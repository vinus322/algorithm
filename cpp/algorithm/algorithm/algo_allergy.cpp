
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

int n, m;

vector<int> friends[51], foods[51];
int result;

vector<int> eatHash;

void search(int cnt) {

	if (cnt >= result) return;
	
	int idx = 0;
	for (; idx < n; idx++) {
		if (eatHash[idx] > 0 ) continue;
		else break;
	}
	if (idx == n) {
		result = cnt;
		return;
	}

	for (int i = 0; i < friends[idx].size() ; i++) {
		int foodIdx = friends[idx][i];
		for (int j = 0; j < foods[foodIdx].size(); j++) {
			int friendIdx = foods[foodIdx][j];
			eatHash[friendIdx]++;
		}

		search(cnt+1);

		for (int j = 0; j < foods[foodIdx].size(); j++) {
			int friendIdx = foods[foodIdx][j];
			eatHash[friendIdx]--;
		}
	}

}


void solve() {
	result = 300;

	cin >> n >> m;

	eatHash.resize(n);

	vector<string> names;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		names.push_back(name);
	}

	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt;  j++) {
			string name;
			cin >> name;

			int idx = 0;
			for (int z = 0; z < names.size(); z++) {
				if (names[z].compare(name) == 0) {
					idx = z; break;
				}
			}
			friends[idx].push_back(i); //idx번째 사람이 먹을 수 있는 음식 m
			foods[i].push_back(idx); //m번째 음식을 먹을 수 있는 사람 idx
		}
		
	}

	search(0);

	cout << result << endl;

	for (int i = 0; i < n; i++) {
		friends[i].clear();
	}

	for (int i = 0; i < m; i++) {
		foods[i].clear();
	}


}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}