#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct thread_data
{
    long long start;
    long long end;
    long long sum;
};

void *worker(void *arg){
    struct thread_data *data=(struct thread_data*)arg;
    for (size_t i = data->start; i <= data->end; i++)
    {
        data->sum+=i;
    }
    return data;
}

int main(){
    struct thread_data t_data;
    pthread_t mythread;
    int result;
    t_data.start=0;
    t_data.end=100;
    t_data.sum=0;


    result=pthread_create(&mythread,NULL,worker,(void *)&t_data);

    pthread_join(mythread,NULL);
    printf("sum : %11lld\n",t_data.sum);
    pthread_exit(NULL);
    return 0;
}