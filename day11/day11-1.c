#include<stdio.h>
#include<math.h>

/*int find_d(int a, int b, int c) {
	int d;
	d = b * b - 4 * a * c;
	return d;
}

float find_x(int a, int b, )*/

int main() {
	int a, b, c, D;
	float x1, x2;
	printf("���� �������� ��� �Է�: ");
	scanf_s("%d %d %d", &a, &b, &c);
	D = b * b - 4 * a * c;
	x1 = (-b + sqrt(D)) / 2 * a;
	x2 = (-b - sqrt(D)) / 2 * a;
	if (D > 0) {
		printf("������������ ��: %.2f, %.2f", x1, x2);
	}
	else if (D == 0) {
		printf("������������ ��: %.2f ", x1 );
	}
	else {
		printf("������������ ��: ���");
	}
	
}