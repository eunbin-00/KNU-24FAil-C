#include<stdio.h>

int main() {
	int i,j,k, high;
	printf("피라미드의 층수를 입력하시오: ");
	scanf_s("%d", &high);
	printf("%d층 피라미드\n", high);
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