#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    
    if (pid==0)
    {
        printf("child pid : %d,    ppid : %d\n",getpid(),getppid()); 
        for(int i=0; i<100;i++){
            printf("%d ",i);
            fflush(NULL);
        }  
        exit(101); 
    }
    else{
        int exitstatus;
        // while(1);   // 여기에서 wait을 안 해주게  반복문을 만들어주어서 wait 안 실행하게 함.
        for(int i=100; i<200;i++){
            printf("%d ",i);
            fflush(NULL);
        }
        wait(&exitstatus);
        printf("parent pid : %d,    ppid : %d\n",getpid(),getppid());  
        printf("exitcode : %d\n",WEXITSTATUS(exitstatus));  
    }
}