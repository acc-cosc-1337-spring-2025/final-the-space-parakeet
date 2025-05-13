#pragma once

#include "die.h"

/*------------------------------------------------------------------------------
    Roll Class
------------------------------------------------------------------------------*/

class Roll {
    public:
        Roll (Die& die1, Die& die2);
        void roll_dice ();
        int roll_value () const;
    private:
        Die& die1;
        Die& die2;
        int rolled_value = die1.roll() + die2.roll();
};
