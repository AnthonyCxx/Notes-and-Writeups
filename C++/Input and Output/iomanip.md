# Input/Output Manipulation (Formatting) in C++
The [\<iomanip\>](https://en.cppreference.com/w/cpp/header/iomanip) library contains a variety of functions called [_manipulators_](https://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/) that aren't displayed like normal input/output, but instead change the way the input/output 
appears/functions. An example of a manipulator is the [_scientific_](https://en.cppreference.com/w/cpp/io/manip/fixed) manipulator, which displays the next float in 
[scientific notation](https://www.chem.tamu.edu/class/fyp/mathrev/mr-scnot.html). The line `cout << scientific << 127.14315;` would display the number 127.14315
as 1.271432e+02.

### boolalpha/noboolalpha
By default, booleans are represented in streams as 1's and 0's (true and false). If you want `cout << true` to output the string "true", then toggle _boolalpha_ 
(boolean -> alphabetic)
```C++
//Displays '1'
cout << true << '\n';

//Displays 'true'
cout << boolalpha << true << '\n';

//Displays '1'
cout << noboolalpha << true << '\n';
```
  

## Sources
CPPReference: [_Standard library header <iomanip>_](https://en.cppreference.com/w/cpp/header/iomanip) <br />
CPPReference: [_Input/output manipulators_](https://en.cppreference.com/w/cpp/io/manip) <br />
CPlusPlus.com: [_\<iomanip\>_](https://www.cplusplus.com/reference/iomanip/) <br />
CPlusPlus.com: [_std::ostream::operator<<_](https://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/) <br />
Microsoft C++ Documentation: [_\<iomanip\> functions_](https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-160) <br />
TutorialsPoint: [_C++ Library - \<iomanip\>_](https://www.tutorialspoint.com/cpp_standard_library/iomanip.htm) <br />
