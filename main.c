
/* You are not allowed to use <stdio.h> */
#include "io.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */

void collection_add(int** collection, int* size, int value) {
    *collection = realloc(*collection, (*size + 1) * sizeof(int));
    if (*collection == NULL) {
        return;
    }
    (*collection)[*size] = value;
    (*size)++;
}

void collection_remove(int** collection, int* size) {
    if (*size > 0) {
        *size -= 1;
        *collection = realloc(*collection, *size * sizeof(int));
        if (*size > 0 && *collection == NULL) {
            return;
        }
    }
}

int main() {

       /*-----------------------------------------------------------------
   *TODO:  You need to implement the command line driver here as
   *       specified in the assignment handout.
   *
   * The following pseudo code describes what you need to do
   *  
   *  Declare the counter and the collection structure variables
   *
   *
   *  In a loop
   *    1) Read a command from standard in using read_char function
   *    2) If the command is not 'a', 'b', 'c': then break the loop
   *    3) Process the command as specified in the handout
   *  End loop
   *
   *  Print your collection of elements as specified in the handout
   *    as a comma delimited series of integers
   *-----------------------------------------------------------------*/

    int counter = 0;
    int* collection = NULL;
    int collection_size = 0;
    int command;

    while ((command = read_char()) != EOF) {
        if (command == 'a') {
            collection_add(&collection, &collection_size, counter);
            counter++;
        } else if (command == 'b') {
            counter++;
        } else if (command == 'c') {
            collection_remove(&collection, &collection_size);
            counter++;
        } else {
            break;
        }
    }

    // Printing the collection as a comma-separated list
    for (int i = 0; i < collection_size; i++) {
        if (i > 0) {
            write_char(',');
        }
        write_int(collection[i]);
    }
    write_char(';');
    write_char('\n');

    // Free allocated memory
    free(collection);

    return 0;

}
