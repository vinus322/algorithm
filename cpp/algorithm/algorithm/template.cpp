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

}



int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}