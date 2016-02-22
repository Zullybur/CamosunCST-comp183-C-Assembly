#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INIT_SIZE 10
#define NUM_CHARS 256

// Double array size and copy over values
char *doubleArraySize(char *oldArray, unsigned int *size)
{
    if(!oldArray || !*oldArray || !size || !*size){
        return NULL;
    }

    char* tempArray = calloc((*size)* 2, sizeof(char));
    if(!tempArray){
        return NULL;
    }
    for (unsigned j = 0; j < *size; j++) {
        tempArray[j] = oldArray[j];
    }
    *size = (*size) *2;
    return tempArray;
}

//Return string length of char array
unsigned stringLength(char *string)
{
    if(!string){
        return 0;
    }
    int i =0;

    while(string[i] != '\0') {
        i++;
    }

    return i;
}

//Compare filter string and user input
//if valid string return user input
//if not valid set error message and retur null
char *getFilteredString(char *prompt, char *filter, char **errorMessage)
{
    char tmp;
    unsigned i = 0;
    unsigned newSize=INIT_SIZE;
    char* tempArray;
    char* userString = calloc(INIT_SIZE, sizeof(char));
    bool rightChar = false;

    if (!filter)
    {
        return NULL;
    }
    //Prompt user for string
    if(prompt && *prompt) {
        printf("please enter string:\n");
    }

    tmp=getc(stdin);
    //put user input into array
    while(tmp != '\n' && tmp !=EOF) {
        //if array is full get new array
        if(i >= newSize) {
            tempArray = doubleArraySize(userString, &newSize);
            if(!tempArray){
                return NULL;
            }
            free(userString);
            userString = tempArray;
        }
        userString[i] = tmp;
        tmp=getc(stdin);
        i++;
    }

    //comapre the  string array and filter array by one character at a time
    for(i =0; i < stringLength(userString); i++) {
        rightChar = false;
        for(int j =0; j < stringLength(filter) ; j++) {
            if( userString[i] == filter[j]) {
                rightChar = true;
                break;

            }
        }

        //if any character is invalid exit with error message.
        if (!rightChar) {
            if(errorMessage){
                *errorMessage="Found invalid character";
            }
            return NULL;
        }
    }

    //if all characters are valid in  string array then return string
    return userString;
}
