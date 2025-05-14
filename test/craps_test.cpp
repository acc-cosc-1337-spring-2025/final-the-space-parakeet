#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "die.h"
#include <iostream>

using std::cout;

/*
TEST_CASE("die rolls values in range [1, 6]") {
	Die die {};
	int rolled;
	int sum = 0;
	for (int i = 0; i < 100; ++i) {
		rolled = die.roll();
		cout << "\trolled:\t" << rolled << "\n";
		REQUIRE(1 <= rolled);
		REQUIRE(rolled <= 6);
		sum += rolled;
	}
	cout << "Average value: " << static_cast<double>(sum) / 100 << "\n";
}
*/

TEST_CASE("die rolls values in range [1, 6]") {
	Die die {};
	int rolled;
	for (int i = 0; i < 10; ++i) {
		rolled = die.roll();
		REQUIRE(1 <= rolled);
		REQUIRE(rolled <= 6);
	}
}
