#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("I am child and i am starting...\n");
        fflush(stdout);
        int fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644); 
        if (fd < 0) {
            perror("open failed");
        }

        dup2(fd, 1);
        close(fd);

        printf("I am child and i am changing the process to execute another command. After dup2 this messages will be printed in the file\n");
        fflush(stdout);

        execvp(argv[2], &argv[2]);
        
        perror("execvp failed"); 
        exit(1); 

    } else {
        printf("I am parent with child PID: %d\n", pid);
        printf("I am waitng of end my child process\n");
        
        sleep(5); 
        printf("All processes are ended\n");
    }

    return 0;
}
