
/* You are not allowed to use <stdio.h> */
#include "io.h"
#include <unistd.h>




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

    int count = 0;
    int collection[100] = {0};
    int number = 0;
    char character;

    do{
        character = read_char();

        if(character == 'a'){
            collection[number] = count;
            number++;
            count++;
        }
        if(character == 'b'){
            count++;
        }
        if(character == 'c'){
            if (number !=0) {
                number--;
            }
            collection[number] = 0;
            count++;
        }
    }
    while (character == 'a' || character == 'b' || character == 'c');

    int spot = 0;
    for (int y = 0; y < number; y++) {
        while (collection[spot] != 0 || spot == 0) {
            write_int(collection[spot]);
            spot++;
            if (collection[spot] != 0) {
                write_char(',');
            }
        }
    }
    write_string(";");
    write_char('\n');

    /*
    write_string("count = ");
    write_int(count);
    write_char('\n');
     */

    return 0;

}
