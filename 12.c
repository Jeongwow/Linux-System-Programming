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
    // // 입력
    // scanf("%s", str[0]);
    // scanf("%s", str[1]);

    str[0][0]='a';
    str[0][1]='b';
    str[0][2]='c';

    str[1][0]='w';
    str[1][1]='b';
    str[1][2]='v';
    


    swap(str[0], str[1]);
    //출력
    printf("%s\n%s\n", str[0], str[1]);
    return 0;
}