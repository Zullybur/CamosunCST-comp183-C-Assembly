#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define NUM_CHARS 256

// Returns a pointer to an array twice as big as 'oldArray'.
// All the values of the 'oldArray' are copied over to the beginning of the new array.
// The remaining half of the new array is set to '\0'.
// 'size' must be the size of the 'oldArray'.
// When the new array is no longer needed, its memory must be deallocated.
// Returns NULL if the array could not be doubled.
char *doubleArraySize(char *oldArray, unsigned int *size)
{
    if (!size || !*size) {
        return NULL;
    }
    
    // Allocate memory for the new array
    unsigned oldSize = *size;
    *size = *size * 2;
    char *newArray = calloc(*size, sizeof(char));
    if (!newArray)
    {
        *size = 0;
        return NULL;
    }
    
    // Copy over the old array
    unsigned int i = 0;
    for (i = 0; i < oldSize; i++)
    {
        newArray[i] = oldArray[i];
    }
    
    return newArray;
}

// Returns the length of the null-terminated 'string'
unsigned stringLength(char *string) {
    if (!string) {
        return 0;
    }
    
    unsigned i = 0;
    while (string[i] != '\0') {
        i++;
    }
    
    return i;
}

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
char *getFilteredString(char *prompt, char *filter, char **errorMessage) {
    // Sort the filter
    bool sortedFilter[NUM_CHARS] = {false};
    if (filter) {
        unsigned i = 0;
        while(filter[i] != '\0') {
            sortedFilter[(unsigned)filter[i++]] = true;
        }
    }
    
    // Display the prompt
    if (prompt) {
        printf("%s", prompt);
    }
    
    // Read in the string
    if (errorMessage) {
        *errorMessage = NULL;
    }
    unsigned index = 0;
    int input = '\0';
    char *output = NULL;
    unsigned outputSize = 0;
    while (true) {
        input = getc(stdin);
        if (input == '\n' || input == EOF) {
            // End of input
            break;
        }
        else if (!sortedFilter[(unsigned)input]) {
            // Stop due to invalid character
            if (errorMessage) {
                *errorMessage = "Found invalid character";
            }
            free(output);
            return NULL;
        }
        
        // Make sure that the buffer is large enough
        if (!output) {
            output = calloc(INITIAL_SIZE, sizeof(char));
            outputSize = INITIAL_SIZE;
        }
        else if (index == outputSize - 1)
        {
            char *tmpOutput = output;
            output = doubleArraySize(tmpOutput, &outputSize);
            free(tmpOutput);
        }
        if (!output) {
            if (errorMessage) {
                *errorMessage = "Out of memory";
            }
            return NULL;
        }
        
        // Store the character
        output[index++] = input;
    }
    
    // Free memory if there is only an empty string
    if (output && output[0] == '\0') {
        free(output);
        return "";
    }
    
    return output;
}
