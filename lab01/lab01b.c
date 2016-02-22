// Author: Matthew Casiro
// Created: Jan 13 2016
// Purpose: Comp-183 Lab 01b Branching and Repetition
// Submitted: Jan 13 2016


#include <stdio.h>
#include "comp183.h"

int main(){
   // Get and validate "Number of data points" from User:
   // - 
   printf("How many data points would you like to enter?\n");
   long numberOfPoints = getLong();
   while (numberOfPoints < 1){
      printf("Please enter a whole number greater than zero:\n");
      numberOfPoints = getLong();
   }

   // Loop through specified number of points and:
   // - request (x,y) coordinates
   // - print "x:" with 'y' stars ("N/A" if y < 0)
   long x;
   long y;
   unsigned i;
   for(i = 0; i < numberOfPoints; i++){
      printf("Enter x[%d]:\n", i);
      x = getLong();
      printf("Enter f(x[%d]):\n", i);
      y = getLong();

      // Output result in bar graph form
      printf("%d: ", x);
      if(y < 0){              // N/A if y < 0
         printf("N/A");
      }else{
         for( ; y > 0; y--){  // Decrement y to 0 for bar graph
            printf("*");
         }
      }
      printf("\n");
   }
}