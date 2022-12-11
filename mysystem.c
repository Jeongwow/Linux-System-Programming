#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(char *command){
    //man page를 참고...

    int f_return=fork(); //fork를 통해 자식 프로세스 생성
    int status;
    if (f_return==0) {  //fork 리턴 0 --> child process
        execl("/bin/bash","/bin/bash","-c",command,NULL); 
    }
    else if(f_return==-1){   //fork 리턴 -1 --> child process 생성 실패
        perror("Error : ");
        exit(0);
    }
    else{  //fork 리턴 child process's pid --> parent process
        wait(&status);   // status에 child process의 exit status를 채워줌.
    }
    return status;
}


int main(){
    // system("ls -l | wc -l");
    int status = my_system("ls -l");
    printf("exit code %d \n",WEXITSTATUS(status)); 
    // 함수 내부에서 child process를 실행시키고,
    //WEXITSTATUS를 통해 함수의 리턴값으로 받아온 status중에서 exit status(8~15비트)의 status만 추출해서 리턴

}