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
