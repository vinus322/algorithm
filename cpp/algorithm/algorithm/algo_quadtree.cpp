#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

//뒤집는 순서
int orderHash[] = { 2, 3, 0, 1};

string reverseQuadtree(string inputString, int& idx) {

	char ch = inputString[idx++];
	string result = "";
	result = ch;

	string quad[4];

	if (ch == 'x') {
		for (int i = 0; i < 4; i++) 
			quad[orderHash[i]] = reverseQuadtree(inputString, idx);
	
		for (int i = 0; i < 4; i++)
			result += quad[i];
	}

	return result;

}


void solve() {
	string inputString;
	int idx = 0;

	cin >> inputString;

	cout << reverseQuadtree(inputString, idx) << endl;
}


int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		solve();
	}
}