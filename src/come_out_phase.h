#pragma once

#include "phase.h"

/*------------------------------------------------------------------------------
    ComeOutPhase Derived Class
------------------------------------------------------------------------------*/

class ComeOutPhase : public Phase {
    public:
        RollOutcome get_outcome(Roll* roll) override;
};