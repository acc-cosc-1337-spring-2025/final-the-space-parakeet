#include "die.h"

/*------------------------------------------------------------------------------
    Die Public Member Functions
------------------------------------------------------------------------------*/

// roll die
// - return a random integer in range [1, sides]
// - integers will have a uniform distribution
int Die::roll() {
    uniform_int_distribution<int> distribution {1, sides};
    return distribution(generator);
}
