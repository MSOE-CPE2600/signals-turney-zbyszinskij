/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: James Zbyszinski
 * 
 * Brief summary of modifications: Program will output that a SIGINT signal was recieved and keep running
 *                                 instead of stopping
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int loop_count = 0;

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal(int sig_num) {
    
    printf("\nCaught SIGINT.\n");

}



int main() {

    printf("PID: %d\n", getpid());

    // Wait until a signal is received
    while(1) {

        signal(SIGINT, handle_signal);

        printf("Loop number: %d\n", ++loop_count);
        printf("Sleeping\n");
        pause();
        sleep(1);

        if (signal(SIGINT, handle_signal) == SIG_ERR) {
            perror("Error handling signal\n");
            return EXIT_FAILURE;
        }

    }

    return 0;
}