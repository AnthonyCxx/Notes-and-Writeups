// Reverses an existing string
void reverse(string& str)
{
    size_t size = str.length();

    for (int i=0; i < size / 2; i++)
    {
        swap(str[i], str[size - i - 1]);
    }
}

// Returns a new string (can be used in expressions like 'str == reverse(str)')
string reverse(const string& source)
{
    string reverse;

    for (int i=source.length() - 1; i > -1; i--)
    {
        reverse += source[i];
    }

    return reverse;
}
