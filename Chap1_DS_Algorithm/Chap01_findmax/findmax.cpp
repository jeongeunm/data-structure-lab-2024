#include <cstdio>

int findArraymax(int score[], int n)
{
	int tmp = score[0];
	for (int i = 1; i < n; i++) {
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}

void main() {
	int score[5] = { 1, 10, 2, 4, 5 };
	int out;
	out = findArraymax(score, 5);
	printf("result = %d", out);
}