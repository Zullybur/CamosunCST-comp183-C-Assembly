#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 9 // Must be at least 1
#define ARRAY_SIZE 4
#define SUM        10

// Flushes stdin
void flushStdin() {
   char tmp;
   do {
      tmp = getc(stdin);
   } while (tmp != '\n' && tmp != EOF);
}

// Gets a valid integer from the user
// User is prompted repeatedly until a valid integer is entered
// This valid integer is returned
int getInt() {
    int output;
    bool done, negative;
    do {
      int input = 0;
       unsigned numDigits = 0;
       done = false;
      negative = false;
      output = 0;
    
        printf("Enter an integer:\n");
        while (true) {
            input = getc(stdin);
            if (input == '\n' || input == EOF) {
                // End of input
                done = negative ? numDigits > 0 : true;
                break;
            }
            else if (input == '-' && !negative && !numDigits) {
               // Initial '-' sign
                negative = true;
                continue;
            }
            else if ('0' <= input && input <= '9') {
                // Valid digit entered
                output = output * 10;
                output = output + (input - '0');
                numDigits++;
                if (numDigits <= MAX_DIGITS)
                {
                    continue;
                }
            }
            
            // Invalid input; flush the input buffer and start from the beginning
            flushStdin();
            break;
        }
    } while (!done);
    
    return negative ? -output : output;
}

// Reads valid integers from stdin and places them into 'array',
// which must be of size ARRAY_SIZE x ARRAY_SIZE. Integers are
// recorded in row-major order. Invalid integers are ignored.
void readArray(int array[ARRAY_SIZE][ARRAY_SIZE]) {
    unsigned i = 0, j = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            printf("Requesting element [%u][%u]:\n", i, j);
            array[i][j] = getInt();
        }
    }
}

// Prints out an 'array' of size ARRAY_SIZE x ARRAY_SIZE.
void printArray(int array[ARRAY_SIZE][ARRAY_SIZE]) {
    unsigned i = 0, j = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j < ARRAY_SIZE; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

// Checks an 'array' of size ARRAY_SIZE x ARRAY_SIZE to
// ensure that all rows and columns each add up to SUM.
// Prints out error messages for all rows and columns that
// do NOT add up to SUM.
void checkArray(int array[ARRAY_SIZE][ARRAY_SIZE]) {
    unsigned i = 0, j = 0;
    
    // Check the rows
    for (i = 0; i < ARRAY_SIZE; i++) {
        int rowSum = 0;
        for (j = 0; j < ARRAY_SIZE; j++) {
            rowSum = rowSum + array[i][j];
        }
        if (rowSum != SUM) {
            printf("Row %u adds up to %d not %d\n", i, rowSum, SUM);
        }
    }

   // Check the columns
    for (i = 0; i < ARRAY_SIZE; i++) {
        int colSum = 0;
        for (j = 0; j < ARRAY_SIZE; j++) {
            colSum = colSum + array[j][i];
        }
        if (colSum != SUM) {
            printf("Column %u adds up to %d not %d\n", i, colSum, SUM);
        }
    }
}

int main() {
    int array[ARRAY_SIZE][ARRAY_SIZE];
    readArray(array);
    printArray(array);
    checkArray(array);
    return 0;
}