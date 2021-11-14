/* 
    A Linear Congruential Random Number Generator built in C++.
    ===========================================================
    
    "A linear congruential generator (LCG) is an algorithm that yields a sequence of pseudo-randomized numbers calculated
    with a discontinuous piecewise linear equation. The method represents one of the oldest and best-known pseudorandom number 
    generator algorithms. The theory behind them is relatively easy to understand, and they are easily implemented and fast, 
    especially on computer hardware which can provide modular arithmetic by storage-bit truncation." 
    - Wikipedia, Linear Congruential Generator
    
    The values chosen for a, c, and m are based on Microsofts implementation of Microsoft Visual/Quick C/C++.
*/

//C++ Header Files
#include <iostream>     //For printing (disinclude if not using main example)
#include <cstdint>     //For fixed-width integers
#include <limits>     //For max limit of a 16-bit integer

//C Header Files
#include <time.h>  //For seeding the RNG with time(NULL)

//A random number generator
class LinearCongruentialGenerator
{
    private:
        std::uint64_t _seed;

    public:
        //Trivial Constructor (used to seed the RNG)
        LinearCongruentialGenerator(std::uint64_t seed): _seed(seed)
        {
            //Empty
        }

        //Generates a random number (0 - 65,535, inclusive)
        [[nodiscard]] std::uint16_t rand() noexcept
        {
            _seed = (214'013 * _seed + 2'531'011) % std::numeric_limits<std::uint16_t>::max();
            return _seed;
        }
};



// DRIVER CODE //
int main()
{
    //Create and seed the random number generator
    LinearCongruentialGenerator RNG(time(NULL));

    //Print 100 random numbers
    for(int i=0; i < 100; ++i)
    {
        std::cout << RNG.rand() << '\n';
    }

    return 0;
}
