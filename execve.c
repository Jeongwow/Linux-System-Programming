#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    pid_t pid=fork();
    if (pid==0)
    {
        char *new_argv[]={"ls","-l",NULL};
        execve("/bin/ls", new_argv, NULL); 
    }
    else{
        wait(&pid);
        printf("Hello world\n");
    }
}
