std::string filter(std::string str, std::function<bool(const char)> predicate)
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
    //Apply <cctype>'s 'tolower()' to every character in the string
    std::for_each(s.begin(), s.end(), [](char& c) -> void {c = tolower(c);});

    //Filter the text (remove an non-alphanumeric characters
    std::string filtered = filter(s, [](const char c){return isalnum(c);});

    //Get the reverse of the string
    std::string reversed = filtered;
    std::reverse(reversed.begin(), reversed.end());

    //A word is a palindrome if the word matches its inverse, character for character
    return filtered == reversed;
}
