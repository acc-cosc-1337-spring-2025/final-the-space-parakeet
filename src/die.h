#pragma once

#include <ctime>
#include <random>

using std::random_device;
using std::mt19937_64;
using std::uniform_int_distribution;

/*------------------------------------------------------------------------------
    Die Class
------------------------------------------------------------------------------*/

class Die {
    public:
        int roll();
    private:
        int sides {6};
        // die is seeded with source of entropy from device on initialisation
        // die uses 64-bit mersenne twister engine and a uniform distribution
        random_device seed;
        mt19937_64 generator {seed()};
};