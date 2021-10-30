# Some Interesting Stuff Here...

## Recursive, Compile-time Fibonacci Sequence
Calculates the Nth number in the Fibonacci sequence at compile time using recursive templates. This really should just be a _constexpr_ function.

```C++
#include <iostream>
using ULL = unsigned long long;

template <ULL N>
struct Fib
{
    static constexpr ULL value = Fib<N-1>::value  + Fib<N-2>::value;
};

template<>
struct Fib<1>
{
    static constexpr ULL value = 1;
};

template<>
struct Fib<0>
{
    static constexpr ULL value = 0;
};

int main()
{
    std::cout << "17th Fibonacci number: " << Fib<17>::value << std::endl;

    return 0;
}
```

## Generic Function Wrapper
> The following example is from chapter 11 of [_C++ Templates, the Complete Guide_](https://www.amazon.com/C-Templates-Complete-Guide-2nd/dp/0321714121) <br />

## Custom Tuple Implementation

https://github.com/eliben/code-for-blog/blob/master/2014/variadic-tuple.cpp

**UNFINISHED**
```C++
#include <iostream>

//Elemental type: fire
class Fire
{
    public:
    void operator()()
    {
        std::cout << "Calling fire\n";
    }
};


//Elemental type: ice
class Ice
{
    public:
    void operator()(int i)
    {
        std::cout << "Calling ice\n";
    }
};


//Derived class that can take any amount of base classes of any type...
template <typename... Bases>
class Staff: public Bases...
{
    using Bases::operator()...;

};

int main()
{
    //Declare a staff of type 'Fire' and 'Ice'
    Staff<Fire, Ice> wizard_staff;

    //Call a derived spell
    wizard_staff();    //arbitrary int to differentiate 'Ice::spell()' and 'Fire::spell()'

    return 0;
}
```
