#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "40.h"

// void merge(int a[], int low, int mid, int high)
// {
//     int b[10000];
//     int i = low, j = mid + 1, k = 0;
  
//     while (i <= mid && j <= high) {
//         if (a[i] <= a[j])
//             b[k++] = a[i++];
//         else
//             b[k++] = a[j++];
//     }
//     while (i <= mid)
//         b[k++] = a[i++];
  
//     while (j <= high)
//         b[k++] = a[j++];
  
//     k--;
//     while (k >= 0) {
//         a[low + k] = b[k];
//         k--;
//     }
// }
  
// void mergesort(int a[], int low, int high)
// {
//     if (low < high) {
//         int m = (high + low)/2;
//         mergesort(a, low, m);
//         mergesort(a, m + 1, high);
//         merge(a, low, m, high);
//     }
// }

char* getStars(unsigned stars) {
    switch(stars){
        case 1:
            return "*";
        case 2:
            return "**";
        case 3:
            return "***";
        case 4:
            return "****";
        case 5:
            return "*****";
        default:
            return "ERROR";
    }
}

struct resortType* getResorts(unsigned num) {
    if (!num) {
        return NULL;
    }
    char* error;
    char* alphaNumericFilter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    struct resortType* resorts = calloc(num, sizeof(struct resortType));
    if (!resorts) {
        return NULL;
    }
    for (unsigned i = 0; i < num; i++) {
        printf("Resort #%u:\n", i+1);
        resorts[i].name = getFilteredString("\tEnter resort name:\n", alphaNumericFilter, &error);
        if (!resorts[i].name) {
            resorts[i].name = "";
        }
        resorts[i].city = getFilteredString("\tEnter city name:\n", alphaNumericFilter, &error);
        if (!resorts[i].city) {
            resorts[i].city = "";
        }
        printf("\tEnter resort rating:\n");
        resorts[i].rating = getUnsigned();
        if (resorts[i].rating == 0 || resorts[i].rating > 5) {
            resorts[i].rating = UNACCEPTABLE;
        }
    }
    printf("\n");
    return resorts;
}

bool printResorts(struct resortType* resorts, unsigned num, char *fileName) {
    FILE *fout;

    fout = fopen(fileName, "w");
    if (fout) {
        for (unsigned i = 0; i < num; i++) {
            fprintf(fout, "%s\t%s\t%s\n", resorts[i].name, resorts[i].city, getStars(resorts[i].rating));
        }
        fclose(fout);
        return true;
    }
    return false;
}

void sortResorts(struct resortType *resorts, unsigned num) {
    
}
