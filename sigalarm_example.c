#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int waitting = 1;

void handlerH(int sig){
    waitting=0;
}

int main(){
    struct sigaction siga;

    sigemptyset(&siga.sa_mask);
    siga.sa_flags=0;
    siga.sa_handler = handlerH;

    if(sigaction(SIGALRM, &siga, NULL)==-1){
        perror("sigaction");
        exit(0);
    }
    alarm(5);
    while(waitting != 0){
        printf("Hello world\n");
        sleep(1);
    }
}