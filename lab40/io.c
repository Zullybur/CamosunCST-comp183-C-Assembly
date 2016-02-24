/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Author: Matthew Casiro                        *
 * Date: TODO                             *
 * Purpose: Validate various user input types    *
** * * * * * * * * * * * * * * * * * * * * * * * */
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
//#include "io.h"

#define INITIAL_SIZE 10
#define NUM_CHARS 256
//#define INT_SIZE (long)(pow(2, 8 * sizeof(int))/2 - 1)
#define INT_SIZE INT_MAX
//#define UNSIGNED_SIZE (long)(pow(2, 8 * sizeof(int)) - 1)
#define UNSIGNED_SIZE (unsigned)INT_MAX * 2
//#define LONG_SIZE (unsigned long)(pow(2, 8 * sizeof(long))/2)
#define LONG_SIZE LONG_MAX
// #define uLONG_SIZE (unsigned long)(pow(2, 8 * sizeof(long)))

void rejectInput(char input) {
    printf("Input invalid, try again:\n");
    while(input != '\n' && input != EOF){
        input = getc(stdin);
    }
    return;
}
long verifyNum(long maxTypeValue, bool isSigned) {
    printf("DEBUG-Entered verifyNum\n");
    bool done = false, first;
    char input;
    int sign;
    long output, checkSum, revertSum;

    while(!done){
        printf("DEBUG-Entered while-001\n");
        // Initialize variables
        done = true;
        first = true;
        sign = 1;
        output = 0;
        input = getc(stdin);
        // Return zero if no input
        if (input == '\n' || input == EOF) {
            return 0;
        }
        // Check for negative value in first position
        if (input == '-' && isSigned) {
            sign = -1;
            input = getc(stdin);
        }
        // Clear leading zeros and return zero if end of input is reached
        while (input == '0') {
            input = getc(stdin);
            if (input == '\n' || input == EOF) {
                return 0;
            }
        }
        do {
            // Clear buffer and exit loop on bad value
            if (input < '0' || input > '9') {
                rejectInput(input);
                done = false;
                break;
            }
            // Add good value to output and check for overflow
            checkSum = output;
            output = (output * 10) + (input - '0');
            printf("DEBUG-Output: %ld\n", output);
            if (output > maxTypeValue) {
                printf("DEBUG-Output too big\n");
                rejectInput(input);
                done = false;
                break;
            }
            revertSum = (output - (input - '0')) / 10;
            if (revertSum != checkSum) {
                printf("DEBUG-Output overflow\n");
                rejectInput(input);
                done = false;
                break;
            }
            input = getc(stdin);
        } while (input != '\n' && input != EOF);
    }
    printf("Returning: %ld * %d = %ld\n", output, sign, output * sign);
    return output * sign;
}

int getInt() {
    bool isSigned = true;
    long temp = verifyNum(INT_SIZE, isSigned);
    return (int)temp;
}

long getLong() {
    bool isSigned = true;
    return verifyNum(LONG_SIZE, isSigned);
}

unsigned getUnsigned() {
    bool isSigned = false;
    long temp = verifyNum(UNSIGNED_SIZE, isSigned);
    return (unsigned)temp;
}

// Take an input array and the size of that array. Create
// a char array of double the original size and copy over all
// values to the new array. Return NULL if any issues,
// or a pointer to the new array if successful.
 char *doubleArraySize(char *oldArray, unsigned int *size) {
    unsigned i, newSize;

    // If Array pointer, Array, Size pointer, or Size are
    // NULL (or 0), then return NULL.
    if (!oldArray || !*oldArray ||
        !size || !*size) {
        return NULL;
    }
    newSize = (*size) * 2;

    // Allocate a new array of double the size, if calloc fails
    // print error and exit program.
    char *newArray = calloc(newSize, sizeof(char));
    if (!newArray) {
        printf("FATAL ERROR: Calloc failed. Exiting Program.\n");
        exit(1);
    }
    // Copy values from original array to new array
    for (i = 0; i < *size; i++) {
        newArray[i] = oldArray[i];
    }
    *size = newSize;
    return newArray;
}

unsigned stringLength(char *string) {
    unsigned length = 0;

    // If string pointer, or string is NULL or zero, return 0
    if(!string || !*string) {
        return 0;
    }
    while (string[length] != 0) {
        length++;
    }
    return length;
}

char *getFilteredString(char *prompt, char *filter, char **errorMessage) {
    unsigned i = 0, j = 0, size = INITIAL_SIZE;
    char input;
    _Bool filterTable[NUM_CHARS];
    char *tmp = NULL;
    char *output = calloc(INITIAL_SIZE, sizeof(char));

    // Initialize boolean array to false, then iterate through
    // filter string and flip values corresponding to ASCII key
    // for each character to true
    for (i = 0; i < NUM_CHARS; i++) {
        filterTable[i] = 0;
    }
    i = 0;
    if(filter && *filter) {
        while (true) {
            input = filter[i];
            if (input == '\n' || input == EOF) {
                break;
            }
            filterTable[input] = 1;
            i++;
        }
    }

    // Prompt user for input if pointer to prompt string is valid
    // and points to a valid string
    if (prompt && *prompt) {
        printf("%s", prompt);
    }
    input = getc(stdin);

    // Check input buffer against filter table
    while (input !='\n' && input != EOF) {
        // If the array holding the input string is full,
        // request a new array of double the size
        if (j == size) {
            tmp = doubleArraySize(output, &size);
            free(output);
            output = tmp;
        }
        // If currect character is 'true' in the filter table,
        // add that character to the output string
        // Otherwise set an error message and exit
        if (filterTable[input]) {
            output[j] = input;
        } else {
            if(errorMessage) {
                *errorMessage = "Found invalid character";
            }
            return NULL;
        }
        input = getc(stdin);
        j++;
    }
    return output;
}

int main () {
    int input;

    printf("DEBUG-Int:\t%ld\n", INT_SIZE);
    printf("DEBUG-Unsigned:\t%ld\n", UNSIGNED_SIZE);
    printf("DEBUG-Long:\t%lu\n", LONG_SIZE);
    printf("\nInteger:\t0\nUnsigned:\t1\nLong:\t\t2\n");
    input = getc(stdin);
    input = input - '0';
    rejectInput(input);
    switch(input){
        case 0:
            printf("Please enter an integer value:\n");
            int output0 = getInt();
            printf("Input: %d\n", output0);
            break;
        case 1:
            printf("Please enter an unsigned value:\n");
            unsigned output1 = getUnsigned();
            printf("Input: %u\n", output1);
            break;
        case 2:
            printf("Please enter a long value:\n");
            long output2 = getLong();
            printf("Input: %ld\n", output2);
            break;
        default:
            printf("FATAL ERROR\n");
    }
}