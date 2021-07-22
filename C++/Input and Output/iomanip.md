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
_fixed_, _scientific_, _hexfloat_, and _defaultfloat_ are for different representations for floats. 
These representations are mutually exclusive and will override the previous representation.

All definitions are from [cplusplus.com: \<ios\>](https://www.cplusplus.com/reference/ios/).

#### fixed
"When floatfield is set to fixed, floating-point values are written using fixed-point notation: the value is represented with exactly as many digits in the 
decimal part as specified by the _precision_ field and with no exponent part." -[std::fixed, cplusplus.com](https://www.cplusplus.com/reference/ios/).

#### scientific
"When floatfield is set to scientific, floating-point values are written using [scientific notation](https://www.chem.tamu.edu/class/fyp/mathrev/mr-scnot.html): 
the value is represented always with only one digit before the decimal point, followed by the decimal point and as many decimal digits as the precision field (precision).
Finally, this notation always includes an exponential part consisting on the letter e followed by an optional sign and three exponential digits."

#### hexfloat
"When floatfield is set to hexfloat, floating-point values are written using [hexadecimal format](https://www.tutorialspoint.com/hexadecimal-number-system)."

#### defaultfloat
"When floatfield is set to defaultfloat, floating-point values are written using the default notation: the representation uses as many meaningful digits as 
needed up to the stream's decimal precision (precision), counting both the digits before and after the decimal point (if any)."

```C++
cout.precision(5);   //Normally, just use 'setprecision(5)'

//All floats will be represented with 5 decimal places
cout << fixed << 159743.124125135 << '\n';   //159743.12413

//All floats will be represented in scientific notation if they can (overwriting 'fixed')
cout << scientific << 159743.124125135 << '\n';   //1.59743e+05

//All floats will be represented in hexfloat (overwriting 'scientific')
cout << hexfloat << 159743.124125135 << '\n';   //0x1.37ff8fe35519bp+17

//Reset float format to normal representation (overwriting 'hexfloat')
cout << defaultfloat << 15.12 << '\n';   //15.12
```
> 159743.12413
1.59743e+05
0x1.37ff8fe35519bp+17
15.12


### dec/hex/oct
_dec_, _hex_, and _oct_ change the [radix](https://en.wikipedia.org/wiki/Radix) (base) of the numbers used for that stream

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
GeeksforGeeks: [_std::oct, std::dec, and std::hex in C++_](https://www.geeksforgeeks.org/stdoct-stddec-and-stdhex-in-cpp/) <br />
