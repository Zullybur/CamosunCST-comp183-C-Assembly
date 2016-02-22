#include <stdio.h>

// Returns an int from stdin. In case of invalid input, the user is reprompted until valid input is provided.
int getInt();

// Returns a long from stdin. In case of invalid input, the user is reprompted until valid input is provided.
long getLong();

// Returns an unsigned from stdin. In case of invalid input, the user is reprompted until valid input is provided.
unsigned getUnsigned();

// Issues a 'prompt' to the user and reads in a string of characters from stdin.
// If all of the entered characters occur in 'filter', this function returns a pointer
// to a character array containing the entered string.
// If the user enters a non-permitted character (one NOT in the 'filter' string),
// the function returns NULL.  The 'errorMessage' is furthermore set to explain
// the reason why the input failed.
// Both the 'prompt' and 'filter' must be null-terminated, but no assumption is made with
// respect to their size.
// If there is not enough memory available to contain the string, this function returns NULL.
// Except for the 'prompt', nothing is printed to stdout.
// The filtered string must be deallocated if no longer needed.
char *getFilteredString(char *prompt, char *filter, char **errorMessage);
