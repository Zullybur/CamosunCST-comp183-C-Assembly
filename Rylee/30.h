// Returns a pointer to an array twice as big as 'oldArray'.
// All the values of the 'oldArray' are copied over to the beginning of the new array.
// The remaining half of the new array is set to '\0'.
// 'size' must be the size of the 'oldArray'.
// When the new array is no longer needed, its memory must be deallocated.
// Returns NULL if the array could not be doubled.
char *doubleArraySize(char *oldArray, unsigned int *size);

// Returns the length of the null-terminated 'string'
unsigned stringLength(char *string);

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