#include <stdlib.h>
#include "random.h"

// Generates a random integer between min and max (inclusive)
int random_int(const int min, const int max)
{
    return min + rand() % (max - min + 1);
}
