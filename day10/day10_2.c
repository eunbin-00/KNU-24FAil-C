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

// 노드 생성
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

// 우선순위 따져 넣기
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

// 노드 삽입
void insert_node(struct Customer* new_customer) {
    struct Customer* n = find_node(new_customer->rank, new_customer->order_amount, new_customer->point);

    new_customer->next = n;
    new_customer->prev = n->prev;
    n->prev->next = new_customer;
    n->prev = new_customer;
}

// 노드 출력
void print_node() {
    struct Customer* cur = head->next;

    printf("---------------------------------\n");
    while (cur != tail) {
        printf("이름: %s\n", cur->customerName);
        printf("등급: %d\n", cur->rank);
        printf("주문량: %d\n", cur->order_amount);
        printf("포인트: %d\n\n", cur->point);
        cur = cur->next;
    }
    printf("---------------------------------\n");
}

// 고객 삭제
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

// 고객 수정
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
            temp->next = temp->prev = NULL; // 삽입을 위해 링크 초기화
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
        printf("1. 고객 정보 입력\n");
        printf("2. 고객 정보 삭제\n");
        printf("3. 고객 정보 수정\n");
        printf("4. 프로그램 종료\n");
        printf("input: ");
        scanf_s("%d", &num);

        switch (num) {
        case 1:
            printf("고객 이름: ");
            scanf_s("%s", customerName, 30);
            printf("등급 (1: A, 2: B, 3: C, 4: D, 5: E): ");
            scanf_s("%d", (int*)&rank);
            printf("주문량: ");
            scanf_s("%d", &order_amount);
            printf("포인트: ");
            scanf_s("%d", &point);
            insert_node(create_node(customerName, rank, order_amount, point));
            break;

        case 2:
            printf("삭제할 고객의 이름: ");
            scanf_s("%s", customerName,30);
            delete_node(customerName);
            break;

        case 3:
            printf("수정할 고객의 이름: ");
            scanf_s("%s", customerName,30);
            printf("1. 등급 수정\n2. 주문량 수정\n3. 포인트 수정\n");
            printf("Input: ");
            scanf_s("%d", &num_e);
            printf("새로운 값: ");
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