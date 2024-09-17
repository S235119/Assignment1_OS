
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
typedef struct Collection {
    int element;
    struct Collection* next;
} Collection;

Collection * createCollection(int element) {
    Collection* newElement = (Collection*)malloc(sizeof(Collection));
    if (newElement == NULL) {
        write_string("Error\n");
        return NULL;
    }
    newElement->element = element;
    newElement->next = NULL;
    return newElement;
}

void edElement(Collection** head, int element) {
    Collection *newElement = createCollection(element);
    Collection *last = *head;

    if (*head == NULL) {
        *head = newElement;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newElement;
}

int
main()
{





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


    char character;
    int count = 0;


    Collection *newCollection = (Collection*)malloc(sizeof(Collection));
    Collection *start= newCollection;

     do {

        character = read_char();
        if (character == 'a') {
            edElement(&newCollection, count);
            count++;
        }
        if(character == 'b'){
                count++;
            write_int(count);
            }

            if(character == 'c'){
            Collection *findElement = newCollection;
                if (findElement != NULL) {
                    while (findElement->next != NULL) {
                        findElement = findElement->next;
                    }
                    findElement->next = NULL;
                }
               count++;
            }
     } while (character == 'a' || character == 'b' || character == 'c');

    if (start !=NULL) {
        while (start->next != NULL){
            write_int(start->element);
            start=start->next;
            if (start->next != NULL) {
                write_char(',');
            }
    }
    }
    else {
        write_char(';');
    }

   // write_int(start->element);
    write_char('\n');


    return 0;

}


