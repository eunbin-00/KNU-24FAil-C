#include<stdio.h>

int main() {
	int i,j,k, high;
	printf("�Ƕ�̵��� ������ �Է��Ͻÿ�: ");
	scanf_s("%d", &high);
	printf("%d�� �Ƕ�̵�\n", high);
	for (i = 1; i <= high; i++) {
		for (j = 1; j <= high - i; j++) {
			printf(" ");
		}
		for (k = 1; k <= 2 *i - 1;k++ ) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}