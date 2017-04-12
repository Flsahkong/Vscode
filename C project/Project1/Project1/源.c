# include<stdio.h>
//# define T 1
//# define i 1
//# define j 1
//# define M 1
//# define N 1

//using namespace std;

int minDay(int N, int M, int * p);

int main() {
	int T = 1, i = 1, j = 1, M = 1, N = 1;
	

	scanf("%d", &T);
	int days[T];
	for (i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		int house[N];
		for (j = 0; j < N; j++) {
			scanf("%ld", &house[j]);
		}
		days[i] = minDay(N, M, house);
	}
	for (i = 0; i < T; i++) {
		printf("Case #%d: %ld\n", i + 1, days[i]);
	}
	return 0;
}

int minDay(int N, int M, int * house) {
	int i, j;
	int days = 0;
	for (i = 0; i < N; i++) {
		int t = house[i];
		if (house[i] <= 0) continue;
		days += house[i];
		for (j = 0; j < M; j++) {
			if (house[i + j] > 0) house[i + j] -= t;
		}
	}
	return days;
}