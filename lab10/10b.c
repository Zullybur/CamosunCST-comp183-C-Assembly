#include <stdio.h>
#include "comp183.h"

int main()
{
   long numPoints = 0L;

   // Obtain the total number of data points
   do {
      printf("Enter the number of data points:\n");
      numPoints = getLong();
   } while (numPoints < 1);

   // Print out the bar graph
   long x = 0L;
   long fx = 0L;
   long i = 0L;
   long j = 0L;
   for (i = 0; i < numPoints; i++) {
      // Gather one data pair at a time
      printf("Enter x[%ld]:\n", i);
      x = getLong();
      printf("Enter f(x[%ld]):\n", i);

      // Print out the corresponding bar graph
      fx = getLong();
      if (fx < 0) {
         printf("%ld: N/A\n", x);
      } else {
         printf("%ld: ", x);
         for (j = 0; j < fx; j++) {
            printf("*");
         }
         printf("\n");
      }
   }

   return 0;
}