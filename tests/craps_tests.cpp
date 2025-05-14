#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>

using std::cout;

TEST_CASE("die rolls values in range [1, 6]") {
	Die die {};
	int rolled;
	for (int i = 0; i < 10; ++i) {
		rolled = die.roll();
		// cout << "\trolled:\t" << rolled << "\n";
		REQUIRE(1 <= rolled && rolled <= 6);
	}
}

/*
TEST_CASE("two dice roll values in range [2, 12] (check indiv. dice are unique)") {
	Die die1 {};
	Die die2 {};
	int rolled1;
	int rolled2;
	int rolled_sum;
	for (int i = 0; i < 10; ++i) {
		rolled1 = die1.roll();
		rolled2 = die2.roll();
		rolled_sum = rolled1 + rolled2;
		cout << "\trolled1:\t" << rolled1 << "\n";
		cout << "\trolled2:\t" << rolled2 << "\n";
		cout << "\trolled_sum:\t" << rolled_sum << "\n";
		REQUIRE(2 <= rolled_sum && rolled_sum <= 12);
	}
}
*/
/*
TEST_CASE("two dice roll values in range [2, 12]") {
	Die die1 {};
	Die die2 {};
	Roll roll {die1, die2};
	for (int i = 0; i < 10; ++i) {
		roll.roll_dice();
		cout << "\trolled:\t" << roll.roll_value() << "\n";
		// REQUIRE(2 <= roll.roll_value() && roll.roll_value() <= 12);
	}
}

TEST_CASE("shooter returns a roll with values between [2, 12]") {
	Shooter shooter {};
	Die die1 {};
	Die die2 {};
	Roll* roll;
	for (int i = 0; i < 10; ++i) {
		roll = shooter.throw_dice(die1, die2);
		cout << "\trolled:\t" << roll->roll_value() << "\n";
		// REQUIRE(2 <= roll->roll_value() && roll->roll_value() <= 12);
	}
}

TEST_CASE("come out phase returns outcomes: natural, craps, point") {
	Shooter shooter {};
	Die die1 {};
	Die die2 {};
	Roll* roll;
	ComeOutPhase come_out_phase {};
	for (int i = 0; i < 10; ++i) {
		roll = shooter.throw_dice(die1, die2);
		REQUIRE(
			come_out_phase.get_outcome(roll) == RollOutcome::NATURAL
		||  come_out_phase.get_outcome(roll) == RollOutcome::CRAPS
		||  come_out_phase.get_outcome(roll) == RollOutcome::NOPOINT
		);
	}
}


TEST_CASE("shooter phase returns outcomes: point, seven out, nopoint") {
	Shooter shooter {};
	Die die1 {};
	Die die2 {};
	Roll* roll;
	roll = shooter.throw_dice(die1, die2);
	PointPhase point_phase {roll->roll_value()};
	for (int i = 0; i < 10; ++i) {
		roll = shooter.throw_dice(die1, die2);
		REQUIRE(
			point_phase.get_outcome(roll) == RollOutcome::POINT
		||  point_phase.get_outcome(roll) == RollOutcome::SEVEN_OUT
		||  point_phase.get_outcome(roll) == RollOutcome::NOPOINT
		);
	}
}

*/