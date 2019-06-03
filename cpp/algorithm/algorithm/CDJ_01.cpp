#include<stdio.h>
#include<iostream>

using namespace std;

void solve() {
	char N[110];
	char a[110], b[110];
	int size = 0;
	
	cin >> N;

	for (int i = 0; N[i] != '\0'; i++) {
		if (N[i] == '\n') continue;
		int num = N[i] - '0';
		if (num == 4) {
			a[i] = '3';
			b[i] = '1';
		}
		else {
			a[i] = N[i];
			b[i] = '0';
		}
		size++;
	}
	a[size] = '\0';

	printf("%s ", a);

	int isZero = true;
	for (int i = 0; i < size; i++) {
		if (isZero) {
			if (b[i] == '0') continue;
			isZero = false;
		}

		printf("%c", b[i]);
	}
}


int main() {

	int t;
	scanf_s("%d", &t);

	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 0;
}