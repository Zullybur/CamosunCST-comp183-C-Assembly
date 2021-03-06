#include <stdio.h>
#include "lab20b.h"     // getInt function

#define TEN 10
#define ROW_CNT 4
#define COL_CNT 4

// Read in 4x4 array from user input one value at a time
void readArray(int userArray[ROW_CNT][COL_CNT]) {
   int i, j;
   for (i = 0; i < ROW_CNT; i++) {
      for (j = 0; j < COL_CNT; j++) {
         printf("Requesting element [%u][%u]:\n", i, j);
         userArray[i][j] = getInt();
      }
   }
}

// Display array to screen in 4x4 grid
void printArray(int userArray[ROW_CNT][COL_CNT]) {
   int i, j;
   for (i = 0; i < ROW_CNT; i++) {
      for (j = 0; j < COL_CNT; j++) {
         if (j > 0 && COL_CNT > j) {
            printf("\t");
         }
         printf("%d", userArray[i][j]);
      }
      printf("\n");
   }
}

// Check array, each row and column must add up to 10
void checkArray(int userArray[ROW_CNT][COL_CNT]) {
   // Check Rows
   int i, j, colSum, rowSum;
   for (i = 0; i < ROW_CNT; i++) {
      rowSum = 0;
      for (j = 0; j < COL_CNT; j++) {
         rowSum += userArray[i][j];
      }
      if (rowSum != TEN) {
         printf("Row %d adds up to %d not %d\n", i, rowSum, TEN);
      }
   }
   // Check Columns
   for (j = 0; j < COL_CNT; j++) {
      colSum = 0;
      for (i = 0; i < ROW_CNT; i++) {
         colSum += userArray[i][j];
      }
      if (colSum != TEN) {
         printf("Column %d adds up to %d not %d\n", j, colSum, TEN);
      }
   }
}

// Main runs through operation functions to get, print, and check the array
int main() {
   int userArray[ROW_CNT][COL_CNT];
   readArray(userArray);
   printArray(userArray);
   checkArray(userArray);
}