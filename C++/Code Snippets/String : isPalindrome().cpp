/*
'<string_view>' is a C++17 header file that increases efficiency

If you don't want to use C++17, replace 'string_view' with 'string&'
*/

#include <string_view>

// Reverses a string, returning a new string
string reverse(const string_view source)
{
    string reversed;

    for (int i=source.length() - 1; i > -1; i--)
    {
        reversed += source[i];
    }

    return reversed;
}

// A palindrome is a word that is spelled the same backwards and forwards
bool isPalindrome(const string& str)
{
    return str == reverse(str);
}
