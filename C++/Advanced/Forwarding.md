# Forwarding in C++
> Pre-requisite: [_lvalues and rvalues_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Advanced/Move%20Semantics.md#lvalues-and-rvalues) <br />

Forwarding uses the function _forward()_ to preserve the value type (_lvalue_ or _rvalue_) of parameters passed to a function so they can be properly used within the 
function and/or passed onto other functions.

## Forwarding References (Universal References)
> Recommended Reading: [_Universal References in C++11_](https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers), by Scott Meyers <br />
> Recommended Video: [_Type Deduction and Why You Should Care_](https://www.youtube.com/watch?v=wQxj20X-tIU), by Scott Meyers

Just because a reference contains _&&_ does not mean it's an _rvalue_ reference — it may be a forwarding reference.
Unlike _lvalue_ references, which can only bind to _lvalues_, and _rvalue_ references, which can only bind to _rvalues_, a forwarding reference can bind to both
_lvalues_ and _rvalues_ (hence why it is also called a universal reference). What looks like an _rvalue_ reference (denoted by _&&_) becomes a universal reference when 
the datatype of the reference must be deduced (like in templated functions (`T&&`) or `auto&& var`). This is because whether the reference becomes an _lvalue_ or _rvalue_
reference depends on the type the function/variable is initialized with. Notice how I explicitly said 'datatype' and 'type', not treating them as interchangable, because they're
not (passing `int` to a parameter `T&&` is much different from passing `const int&`); This is because of the rulesets for type deductions, which are explained in the video linked above.
If the result of the deduction is a reference to a reference (like `(int& &&)`, which is illegal), then 
[reference collapsing](https://www.ibm.com/docs/en/xl-c-and-cpp-aix/13.1.2?topic=operators-reference-collapsing-c11) will simplify the reference into a single reference
(either _&_ or _&&_).

**WARNING**: Use universal references with care, since they WILL become the preferred function for any datatype that is implicitly converted since functions with universal
references are both templated and take any type of reference. If you write a function that takes _const string&_ and one that takes _template \<typename T\> T&&_, then passing 
'_Hello_' to it will call _template \<typename T\> T&&_ instead of _const string&_ because string literals like '_Hello_' are actually c-strings (const char\*), not strings.
This can introduce very subtle bugs, especially with copy constructors. [Source: 16:30](https://www.youtube.com/watch?v=pIzaZbKUw2s)

Here is an example of a universal reference, which can take an _lvalue_ or an _rvalue_ without problem.
```C++
#include <iostream>
#include <string>
using namespace std;

//A function that takes a forwarding reference (lvalues and rvalues), a templated '&&'
template <typename T>
void print(T&& message)  //Argument must be of type 'T'
{
    cout << message << '\n';
}

int main()
{
    /*
        Function 'print()' can take both lvalues and rvalues,
        since it's a forwarding reference
    */

    //lvalue
    string str = "This is an lvalue";
    print(str);

    //rvalue
    print("This is an rvalue");

    return 0;
}
```

## 

## Preserving Value Types with _std::forward()_ (Perfect Forwarding)
> Recommended Video: [_Back to Basics: Move Semantics (part 2 of 2)_](https://www.youtube.com/watch?v=pIzaZbKUw2s), by Klaus Iglberger <br />

When you pass an argument to a function, it becomes an _lvalue_ regardless of whether it was passed to the function as an _lvalue_ or an _rvalue_, since parameters 
are variables. If you call _forward()_ on an argument, it casts the argument to the value type it was originally passed as. This allows you to pass arguments from
a function to another function without losing the type of value, which is called perfect forwarding and is vitally important for wrapper and factory functions.

**WARNING**: Never call _forward()_ twice on the same object.

In short, _move()_ allows you to treat an _lvalue_ like an _rvalue_ and _forward()_ allows you to preserve the orignal type of value that was passed.
```C++
#include <iostream>
#include <string>
using namespace std;

//Prints lvalues
void print(string& str)
{
    cout << "Used an lvalue...\n";
}

//Prints rvalues
void print(string&& str)
{
    cout << "Used an rvalue...\n";
}

//Wrapper
template <typename T>
void wrapper(T&& value)
{
    //Calls all values as lvalues (losing the type of value)
    print(value);
}

//Wrapper that uses 'forward<T>' to preserve value types
template <typename T>
void forwardWrapper(T&& value)
{
    //Calls lvalues as lvalues and rvalues and rvalues
    print(forward<T>(value));
}

int main()
{
    cout << "A demonstration of forwarding. The first value should be 'lvalue' and the second should be 'rvalue'\n\n";

    string str = "This string is an lvalue; 'string()' is an rvalue";

    //Using lvalues and rvalues as arguments WITHOUT forwarding
    cout << "Using a wrapper WITHOUT using 'forward()'\n";
    wrapper(str);
    wrapper(string());

    //Using lvalues and rvalues as arguments WITH forwarding
    cout << "\nUsing a wrapper WITH using 'forward()'\n";
    forwardWrapper(str);
    forwardWrapper(string());

    return 0;
}
```

## Sources
CPPCon 2014: [_Scott Meyers: "Type Deduction and Why You Care"_](https://www.youtube.com/watch?v=wQxj20X-tIU) <br />
Feabhas: [_Your handy cut-out-and-keep guide to std::forward and std::move_](https://blog.feabhas.com/2018/04/handy-cut-keep-guide-stdforward-stdmove/) <br />
SweedenCpp: [_What is this std::forward thing?_](https://www.youtube.com/watch?v=srdwFMZY3Hg), by Paul Dreik <br />
isocpp.org: [_What's the difference between std::move and std::forward?_](https://isocpp.org/blog/2018/02/quick-q-whats-the-difference-between-stdmove-and-stdforward) <br />
Howard Hinnant: [_What's the difference between std::move and std::forward_](https://stackoverflow.com/questions/9671749/whats-the-difference-between-stdmove-and-stdforward/9672202#9672202) <br />
Mircea Baja's Blog: [_C++ std::move and std::forward_](https://bajamircea.github.io/coding/cpp/2016/04/07/move-forward.html) <br />
TechMunching: [_Universal Reference and Perfect Forwarding_](https://techmunching.com/universal-reference-and-perfect-forwarding/) (this article is really good) <br />
Petr Zemek's Blog: [_Universal vs Forwarding References in C++_](https://blog.petrzemek.net/2016/09/17/universal-vs-forwarding-references-in-cpp/) <br />
open-std.org: [_Forwarding References_](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4164.pdf) (technical article, worth reading) <br />
Drew Campbell's Blog: [_Understanding Move Semantics and Perfect Forwarding: Part 3_](https://drewcampbell92.medium.com/understanding-move-semantics-and-perfect-forwarding-part-3-65575d523ff8) <br />
CPPCon 2019: [_Klaus Iglberger: “Back to Basics: Move Semantics (part 2 of 2)”_](https://www.youtube.com/watch?v=pIzaZbKUw2s&t) <br />
