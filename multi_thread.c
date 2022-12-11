#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREAD 4

struct thread_data{ 
    long long start;
    long long end;
    long long sum;
};


void *worker(void *arg){ // 각 thread의 function
    struct thread_data *a= (struct thread_data*)arg;
    for (size_t i = a->start; i <= a->end; i++){  // 값들을 다 더해주는 역할.
        a->sum+=i;
    }
    return a;
}

int main(){
    int start=0;
    int goal=1000000000;
    long long all_sum=0;
    pthread_t myfunc_thread[NUM_THREAD]; // 멀티 스레드를 하기위해 배열로 만듦.
    int result[NUM_THREAD];
    struct thread_data a[NUM_THREAD]; // 데이터를 저장할 구조체 역시 배열로 만듦.

    int each=goal/NUM_THREAD;

    for (int i = 0; i < NUM_THREAD; i++) { // 각 스레드의 할당량 초기화
        // 각 스레드에서 처리할 데이터의 첫부분, 끝부분, sum값 초기화
        a[i].start=start+1;
        a[i].end=start+each;
        printf("%11lld ~ %11lld\n",a[i].start,a[i].end);
        a[i].sum=0;
        start=a[i].end;
        // printf("%d\n",a[i].start);
    }
    
    for (int i = 0; i < NUM_THREAD; i++) { // 이 부분에서 Thread개수 설정마다 총 4개, 2개, 1개의 Thread를 만듦.
        result[i]=pthread_create(&myfunc_thread[i],NULL,worker,(void*)&a[i]);
    }
    

    for (int i = 0; i < NUM_THREAD; i++) { // pthread_join을 통해 각 Thread가 끝나기를 기다렸다가, 완전 종료 시켜줌.
        pthread_join(myfunc_thread[i],NULL);
    }
    
    for (int i = 0; i < NUM_THREAD; i++) { // 각 sum값을 다 더하여 총 sum값 계산
        all_sum+=a[i].sum;
    }
    //모두 다 더한 값 출력.
    printf("%11lld\n",all_sum);

    pthread_exit(NULL);
    return 0;
}