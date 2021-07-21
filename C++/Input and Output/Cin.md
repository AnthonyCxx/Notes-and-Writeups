# Input in C++ with _cin_
_cin_, which stands for 'character input' belongs to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) library and is used to read characters to [stdin](http://www.cs.kent.edu/~durand/CS1/Notes/06_IO/cs1_io.html) (the keyboard). _cin_ generally uses an [overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) 
left bit-shift operator (>>) to read from the keyboard (e.g. `cin >> someVariable`), but also has other functions like [_cin.get()_](https://www.geeksforgeeks.org/cin-get-in-c-with-examples/) 
and [_cin.getline()_](https://www.includehelp.com/cpp-programs/cpp-program-to-read-string-using-cin-getline.aspx). 

Note: cin is an object within the std (standard) namespace. If you want to use it without `using namespace std`; at the top of your program, you'll have to write `std::cin` instead of just `cin` every time you use it.

## Basic Usage with the >> Operator
The >> operator is overloaded to it takes input from _cin_ and stores it in the given variable (e.g. `cin >> word`). How the data is read depends on the 
datatype of the variable the input is being stored in. If you read the input '15' into an integer, then the variable will hold the integer 15; conversely, if you read the 
input '15' into a string, then the variable will hold the string "15". If you accidentally read the input as the wrong type, you can always convert the input using 
[_stoi()_](https://en.cppreference.com/w/cpp/string/basic_string/stol) (**s**tring **to** **i**nteger), [_to\_string()_](https://www.cplusplus.com/reference/string/to_string/),
or some similar function.

Notes: <br />
An expression using `cin >>` returns \*_this_ (_cin_), so you can just write `cin >> x >> y >> z;` without having
to write cin every time.

If you have trouble keeping track of which direction the arrows go for _cout_ (<<) and _cin_ (>>), think of it this way: the arrows for _cout_ go towards _cout_, because output
goes outwards; the arrows for _cin_ point towards the variable that takes the input.

```C++
#include <iostream>
using namespace std;

int main()
{
    //Declare two integers to store the user input
    int num1, num2;

    //Get two integers from the user
    cout << "Enter two numbers to add together: ";
    cin >> num1 >> num2;    //No need for a newline character because the user confirms input by pressing enter (\n)

    //Display the result of 'num1 + num2' ("The numbers <num1> and <num2> added together is: <num1 + num2>")
    cout << "The numbers " << num1 << " and " << num2 << " added together is: " << num1 + num2 << '\n';

    return 0;
}
```

## _cin_ Methods
| Method | Description |
| ------ | ----------- |
| cin.get(char&) | reads a single character; returns 0 if the operation fails (e.g. EOF). |
| cin.ignore(streamsize, char) | ignores the next _streamsize_ characters in the stream, until it reaches _char_ delimiter |
| cin.peek() | returns the next character in the stream, but does not remove it |
| cin.putback(char) | puts back the most recently read character. _char_ **must** be the most recently read character. |
| cin.getline(char\*, int) | reads _int_ characters into _char\*_ buffer (implicitly includes \\0). Stops prematurely on reaching \\n or EOF. |
| cin.read(char\*, int) | reads _int_ characters into _char\*_ buffer (implicitly includes \\0). Stops prematurely on reaching EOF |
| cin.gcount() | counts the characters read by the last unformatted input operation (works for cin, but not peek or putback) |
|  |  |
|  |  |
|  |  |
|  |  |
> This chart is a collection of excerpts from the [public notes](https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200109/notes/io.html) from Harvey Mudd College Computer Science Department 

```C++

```
> For reading lines, you [_getline()_](https://www.geeksforgeeks.org/getline-string-c/) from the [\<string\>](https://en.cppreference.com/w/cpp/header/string) library. <br />
> Only use _cin.getline()_ for C-strings.

## Sources
GeeksforGeeks: [_cin in C++_](https://www.geeksforgeeks.org/cin-in-c/) <br />
Programiz: [_C++ cin_](https://www.programiz.com/cpp-programming/library-function/iostream/cin) <br />
GeeksforGeeks: [_cin.get() in C++ with Examples_](https://www.geeksforgeeks.org/cin-get-in-c-with-examples/) <br />
Harvey Mudd College: [_C++ File Input/Output_](https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200109/notes/io.html) <br />
