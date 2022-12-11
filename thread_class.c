#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *myfunc(void *arg){
    printf("I'm hello world\n");
    pthread_exit(NULL);
}

int main(){
    int n=100;
    pthread_t myfunc_thread[n];
    int result[n];


    for(int i=0; i<n; i++){
        result[i]=pthread_create(&myfunc_thread[i],NULL,myfunc,NULL);
        if (result[i]){
            exit(1);
        }
    }

    
    // pthread_join(myfunc_thread, NULL);
    for(int i=0; i<n; i++){
        pthread_join(myfunc_thread[i], NULL);
    }
    printf("I am the main thread\n");


    
    pthread_exit(NULL);
    return 0;
}