/*
  Solution explanation (solution 1): https://stackoverflow.com/questions/15355080/the-most-efficient-way-to-reverse-a-number
  Solution explanation (solution 2): https://www.programiz.com/cpp-programming/examples/reverse-number
  
  Reversing a number is fairly easy, but the problem arises when you learn 
  that "the environment does not allow you to store 64-bit integers". This means
  that you cannot cop out and store the value in an unsigned long long and then just
  check if the value with within std::numeric_limits<int>::min() and ::max().
*/


/*
  SOLUTION 1: Casting to std::string
  ==================================
  
  This is a fairly straight-forward solution. Cast the integer
  to a string and then reverse it character by character. If you 
  get an error when casting it back to an integer, then you know
  that the number is not a valid int.
*/
int reverse(int x) 
{
    //String representation of the integer
    std::string as_str = to_string(x);

    //Iterate over the string, swapping every step. Skip first index if negative.
    for(int i=(x < 0 ? 1 : 0), j=as_str.size()-1 ; i < j; ++i, --j)
    {
        //Swap the current index with its mirror
        std::swap(as_str[i], as_str[j]);
    }

    //Get the result as an integer
    try
    {
          //The stoi() function ONLY returns integers and throws an error if it's out of range. Use std::stol and std::stoll for longs/long longs
          return stoi(as_str);  //breaks here if an error is thrown
    }
        catch(const out_of_range&) //If larger than an int (32 bits), stoi throws oor (out_of_range)
    {
        //If no conversion to int can be made, return 0
        return 0;
    }
}


/*
  SOLUTION 2: Using Integer Arithmetic
  ====================================
  
  This solution operates off the following principles:
  1. Modding an integer 10 yields the last digit of the number (e.g. 127 % 10 -> 7).
  2. Multiplying an integer by 10 moves all the digits over 1 and leaves a space (0), which can be added to.
  3. Dividing an integer by 10 discards the last number (e.g. 127 / 10 -> 12, assuming integer division).
  
  I used took the absolute value of the integer instead of just doing 'x = -x' because
  "In 2's complement systems, the absolute value of the most-negative value is out of range, 
  e.g. for 32-bit 2's complement type int, INT_MIN is -2147483648, but the would-be result 2147483648
  is greater than INT_MAX, which is 2147483647." -cppreference
*/
int reverse(int x) 
{
    int result = 0;
    int remainder;
    bool isNeg = false;

    //If the original number is negative, make it positive for modulus trick to work
    if (x < 0)
    {
        isNeg = true;
      
        /*
          Take the absolute value of the integer instead of just doing 'x = -x' because
          "In 2's complement systems, the absolute value of the most-negative value is out of range, 
          e.g. for 32-bit 2's complement type int, INT_MIN is -2147483648, but the would-be result 2147483648
          is greater than INT_MAX, which is 2147483647." -cppreference
        */
        x = abs(x); 
    }

    //Until you reach 0 (at which point the int is completely reversed)
    while (x > 0)
    {
        //If you are about to exceed the max value of an integer, end by returning 0
        if (std::numeric_limits<std::int32_t>::max() / 10 < result)
            return 0;

        //Get the last digit of the original
        remainder = x % 10;

        //Append the last digit of the original to the result
        result = result*10 + remainder;

        //Remove the last digit from the original number 
        x /= 10;
    }

    //If the initial number was negative, return the result as negative
    return isNeg ? -result : result;
}
