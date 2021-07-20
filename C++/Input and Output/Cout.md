# Output in C++ with _cout_
_cout_, which stands for 'character output' (if you don't believe me, see [this response](https://www.stroustrup.com/bs_faq2.html#cout) from the creator of C++ himself) belongs to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) 
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
    //Displays 'Hello, world!'
    cout << "Hello, world!\n";

    //Displays '5 + 5 = 10'
    cout << "5 + 5 = " << 5 + 5 << '\n';

    //Displays '5 + 5 = 10'
    int a = 5, b = 5;
    cout << a << " + " << b << " = " << a + b << '\n';

    return 0;
}
```
> Notice how I have to put spaces on both sides of `+` and `=` -- this is because C++ does not include spaces inbetween output, just like it doesn't implicitly include newlines.

## Newlines with _'\\n'_ and _endl_
You can end the current line (and start a new line) by outputting one of two choices: the [escape character](https://ciphertrick.com/c-beginners-introduction-to-escape-sequences/) _\\n_, or the object [_endl_](https://en.cppreference.com/w/cpp/io/manip/endl). Outputting _\\n_ just ends the current line, while _endl_ ends the current line
and [flushes](https://www.geeksforgeeks.org/buffer-flush-means-c/) the output stream, making it _endl_ a combination of _\\n_ and _cout.flush()_.
When people learn how to use _endl_ to end the current line, they usually use it everywhere. This is bad practice as not only is it unncessary to flush the 
buffer every time you want to start a new line, but it also reduces the efficiency that [buffered input](https://gcc.gnu.org/onlinedocs/libstdc++/manual/streambufs.html) allows for.

```C++
#include <iostream>
using namespace std;

int main()
{
    //Start a new line
    cout << "Hello, World!\n";

    //Start a new line AND flushes the output stream (cout.flush())
    cout << "Hello, world!" << endl;

    return 0;
}
```
> Here, there is no need to flush the output, so _\n_ is preferable to _endl_.

## Formatting Output with _cout.setf()_ and _cout.unsetf()_

## Unformatted Output with _cout.put()_ and _cout.write()_
The _cout_ object inherits from the [_ostream class_](https://www.cplusplus.com/reference/ostream/ostream/) and so inherits the methods from said class. The [_ostream::put()_](https://www.cplusplus.com/reference/ostream/ostream/put/)
and [_ostream::write()_](https://www.cplusplus.com/reference/ostream/ostream/write/) methods can be used to write unformatted output to the screen (ignoring any format specifiers set such as _setw()_ or _setprecision()_).
_ostream::put()_ writes a single character to the stream (like _putchar()_ in C) and _ostream::write()_ writes _n_ characters to the stream, given an array. As a rule of thumb,
use `cout <<` when you can.
```C++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Write 15 chars of the following string
    cout.write("this is a string", 15);
    cout.put('\n');    //Put a newline

    return 0;
}
```


## Sources
Programiz: [_C++ cout_](https://www.programiz.com/cpp-programming/library-function/iostream/cout) <br />
JavaTPoint: [_C++ Basic Input/Output_](https://www.javatpoint.com/cpp-basic-input-output#:~:text=Standard%20end%20line%20(endl),characters%20and%20flushes%20the%20stream.) <br />
LearnCPP.com: [_1.5 — Introduction to iostream: cout, cin, and endl_](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/) <br />
IncludeHelp.com: [_C++ Manipulators - endl, setw, setprecision, setf_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx) <br />
Educative.io: [_What is the difference between endl and \n in C++?_](https://www.educative.io/edpresso/what-is-the-difference-between-endl-and-n-in-cpp) <br />
GeeksforGeeks: [_endl vs \\n in C++_](https://www.geeksforgeeks.org/endl-vs-n-in-cpp/) <br />
GeeksforGeeks: [_What does buffer flush means in C++ ?_](https://www.geeksforgeeks.org/buffer-flush-means-c/) <br />
CPPReference: [_ios\_base: setf()_](https://en.cppreference.com/w/cpp/io/ios_base/setf) <br />
Florida State University CS Department: [_Output Stream Formatting_](https://www.cs.fsu.edu/~myers/c++/notes/formatting.html) <br />
