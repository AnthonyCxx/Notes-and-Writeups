# Templates (Generics) in C++
Templates are a definition of a function of class that is not specific to any one type.
The classic example of a template is the _swap()_ function. The _swap()_ function is simple and makes no calls to type-specific features like string's _substr()_ method,
so why write five different overloads of the same exact function when the only difference is the datatype? When you write a templated function _swap()_, you can call it
with any datatype, saving you plenty of time that you would have spent overloading functions. To make a function a template, add `template <typename T>` before the return type,
where '_T_' is the name of the datatype of whatever variable is subject to change. The name '_T_' is entirely arbitrary — you can name the type whatever you want, but '_T_'
is generally used because it's short and makes sense (since '_T_' is short for type). In fact, some languages like C# mandate '_T_' as the indicator of a generic type.

Interestingly enough, the type-specific versions of templated function/class do not exist until used in the program. To prove this, make a syntax error in a templated
function and compile the program without using it. The program will compile just fine.

## Templated Functions

## Templated Classes

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
