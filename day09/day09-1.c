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

	printf("첫번째 벡터(x,y,z): ");
	scanf_s("%d %d %d", &v1.x, &v1.y, &v1.z);
	printf("두번째 벡터(x,y,z): ");
	scanf_s("%d %d %d", &v2.x, &v2.y, &v2.z);

	printf("\n입력된 첫번째 백터: \t%d, \t%d, \t%d", v1.x, v1.y, v1.z);
	printf("\n입력된 두번째 백터: \t%d, \t%d, \t%d\n\n", v2.x, v2.y, v2.z);

	int n;
	printf("1.벡터의 합 \n2.벡터의 차 \n3.벡터의 외적 \n4.벡터의 내적 \n5.종료\n");


	int t= 1;
	while (t) {
		printf("명령입력: ");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("벡터의 합은 ");
			func1(v1, v2);
			printf("\n");
			break;
		case 2:
			printf("벡터의 합은 ");
			func2(v1, v2);
			printf("\n");
			break;
		case 3:
			printf("벡터의 외적은 ");
			func3(v1, v2);
			printf("\n");
			break;
		case 4:
			printf("벡터의 내적은 ");
			func4(v1, v2);
			printf("\n");
			break;
		case 5:
			t = 0;
			break;
		default:
			printf("입력 오류");
			printf("\n");
		}
	}
	

}