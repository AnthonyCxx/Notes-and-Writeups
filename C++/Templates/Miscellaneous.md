## Template Type-guarding with _std::enable\_if_
Templates can be specialized such that they can only be used for certain types, making them safer. For example, if I wrote a function _divide()_, I would want it to work
with all numeric types ([_std::is\_arithmetic()_](https://en.cppreference.com/w/cpp/types/is_arithmetic)), but not string literals. To

## Proper Return Type Deduction for Templates with Different Types
Let's say you have a templated function called _multiply()_, which takes two numbers of different types _T1_ and _T2_ and returns their product. What would the return type be?
Would it be _T1_? But what if the product was a double and _T1_ were an integer? It would truncate the result. To avoid this problem, you can use _auto_ as the return type,
which makes the compiler determine the return type. If you want to specify rules for determining the return type during deduction instead of leaving it to be deduced by the datatype of the return statement, you can use [trailing return types](https://www.ibm.com/docs/en/zos/2.1.0?topic=declarators-trailing-return-type-c11). For example, if you wrote `-> decltype(a*b)`, then
the return type would be deduced to be the datatype of the product of _a_ and _b_.

**WARNING:** _decltype()_ may return a reference. Use `-> typename std::decay<decltype(a*b)>::type` to prevent returning references and discard cv-qualifiers.
```C++
#include <iostream>

//Templated function 'multiply' takes two arguments of different types
template <typename T1, typename T2>
auto multiply(const T1& a, const T2& b) -> decltype(a*b)   //Trailing return type, requires return type 'auto'
{
    return a*b;
}
```
> [_What is decltype()?_](https://docs.microsoft.com/en-us/cpp/cpp/decltype-cpp?view=msvc-160) <br />
> [_What is std::decay\<T\> and When Should I use It?_](https://newbedev.com/what-is-std-decay-and-when-it-should-be-used) <br />
> [Why did I write _typename std::decay\<T\>_ instead of just std::decay\<T\>?](https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords) <br />
