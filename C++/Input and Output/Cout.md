# Output in C++ with _cout_
_cout_, which stands for 'common output' (at least what I heard from college, I've also seen 'character output' and 'console output') belongs to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) 
library and is used to characters to [stdout](https://en.cppreference.com/w/cpp/io/c/std_streams). _cout_ generally uses an [overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) right bit-shift
operator (<<) to write to the screen (e.g. `cout << "Hello, World!\n"`), but also has other functions like [_cout.put()_](https://en.cppreference.com/w/cpp/io/basic_ostream/put) and [_cout.write()_](https://en.cppreference.com/w/cpp/io/basic_ostream/write).  In addition to general I/O functions, the [\<iomanip\>](https://en.cppreference.com/w/cpp/header/iomanip) (I/O Manipulation) library provides methods like
[_setw()_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx), [_setfill()_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx) and [_setprecision()_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx),
which can be used to format output with _cout_. 

Note: _cout_ is an object within the _std_ (standard) namespace. If you want to use it without `using namespace std;` at the top of your program, you'll have to write `std::cout`
instead of just `cout` every time you use it.

## Basic Usage with the << Operator
The << operator is overloaded such that it writes literals and expressions that evaluate to literals to the screen. An expression using `cout <<` returns _\*this_ (_cout_), 
so you can write `cout << "this " << "is " << "acceptable.\n";` and not have to write _cout_ every time. 

C++ does not have [string interpolation](https://www.programiz.com/python-programming/string-interpolation) (formatted strings), so you have to chain _cout_ with _<<_
in order to achieve the same effect. Technically, C++20 did introduce the [format()](https://en.cppreference.com/w/cpp/utility/format/format) function, but if you don't 
understand move semantics and forwarding, then you should stick with C++11 until you do.
```C++
#include <iostream>
using namespace std;

int main()
{
    // Displays 'Hello, world!'
    cout << "Hello, world!\n";

    // Displays '5 + 5 = 10'
    cout << "5 + 5 = " << 5 + 5 << '\n';

    // Displays '5 + 5 = 10'
    int a = 5, b = 5;
    cout << a << " + " << b << " = " << a + b << '\n';

    return 0;
}
```
> Notice how I have to put spaces on both sides of `+` and `=` -- this is because C++ does not include spaces inbetween output, just like it doesn't implicitly include newlines.

## Newlines with _'\\n'_ and _endl_
When people learn how to use _endl_ to end the current line, they usually use it _everywhere_. This is wrong, so don't do it. 

```C++

```

## Sources
Programiz: [_C++ cout_](https://www.programiz.com/cpp-programming/library-function/iostream/cout) <br />
LearnCPP.com: [_1.5 — Introduction to iostream: cout, cin, and endl_](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/) <br />
IncludeHelp.com: [_C++ Manipulators - endl, setw, setprecision, setf_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx) <br />
Educative.io: [_What is the difference between endl and \n in C++?_](https://www.educative.io/edpresso/what-is-the-difference-between-endl-and-n-in-cpp) <br />
GeeksforGeeks: [_endl vs \\n in C++_](https://www.geeksforgeeks.org/endl-vs-n-in-cpp/) <br />
GeeksforGeeks: [_What does buffer flush means in C++ ?_](https://www.geeksforgeeks.org/buffer-flush-means-c/) <br />
