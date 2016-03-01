/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Author: Matthew Casiro                        *
 * Date: February 24th 2016                      *
 * Purpose: Validate various user input types    *
 * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "40.h"

#define MIN_RATING 1
#define MAX_RATING 5

// Incorporate string representations of all possible ratings in an array
static char* const ratingString[] = {"", "*", "**", "***", "****", "*****"};

// Store name, city, and rating (between MIN_RATING to MAX_RATING inclusive)
// from user input for a given number of resorts
struct resortType* getResorts(unsigned num) {
    if (!num) {
        return NULL;
    }
    char* error;
    // Allow alphanumeric characters and spaces
    char* alphaNumericFilter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    struct resortType* resorts = calloc(num, sizeof(struct resortType));
    if (!resorts) {
        return NULL;
    }
    // Interate through resort array getting information for each entry
    for (unsigned i = 0; i < num; i++) {
        printf("Resort #%u:\n", i + 1);
        resorts[i].name = getFilteredString("\tEnter resort name:\n", alphaNumericFilter, &error);
        if (!resorts[i].name) {
            resorts[i].name = "";
            printf("%s\n", error);
        }
        resorts[i].city = getFilteredString("\tEnter city name:\n", alphaNumericFilter, &error);
        if (!resorts[i].city) {
            resorts[i].city = "";
            printf("%s\n", error);
        }
        printf("\tEnter resort rating:\n");
        resorts[i].rating = getUnsigned();
        if (resorts[i].rating < MIN_RATING || resorts[i].rating > MAX_RATING) {
            resorts[i].rating = UNACCEPTABLE;
        }
    }
    return resorts;
}

// Output resort information from array to provided file
bool printResorts(struct resortType* resorts, unsigned num, char *fileName) {
    if (!resorts || !num || !fileName) {
        return false;
    }
    // Open file with write permissions
    FILE *fout;
    fout = fopen(fileName, "w");
    if (fout) {
        // Output all resort information to file
        for (unsigned i = 0; i < num; i++) {
            fprintf(fout, "%s\t%s\t%s\n", resorts[i].name, resorts[i].city, ratingString[resorts[i].rating]);
        }
        fclose(fout);
        return true;
    }
    // Return false if file creation fails
    return false;
}

// Sort resort structs in alphabetical order in provided array
void sortResorts(struct resortType *resorts, unsigned num) {
    if (!resorts || !num) {
        return;
    }
    // Sort array using bubble sort
    struct resortType tmp;
    unsigned i, j;
    for (i = 0; i < (num - 1); i++) {
        for(j = 1; j < num - i; j++) {
            if (strcmp(resorts[j].name, resorts[j - 1].name) < 0) {
               tmp = resorts[j];
               resorts[j] = resorts[j - 1];
               resorts[j-1] = tmp;
            }
        }
    }
}
