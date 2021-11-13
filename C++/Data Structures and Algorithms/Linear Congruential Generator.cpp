// Random Number Generation in C++

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
        std::int64_t _seed;

    public:
        //Trivial Constructor (used to seed the RNG)
        LinearCongruentialGenerator(std::int64_t seed): _seed(seed)
        {
            //Empty
        }

        //Generates a random number
        [[nodiscard]] std::int16_t rand() noexcept
        {
            _seed = (214'013 * _seed + 2'531'011) % std::numeric_limits<std::int16_t>::max();
            return _seed;
        }
};

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
