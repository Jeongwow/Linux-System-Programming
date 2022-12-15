#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void fork1(){
    int x=1;
    pid_t pid=fork();
    if (pid==0)
    {
        printf("child has x = %d\n",++x);
    }
    else {
        printf("parent has x = %d\n",--x);
    }
    printf("bye from process %d with x = %d\n",getpid(),x);
}

void fork3(){
    printf("L0\n");
    fork();
    printf("L1\n");
    fork();
    printf("L2\n");
    fork();
    printf("Bye\n");
}

int main(){
    fork3();
}