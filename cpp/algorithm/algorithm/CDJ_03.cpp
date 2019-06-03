#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int alpa[28];

int primArr[10010];


char findAlpa(int num) {
	for (int i = 0; i < 26; i++) {
		if (alpa[i] == num) {
			return (char)(i + 'A');
		}
	}
	return 'A';
}


void solve() {
	int L;
	int N, prime[110];

	cin >> N >> L;

	long long inputNum[110];

	for (int i = 0; i < L; i++) {
		cin >> inputNum[i];
	}

	long long num1 = inputNum[0], num2 = inputNum[1];
	int a, b;

	for (int i = 3; i*i <= num1; i++) {
		if (primArr[i] == 1) continue;
		if (num1%i == 0) {
			a = i;
			b = num1 / i;
			break;
		}
	}
	int first, second;
	int currNum;
	if (num2%a == 0) {
		first = currNum = prime[0] = b;
		second = a;
	}
	else {
		first = currNum = prime[0] = a;
		second = b;
	}

	bool isSuccess = true;

	for (int i = 0; i < L; i++) {
		if (inputNum[i] < currNum) {
			isSuccess = false;
			break;
		}
		prime[i + 1] = inputNum[i] / currNum;
		currNum = prime[i + 1];
	}


	if (!isSuccess) {
		currNum = second;
		first = second;
		for (int i = 0; i < L; i++) {
			prime[i + 1] = inputNum[i] / currNum;
			currNum = prime[i + 1];
		}
	}

	sort(prime, prime + (L + 1));

	int before = -1;
	int top = 0;
	for (int i = 0; i <= L; i++) {
		if (before != prime[i]) {
			alpa[top++] = prime[i];
			before = prime[i];
		}
	}

	currNum = first;
	printf("%c", findAlpa(first));
	for (int i = 0; i < L; i++) {
		if (currNum <= 0) return;
		currNum = inputNum[i] / currNum;
		printf("%c", findAlpa(currNum));
	}

}


int main() {

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 0;
}