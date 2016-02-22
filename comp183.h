#include <math.h>
#include <stdlib.h>

double getLongDouble()
{
    const unsigned BUFFER_SIZE = log10(pow(2, 8 * sizeof(long double))) + 1;
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    return strtod(buffer, NULL);
}
double getDouble()
{
    const unsigned BUFFER_SIZE = log10(pow(2, 8 * sizeof(double))) + 1;
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    return strtod(buffer, NULL);
}

long getLong()
{
    const unsigned BUFFER_SIZE = log10(pow(2, 8 * sizeof(long))) + 1;
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    return strtol(buffer, NULL, 10);
}

unsigned getUnsigned()
{
    const unsigned BUFFER_SIZE = log10(pow(2, 8 * sizeof(unsigned))) + 1;
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    return labs(strtol(buffer, NULL, 10));
}

