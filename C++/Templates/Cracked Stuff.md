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

## Perfectly Generic Function Wrappers
The following code can take any function with any number of arguments and will return the time it takes to run the function. If the return type is not void, then it
returns the return value of the called function along with the elapsed time (in that order) as a [std::pair](https://en.cppreference.com/w/cpp/utility/pair).
```C++
#include <utility>
#include <functional>
#include <chrono>
#include <type_traits>

template <typename Function, typename... Args>
decltype(auto) time(Function&& func, Args&&... args)
{
    //Floating-point seconds
    using fpsecond = std::chrono::duration<double, std::ratio<1,1>>;

    //Keep track of the starting time and declare an ending time
    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    double elapsedTime;

    //If a void function, call it and just return the elapsed time
    if constexpr (std::is_same_v<std::invoke_result_t<Function, Args...>, void>)
    {
        //Call the passed function with the given arguments (forwarding the arguments to preserve qualifiers)
        std::invoke(std::forward<Function>(func), std::forward<Args>(args)...);

        //Record the elapsed time
        elapsedTime = std::chrono::duration_cast<fpsecond>(std::chrono::steady_clock::now() - startTime).count();

        //Return the elapsed time (current time - start time) as a double
        return elapsedTime;
    }
    else  //Otherwise, return the return value of the passed function along with the elapsed time as std::pair
    {
        decltype(auto) returnValue = std::invoke(std::forward<Function>(func), std::forward<Args>(args)...);

        //Record the elapsed time
        elapsedTime = std::chrono::duration_cast<fpsecond>(std::chrono::steady_clock::now() - startTime).count();

        //Return the called function's return value along with the elapsed time as std::pair
        return std::make_pair(returnValue, elapsedTime);
    }
}
```
> NOTE: you do have to compile with C++17 for this to work, so add `-std=c++17` to all your compilations <br />
> NOTE: if you pass a templated function, you cannot leave out the template type. templatedSwap<int>(a,b) is fine but templatedSwap(a,b) is not <br />

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
