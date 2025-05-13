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
		cout << rolled;
		REQUIRE(1 <= rolled && rolled <= 6);
	}
}

