#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include "die.h"

using std::cout;

TEST_CASE("die rolls values in range [1, 6]") {
	Die die {};
	int rolled;
	for (int i = 0; i < 10; ++i) {
		rolled = die.roll();
		cout << "\trolled:\t" << rolled << "\n";
		REQUIRE(1 <= rolled && rolled <= 6);
	}
}

TEST_CASE("two dice roll values in range [2, 12]") {
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

