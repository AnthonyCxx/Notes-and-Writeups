// Split a string by a delimiter
#include <string>
#include <vector>

vector<string> split(const string& text, const char delimiter)
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

    // Append the last word
    split_text.push_back(word);

    return split_text;
}
