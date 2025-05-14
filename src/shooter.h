#pragma once

#include "roll.h"
#include <vector>

using std::vector;

/*------------------------------------------------------------------------------
    Shooter Class
------------------------------------------------------------------------------*/

class Shooter {
    public:
        Roll* throw_dice(Die& die1, Die& die2);
        void display_rolled_values();
        ~Shooter();
    private:
        vector<Roll*> rolls;
};
