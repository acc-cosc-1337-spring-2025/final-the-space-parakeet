#include "roll.h"

/*------------------------------------------------------------------------------
    Roll Public Member Functions
------------------------------------------------------------------------------*/

Roll::Roll(Die& die1, Die& die2):
    die1(die1), die2(die2) {
}

// roll dice
// - roll die1 and die2
// - save the sum to rolled_value
void Roll::roll_dice() {
    rolled_value = die1.roll() + die2.roll();
}

// return rolled value
int Roll::roll_value() const {
    return rolled_value;
}