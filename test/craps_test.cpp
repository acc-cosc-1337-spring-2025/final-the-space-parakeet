#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "roll.h"
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>

using std::cout;

// TEST_CASE("Die rolls values in range [1, 6].") {
// 	Die die {};
// 	int rolled;
// 	int sum = 0;
// 	for (int i = 0; i < 100; ++i) {
// 		rolled = die.roll();
// 		cout << "\trolled:\t" << rolled << "\n";
// 		REQUIRE(1 <= rolled);
// 		REQUIRE(rolled <= 6);
// 		sum += rolled;
// 	}
// 	cout << "Average value: " << static_cast<double>(sum) / 100 << "\n";
// }


TEST_CASE("Die rolls values in range [1, 6].") {
	Die die {};
	int rolled;
	for (int i = 0; i < 10; ++i) {
		rolled = die.roll();
		REQUIRE(1 <= rolled);
		REQUIRE(rolled <= 6);
	}
}

// TEST_CASE("Two dice roll values in range [2, 12] (check indiv. dice values are unique).") {
// 	Die die1 {};
// 	Die die2 {};
// 	int rolled1;
// 	int rolled2;
// 	int rolled_sum;
// 	int total_sum = 0;
// 	for (int i = 0; i < 100; ++i) {
// 		rolled1 = die1.roll();
// 		rolled2 = die2.roll();
// 		rolled_sum = rolled1 + rolled2;
// 		cout << "\trolled1:\t" << rolled1 << "\n";
// 		cout << "\trolled2:\t" << rolled2 << "\n";
// 		cout << "\trolled_sum:\t" << rolled_sum << "\n";
// 		REQUIRE(2 <= rolled_sum);
// 		REQUIRE(rolled_sum <= 12);
// 		total_sum += rolled_sum;
// 	}
// 	cout << "Average value: " << static_cast<double>(total_sum) / 100 << "\n";
// }


TEST_CASE("Two dice roll values in range [2, 12].") {
	Die die1 {};
	Die die2 {};
	Roll roll {die1, die2};
	for (int i = 0; i < 10; ++i) {
		roll.roll_dice();
		REQUIRE(2 <= roll.roll_value());
		REQUIRE(roll.roll_value() <= 12);
	}
}

TEST_CASE("Shooter returns pointer to roll with values between [2, 12].") {
	Die die1 {};
	Die die2 {};
	Roll* roll;
	Shooter shooter {};
	for (int i = 0; i < 10; ++i) {
		roll = shooter.throw_dice(die1, die2);
		REQUIRE(2 <= roll->roll_value());
		REQUIRE(roll->roll_value() <= 12);
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
		switch (roll->roll_value()) {
			case 7: case 11:               REQUIRE(come_out_phase.get_outcome(roll) == RollOutcome::NATURAL); break;
			case 2: case 3: case 12:       REQUIRE(come_out_phase.get_outcome(roll) == RollOutcome::CRAPS); break;
			default:                       REQUIRE(come_out_phase.get_outcome(roll) == RollOutcome::POINT); break;
		}
	}
}

TEST_CASE("shooter phase returns outcomes: point, seven out, nopoint") {
	Shooter shooter {};
	Die die1 {};
	Die die2 {};
	Roll* roll = shooter.throw_dice(die1, die2);
	int point = roll->roll_value();
	PointPhase point_phase {point};
	for (int i = 0; i < 10; ++i) {
		roll = shooter.throw_dice(die1, die2);
		if (roll->roll_value() == point) 	REQUIRE(point_phase.get_outcome(roll) == RollOutcome::POINT);
		else if (roll->roll_value() == 7)	REQUIRE(point_phase.get_outcome(roll) == RollOutcome::SEVEN_OUT);
		else								REQUIRE(point_phase.get_outcome(roll) == RollOutcome::NOPOINT);
	}
}





