# Input/Output Manipulation (Formatting) in C++
The [\<iomanip\>](https://en.cppreference.com/w/cpp/header/iomanip) library contains a variety of functions called [_manipulators_](https://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/) that aren't displayed like normal input/output, but instead change the way the input/output 
appears/functions. An example of a manipulator is the [_scientific_](https://en.cppreference.com/w/cpp/io/manip/fixed) manipulator, which displays the next float in 
[scientific notation](https://www.chem.tamu.edu/class/fyp/mathrev/mr-scnot.html). The line `cout << scientific << 127.14315;` would display the number 127.14315
as 1.271432e+02.

### boolalpha/noboolalpha
By default, booleans are represented in streams as 1's and 0's (true and false). If you want `cout << true` to output the string "true", then toggle _boolalpha_ 
(boolean -> alphabetic).
```C++
//Displays '1'
cout << true << '\n';

//Displays 'true'
cout << boolalpha << true << '\n';

//Displays '1'
cout << noboolalpha << true << '\n';

// Program 2 //
bool input;

cout << "Enter true or false: ";
cin >> boolalpha >> input;

//bool 'input' is 'true' if the user enters 'true' verbatim (all lowercase)
cout << "You entered: " << (input ? "True" : "False") << '\n';
```

### showpos/noshowpos
_showpos_ displays a _+_ sign in front of positive numbers, helping align positive and negative numbers as well as making them more explicit.

```C++
//Toggles showpos, showing a '+' for all numbers until noshowpos is used
cout << showpos;

//Prints -5 - 5, aligned because of the '+' sign
for(int i = -5; i < 6; i++)
{
  cout << i << '\n';
}
```

### showpoint/noshowpoint
Displays the mantissa (the stuff after the decimal point), even if a float does not have numbers there. For example, the float '15' would be '15.0000'.
By default, _showpoint_ shows 4 decimal places, but this can be modified by _setprecision()_.

```C++
int integer = 10;
float f = 15;
float f2 = 20.25;

//Prints: 'BEFORE showpoint: integer = 10, f = 15, f2 = 20.25'
cout << "BEFORE showpoint: integer = " << integer << ", f = " << f << ", f2 = " << f2 << endl;

cout << showpoint;

//Prints: 'AFTER showpoint: integer = 10, f = 15.0000, f2 = 20.2500'
cout << "AFTER showpoint: integer = " << integer << ", f = " << f << ", f2 = " << f2 << endl;
```

### fixed/scientific/hexfloat/defaultfloat
"When floatfield is set to fixed, floating-point values are written using fixed-point notation: the value is represented with exactly as many digits in the 
decimal part as specified by the precision field (precision) and with no exponent part." -[std::fixed, cplusplus.com](https://www.cplusplus.com/reference/ios/fixed/).

```C++

```

### dec/hex/oct


```C++

```

### showbase/noshowbase


```C++

```

### uppercase/nouppercase


```C++

```

### internal/left/right


```C++

```

### unitbuf/nounitbuf


```C++

```

## Sources
CPPReference: [_Standard library header <iomanip>_](https://en.cppreference.com/w/cpp/header/iomanip) <br />
CPPReference: [_Input/output manipulators_](https://en.cppreference.com/w/cpp/io/manip) <br />
CPlusPlus.com: [_\<iomanip\>_](https://www.cplusplus.com/reference/iomanip/) <br />
CPlusPlus.com: [_std::ostream::operator<<_](https://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/) <br />
Microsoft C++ Documentation: [_\<iomanip\> functions_](https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-160) <br />
TutorialsPoint: [_C++ Library - \<iomanip\>_](https://www.tutorialspoint.com/cpp_standard_library/iomanip.htm) <br />
GeeksforGeekss: [_std::fixed, std::scientific, std::hexfloat, std::defaultfloat in C++_](https://www.geeksforgeeks.org/stdfixed-stdscientific-stdhexfloat-stddefaultfloat-c/) <br />
