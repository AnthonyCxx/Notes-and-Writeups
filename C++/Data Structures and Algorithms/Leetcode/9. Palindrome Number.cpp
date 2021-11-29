
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
  Solution 2: Using Math (**shutters**)
  =====================================
  1. You can get the last number of an integer by modding it by 10
  2. You can append a number to an integer by multiplying it by 10 and then adding the number
  3. You can truncate the last number of an integer by dividing it by 10
*/
bool isPalindrome(int x) 
{
    if (x < 0)
        return false;

    //Variables
    int x_copy = x;         //Create a copy of x that can be manipulated 
    long x_reversed = 0;   //Stores the reveresed value of x, which may exceed the max size of an int

    //Until there are no numbers left in x
    while (x_copy != 0)
    {
        //Append the last digit of x_copy to x_reveresed
        x_reversed = x_reversed*10 + (x_copy % 10);

        //Remove the last digit from the x_copy
        x_copy /= 10;
    }

    return x == x_reversed;
}
