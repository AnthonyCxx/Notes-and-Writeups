// Split a string into a dynamic array (a vector) using a delimiter, emulating '.split()' in Python. This can be reworked to work with any type pretty easily.
#include <string>
#include <vector>

vector<string> split(const string& text, const char delimiter)   //Could also be 'char&' or 'char&&'
{
    vector<string> split_text;
    string word;

    // For every character in the text
    for(int i=0; i < text.length(); i++)
    {
        if (text[i] == delimiter)
        {
            split_text.push_back(word);
            word.clear();
        }
        else
            word += text[i];   // C++ strings are mutable, so this isn't a problem
    }

    // Append the last word (not appended per the lack of delimiter at the end)
    split_text.push_back(word);

    return split_text;
}
