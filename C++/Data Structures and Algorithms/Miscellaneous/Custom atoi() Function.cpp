// Uses std::optional AND constexpr std::all_of. 
// !! Compile in C++17 by adding '-std=c++17' !!

#include <iostream>
#include <string>
#include <algorithm>
#include <optional>

//Custom 'atoi' function, returns the integer equivalent of a numeric string if possible, otherwise return std::nullopt (no value)
template <typename returnType = int>
[[nodiscard]] constexpr std::optional<returnType> toInt(const std::string& str) noexcept
{
    //Custom implementation of C's 'isdigit()' from the <cctype> library, but using constexpr and noexcept for better performance
    auto isNumericChar = [](const char c) constexpr noexcept -> bool { return c >= 48 and c <= 57; };

    //Return nullopt if not all the characters are 0-9 (with the exception of the first character, which may be a positive/negative sign or a number)
    if ( !(str[0] == '-' or str[0] == '+' or isNumericChar(str[0]))   or   !std::all_of(str.cbegin()+1, str.cend(), isNumericChar))
        return std::nullopt;

    //Declare the result (starts at 0 because it's used before being assigned the result of the expression)
    returnType result = 0;
    
    //For every character in the string (skipping leading zeros and positive/negative signs)
    for(std::size_t i = str.find_first_not_of("-+0"); i < str.size(); ++i)
    {
        //Append the integer version of the current character to the current value of the result
        result = result*10 + static_cast<int>(str[i] - '0');
    }
    
    //Make the result negative if there's a negative sign
    return str[0] == '-' ? -result : result;
} 



// DRIVER CODE //
int main()
{
    //Test the basic function
    std::cout << "toInt(12345): " << toInt("12345").value() << '\n';
    
    //Test with non-int return type (templated return type)
    std::cout << "toInt(99999999999): " << toInt<unsigned long long>("99999999999").value() << '\n';

    //test with leading zeros
    std::cout << "toInt(00072): " << toInt("00072").value() << '\n';

    //Test with negative signs
    std::cout << "toInt(-12): " << toInt("-12").value() << '\n';


    //Test with positive signs
    std::cout << "toInt(+12): " << toInt("+12").value() << '\n';
    
    //Test with negatives and leading zeros
    std::cout << "toInt(-00012): " << toInt("-00012").value() << '\n';

    return 0;
}
