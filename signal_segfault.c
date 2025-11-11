/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: James Zbyszinski
 * 
 * Brief summary of modifications: Added a handler for the segmentation fault
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/mman.h>

static void handler(int sig_num){
    printf("Segmentation fault detected and caught\n");
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, handler);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}