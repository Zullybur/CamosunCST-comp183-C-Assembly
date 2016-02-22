#include <stdbool.h>

enum ratingType { UNACCEPTABLE = 1, POOR, AVERAGE, GOOD, EXCELLENT };

struct resortType {
    char *name;
    char *city;
    enum ratingType rating;
};

// Prompt user for information pertaining to each of 'num' resorts.
// Returns a pointer to an array containing the entered resort information.
// If num is 0, NULL is returned.
// If num is not null, but memory could not be allocated, NULL is returned.
// If invalid strings or ratings are entered, the corresponding entries are
// set to "" or UNACCEPTABLE.
// The returned array has to be freed eventually.
struct resortType* getResorts(unsigned num);

// Prints resort information to the file called 'fileName'.
// In case an error occurs, false is returned; otherwise, true is returned.
// 'num' must correspond to the number of resorts.
bool printResorts(struct resortType* resorts, unsigned num, char *fileName);

// Sorts the resorts by name.
// 'num' must correspond to the number of resorts.
void sortResorts(struct resortType *resorts, unsigned num);
