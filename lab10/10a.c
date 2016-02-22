#include <stdio.h>
#include "comp183.h"

int main()
{
   double valA = 0.0;
   double valFA = 0.0;
   double valC = 0.0;
   double valFC = 0.0;
   double valB = 0.0;
   double valFB = 0.0;

   // Collect the data points
   printf("Enter value for a:\n");
   valA = getDouble();

   printf("Enter value for f(a):\n");
   valFA = getDouble();

   printf("Enter value for c:\n");
   valC = getDouble();

   printf("Enter value for f(c):\n");
   valFC = getDouble();

   printf("Enter value for b:\n");
   valB = getDouble();

   // Validate the data points
   if ((valB <= valA) || (valC <= valB)) {
      printf("Error: a < b < c is not true\n");
      return -1;
   }

   // Compute the freezing point
   valFB = valFA + (valFC - valFA) * (valB - valA) / (valC - valA);
   printf("Freezing temperature with salinity %f is %f.\n", valB, valFB);

   return 0;
}