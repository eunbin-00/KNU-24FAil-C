#include <stdio.h>

int rec(int a);

int main() {
	int in;
	printf("계산할 팩토리얼 값 입력 : ");
	scanf_s("%d", &in);
	int result = rec(in);
	printf("%d! = %d", in, result);
		
}
int rec(int a) {
	if (a == 1 || a== 0) {
		return 1;
	}
	int res;
	res = a* rec(a - 1);
	return res;
}