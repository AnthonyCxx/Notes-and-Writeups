void reverse(string& str)
{
    size_t size = str.length();

    for (int i=0; i < size / 2; i++)
    {
        swap(str[i], str[size - i - 1]);
    }
}
