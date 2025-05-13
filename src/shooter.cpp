#include "shooter.h"
#include <iostream>

using std::cout;

Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* roll = new Roll {die1, die2};
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values() {
    for (auto roll : rolls)
        cout << roll->roll_value() << "\n";
}

Shooter::~Shooter() {
    for (auto roll : rolls)
        delete roll;
}