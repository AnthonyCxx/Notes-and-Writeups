/*
  Given an integer n, return the amount of bits set (1 bits).

  Inspiration for this solution goes to the Seander's "Counting Bits Set" method on his page at Stanford:
  https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetNaive
*/

int hammingWeight(std::uint32_t n) 
{
    unsigned int total = 0;

    //For every bit in the integer
    for(; n; n >>= 1)
    {
        //Increase the total if the current bit is 1
        if (n & 1)
          total++; 
    }

    //Return the total
    return total;
}
