# Built-in Exceptions in C++
The following exceptions are built into C++ and inherited from the [_exception class_](https://en.cppreference.com/w/cpp/error/exception).

## _logic\_error_
The following exceptions derive from [_logic\_error_](https://en.cppreference.com/w/cpp/error/logic_error), which is used for faulty logic.

### _out\_of\_range_
_out\_of\_range_ is thrown when you attempt to access an element that is out of the range of the object. Note that this does not work with the array subscript operator: _[ ]_

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
        clog << "Error: " << e.what() << '\n';
    }

    return 0;
}
```
