# Anatomy of a C++ Program
Here is an analysis of a simple C++ program. For reference, C++ source code files should end with the _.cpp_ extension.

```C++
#include <iostream>
using namespace std;

int main()
{
    // This is a comment

    /*
        This is a multi-line comment
    */

    cout << "Hello, world!" << endl;

    return 0;
}
```

## The _main()_ function
A function is a block of code that performs an action. The _main()_ function is where every C++ program starts. <br />
Naturally, this means there can only be one _main()_ function and the name _main()_ must be written verbatim. 

## Return 0
The line _return 0_ returns the error code 0 to the system that ran the program, indicating that there was no error.

## Comments
The lines `// This is a comment` and `/* This is a multi-line comment` are comments, lines in the source code that will be ignored by 
[the compiler](https://www.freecodecamp.org/news/c-compiler-explained-what-is-the-compiler-and-how-do-you-use-it/). Comments allow you to 
document your code, making it more legible and leaving notes for anyone else that will read it. 
