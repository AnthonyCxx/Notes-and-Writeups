//Iterative fibonacci sequence
unsigned long long fib(unsigned long long n)
{
    unsigned long long previous = 1, current = 1, next;

    //If 'n' is 0 or 1, return the appropriate number
    if (n <= 1)
        return n;

    //Calculate the Fibonacci number
    for(std::size_t i = 3; i <= n; ++i)  //Starting at the third iteration (skips the first two)
    {
        next = previous + current;
        previous = current;
        current = next;
    }

    return next;
}
