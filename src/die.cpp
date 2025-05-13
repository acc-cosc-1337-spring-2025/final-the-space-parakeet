#include "die.h"

/*------------------------------------------------------------------------------
    Die Public Member Functions
------------------------------------------------------------------------------*/

// roll die
// - generate a random integer in range [1, sides]
// - integers will have a uniform distribution
int Die::roll () {
    std::uniform_int_distribution<int> distribution {1, sides};
    return distribution(generator);
}
