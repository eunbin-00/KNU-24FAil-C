#include<stdio.h>
#include<math.h>
//f(1)*(b-a)/n +..+ f(n)*(b-a)/n

double f(double x) {
	return  - log10(1.0 / x) + sin(x);
}

int main() {
	int start, end, n_max;
	double range, sum=0;
	printf("적분할 시작 값을 입력하세요: ");
	scanf_s("%d", &start);
	printf("적분할 끝 값을 입력하세요: ");
	scanf_s("%d", &end);
	printf("시행할 최대 구간을 입력하세요(2^n): ");
	scanf_s("%d", &n_max);

	for (int i = 0; i <= n_max; i++) {
		range = ((end - start) / pow(2,i));
		sum = 0;
		for (int j = 0; j <pow(2,i); j++) {
			double x = start + range * j;
			sum = sum + f(x) * range;
		}
		printf("구간: %-10d 적분 결과: %f\n", (int)pow(2, i), sum);
	}


	return 0;
}