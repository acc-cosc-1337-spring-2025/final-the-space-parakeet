#pragma once

#include "phase.h"

/*------------------------------------------------------------------------------
    PointPhase Derived Class
------------------------------------------------------------------------------*/

class PointPhase : public Phase {
    public:
        PointPhase(int point);
        RollOutcome get_outcome(Roll* roll) override;
    private:
        int point;
};