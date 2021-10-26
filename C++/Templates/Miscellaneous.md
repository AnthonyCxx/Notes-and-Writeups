## Using Non-datatype as Template Arguments
Remember when I said that templates are more than just generics? Well, here's a reason why: a template argument can be something other than a datatype. If you've ever used
a container from the standard template library ([STL containers](https://www.cplusplus.com/reference/stl/)) like _std::array_, then you've seen that you can use a template
argument to indicate the size of a data structure. Here, the size of the _List_ class is a _std::size\_t_ variable called _N_, which is a letter often used to represent
the size of a collection of items in computer science.

This is just one of many things that you could use aside from a datatype; you can do a lot with non-template type parameters (compile-time recursive Fibonacci sequence using structs with const static values, anyone?).
```C++
#include <iostream>
#include <vector>
#include <initializer_list>


template <typename T, std::size_t N>
class List
{
    private:
        std::vector<T> data;

    public:
        //Constructor using an initializer_list
        constexpr List(std::initializer_list<T> elems): data(elems)
        {
            //Empty!
        }

        //Compile-time function: fills the array with a given value
        constexpr void fill(T value) noexcept
        {
            for(size_t i=0; i < N; ++i)
            {
                data[i] = value;
            }
        }
};


int main()
{
    //Initialize list with std::initializer_list
    List<int, 5> list {1, 2, 3, 4, 5};

    list.fill(10);

    return 0;
}
```
> Reference: [_What is size\_t?_](https://en.cppreference.com/w/cpp/types/size_t)

## Proper Return Type Deduction for Templates with Different Types
Let's say you have a templated function called _multiply()_, which takes two numbers of different types _T1_ and _T2_ and returns their product. What would the return type be?
Would it be _T1_? But what if the product was a double and _T1_ were an integer? It would truncate the result. To avoid this problem, you can use _auto_ as the return type,
which makes the compiler determine the return type. If you want to specify rules for determining the return type during deduction instead of leaving it to be deduced by the datatype of the return statement, you can use [trailing return types](https://www.ibm.com/docs/en/zos/2.1.0?topic=declarators-trailing-return-type-c11). For example, if you wrote `-> decltype(a*b)`, then
the return type would be deduced to be the datatype of the product of _a_ and _b_.

**WARNING:** _decltype()_ may return a reference. Use `-> typename std::decay<decltype(a*b)>::type` to prevent returning references and discard cv-qualifiers (remember to `#include <type_traits>`!).
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

## Template Type-deduction Guides for Classes
With C++17 came [class template argument deduction](https://en.cppreference.com/w/cpp/language/class_template_argument_deduction) (CTAD), which allow you to guide how the
compiler deduces the datatype of a class. In this example (which was practically taken straight from isocpp.org), the compiler uses the type _std::string_ whenever
it encounters a _const char\*_ (a string literal). In all reality, you could have just used `"Hello, world!"s` (the [""s string literal suffix](https://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s)).

Note: from testing, I noticed that it doesn't warn you if you accidentally compile with C++14 or before; instead, you just get a generic compilation error. Please remember
to compile with C++17 when using CTAD.
```C++
#include <iostream>

template <typename T>
class Container
{
    private:
        T data;

    public:
        //Simple constructor using initialization list
        Container(T param): data(param) {}; 
};

//Type deduction guide -- constructor will consider arguments to be 'std::string' when given 'const char*'
Container(const char*) -> Container<std::string>;

int main()
{
    //'T' would normally be 'const char*' since it's a string literal, but now it's 'std::string'
    Container dummy_var("this object will be of type std::string because of deduction guides");

    return 0;
}
```

## Preventing Template Instantiation with _std::enable\_if_
_std::enable\_if\<condition, returnType\>_ is a function evaluated at compile-time that can be used to restrict templates to being of certain types (like [_static\_assert_](https://en.cppreference.com/w/cpp/language/static_assert), but without the forced error); moreover, it can be used to include or exclude considering certain template overloads when substituting types. _std::enable\_if_ takes the place of the return type of the function, so the type it returns should be the return type of the function. If no type is provided, it assumes and returns _void_.

Succinctly put, _std::enable\_if_ is "a metafunction is a convenient way to leverage [SFINAE](https://en.cppreference.com/w/cpp/language/sfinae) to conditionally 
remove functions from overload resolution based on type traits and to provide separate function overloads and specializations for different type traits." -cppreference, [_std::enable\_if_](https://en.cppreference.com/w/cpp/types/enable_if)

## Sources
Medium: [C++ 17 Class Templates: CTAD and Type Deduction Guide](https://medium.com/codex/c-17-class-templates-ctad-and-type-deduction-934d9cf5f529) <br />
cppreference: [Class template argument deduction (CTAD)](https://en.cppreference.com/w/cpp/language/class_template_argument_deduction) <br />
isocpp.org: [Quick Q: What are template deduction guides in C++17?](https://isocpp.org/blog/2017/09/quick-q-what-are-template-deduction-guides-in-cpp17) <br />
