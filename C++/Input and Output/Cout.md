# Output in C++ with _cout_
_cout_, which stands for 'common output' (at least what I heard from college, I've also seen 'character output' and 'console output') belongs to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) 
library and writes characters to [stdout](https://en.cppreference.com/w/cpp/io/c/std_streams). _cout_ generally uses an [overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) right bit-shift
operator (<<) to write to the screen (e.g. `cout << "Hello, World!\n"`), but also has other functions like [_cout.put()_](https://en.cppreference.com/w/cpp/io/basic_ostream/put) and [_cout.write()_](https://en.cppreference.com/w/cpp/io/basic_ostream/write).  In addition to providing general I/O functions, _cout_ also provides methods like
[_setw()_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx), [_setfill()_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx) and [_setprecision()_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx) under the [\<iomanip\>](https://en.cppreference.com/w/cpp/header/iomanip) (I/O Manipulation) library,
which can be used to format output.


## Sources
Programiz: [_C++ cout_](https://www.programiz.com/cpp-programming/library-function/iostream/cout) <br />
LearnCPP.com: [_1.5 — Introduction to iostream: cout, cin, and endl_](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/) <br />
IncludeHelp.com: [_C++ Manipulators - endl, setw, setprecision, setf_](https://www.includehelp.com/cpp-tutorial/cpp-manipulators-endl-setw-setprecision-setf-cpp-programming-tutorial.aspx) <br />
