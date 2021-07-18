// Made in C++20, compile with 'g++ -std=c++2a'
#include <string_view>

bool startsWith(const string_view text, const string_view searchStr)
{
    return text.find(searchStr) == 0;
}

bool endsWith(const string_view text, const string_view searchStr)
{
    return text.rfind(searchStr) + searchStr.length() == text.length();
}
