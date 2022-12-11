#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig){
    printf("handler : I got a signal %d\n",sig);
}

int main(){
    signal(SIGINT, handler); // 핸들러 설정
    //     signal(SIGSTOP, handler); 
    // 이렇게 하면 왜 sigstop 들어왔을 때 handler함수 실행 안할까..
    while(1){
        printf("Hello world\n");
        sleep(1);
    }
}