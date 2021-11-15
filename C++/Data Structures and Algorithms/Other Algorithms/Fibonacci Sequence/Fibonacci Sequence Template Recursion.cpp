//Compile-time Fibonacci sequence using template recursion
template <unsigned long long N>
struct Fib
{
    static constexpr unsigned long long value = Fib<N-1>::value  + Fib<N-2>::value;
};

template<>
struct Fib<1>
{
    static constexpr unsigned long long value = 1;
};

template<>
struct Fib<0>
{
    static constexpr unsigned long long value = 0;
}
