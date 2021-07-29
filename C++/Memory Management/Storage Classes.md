# Storage Classes in C++


## _auto_
_auto_ is C++'s equivalent of [_var_](https://www.geeksforgeeks.org/var-keyword-in-java/) in Java and C#; _auto_ leaves the datatype of a variable to be inferred by the
compiler, which prevents you from having to type out long datatypes names. Only use _auto_ where you feel that the datatype is clear, as _auto_ can greatly
reduce code readability when overused. You can see that _auto_ is replaced by the appropriate datatype by the compiler during the early stages of compilation
with [cppinsights.io](https://cppinsights.io/).

_auto_ can be used as the return type for a function and can even be used as the type for a function parameter (as of C++20). <br />
[Here](https://lesleylai.info/en/auto-parameters/)'s why you shouldn't do that. 
```C++
#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto add(T1 a, T2 b)    //Automatic return type
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
The _extern_ keyword (short for 'external') provides an alternative to _#include_, allowing you to use variables and functions declared in other files without including the
other file. The default value of an external variable is 0.

File 1
```C++
// Compile with 'g++ *.cpp' ('*' wildcard matches with all C++ source code files)
#include <iostream>
using namespace std;

extern void ascii(char);     // There is a void function that accepts a char in another file

int main()
{
    char input;

    cout << "Enter a character to find its ASCII value: ";
    cin.get(input);

    ascii(input);   //prints the ASCII value of a character

    return 0;
}
```

File 2
```C++
// The other file
#include <iostream>
using namespace std;

void ascii(char character)
{
    cout << "The ASCII value of " << character << " is " << (int) character << '\n';
}
```

## _static_
Static variables do not go out of scope, unlike local variables. Static variables can be used to maintain values even between function calls.
Static class members are shared between all instances of said class, so you could have a static data member '_count_' used to keep track of the amount
of instances of the class. To make this work, increment _count_ in the constructor and decrement it in the destructor.

The default value of a static variable is 0
```C++
#include <iostream>
using namespace std;

// Loop X number of times, keeping track of how many total times
void loop(int times)
{
    static int total;   // Default value is 0, not garbage.

    for(int i = 0; i < times; i++)
    {
        total++;
    }

    cout << "The loop has been run a total of " << total << " times\n";
}

int main()
{
    loop(3);        // Loop 3 times
    loop(5);       // Loop 5 times
    loop(12);     // Loop 12 times

    return 0;
}
```
> Prints: <br />
> The loop has been run a total of 3 times <br />
> The loop has been run a total of 8 times <br />
> The loop has been run a total of 20 times <br />

## _mutable_
Think _mut-_ as in mutation. The _mutable_ keyword allows a data member of a class or struct to be modified even if the class/struct is _const_.

```C++
#include <iostream>
using namespace std;

class ExampleClass
{
    //Public data members, for sake of ease
    public:
        int a;
        mutable int b;
        ExampleClass(int, int);
        void print() const;
};

ExampleClass::ExampleClass(int A, int B)
{
    a = A;
    b = B;
}

void ExampleClass::print() const
{
    cout << "a = " << a << ", b = " << b << '\n';
}

int main()
{
    //Declare a const ExampleClass, 'example'
    const ExampleClass example(10, 10);

    //Print 'a' and 'b'
    example.print();

    //example.a = 20;     <== Error, 'example.a' is read-only
    example.b = 20;       //Fine, because 'b' is mutable

    //Print 'a' and 'b'
    example.print();

    return 0;
}
```

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
