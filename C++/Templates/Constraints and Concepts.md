# Selection with _std::enable\_if_ and _concept_
> **NOTE**: As of 10/27/2021, compiler support for concepts is still in progress. To use concepts with GCC, you must compile with C++20 and allow concepts with the 
> -fconcepts option like `g++ -std=c++2x -fconcepts file.cpp`

## Preventing Template Instantiation with _std::enable\_if_
> Eli Bendersky's website: [_SFINAE and enable_if_](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/) <br />
> cppreference: [_std::enable\_if_](https://en.cppreference.com/w/cpp/types/enable_if) <br />

_std::enable\_if\<condition\>_ is a function evaluated at compile-time that can be used to restrict templates to being of certain types (like [_static\_assert_](https://en.cppreference.com/w/cpp/language/static_assert), but without the forced error); moreover, it can be used to include or exclude considering certain template overloads when substituting types. Here, the function _add()_ is not considered for non-trivial types (as if it did not even exist). If no type is provided, it assumes and returns _void_.

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

The following example places a _requires_ constraint on the function _printStats_, forcing all passed types to be of or derived from the 'Animal' class. It is necessary
to use [_std::decay\<\>_](https://en.cppreference.com/w/cpp/types/decay) when comparing datatypes because [cv-qualifiers](https://en.cppreference.com/w/cpp/language/cv) (like
`const` and `volatile`) and [references](https://www.tutorialspoint.com/cplusplus/cpp_references.htm) (like `int&` and `int&&`) are can change the "type" of a variable.
If you passed `Animal&&` to the function _printStats_, then `std::is_same<Animal,T>` would return false, since `Animal` and `Animal&&` are not the same datatype. Unless you are 
trying to differentiate between cq-qualified and reference templates, it is often the case that you should discard both cv-qualifiers and references when comparing types.

```C++
#include <iostream>
#include <cstdint>    //Contains fixed-width integers (8-bit integers)
#include <string>
#include <type_traits>  //For evaluating types

//Class 'Animal' stores the name, age, and genus of an animal
struct Animal
{
    //Data members
    std::string m_name;       //Name of the animal
    std::string m_genus;     //Genus of the animal
    std::uint8_t m_age;      //8-bit fixed-width integer for the age (max value: 256)

    //Constructor
    Animal(std::string name, std::string genus, std::uint8_t age): m_name(name), m_genus(genus), m_age(age)
    {

    }
};

//Class 'Dog' inherits from 'Animal'
struct Dog: public Animal
{
    //Singular constructor to pass on the values
    Dog(std::string name, std::string genus, std::uint8_t age): Animal(name, genus, age)
    {

    }
};


//Function 'printStats' REQUIRES that the variable passed be 'Animal' or derived from it
template <typename T>
requires std::is_same_v<Animal, std::decay_t<T>> || std::is_base_of_v<Animal, std::decay_t<T>>
void printStats(T&& animal)
{
    std::cout << "Name: " << animal.m_name << '\n';
    std::cout << "Age: " << (int) animal.m_age << '\n';  //Convert char to int
    std::cout << "Genus: " << animal.m_genus << '\n';
}

int main()
{
    Dog dexter("Dexter", "Shiba Inu", 240);
    printStats(dexter);

    return 0;
}
```
> The calls to _std::decay\_t_ are necessary because if 'T' is cv-qualified (const or volitile) or a reference, then both checks will return _false_.

## Concepts
Think of concepts as a _typedef_ for a _requires_ statement — they're a succint way to refer to a more complex/verbose set of constraints. If you're going to be writing
the same set of contraints over and over again, then you might as well make them a concept so you don't have to write ad nauseam (and risk making a mistake). After all,
all these constraints are evaluated at compile time and don't affect the actual program, so might as well.

```C++
template <typename T>
concept isAnimal = requires
{
    std::is_same_v<Animal, std::decay_t<T>> || std::is_base_of_v<Animal, std::decay_t<T>>;
};

//Function 'printStats' REQUIRES that the variable passed be 'Animal' or derived from it
template <typename T>
requires isAnimal<T>
void printStats(T&& animal)
{
    std::cout << "Name: " << animal.m_name << '\n';
    std::cout << "Age: " << (int) animal.m_age << '\n';
    std::cout << "Genus: " << animal.m_genus << '\n';
}
```
> Compiled with `g++ -std=gnu++0x -fconcepts file.cpp`

## Using Concepts as Interfaces
Concepts can require that a datatype have certain methods, which is essentially an [interface](https://kindsonthegenius.com/blog/what-are-interfaces-in-c-and-java-a-simple-explanation/) from C# or Java. Using a concept in this way allows you to write a generic function that works with everything that meets a set of user-defined constraints.
Here, the print function requires that its parameter have both a `.begin()` and `.end()` method, since it's required to iterate over the loop (note: this is an arbitrary 
constraint — I could just as easily have used a raw for-loop and just passed the size of the container). If a type fails to meet the constraints, then a compile-time error
will be thrown that will say something like `constraints not satisfied | void print(T&& cont)`.

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
