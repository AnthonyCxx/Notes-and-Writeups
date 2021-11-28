/*
  Wow, I really hated this one, but I hate myself more for doing it at 1:06 in the morning.
  
  Long and short of it: write a regex that can properly identify if a string is a valid number or not.
*/


bool isNumber(string s) 
{   
    /*
      Clause analysis:
      (\+|-)?                   : optional + or - sign
      (\d+|\d+\.\d*|\d*\.\d+)   : regex for a number. Have to patrition out '3.' and '.3' because "\d*\.\d*" includes the illegal '.', which is meaningless
      ((e|E)(\+|-)?\d+)?        : optional 'E' to the power of some integer, which may or may not have a sign
    */
  
    static std::regex pattern(R"((\+|-)?(\d+|\d+\.\d*|\d*\.\d+)((e|E)(\+|-)?\d+)?)");   //static because only one instance is needed throughout the program
    return std::regex_match(s, pattern);
}
