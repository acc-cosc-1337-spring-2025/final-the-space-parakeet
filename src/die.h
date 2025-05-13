#pragma once

#include <ctime>
#include <random>

/*------------------------------------------------------------------------------
    Die Class
------------------------------------------------------------------------------*/

class Die {
    public:
        int roll ();
    private:
        int sides {6};
        // die is seeded with source of entropy from device on initialisation
        // die uses 64-bit mersenne twister engine and a uniform distribution
        std::random_device seed;
        std::mt19937_64 generator {seed()};
};