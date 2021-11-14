#include <iostream>

/*
    This program operates off the following principles:
    1. Modding an integer 10 yields the last digit of the number (e.g. 127 -> 7).
    2. Multiplying an integer by 10 moves all the digits over 1 and leaves a space (0), which can be added to.
    3. Dividing an integer by 10 discards the last number (e.g. 127 -> 12, assuming integer division).
*/

int main()
{
    //Pick a number to reverse
    int original = 12345;

    //Declare a result and a remainder (result starts at 0 because it's used before assigned)
    int result = 0, remainder;

    //Until you have no numbers left
    while (original != 0)
    {
        //Get the last digit of the original
        remainder = original % 10;

        //Append the last digit of the original to the result
        result = result*10 + remainder;

        //Remove the last digit from the original number
        original /= 10;

        // >> Repeat over with the next digit >>
    }

    //Print the result
    std::cout << "The number in reverse is: " << result << '\n';

    return 0;
}
