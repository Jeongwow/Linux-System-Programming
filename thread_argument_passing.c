#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct thread_data{
    long long start;
    long long end;
    long long sum;  
};

void *worker(void *arg){
    struct thread_data *a= (struct thread_data*)arg;
    for (size_t i = a->start; i <= a->end; i++){
        a->sum+=i;
    }
    return a;
}

int main(){
    int n=10;
    pthread_t myfunc_thread;
    int result;
    struct thread_data a;
    a.start=0;
    a.end=100;
    a.sum=0;

    result=pthread_create(&myfunc_thread,NULL,worker,(void*)&a);

    pthread_join(myfunc_thread,NULL);

    printf("sum : %11lld\n",a.sum);
    pthread_exit(NULL);
    return 0;
}