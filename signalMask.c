#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    sigset_t block_set, prev_set;

    // initialize a signal set to contain SIGINT
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    // block SIGINT
    sigprocmask(SIG_BLOCK, &block_set, &prev_set);

    printf("going to sleep 5 seconds, try control-C\n");
    sleep(5);
    printf("going ahead\n");

    // restore original siganl
    sigprocmask(SIG_SETMASK,&prev_set,NULL);
    while(1){
        printf("doing useless....\n");
        sleep(1);
    }

}