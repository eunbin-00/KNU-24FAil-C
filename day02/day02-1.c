#include <stdio.h>

int main() {
	int n;
	double a, b;
	printf("1.���ϱ�  2.����  3.���ϱ�  4.������\n ");
	printf("���ϴ� ����� ���ڷ� �Է����ּ���: ");
	scanf_s("%d", & n);
	printf("\n����� ���� 2���� �Է����ּ���.:");
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
		printf("��� �Է� ����");
	}
	return 0;
}