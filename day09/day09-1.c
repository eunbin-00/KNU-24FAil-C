#include<stdio.h> 

struct vec {
	int x, y, z;
};

void func1( struct vec v1, struct vec v2) {
	printf("x= %d, y= %d, z= %d", v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

void func2(struct vec v1, struct vec v2) {
	printf("x= %d, y= %d, z= %d", v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

void func3(struct vec v1, struct vec v2) {
	printf("x= %d, y= %d, z= %d", v1.y * v2.z - v1.z * v2.y, v1.x * v2.z - v1.z * v2.x, v1.x * v2.y - v1.y * v2.x);
}

void func4(struct vec v1, struct vec v2) {
	printf("v1 * v2 = %d", v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

int main() {


	struct vec v1;
	struct vec v2;

	printf("ù��° ����(x,y,z): ");
	scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
	printf("�ι�° ����(x,y,z): ");
	scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

	printf("\n�Էµ� ù��° ����: \t%d, \t%d, \t%d", v1.x, v1.y, v1.z);
	printf("\n�Էµ� �ι�° ����: \t%d, \t%d, \t%d\n\n", v2.x, v2.y, v2.z);

	int n;
	printf("1.������ �� \n2.������ �� \n3.������ ���� \n4.������ ���� \n5.����\n");


	int t= 1;
	while (t) {
		printf("����Է�: ");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("������ ���� ");
			func1(v1, v2);
			printf("\n");
			break;
		case 2:
			printf("������ ���� ");
			func2(v1, v2);
			printf("\n");
			break;
		case 3:
			printf("������ ������ ");
			func3(v1, v2);
			printf("\n");
			break;
		case 4:
			printf("������ ������ ");
			func4(v1, v2);
			printf("\n");
			break;
		case 5:
			t = 0;
			break;
		default:
			printf("�Է� ����");
			printf("\n");
		}
	}
	

}