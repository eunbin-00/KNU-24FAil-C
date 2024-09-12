#include <stdio.h>

int main() {
	int n;
	double a, b;
	printf("1.더하기  2.빼기  3.곱하기  4.나누기\n ");
	printf("원하는 기능을 숫자로 입력해주세요: ");
	scanf_s("%d", & n);
	printf("\n계산할 숫자 2개를 입력해주세요.:");
	scanf_s("%lf %lf", &a, &b);
	double result = 0;

	if (n == 1) {
		result = a + b;
		printf("%lf", result);
	}
	else if (n == 2) {
		result = a - b;
		printf("%lf", result);
	}
	else if (n == 3) {
		result = a * b;
		printf("%lf", result);
	}
	else if (n == 4) {
		result = a / b;
		printf("%lf", result);
	}
	else {
		printf("기능 입력 오류");
	}
	return 0;
}