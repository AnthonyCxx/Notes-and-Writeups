//Recursive Fibonacci sequence
unsigned long long fib(unsigned long long n = 0)
{
    //If reached the beginning of the Fibonacci sequence
    if (n < 2)
        return n;

    //Calculate the previous two steps in the Fibonacci sequence
    return fib(n-1) + fib(n-2);
}
