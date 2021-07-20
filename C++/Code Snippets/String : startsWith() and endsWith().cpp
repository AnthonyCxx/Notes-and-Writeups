#include <string>

bool startsWith(const string& text, const string& substr)
{
        return text.find(substr) == 0;
}

bool endsWith(const string& text, const string& substr)
{
        return text.rfind(substr) + substr.length() == text.length();
}
