//In-depth problem explanation (C#): https://cis300.cs.ksu.edu/stacks-queues/paren/


/*
    To find a valid solution for this problem, you have to iterate over every character in the string,
    keeping track of the most recently opening parenthesis. If you coming across a closing parenthesis
    that does not match the most recently opening parenthesis, they the string is malformed (invalid).
    By the time you finish iterating over the string, you should have no unmatched opening parentheses
    (which means the stack should be empty)
*/
bool isValid(std::string s) 
{
    //Create a stack to store the left parentheses
    std::stack<char> stk;

    //For every character in the string
    for (const char c : s)
    {
        //If an opening parenthesis, store it
        if (c == '(' or c == '[' or c == '{')
        {
            stk.push(c);
        }
        else if (!stk.empty())   //if there are opening parenthesis to match with
        {
            if (stk.top() == '(' and c == ')')    //if ( and )
            { 
                stk.pop();
            }
            else if (stk.top() == '[' and c == ']')  //if [ and ]
            {
                stk.pop();
            }
            else if (stk.top() == '{' and c == '}')  //if { and }
            {
                stk.pop();
            }
            else //if most recent opening parenthesis does not match the closing parenthesis -> invalid string
                return false;
        }
        else //if you encounter a closing parenthesis without having an opening parenthesis to match it with -> invalid string
            return false;
    }

    //If there are no unclosed parentheses -> valid string
    return stk.empty();
}
