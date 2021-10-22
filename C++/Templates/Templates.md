# Templates (Generics) in C++
> Video: CPPCon 2014, [_Scott Meyers: "Type Deduction and Why You Care"_](https://www.youtube.com/watch?v=wQxj20X-tIU) <br />
> Blog post: [C++ TUTORIAL - TEMPLATES - 2020](https://www.bogotobogo.com/cplusplus/templates.php#TemplateSpecialization) <br />

## Default Arguments for Templates
As of C++17, you can provide a default datatype for templates. That way, you can write a templated function/class and only write out the datatype in angled brackets
if you're working with different datatypes. Just like default parameters, you write a default template parameter as `template <typename T = int>`.

Here's the same _Array_ class you just used above, but with a default type of _int_.

```C++
//Compiles with C++17 and above: 'g++ -std=c++17 file.cpp'
#include <iostream>
#include <iomanip>
using namespace std;

// ARRAY CLASS //
template <typename T = int>   //Default datatype is now 'int'
class Array
{
    private:
        //Data members
        T* array;     //Array Pointer
        size_t size;

    public:
        //Functions
        Array(const size_t);
        ~Array();
        void fill(const T);
        void print() const;

        //Overloaded Operators
        T& operator[](int) const;
};

//Constructor
template <typename T>
Array<T>::Array(const size_t Size)
{
    size = Size;
    array = new T[size];
}

//Destructor
template <typename T>
Array<T>::~Array()
{
    //Free the array
    delete [] array;
}

//Fill: initialize the array
template <typename T>
void Array<T>::fill(const T value)
{
    for(int i=0; i < size; i++)
    {
        array[i] = value;
    }
}

//Print: print the array
template <typename T>
void Array<T>::print() const
{
    for(int i=0; i < size; i++)
    {
        //Print comma-separated indices
        cout << array[i] << (i != size-1 ? ", " : "");
    }
    cout << '\n';
}

//[] Overload: element access
template <typename T>
T& Array<T>::operator[](int index) const  //Return array index by reference so you can assign (and alter) it
{
    return array[index];
}


// DRIVER CODE //
int main()
{
    //An array of 10 ints
    Array arr(10);   //No <int> suffix
    arr.fill(7);
    arr.print();

    return 0;
}
```

## Template Specialization
Instances of a specific class/function will be created from a template if an instance of it does not already exist. Because the compiler will not overwrite manually-created
versions of a template for specific datatypes, we can overload the same templated method to work differently for different types. Here, I have a generic '_add()_' function
that has a special case for strings that includes a space between each of the strings instead of just appending one to the other.

```C++
#include <iostream>
#include <string>
using namespace std;

//Generic add function
template <typename T>
T add(T a, T b)
{
    return a + b;
}

//Template specialization: 'string' version includes and extra space
template <>
string add(string a, string b)
{
    return a + " " + b;
}

//Main function
int main()
{
    //Different usages of templated 'add' function: standard and specialized
    cout << add<int>(10, 20) << '\n';                    //30
    cout << add<string>("this and", "that") << '\n';    //'this and that'

    return 0;
}
```

## Template Type-guarding with _std::enable\_if_
Templates can be specialized such that they can only be used for certain types, making them safer. For example, if I wrote a function _divide()_, I would want it to work
with all numeric types ([_std::is\_arithmetic()_](https://en.cppreference.com/w/cpp/types/is_arithmetic)), but not string literals. To

## Sources
CPPCon 2014: [_Scott Meyers: "Type Deduction and Why You Care"_](https://www.youtube.com/watch?v=wQxj20X-tIU) <br />
isocpp.org: [_Templates_](https://isocpp.org/wiki/faq/templates) <br />
IBM C++ Documentation: [_Templates (C++ only)_](https://www.ibm.com/docs/en/i/7.4?topic=reference-templates-c-only) <br />
GeeksforGeeks: [_Templates in C++_](https://www.geeksforgeeks.org/templates-cpp/) <br />
Programiz: [_C++ Templates_](https://www.programiz.com/cpp-programming/templates) <br />
TheCherno: [_Templates in C++_](https://www.youtube.com/watch?v=I-hZkUa9mIs) <br />
IBM C++ Documentation: [_Default arguments for template parameters (C++ only)_](https://www.ibm.com/docs/en/zos/2.1.0?topic=parameters-default-arguments-template) <br />
StackOverflow: [_Template default arguments_](https://stackoverflow.com/questions/15373823/template-default-arguments) <br />
[C++ TUTORIAL - TEMPLATE SPECIALIZATION - 2020](https://www.bogotobogo.com/cplusplus/template_specialization_function_class.php) <br />
