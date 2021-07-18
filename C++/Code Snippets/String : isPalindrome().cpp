string reverse(const string& source)
{
    string reverse;

    for (int i=source.length() - 1; i > -1; i--)
    {
        reverse += source[i];
    }

    return reverse;
}

bool isPalindrome(const string& str)
{
    return str == reverse(str);
}
