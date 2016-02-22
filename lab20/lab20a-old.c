#include <stdio.h>
#include <stdbool.h>

int main() {
   int input;
   long output = 0;
   unsigned charCount = 0;
   bool isFirst = true;
   bool done = false;
   bool isNegative = false;
   unsigned debugCount;

   // Get user input.
   while (!done) {
      printf("Enter a valid integer between -999999999 and +999999999:\n");
      done = true;
      debugCount = 0;
      // Parse and validate user input.
      do {
         input = getc(stdin);
         printf("DEBUG: position: %u\n", debugCount);

         // Check for valid negative value, flip isFirst to false.
         if (input == '-' && isFirst) {
            printf("DEBUG: Entering negative if\n");
            isNegative = true;
            isFirst = false;
         
         /* If valid input: move output over by power of 10, add current
            char to input, set isFirst to false, increment charCount. */
         }else if (input >= '0' && input <= '9' ) {
            printf("DEBUG: Entering valid if\n");
            output *= 10;
            output += (long)(input - '0');
            isFirst = false;
            printf("--DEBUG: Output: %ld\n", output);
            if (output > 999999999){
               printf("DEBUG: Large output\n");
               done = false;
            }
         
         // If invalid input: clear stdin, reset bools, reset output.
         }else if (input != '\n' && input != EOF) {
            printf("DEBUG: Entering dump if\n");
            do {
               input = getc(stdin);
            } while (input != '\n' && input != EOF);
            isFirst = true;
            done = false;
            isNegative = false;
            output = 0;
            printf("Invalid input, please try again.\n");
         }
         debugCount++;
         /*if (output > 999999999) {
            do {
               input = getc(stdin);
            } while (input != '\n' && input != EOF);
            isFirst = true;
            done = false;
            isNegative = false;
            output = 0;
            printf("Invalid input, please try again.\n");
         }*/
      } while (input != '\n' && input != EOF);
   }

   // Flip value to negative if required.
   if (isNegative) {
      output *= -1;
   }
   printf("Value entered is: %d\n", output);

   return 0;
}