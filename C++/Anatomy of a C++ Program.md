# Anatomy of a C++ Program
> Reference: [_C++ Basic Syntax_](tutorialspoint.com/cplusplus/cpp_basic_syntax.htm) <br />

Here is an analysis of a simple C++ program. For reference, C++ source code files should end with the _.cpp_ extension. 
If you are using g++ from the Gnu Compiler Collection, then you can compile your code with the command `g++ file.cpp` where _file_ is the name of the file.
If you are compiling multiple files, just add the extra files after _file.cpp_ (the order doesn't matter).

```C++
#include <iostream>
using namespace std;

int main()
{
    /*
        This is a 
        multi-line comment
    */

    // Writes 'Hello, World!' to the screen
    cout << "Hello, world!" << endl;

    return 0;
}
```

## The _main()_ function
A function is a block of code that performs an action. The _main()_ function is where every C++ program starts. <br />
Naturally, this means there can only be one _main()_ function and the name _main()_ must be written verbatim. 

```C++
int main()
{

}
```

## _return 0;_
The line _return 0_ returns the error code 0 to the system that ran the program, indicating that there was no error. _return 0_ must always be the last line of the program,
since returning from the main function will automatically end the program.

```C++
int main()
{

    return 0;
}
```

## Comments
The lines `// Writes 'Hello, World!' to the screen` and `/* This is a multi-line comment */` are comments, lines in the source code that will be ignored by 
[the compiler](https://www.freecodecamp.org/news/c-compiler-explained-what-is-the-compiler-and-how-do-you-use-it/). Comments allow you to 
document your code, making it more legible and leaving notes for anyone else that will read it. 

```C++
int main()
{
     // This is a comment

    /*
        This is a 
        multi-line comment
    */

    return 0;
}
```

## _#include \<iostream\>_
_#include \<iostream\>_ includes a header file that contains the funtions needed for input and output.


```C++
#include <iostream>

int main()
{
     // This is a comment

    /*
        This is a 
        multi-line comment
    */

    return 0;
}
```

## _cout << "Hello, world!" << endl;_
This line outputs the string "_Hello, World!_" onto the screen and begins a new line (_cout_ = character output; _endl_ = endline).

```C++
#include <iostream>

int main()
{
     // This is a comment

    /*
        This is a 
        multi-line comment
    */

    cout << "Hello, world!" << endl;
    
    return 0;
}
```


## _using namespace std;_
All C++ objects belong to the _std_ (standard) namespace. This means that if you don't write `using namespace std;`, then you'll have to prefix _cout_ or _endl_ with 
_std::_ every time you use them. If you're taking a college course, you'll likely be told to use `using namespace std;` in all circumstances; however, in real life, virtually
no one uses it because of the problems they introduce ([src](https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/): scroll down to "problems with _using_ directives").

```C++
#include <iostream>
using namespace std;

int main()
{
    // This is a comment

    /*
        This is a 
        multi-line comment
    */

    cout << "Hello, world!" << endl;

    return 0;
}
```
