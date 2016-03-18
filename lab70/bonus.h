#include <stdbool.h>

struct bigDouble {
    char *doubleString;
    unsigned stringSize;
    bool negative;
    unsigned numDigitsAfterDot;
    unsigned numDigitsBeforeDot;
};

// Frees the double
void freeDouble(struct bigDouble *doubleStruct);

// Returns a valid double or NULL. A valid non-negative double starts with one or more digits, followed
// by an optional . and one or more digits. A valid negative double starts with a minus, followed by one
// or more digits, followed by an optional . and one or more digits. Invalid doubles include .0, -.0, and 1.
// The returned double must be freed eventually.
struct bigDouble *getDouble();

// Takes in two double strings and returns their sum. The returned double must be freed eventually.
struct bigDouble *addDouble(struct bigDouble *doubleStruct1, struct bigDouble *doubleStruct2);

// Prints out the double
void printDouble(struct bigDouble *doubleStruct);
