/* 
 * Author: Matthew Casiro
 * Created: Jan 13 2016
 * Purpose: Comp-183 Lab 01a Branching and Repetition
 * Submitted: Jan 13 2016
 */

#include <stdio.h>
#include "comp183.h"
#include <stdbool.h>

int main(){
   // Prompt user for input 'salinity1' (salinity, double)
   printf("Please enter the first (lowest) salinity level:\n");
   double salinity1 = getDouble();

   // Prompt user for input 'freezingPoint1' (freezing point, double)
   printf("Please enter the freezing point for first salinity level:\n");
   double freezingPoint1 = getDouble();

   // Prompt user for input 'salinity3' (salinity, double)
   printf("Please enter the third (highest) salinity level:\n");
   double salinity3 = getDouble();

   // Prompt user for input 'freezingPoint3' (freezing point, double)
   printf("Please enter the freezing point for third salinity level:\n");
   double freezingPoint3 = getDouble();

   // Prompt user for input 'salinity2' (salinity, double)
   printf("Please enter third (mid range) salinity level:\n");
   double salinity2 = getDouble();

   // EXIT UNLESS: a < b < c
   bool goodData = ((salinity1 < salinity2) && (salinity2 < salinity3));
   if(!goodData){
      printf("ERROR: First salinity must be smallest, second salinity must be biggest.\n");
      return -1;
   }

   /*
    * Calculate freezingPoint2 using formula:
    * f(b) = f(a) + ((f(c) - f(a)) * (b - a) / (c - a))
    */
   double freezingPoint2 = freezingPoint1 + ((freezingPoint3 - freezingPoint1) * (salinity2 - salinity1) / (salinity3 - salinity1));

   // Output freezingPoint for salinity 'b'
   printf("The freezing point for salinity level %f is: %f\n", salinity2, freezingPoint2);

   return 0;
}