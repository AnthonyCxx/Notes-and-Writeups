// Reverses a string, returning a new string
string reverse(const string& source)
{
    string reverse;

    for (int i=source.length() - 1; i > -1; i--)
    {
        reverse += source[i];
    }

    return reverse;
}

// A palindrome is a word that is spelled the same backwards and forwards
bool isPalindrome(const string& str)
{
    return str == reverse(str);
}
