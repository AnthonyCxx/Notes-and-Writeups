//From this GeeksforGeeks article: https://www.geeksforgeeks.org/stringstream-c-applications/

#include <string>
#include <sstream>

// Count the amount of words in a string
int wordCount(const string& str)
{
    stringstream text(str);
    string word;
    int count = 0;

    // For every word in the string stream, increment the count
    while (text >> word) count++;

    return count;
}
