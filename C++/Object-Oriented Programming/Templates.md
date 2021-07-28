# Templates (Generics) in C++
Templates are a definition of a function of class that is not specific to any one type.
The classic example of a template is the _swap()_ function. The _swap()_ function is simple and makes no calls to type-specific features like string's _substr()_ method,
so why write five different overloads of the same exact function when the only difference is the datatype? When you write a templated function _swap()_, you can call it
with any datatype, saving you plenty of time that you would have spent overloading functions. 

To make a function a template, add `template <typename T>` before the return type,
where '_T_' is the name of the datatype of the variable that is subject to change. The name '_T_' is entirely arbitrary — you can name the type whatever you want, but '_T_'
is generally used because it's short and makes sense (since '_T_' is short for type). '_T_' is so common that some languages like C# mandate it as the indicator of 
generic type. When using a templated function/class, you should specifiy the datatype by putting the type in angled brackets after the name of the function/class
(e.g. `void swap<int>(a, b)`). You can leave the compiler to imply the datatypes, but including the type helps code readability.

Interestingly enough, the type-specific versions of templated function/class do not exist until used in the program, which is when the compiler creates them. 

## Templated Functions
An example of a templated function.

```C++
//A simple program to swap A and B using templates.
#include <iostream>
using namespace std;

template <typename T>    //Make 'swap()' generic, using type indicator, 'T'
void genericSwap(T& a, T& b)   //Two generic types, 'T', passed by reference
{
    //Declare a generic variable
    T temp;

    //Swap 'a' and 'b'
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int intA = 10, intB = 20;
    char charA = 'A', charB = 'Z';

    //Before
    cout << "ints A and B BEFORE swap: " << intA << ", " << intB << '\n';
    cout << "chars A and B BEFORE swap: " << charA << ", " << charB << '\n';

    //An int and a char version of 'swap()'
    genericSwap<int>(intA, intB);
    genericSwap<char>(charA, charB);

    //After
    cout << "ints A and B AFTER swap: " << intA << ", " << intB << '\n';
    cout << "chars A and B AFTER swap: " << charA << ", " << charB << '\n';

    return 0;
}
```

## Templated Classes
An example of a templated class. Templates provide a safer alternative to using [void pointers to achieve polymorphism](https://riptutorial.com/c/example/17747/polymorphic-behaviour-with-void-pointers), as you would do in C. If you make your class templated, then all the methods must also be templated and you have to put `ClassName<T>::` as the 
prefix instead of just `ClassName::` as your normally would.

This example is a simple array class, based on the [_array_ class](https://www.cplusplus.com/reference/array/array/) from the C++ Standard Template Library.
```C++

```

## Default Parameters
As of C++17, you can provide default arguments for template paramters.

## Sources
isocpp.org: [_Templates_](https://isocpp.org/wiki/faq/templates) <br />
IBM C++ Documentation: [_Templates (C++ only)_](https://www.ibm.com/docs/en/i/7.4?topic=reference-templates-c-only) <br />
GeeksforGeeks: [_Templates in C++_](https://www.geeksforgeeks.org/templates-cpp/) <br />
Programiz: [_C++ Templates_](https://www.programiz.com/cpp-programming/templates) <br />
TheCherno: [_Templates in C++_](https://www.youtube.com/watch?v=I-hZkUa9mIs) <br />
IBM C++ Documentation: [_Default arguments for template parameters (C++ only)_](https://www.ibm.com/docs/en/zos/2.1.0?topic=parameters-default-arguments-template) <br />
StackOverflow: [_Template default arguments_](https://stackoverflow.com/questions/15373823/template-default-arguments) <br />
