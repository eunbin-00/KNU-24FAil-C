#include<stdio.h> 

struct Product {
	int id, cost;
	char name[100];
};

void printProduct(struct Product p) {
	printf("상품 ID %d\n", p.id);
	printf("상품명  %s\n", p.name);
	printf("가격 %d\n\n", p.cost);
}

int main() {



	struct Product p[5];
	int n = 0;
	for (int i = 0; i <= 4; i++) {
		printf("상품정보를 입력하세요 (입력중단은 id에 0입력)\n");
		printf("상품 ID: ");
		scanf_s("%d", &p[i].id);
		if (p[i].id == 0) {
			break;
		}
		printf("상품명: ");
		scanf_s("%s", p[i].name, sizeof(p[i].name));
		printf("가격: ");
		scanf_s("%d", &p[i].cost);
		printf("\n");
		n = n + 1;


	}
	printf("\n\n<입력된 상품 목록>\n");
	for (int j = 0; j < n; j++) {
		printProduct(p[j]);
	}
	return 0;
}
