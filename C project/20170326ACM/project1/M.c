# include<stdio.h>
# include<stdlib.h>
# include<math.h>

void qsort(int *p, int start, int end)
{
	if (start < end) {
		int i = start;														//i代表了左边小于p[start]的数的最大下标，j代表了找到的小于p[start]的最小的数
		for (int j = i + 1; j <= end; j++) {
			if (p[j] < p[start]) {										//运用了双指针错位的方法
				i++;
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
		int temp = p[i];
		p[i] = p[start];
		p[start] = temp;


		qsort(p, start, i - 1);
		qsort(p, i + 1, end);
	}


int in()
{
	int n, s;
	scanf("%s %s", n, s);
	int N = n - '0';
	int  S = s - '0';
	int A[N], C[N], L[N], R[N],L = 0,R = 0,spend[N];
	int i ,j,k,cnt = 0,ans = 0;
	for (i = 0; i < N; i++) {
		scanf("%d %d %d %d", A[i], C[i], L[i], R[i]);
	}

	for (j = 0; i < N; j++) {
		L += L[j];
		R += R[j];	
	}
	if (S > R || S<L)		printf("impossible");

	qsort(&A[0], 0, N - 1);

	for (k = 0; k<N; k++) {
		if (L[k] <= A[k] <= R[k])	spend[k] = 0;
		else {
			if (abs(A[i] - L[i])>abs(A[i] - R[i]))		spend[k] = abs(A[i] - R[i]);
			else	spend[k] = abs(A[i] - L[i]);
		}
	
			
			
			
			
			
			
			
			if (abs(A[i] - L[i])>C[i] || abs(A[i] - R[i])>C[i]) {
		cnt++;
	}
			else if(abs(A[i] - L[i])>abs(A[i] - R[i])) {
			ans += abs(A[i] - R[i]);
		}
	

	system("pause");
	return 0;
}