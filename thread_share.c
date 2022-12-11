#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 1

volatile static long long counter=0; //
volatile static char is_running=1;

void *myfunc(void *arg){

    while(is_running== 1){
        counter++;
    }
    pthread_exit(NULL);
}

int main(){
    int n=10;
    pthread_t myfunc_thread[n];
    int result[n];


    for(int i=0; i<n; i++){
        result[i]=pthread_create(&myfunc_thread[i],NULL,myfunc,NULL);
        if (result[i]){
            exit(1);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("counter : %11lld\n",counter);
        sleep(1);
    }
    is_running=0;
    
    printf("hello im main thread\n");
    pthread_exit(NULL);
    return 0;
}