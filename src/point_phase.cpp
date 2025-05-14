#include "point_phase.h"

/*------------------------------------------------------------------------------
    PointPhase Public Member Functions
------------------------------------------------------------------------------*/

PointPhase::PointPhase(int point):
    point(point) {
}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    if (roll->roll_value() == point)    return RollOutcome::POINT;
    if (roll->roll_value() == 7)        return RollOutcome::SEVEN_OUT;
    else                                return RollOutcome::NOPOINT;
}