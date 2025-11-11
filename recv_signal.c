/**
 * File: recv_signal.c
 * Modified by: James Zbyszinski
 * 
 * Brief summary of program: Waits until a signal is recieves a signal and outputs the value of the
 *                           signal recieved
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int sig_num, siginfo_t *info, void *context){
    printf("Signal value of %d recieved\n", info->si_value.sival_int);
    exit(0);
}

int main(){

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigaction(SIGUSR1, &sa, NULL);

    printf("Wating fo SIGUSR command to %d\n", getpid());

    while(1){
        sleep(1);
    }

    return 0;
}