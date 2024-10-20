#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void fillRandom (int array[SIZE][SIZE]);
void printArray (int array[SIZE][SIZE]);
void movePointer(void* array);

int main() {
	int array[SIZE][SIZE];

	fillRandom(array);
	printArray(array);
	movePointer(array);


	return 0;
}

void fillRandom(int array[SIZE][SIZE]) {
	srand(1);
	for (int i = 0; i<10; i++) {
		for (int j = 0; j < 10; j++) {
			array[i] [j] = rand( ) % 19 + 1;
		}
	}
}

void printArray(int array[SIZE][SIZE]) {
	printf("�迭 ���: \n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	int a = 0, b = 0, c=0 ; 
	int n=0 ;
	

	while (1) {
		int value = *((int*)array + n);
		n = n + value;
		printf("���� ��ġ : (%d, %d), �迭�� �� :%d  \n", a, b, value);
		if (n >= 100) {
			printf("�� �̻� �̵��� �� �����ϴ�\n");
			printf("���� ��ġ: (%d, %d), �迭�� �� :%d  ", a, b, value);
			break;
		}
		c = a * 10 + b + value;
		a = c / 10;
		b = c % 10;
	}



}