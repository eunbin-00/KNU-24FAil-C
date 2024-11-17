#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum rank {
    A = 1, 
    B,
    C,
    D,
    E  
};

struct Customer {
    char* customerName;
    enum rank rank;
    int order_amount; 
    int point; 
    struct Customer* prev, * next;
};

struct Customer* head, * tail;

// ��� ����
struct Customer* create_node(char* customerName, enum rank rank, int order_amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    new_customer->customerName = (char*)malloc(strlen(customerName) + 1); 
    strcpy_s(new_customer->customerName,30, customerName);

    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->next = new_customer->prev = NULL;

    return new_customer;
}

// �켱���� ���� �ֱ�
struct Customer* find_node(enum rank rank, int order_amount, int point) {
    struct Customer* cur = head->next; 

    while (cur != tail) { 
        if (cur->rank > rank) return cur; 
        if (cur->rank == rank && cur->order_amount < order_amount) return cur; 
        if (cur->rank == rank && cur->order_amount == order_amount && cur->point < point) return cur; 

        cur = cur->next; 
    }

    return tail; 
}

// ��� ����
void insert_node(struct Customer* new_customer) {
    struct Customer* n = find_node(new_customer->rank, new_customer->order_amount, new_customer->point);

    new_customer->next = n;
    new_customer->prev = n->prev;
    n->prev->next = new_customer;
    n->prev = new_customer;
}

// ��� ���
void print_node() {
    struct Customer* cur = head->next;

    printf("---------------------------------\n");
    while (cur != tail) {
        printf("�̸�: %s\n", cur->customerName);
        printf("���: %d\n", cur->rank);
        printf("�ֹ���: %d\n", cur->order_amount);
        printf("����Ʈ: %d\n\n", cur->point);
        cur = cur->next;
    }
    printf("---------------------------------\n");
}

// �� ����
int delete_node(char* customerName) {
    struct Customer* prev = head;
    struct Customer* cur = head->next;
    while (cur != NULL) {
        if (strcmp(customerName, cur->customerName) == 0) {
            prev->next = cur->next;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

// �� ����
int edit_node(char* name, int num_e, int new_value) {
    struct Customer* cur = head->next;

    while (cur != tail) {
        if (strcmp(name, cur->customerName) == 0) {
            switch (num_e) {
            case 1: 
                cur->rank = new_value;
                break;
            case 2: 
                cur->order_amount = new_value;
                break;
            case 3: 
                cur->point = new_value;
                break;
            default:
                return 0;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            struct Customer* temp = cur;
            temp->next = temp->prev = NULL; // ������ ���� ��ũ �ʱ�ȭ
            insert_node(temp);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}


int main() {
    char customerName[30];
    int order_amount, point, num, num_e, new_value;
    enum rank rank;
    int w = 1;

    head = (struct Customer*)malloc(sizeof(struct Customer));
    tail = (struct Customer*)malloc(sizeof(struct Customer));
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;

    while (w) {
        printf("1. �� ���� �Է�\n");
        printf("2. �� ���� ����\n");
        printf("3. �� ���� ����\n");
        printf("4. ���α׷� ����\n");
        printf("input: ");
        scanf_s("%d", &num);

        switch (num) {
        case 1:
            printf("�� �̸�: ");
            scanf_s("%s", customerName, 30);
            printf("��� (1: A, 2: B, 3: C, 4: D, 5: E): ");
            scanf_s("%d", (int*)&rank);
            printf("�ֹ���: ");
            scanf_s("%d", &order_amount);
            printf("����Ʈ: ");
            scanf_s("%d", &point);
            insert_node(create_node(customerName, rank, order_amount, point));
            break;

        case 2:
            printf("������ ���� �̸�: ");
            scanf_s("%s", customerName,30);
            delete_node(customerName);
            break;

        case 3:
            printf("������ ���� �̸�: ");
            scanf_s("%s", customerName,30);
            printf("1. ��� ����\n2. �ֹ��� ����\n3. ����Ʈ ����\n");
            printf("Input: ");
            scanf_s("%d", &num_e);
            printf("���ο� ��: ");
            scanf_s("%d", &new_value);
            edit_node(customerName, num_e, new_value);

            break;

        case 4:
        default:
            w = 0;
            break;

        }
        if (w == 1) { print_node(); }
    }
    return 0;
}