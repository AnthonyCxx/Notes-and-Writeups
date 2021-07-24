# Built-in Exceptions in C++
The following exceptions are built into C++ and inherited from the [_exception class_](https://en.cppreference.com/w/cpp/error/exception). <br />
There are plenty of exceptions built into C++, but a lot of them are very specific, so I've included the most applicable here.

### _invalid\_argument_
_invalid\_arugment_ is thrown when 

### _bad\_alloc_
_bad\_alloc_ is thrown when a _new_ statement fails to allocate new memory.

```C++
#include <iostream>
using namespace std;

int main()
{
    try
    {
        //Always fails, array size is too large (~9.223 quadrillion bytes or 8 petabytes)
        int* massiveArray = new int[9223372036854775];
    }
    catch(const bad_alloc& e)  //Catch failed 'new' statement
    {
        clog << "Error: " << e.what() << '\n';
    }

    return 0;
}
```

### _out\_of\_range_
_out\_of\_range_ is thrown by some STL data structures (vectors, arrays, bitsets) when you attempt to access an element that is out of the range of the object.
Note that this does not work with the array subscript operator: _[ ]_

```C++
#include <iostream>
#include <array>
using namespace std;

int main()
{
     //An array of 100 integers
     array<int, 100> arr;
     int element;

    try
    {
        //Get the 99999th element
        element = arr.at(99998);     //Throws 'out_of_range'
        cout << "The 99999th element is: " << element << '\n';
    }
    catch (const out_of_range& e)
    {
        //Prints: 'Error: array::at: __n (which is 99998) >= _Nm (which is 100)'
        clog << "Error: " << e.what() << '\n';
    }

    return 0;
}
```

## Sources
cplusplus.com: [_\<stdexcept\>_](https://www.cplusplus.com/reference/stdexcept/) <br />
CPPReference: [_std::exception_](https://en.cppreference.com/w/cpp/error/exception) <br />
StackOverflow: [_stdexcept vs exception Headers in c++_](https://stackoverflow.com/questions/25163105/stdexcept-vs-exception-headers-in-c) <br />
StackOverflow: [_What exception classes are in the standard C++ library_](https://stackoverflow.com/questions/11938979/what-exception-classes-are-in-the-standard-c-library) <br />
StackOverflow: [_C++ Standard Library Exception List?_](https://stackoverflow.com/questions/2843820/c-standard-library-exception-list?noredirect=1&lq=1) <br />
