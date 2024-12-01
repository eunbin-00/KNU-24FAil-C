#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TOPPING 10000

// topping_len�� �迭 topping�� �����Դϴ�.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int left_top[MAX_TOPPING + 1] = { 0, };
    int right_top[MAX_TOPPING + 1] = { 0, };
    int num_left = 0;
    int num_right = 0;

    for (int i = 0; i < topping_len; i++) {
        int top = topping[i]; //i������ �迭�� �ִ� �� top

        if (right_top[top] == 0) {
            num_right++;
        }
        right_top[top]++;// �ش��ϴ� top�� ����up
    }


    for (int i = 0; i < topping_len; i++) {
        int top = topping[i];
        right_top[top]--;
        if (right_top[top] == 0) {
            num_right--;

            if (left_top[top] == 0) {
                num_left++;
            }
            left_top[top]++;


        }
        if (num_right == num_left) {
            answer++;
        }

    }

    return answer;
}