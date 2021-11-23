/*
  Given two strings, return true if strings 's' and 't' are anagrams of each other
*/


/*
  Solution 1:
  ====================
*/
bool isAnagram(string s, string t) 
{
    std::unordered_map<char32_t, int> chars;

    for(const char c : s)
    {
        if (chars.find(c) == chars.end())
            chars.insert({c, 1});
        else
            chars[c]++;
    }

    for(const char c : t)
    {
        if (chars.find(c) == chars.end())
            return false;
        else
            chars[c]--;
    }

    for(const auto& map_entry : chars)
    {
        if (map_entry.second)
            return false;
    }

    return true;
}

/*
  Solution 2: 
  =======================

  Credit: https://leetcode.com/PriyanshuPundhir/
*/
bool isAnagram(string s, string t) 
{
    std::unordered_map<char32_t, int> chars;

    if(s.length()!=t.length()) 
        return false;

    for(int i=0; i < s.size(); i++)
    {
            chars[s[i]]++;
            chars[t[i]]--;
    }

    for(const auto& map_entry : chars)
    {
        //If the 
        if (map_entry.second)
           return false;
    }

    return true;
}
