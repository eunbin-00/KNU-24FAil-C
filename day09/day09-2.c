#include<stdio.h> 

struct Product {
	int id, cost;
	char name[100];
};

void printProduct(struct Product p) {
	printf("��ǰ ID %d\n", p.id);
	printf("��ǰ��  %s\n", p.name);
	printf("���� %d\n\n", p.cost);
}

int main() {



	struct Product p[5];
	int n = 0;
	for (int i = 0; i <= 4; i++) {
		printf("��ǰ������ �Է��ϼ��� (�Է��ߴ��� id�� 0�Է�)\n");
		printf("��ǰ ID: ");
		scanf_s("%d", &p[i].id);
		if (p[i].id == 0) {
			break;
		}
		printf("��ǰ��: ");
		scanf_s("%s", p[i].name, sizeof(p[i].name));
		printf("����: ");
		scanf_s("%d", &p[i].cost);
		printf("\n");
		n = n + 1;


	}
	printf("\n\n<�Էµ� ��ǰ ���>\n");
	for (int j = 0; j < n; j++) {
		printProduct(p[j]);
	}
	return 0;
}
