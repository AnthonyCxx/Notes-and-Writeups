# Selection with _std::enable\_if_ and _concept_
> **NOTE**: compiler support for concepts is still in progress. To use concepts with GCC, you must compile with C++20 and allow concepts with the -fconcepts option like 
`g++ -std=c++2x -fconcepts file.cpp`

## Preventing Template Instantiation with _std::enable\_if_
> Eli Bendersky's website: [_SFINAE and enable_if_](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/) <br />
> cppreference: [_std::enable\_if\_](https://en.cppreference.com/w/cpp/types/enable_if) <br />

_std::enable\_if\<condition, returnType\>_ is a function evaluated at compile-time that can be used to restrict templates to being of certain types (like [_static\_assert_](https://en.cppreference.com/w/cpp/language/static_assert), but without the forced error); moreover, it can be used to include or exclude considering certain template overloads when substituting types. Here, the function _add()_ is not considered for non-trivial types (as if it did not even exist). If no type is provided, it assumes and returns _void_.

Succinctly put, _std::enable\_if_ is "a metafunction is a convenient way to leverage [SFINAE](https://en.cppreference.com/w/cpp/language/sfinae) to conditionally 
remove functions from overload resolution based on type traits and to provide separate function overloads and specializations for different type traits." -cppreference, [_std::enable\_if_](https://en.cppreference.com/w/cpp/types/enable_if)

An example of an add function that only works on [trivial](https://en.cppreference.com/w/cpp/named_req/TrivialType) types. You can think of trivial types as those that are
compatible with the C language (built-ins and structs/classes with trivial constructors).
```C++
template <typename T, typename = std::enable_if<std::is_trivial<T>::value>>
auto add(T&& a, T&& b)
{
    return a + b;
}

int main()
{
    return 0;
}
```
> "A trivial default constructor is a constructor that performs no action. All data types compatible with the C language (POD types) are trivially default-constructible." -cppreference, [trivial constructors](https://en.cppreference.com/w/cpp/language/default_constructor#Trivial_default_constructor).

## Adding Constraints to Templates
C++20 introduced the _requires_ and _concept_ keyword, which allow us to add conditions to templates that act as constraints. A concept is "Concepts are named Boolean predicates
on template parameters, evaluated at compile time. A concept may be associated with a template (class template, function template, or member function of a class template), 
in which case it serves as a constraint: it limits the set of arguments that are accepted as template parameters." -Wikipedia, [_concepts_](https://en.wikipedia.org/wiki/Concepts_(C%2B%2B))

```C++

```

## Using Concepts as Interfaces


```C++
#include <iostream>
#include <array>

//Declaration of a concept like an interface
template <typename T>
concept hasIterator = requires(T container)
{
    //Any function with a '.begin()' and a '.end()' method will satisfy the 'hasIterator' requirement
    container.begin();
    container.end();
};                           //<== ENDS WITH A SEMI-COLON (it's a declaration!)


//Declare a generic print function. The only requirement is that it needs a '.begin()' and a '.end()' method
template <typename T>
requires hasIterator<T>
void print(T&& cont)   //Universal reference
{
    for(auto itr=cont.begin(); itr != cont.end(); ++itr)
    {
        std::cout << *itr << ' ';
    }
    std::cout << '\n';
}

int main()
{
   std::array<int, 3> arr {1, 2, 3};
   print(arr);

    return 0;
}
```
> Compiled with `g++ -std=gnu++0x -fconcepts file.cpp`
