#include <stdio.h>
#include <unistd.h>
#include "home_task.h"

int main(){
    printf("Starting the program...\n");
    printf("I am the main process with PID: %d\n", getpid());

    int pid = fork();
    if(pid == 0){
        printf("I am the child process with PID: %d and PPID: %d\n", getpid(), getppid());
        ChildProcess();
    } else if(pid > 0){
        printf("I am the parent process with PID: %d\n", getpid());
        ParentProcess();
    } else {
        perror("fork failed");
        return 1;
    }
    return 0;
}

void ChildProcess(void){
    for(int i = 0; i < MAX_COUNT; i++){
        printf("This line is from child, value = %d\n", i);
    }
}

void ParentProcess(void){
    for(int i = 0; i < MAX_COUNT; i++){
        printf("This line is from parent, value = %d\n", i);
    }
}