#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>

using std::cout;

int main() {
	// Note:
	// - I'm using the C++11 <ctime> and <random> libraies to generate random integers
	//   with a uniform distribution, because the old srand(time(0)) and modulo method 
	//   introduces bias towards certain numbers and fairly weighted dice are important 
	//   for a casino game. (See die class for implementation.)
	Die die1 {};
	Die die2 {};
	Shooter shooter {};
	Roll* roll;
	int rolled_value;

	// Come out phase: 
	// - Roll while outcome is natural (7, 11) or craps (2, 3, 12).
	// - End come out phase if outcome is point (4, 5, 6, 8, 9, 10).
	cout << "Start of come out phase.\n";
	ComeOutPhase come_out_phase {};
	roll = shooter.throw_dice(die1, die2);
	rolled_value = roll->roll_value();
	while (come_out_phase.get_outcome(roll) != RollOutcome::POINT) {
		cout << "Rolled " << rolled_value << ". Roll again.\n";
		roll = shooter.throw_dice(die1, die2);
		rolled_value = roll->roll_value();
	}

	// Point phase:
	// - End point phase if number is point or 7.
	// - Roll while outcome is any other number (nopoint).
	cout << "Rolled " << rolled_value << "! Start of point phase.\n";
    cout << "Roll until " << rolled_value << " or 7 is rolled.\n";
	PointPhase point_phase(rolled_value);
	roll = shooter.throw_dice(die1, die2);
	rolled_value = roll->roll_value();
	while (point_phase.get_outcome(roll) == RollOutcome::NOPOINT) {
		cout << "Rolled " << rolled_value << ". Roll again.\n";
		roll = shooter.throw_dice(die1, die2);
		rolled_value = roll->roll_value();
	}

	// Game over:
	// - Display all rolled numbers.
	cout << "Rolled " << rolled_value << "! End of point phase.\n";
	cout << "Game over. Rolled numbers:\n";
	shooter.display_rolled_values();
	return 0;
}
