#include <stdio.h>
#include <string.h>

void reverse(char* str); 

int main() {
    char str[100];

    printf("문자열을 입력하세요: ");
    scanf_s("%s", sizeof(str));  

    reverse(str); 
    printf("뒤집어진 문자열: %s\n", str);  

    return 0;
}

void reverse(char* str) {
    int len = strlen(str);  
    char temp;

    for (int i = 0; i < len/2 ; i++) {
        temp = str[i];
        str[i] = str[len - i -1];
        str[len - i -1] = temp;
    }
}