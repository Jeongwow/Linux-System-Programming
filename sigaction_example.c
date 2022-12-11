#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler_ouch(int sig){
    printf("This is handler : I got this siganl %d\n",sig);
}

int main(){
    struct sigaction siga;

    sigemptyset(&siga.sa_mask);
    siga.sa_flags=0;
    siga.sa_handler=handler_ouch;
    if(sigaction(SIGINT,&siga,NULL)==-1){
        perror("sigaction");
        exit(0);
    }
    while (1) {
        printf("Hello world\n");
        sleep(1);
    }
    

}