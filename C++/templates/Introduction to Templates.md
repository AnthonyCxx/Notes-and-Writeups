# Introduction to Templates in C++
Templates are a definition of a function of class that is not specific to any one type.
The classic example of a template is the _swap()_ function. The _swap()_ function is simple and makes no calls to type-specific features like string's _substr()_ method,
so why write five different overloads of the same exact function when the only difference is the datatype? When you write a templated function _swap()_, you can call it
with any datatype, saving you plenty of time that you would have spent overloading functions. 

To make a function a template, add `template <typename T>` before the return type,
where '_T_' is the name of the datatype of the variable that is subject to change. The name 'T' is entirely arbitrary — you can name the type whatever you want, but 'T'
is generally used because it's short and makes sense (since 'T' is short for type). 'T' is so common that some languages like C# mandate it as the indicator of 
generic type. When using a templated function/class, you should specifiy the datatype by putting the type in angled brackets after the name of the function/class
(e.g. `void swap<int>(a, b)`). You can leave the compiler to imply the datatypes, but including the type helps code readability.

When you use a template like `swap<int>(a, b)`, it's not calling a type-generic version of the function. What's actually happening is the compiler is creating a version of 
the `swap()` function that works with integers. The very idea of templates is that you give the compiler a template and it generates the appropriate functions that you need.
So, if you never call `swap<char>(a, b)`, then the _char_ version of the swap function does not exist because it was never created.

## Templates Functions

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

```C++

```
