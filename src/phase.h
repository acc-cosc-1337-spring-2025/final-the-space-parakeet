#pragma once

#include "roll.h"

/*------------------------------------------------------------------------------
    RollOutcome Enum Class
------------------------------------------------------------------------------*/

enum class RollOutcome {
    NATURAL,
    CRAPS,
    POINT,
    SEVEN_OUT,
    NOPOINT
};

/*------------------------------------------------------------------------------
    Phase Abstract Class
------------------------------------------------------------------------------*/

class Phase {
    public:
        virtual RollOutcome get_outcome(Roll* roll) = 0;
};
