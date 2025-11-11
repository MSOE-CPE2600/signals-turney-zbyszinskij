/**
 * File: signal_sigaction.c
 * Modified by: James Zbyszinski
 * 
 * Brief summary of program:
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig_num, siginfo_t *signal, void *context){ 

    printf("SIGUSR recieved\n"); 
    printf("Calling %d\n", signal->si_pid);

} 

int main(){

    struct sigaction sa; 
    sa.sa_sigaction = handler; 
    sa.sa_flags = SA_SIGINFO; 
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1) { 
        perror("Could not register signal\n"); 
        exit(1);
    } 

    while (1) { 
        printf("Waiting for signal to %d\n", getpid()); 
        sleep(1);
    } 

    return 0;

}