#include <stdio.h>

int rec(int a);

int main() {
	int in;
	printf("����� ���丮�� �� �Է� : ");
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