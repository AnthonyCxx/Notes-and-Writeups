# Storage Classes in C++


## _auto_
_auto_ is C++'s equivalent of [_var_](https://www.geeksforgeeks.org/var-keyword-in-java/) in Java and C#; _auto_ leaves the datatype of a variable to be inferred by the
compiler, which prevents you from having to type out long datatypes names. Only use _auto_ where you feel that the datatype is clear, as _auto_ can greatly
reduce code readability when overused.

_auto_ can be used as the return type for a function and can even be used as the type for a function parameter (as of C++20).
[Here](https://lesleylai.info/en/auto-parameters/)'s why you shouldn't do that. 
```C++
#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto add(T1 a, T2 b)
{
    return a + b;
}

int main()
{
    auto intA = 100;
    auto floatB = 3.14f;

    cout << "100 + 3.14 = " << add(intA, floatB) << '\n';

    return 0;
}
```

## _extern_

## _static_

## _mutable_

## _thread\_local_

## _register_
I've included _register_ last as, although it does exist, it was deprecitated in C++11 and was [removed in C++17 ](https://botondballo.wordpress.com/2015/06/05/trip-report-c-standards-meeting-in-lenexa-may-2015/). If you try to compile a program with the _register_ keyword in it with C++17, you will get a warning '_warning: ISO C++17 does not allow ‘register’
storage class specifier_'.

The _register_ keyword was a hint to the compiler to store the variable in a [CPU register](https://whatis.techtarget.com/definition/register) istead of in memory so it 
can be accessed faster. Data is typically stored in a CPU register when it is accessed often; this practice increases program performance. The problem with the _register_ 
keyword was that the compiler is much better at deciding what data should be stored in the register and when, so it ignored the keyword the majority of the time. This was
such a problem that the keyword was subsequently removed (just like _auto_ in C).

## Sources
Microsoft C++ Documentation: [_Storage Classes_](https://docs.microsoft.com/en-us/cpp/cpp/storage-classes-cpp?view=msvc-160) <br />
cppreference.com: [_Storage Class Specifiers_](https://en.cppreference.com/w/cpp/language/storage_duration) <br />
TutorialsPoint: [_Storage Classes in C++_](https://www.tutorialspoint.com/cplusplus/cpp_storage_classes.htm) <br />
JavaTPoint: [_C++ Storage Classes_](https://www.javatpoint.com/cpp-storage-classes) <br />
GeeksforGeeks: [_Storage Classes in C++ with Examples_](https://www.geeksforgeeks.org/storage-classes-in-c-with-examples/) <br />
Programiz: [_C++ Storage Class_](https://www.programiz.com/cpp-programming/storage-class) <br />
