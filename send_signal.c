/**
 * File: send_signal.c
 * Modified by: James Zbyszinski
 * 
 * Brief summary of program: Sends a signal of a random value using SIGUSR
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>


int main(int argc, char* argv[]){

    if(argc == 2){
        int pid = atoi(argv[1]);
        union sigval val;
        
        srand(time(NULL));
        val.sival_int = rand() % 100;

        if(sigqueue(pid, SIGUSR1, val) == -1){
            printf("Error sending signal\n");
        }
        else{
            printf("%d, sent to pid %d with SIGUSR1\n", val.sival_int, pid);
        }
    }
    else{
        printf("Invalid argument\n");
    }

    return 0;

}