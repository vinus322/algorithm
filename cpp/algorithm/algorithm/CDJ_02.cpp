#include<stdio.h>
#include<iostream>

using namespace std;

void solve() {
	int N;
	char inputStr[100010];

	cin >> N >> inputStr;

	for (int i = 0; inputStr[i]!='\0'; i++) {
		char changeDir = inputStr[i] == 'E' ? 'S' : 'E';
		printf("%c", changeDir);
	}
}


int main() {

	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 0;
}