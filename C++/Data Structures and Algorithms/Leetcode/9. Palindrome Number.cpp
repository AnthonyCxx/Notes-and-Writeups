
/*
  Solution 1: Casting to std::string
  ==================================
  By casting the integer to a string, we can know the 
  number of digits (now characters). From there, it's just
  a matter of iterating over the string and making sure the
  numbers match.
*/
bool isPalindrome(int x) 
{
    //Cast the integer to a string to determine the number of characters
    std::string str = std::to_string(x);

    //Mirrored iteration: make sure each number 'i' and 'j' match
    for(std::size_t i=0, j=str.size()-1; i < j; ++i, --j)
    {
        if (str[i] != str[j])
            return false;
    }

    //If all the checks were passed
    return true;
}


/*

*/
