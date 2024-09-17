
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
    typedef struct Collection {
        int element;
        struct Collection* next;
    } Collection;

    char character;


  /*  Collection * createCollection(int element) {
        character = read_char();
        Collection* newElement = (Collection*)malloc(sizeof(Collection));
        newElement=character;
        if (newElement == NULL) {
            write_string("Error\n");
            return NULL;
        }
        newElement->element = element;
        newElement->next = NULL;
        return newElement;
    }*/





    Collection *newElement = (Collection*)malloc(sizeof(Collection));
    Collection *current;
    Collection *prev = NULL;


   int count = 0;
    /*
    int collection[100] = {0};
    int number = 0;
*/

    do{

        character = read_char();
        if(character == 'a') {
            if (newElement == NULL){
            newElement->element = count;
            newElement->next = NULL;

        } else {
                while (newElement->next != NULL) {
                    newElement = newElement->next;
                    write_int(newElement->element);
                } newElement -> element = count;
                newElement -> next = NULL;
            }

        count++;

        }
        if(character == 'b'){
            count++;
        }

        if(character == 'c'){
            if (current != NULL) {
                while (current->next != NULL) {
                    current = current->next;
                }
                prev->next = current;
                prev->next = NULL;
                newElement= prev;
            }
           count++;
        }
    }
    while (character == 'a' || character == 'b' || character == 'c');

    if(current -> next != NULL){
        while (current -> next != NULL) {
            write_int(current -> element);
            current = current -> next;
            if (current -> next != NULL) {
                write_char(',');
            }
        }

    }
    write_int(newElement -> element);
    write_char(';');
    write_char('\n');

    /*
    write_string("count = ");
    write_int(count);
    write_char('\n');
     */

    return 0;

}
