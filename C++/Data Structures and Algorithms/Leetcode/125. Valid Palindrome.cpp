/*
    This challenge requires you to filter a string and then determine if it's a palindrome.
    I could have done the transformation to lowercase at the same time as filtering the string,
    but I wanted to write the code in such a way that it could be repurposed. Because of this,
    it is a little slower than most solutions.
*/

template <typename Function>
[[nodiscard]] std::string filter(std::string str, Function&& predicate) noexcept
{
    std::string filteredText;

    //For every char the in string
    for(const char c : str)
    {
        if (predicate(c))  //Apply the predicate, copying if true
            filteredText = std::move(filteredText) + c;
    }

    return filteredText;
}


bool isPalindrome(std::string s)
{
    //If 'c' is a captial letter, make it lowercase
    auto toLowercase = [](char& c) constexpr noexcept -> char {return c >= 'A' and c <= 'Z' ? c + 32 : c;};

    //Apply <cctype>'s 'tolower()' to every character in the string (O(n))
    std::for_each(s.begin(), s.end(), [&toLowercase](char& c) constexpr noexcept -> void {c = toLowercase(c);});

    //Filter the text (remove an non-alphanumeric characters
    std::string filtered = filter(s, [](const char c){return isalnum(c);});

    
    //If any character does not match with its opposite, return false
    for(std::size_t i=0; i < filtered.size()/2; ++i)
    {
        if (filtered[i] != filtered[filtered.size()-i-1])
            return false;
    }


    //If all the characters matched, return true
    return true;
}
