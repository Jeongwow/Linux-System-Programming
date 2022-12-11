#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct two_double
{
    double a;
    double b;
}data;

void signal_handler(int signo){
    printf("%f, %f\n",data.a,data.b);
    alarm(1);
}

int main() {
    struct sigaction sa;
    static struct two_double zeros={0.0,0.0},ones={1.0,1.0};

    sigemptyset(&sa.sa_mask);
    sa.sa_flags=0;
    sa.sa_handler = signal_handler;
    if(sigaction(SIGALRM,&sa,NULL)==-1){
        perror("sigaction");
        exit(0);
    }
    data=zeros;
    alarm(1);
    while(1){
        // 이 부분에서 sa.sa_mask라는 signal set
        sigprocmask(SIG_BLOCK,&sa.sa_mask,NULL);
        data=zeros;
        sigprocmask(SIG_UNBLOCK,&sa.sa_mask,NULL);
        sigprocmask(SIG_BLOCK,&sa.sa_mask,NULL);
        data=ones;
        sigprocmask(SIG_UNBLOCK,&sa.sa_mask,NULL);
    }
}