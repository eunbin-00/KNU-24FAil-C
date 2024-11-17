#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
	char name [30];
	int jumsu;
	struct NODE* link;
};

struct NODE* head;

struct NODE* cre_node(char* name, int jumsu) {
	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy_s(new_node->name, 30, name);
	new_node->jumsu = jumsu;
	new_node->link = NULL;

	return new_node;
}

struct NODE* find_node(int jumsu)
{
	struct NODE* prev = head;
	struct NODE* cur = head->link;
	if (cur == NULL) {
		return head;
	}
	while (cur != NULL) {
		if (cur->jumsu >= jumsu) {
			if (cur->link == NULL) {
				return cur;
			}
			prev = cur;
			cur=cur->link;
			return prev;
		}
		else {
			return prev;
		}
	}
}


void ins_node (struct NODE* new_node) {
	struct NODE* n = find_node(new_node -> jumsu);
	new_node->link = n->link;
	n->link = new_node;
} //jumsu�� �� ���� ���� �Ʒ��� �Էµ�

void pri_node()
{
	struct NODE* cur = head->link;
	printf("---------------------------------\n");
	while (cur != NULL) {
		printf("%s: %d\n", cur->name , cur->jumsu);
		cur = cur->link;
	}
	printf("---------------------------------\n");
 }



int del_node(char* name) {
	struct NODE* prev = head;
	struct NODE* cur = head-> link;
	while (cur != NULL) {
		if (strcmp(name, cur->name)==0) {
			prev->link = cur->link;
			free(cur);
			return 1;
		}
		prev = cur;
		cur = cur->link;
	}
	return 0;
}





int main() {
	int num, jumsu, w=1;
	char name[30];
	head= (struct NODE*)malloc(sizeof(struct NODE));
	head->link=NULL; //head �ʱ�ȭ

	while (w)
	{
		printf("1.�л��� ������ �Է�: \n");
		printf("2.�л� ���� ����\n");
		printf("3.���α׷� ����: \n");
		printf("input: ");
		scanf_s("%d", &num);
		switch (num) {
		case 1:
			printf("�л��̸�: ");
			scanf_s("%s", name, 30);
			printf("����: ");
			scanf_s("%d", &jumsu);
			ins_node(cre_node(name, jumsu));
			break;

		case 2:
			printf("\n������ �л��� �̸�: ");
			scanf_s("%s", name, 30);
			del_node(name);
			break;

		case 3:
		default:
			w = 0;
			break;
		}
		pri_node();
	}
	return 0;
}