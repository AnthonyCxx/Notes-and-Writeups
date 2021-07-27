# Outputting Errors in C++ with _cerr_ and _clog_
_clog_ and _cerr_, which stand for 'character log' and 'character error' respectively, belong to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) 
library and are used to write characters to [stderr](http://www.cs.kent.edu/~durand/CS1/Notes/06_IO/cs1_io.html) (the screen). _clog_ and _cerr_ generally use an
[overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) right bit-shift operator (<<) to write to the screen <br />
(e.g. `cerr << "Fatal error: the file could not be opened or does not exist";`). Both _clog_ and _cerr_ inherit from the 
[_std::ostream_](https://www.cplusplus.com/reference/ostream/ostream/) class, so they inherit methods like [_.flush()_](https://www.cplusplus.com/reference/ostream/ostream/flush/)
and [_.fill()_](https://www.cplusplus.com/reference/ios/ios/fill/).

Note: _clog_ and _cerr_ are objects within the std (standard) namespace. If you want to use them without `using namespace std;` at the top of your program, you'll have to write `std::clog/cerr` instead of just `clog/cerr` every time you use them.

## _cerr_ vs _clog_
_cerr_ and _clog_ are both associated with the [stderr](https://www.ibm.com/docs/en/zos/2.2.0?topic=output-using-c-c-standard-streams-redirection) (standard error) stream
and perform the same function. The only difference between _cerr_ and _clog_ is that _clog_ is buffered and _cerr_ is not. All this means
is that when you perform an I/O operation with _clog_ (like `clog << "An error has occured'`), it may not write to the screen immediately; typically, buffered streams
(like _cout_ and _clog_) wait until the output reaches a certain length before writing to the screen — this is to increase efficiency, as I/O operations tend to be rather slow.
_cerr_ on the other hand is unbuffered, so every time you write to _cerr_, it immediately writes to the screen. Because of this, _cerr_ is often reserved for fatal errors
(i.e. ones that crash the system) as buffering the output may prevent it from being written entirely. In essence, use _clog_ for general errors, and reserve _cerr_ for
errors that would crash/abnormally terminate the program.

## Basic Usage with the << Operator
The << operator is overloaded such that it writes literals and expressions that evaluate to literals to the screen. An expression using <br /> `clog/cerr <<` returns 
\*this (_clog_/_cerr_), so you can write `clog/cerr << "this " << "is " << "acceptable.\n";` and not have to write _clog_/_cerr_ every time.

```C++
#include <iostream>
#include <fstream>       //Contains 'ifstream' datatype
#include <cstdlib>      //Contains 'exit()'
using namespace std;

int main()
{
    //Declare a read-only file 'file'
    ifstream file;

    //Open a file 'thisFileDoesNotExist.txt' in read mode
    file.open("thisFileDoesNotExist.txt");

    //Verify that the file is valid
    if (!file)   // 'file' evals to false if invalid
    {
        clog << "Fatal error: file could not be opened or does not exist...\n";
        exit(1);  //Exit with status code 1
    }

    return 0;
}
```
> The 'ifstream' datatype has an overloaded 'bool' operator such that it evaluates to false if the file is invalid <br />
> (does not exist or cannot be opened)

## Sources
IBM Documentation: [_Using C and C++ standard streams and redirection_](https://www.ibm.com/docs/en/zos/2.1.0?topic=output-using-c-c-standard-streams-redirection) <br />
CPlusPlus: [_std::ostream_](https://www.cplusplus.com/reference/ostream/ostream/) <br />
CPlusPlus: [_cout, cerr, and clog_](http://www.cplusplus.com/forum/beginner/108474/) <br />
StudyMite: [_cerr and clog in C++_](https://www.studymite.com/cpp/cerr-and-clog-in-cpp/) <br />
Medium: [_Cerr — Error Stream Object in C++_](https://medium.com/swlh/cerr-error-stream-object-in-c-9d62d564e72c) <br />
