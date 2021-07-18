// Returns a new string (meant to be used in expressions like 'str == reverse(str)')
string reverse(const string& source)
{
    string reverse;

    for (int i=source.length() - 1; i > -1; i--)
    {
        reverse += source[i];
    }

    return reverse;
}
