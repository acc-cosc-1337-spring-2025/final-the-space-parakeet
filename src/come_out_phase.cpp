#include "come_out_phase.h"

/*------------------------------------------------------------------------------
    ComeOutPhase Public Member Functions
------------------------------------------------------------------------------*/

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    switch (roll->roll_value()) {
        case 7: case 11:                return RollOutcome::NATURAL;
        case 2: case 3: case 12:        return RollOutcome::CRAPS;
        default:                        return RollOutcome::POINT;
    }
}