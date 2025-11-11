/**
 * File: signal_alarm.c
 * Modified by: James Zbyszinski
 * 
 * Brief summary of program: Sets an alarm to go off in five seconds.
 *                           The program will then use a signal hanlder to tell the user that the alarm
 *                           signal was recieved
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_alarm(){
    printf("Alarm signal recieved\n");
}

int main(void){


    signal(SIGALRM, handle_alarm);

    printf("Alarm going off in\n");

    alarm(5);

    for(int i = 5; i > 0; i--){
        printf("%d\n", i);
        sleep(1);
    }

    if (signal(SIGALRM, handle_alarm) == SIG_ERR) {
        perror("Error handling signal\n");
        return EXIT_FAILURE;
    }

    
}