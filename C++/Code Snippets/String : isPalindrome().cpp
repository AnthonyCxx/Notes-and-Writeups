// Reverses a string, returning a new string
string reverse(const string& source)
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
