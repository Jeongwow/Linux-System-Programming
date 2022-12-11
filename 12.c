#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(char* str1, char* str2)
{
    char* temp;
    temp = str1;
    str1 = str2;
    str2 = temp;
}

int main() 
{
    char str[2][100];
    // 입력
    scanf("%s", str[0]);
    scanf("%s", str[1]);

    swap(str[0], str[1]);
    //출력
    printf("%s\n%s", str[0], str[1]);
    return 0;
}