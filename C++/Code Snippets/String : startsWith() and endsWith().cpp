/*
'<string_view>' is a C++17 header file that increases efficiency

If you don't want to use C++17, replace 'string_view' with 'string&'
*/

#include <string_view>

bool startsWith(const string_view text, const string_view searchStr)
{
    return text.find(searchStr) == 0;
}

bool endsWith(const string_view text, const string_view searchStr)
{
    return text.rfind(searchStr) + searchStr.length() == text.length();
}
