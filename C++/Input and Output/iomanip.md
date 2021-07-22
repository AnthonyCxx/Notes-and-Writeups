# Input/Output Manipulation (Formatting) in C++
The [\<iomanip\>](https://en.cppreference.com/w/cpp/header/iomanip) library contains a variety of functions called [_manipulators_](https://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/) that aren't displayed like normal input/output, but instead change the way the input/output 
appears/functions. An example of a manipulator is the [_scientific_](https://en.cppreference.com/w/cpp/io/manip/fixed) manipulator, which displays the next float in 
[scientific notation](https://www.chem.tamu.edu/class/fyp/mathrev/mr-scnot.html). The line `cout << scientific << 127.14315;` would display the number 127.14315
as 1.271432e+02. A fair amount of these flags/manipulators can be used with both input and output, so feel free to mess around. If you want to read hexadecimal input
from a file, you can use the _hex_ flag.

This is not a comprehensive list of manipulators.

## Manipulators

### setw()
_setw()_, which is short of 'set width', sets the minimum length of the output. If the output is less than the the given number, the output will be padded to 
meet the width. _setw()_ takes a single integer as a parameter, which is the minimum width. A minimum width of 5 is 5 characters in length.
Unlike most flags and manipulators, _setw()_ does NOT persist between output, only affecting the next bit out output (ignoring other manipulators).

While doing some testing, I found that _setw()_ does count escape sequences when counting the minimum width.
```C++
//'Hello, World!' is 14 characters long, so it's padded by 6
cout << setw(20) << "Hello, world!\n";    // <== '\n' is counted by 'setw()'

//Not padded -- 'setw()' does not persist between calls
cout << "Hello, World!\n";
```

### setfill()
_setfill()_ takes a single character that can be used to change what _setw()_ pads with. By default, this character is a space.

```C++
cout << setfill('.');

//Displays '......Hello, world!'
cout << setw(20) << "Hello, world!\n";    

//Displays 'Hello, World!'
cout << "Hello, World!\n";
```

### setprecision()
_setprecision()_ can be used to change the amount of decimal places shown by a float. _setprecision()_ will only work if the [_fixed_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/iomanip.md#fixedscientifichexfloatdefaultfloat)
flag is set.

```C++
const double PI = 3.14159265;
cout << setprecision(7);

//Displays '3.141593' (mantissa = 6)
cout << PI << '\n';

//Set the 'fixed' flag
cout << fixed;

//Displays '3.1415927' (mantissa = 7)
cout << PI << '\n';
```

## Flags
Flags are toggleable manipulators; once enabled, the flag will continue to manipulate all input/output until restored to the default. <br />
Some flags do not have a '_no_' counterpart (like _boolalpha_ and _noboolalpha_), this is because the state of this flag is not a single concept
that is or is not (like a boolean), but instead one of a set of values. For example, the default for _dec_/_hex_/_oct_ is _dec_ ([decimal](https://www.tutorialspoint.com/decimal-number-system),
the base-10 system we use); the decimal system is in contrast with but not the opposite of the hexadecimal and octal systems. Opposites do not exist for concepts
with more than one counterpart.

### boolalpha/noboolalpha
By default, booleans are represented in streams as 1's and 0's (true and false). If you want `cout << true` to output the string "true", then toggle _boolalpha_ 
(boolean -> alphabetic). This approach is preferable to writing `(<bool> ? "true" : "false")` every single time.
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

//bool 'input' is 'true' if and only if the user enters 'true' verbatim (all lowercase)
cout << "You entered: " << (input ? "True" : "False") << '\n';
```

### showpos/noshowpos
_showpos_ displays a _+_ sign in front of positive numbers, helping align positive and negative numbers as well as making them more explicit.

```C++
//Toggles showpos, showing a '+' for all numbers until noshowpos is used
cout << showpos;

//Prints -5 through 5, aligned because of the '+' sign
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
decimal part as specified by the _precision_ field and with no exponent part."

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
cout.precision(5);   //Normally, just use 'cout << setprecision(5)'

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
_dec_, _hex_, and _oct_ change the [radix](https://en.wikipedia.org/wiki/Radix) (base) of the numbers used for that stream to decimal, hexadecimal, or octal.

```C++
//Declare an int to catch input and set 'cin' to read numbers as hexadecimal
int input;
cin >> hex;

//Get a number from the user (user input: '0x1f')
cout << "Enter a number: ";
cin >> input;

/*
  You really don't need 'dec' here as it is the default setting
  and it has not been altered earlier (cin and cout are independent),
  but I felt making it more explicit would help :)
*/

//User input '0x1f' is equal to '31' in decimal
cout << dec << "You entered: " << input << '\n';
cout << "The number 20 in octal is: " << oct << 20 << '\n'  //'20' is '24' in octal
```

### showbase/noshowbase
_showbase_ is a modifier for _hex_ and _oct_ that shows the radix indicator for hexadecimal and octal numbers.

```C++
//Show radix indicator for hex. and octal numbers
    cout << showbase;

    cout << hex << 20 << '\n';    //0x14
    cout << oct << 20 << '\n';   //024
```

### uppercase/nouppercase
_uppercose_ is a modifier for _hex_ and _showbase_ that outputs hexadecimal letters (A-F) and the hex. radix indicator (0X) in uppercase.

```C++
//Show radix indicator for hexadecimal numbers in uppercase
cout << showbase << uppercase;

cout << hex << 28 << '\n';    //0X1C
```

### left/right/internal
_left_, _right_, and _internal_ change the alignment (justification) of the text.

#### _left_
_left_ aligns the text to the left, padding the text to the right.

#### _right_
_right_ aligns the text to the right, padding the text to the left.

#### _internal_
_internal_ pads the text inbetween the number and its modifiers. <br />
A hexadecimal number 0x1B may be padded like '0x#1B' in order to reach 5 characters.

```C++
//'setw(5)' makes the width of every output 5 characters
cout << setfill('#');

//Displays -50##
cout << left << setw(5) << -50 << '\n';

//Displays ##-50
cout << right << setw(5) << -50 << '\n';

//Displays -##50
cout << internal << setw(5) << -50 << '\n';
```

### unitbuf/nounitbuf
Streams such as _cout_ are [buffered](http://www.cplusplus.com/forum/beginner/192071/), meaning that just because you write `cout << "Hello, World!"`
doesn't mean that the program immediately writes 'Hello, World!' to the screen. _cout_ waits until it gets more input because it's more efficient to write one time
with larger input than to write a number of separate times with smaller input. Buffering can be manually disabled with the _nounitbuf_ flags and re-enabled with the
_unitbuf_ flag.

```C++
//Buffering disabled
cout << nounitbuf;
cout << "Hello, world!\n";

//Buffering re-enabled (default setting)
cout << unitbuf;
cout << "Hello, world!\n";
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
