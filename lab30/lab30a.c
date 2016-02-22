#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INIT_SIZE 5
#define ASCII_MAX 256

// Initialize a bool array to 'false'.
// For each char in the filter array, set the key
// representing the ascii value for that char to 'true'.
void setBools(_Bool *filterTable) {
   unsigned input, i;
   for (i = 0; i < ASCII_MAX; i++) {
      filterTable[i] = 0;
   }

   while (true) {
      input = getc(stdin);
      if (input == '\n' || input == EOF) {
         break;
      }
      filterTable[input] = 1;
   }
}

// Receive current char array, create new array of size n * 2,
// copy values from old array to new array, release old array
// from memory and shift pointer to new array.
void getCharArray(char **original, unsigned int *size) {
   unsigned i;
   char *newArray = calloc((*size) * 2, sizeof(char));
   
   if (!newArray) {
      printf("FATAL ERROR: Array creation failed.");
      return;
   }

   if (*original == NULL) {
      *original = newArray;
      return;
   }

   for (i = 0; i < *size; i++) {
      newArray[i] = (*original)[i];
   }
   free(*original);

   *size = (*size) * 2;
   *original = newArray;
}

// Receive and output optional promt string, check input
// against submitted filter table, and return error message
// if any character fails. Print input string if all pass.
void checkString(char *prompt, _Bool *filterTable, char *errMsg) {
   char *output = NULL;
   char input;
   unsigned i = 0, size = INIT_SIZE;
   getCharArray(&output, &size);

   if (prompt) {
      printf("%s\n", prompt);
   }

   input = getc(stdin);

   // Check input against filter table
   while (input !='\n' && input != EOF) {
      if (i == size) {
         getCharArray(&output, &size);
      }
      if (filterTable[input]) {
         output[i] = input;
      } else {
         output = errMsg;
         break;
      }
      input = getc(stdin);
      i++;
   }

   printf("%s\n", output);

}

int main() {
   _Bool filterTable[ASCII_MAX];
   char* userInput;

   // Prompt for filter string and call 
   printf("Please enter the filter characters:\n");
   setBools(filterTable);
   
   checkString("String NAO", filterTable, "Your string failed.");

   printf("\n");
   return 0;
}