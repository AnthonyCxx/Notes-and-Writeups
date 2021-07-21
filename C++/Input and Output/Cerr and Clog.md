# Errors in C++ with _cerr_ and _clog_
_clog_ and _cerr_, which stand for 'character log' and 'character error' respectively, belong to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) 
library and are used to write characters to [stderr](http://www.cs.kent.edu/~durand/CS1/Notes/06_IO/cs1_io.html) (the screen). _clog_ and _cerr_ generally use an
[overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) right bit-shift operator (<<) to write to the screen <br />
(e.g. `cerr << "Fatal error: the file could not be opened or does not exist";`). Both _clog_ and _cerr_ inherit from the 
[_std::ostream_](https://www.cplusplus.com/reference/ostream/ostream/) class, so they inherit methods like [_.flush()_](https://www.cplusplus.com/reference/ostream/ostream/flush/)
and [_.fill()_](https://www.cplusplus.com/reference/ios/ios/fill/).

Note: _clog_ and _cerr_ are objects within the std (standard) namespace. If you want to use them without `using namespace std;` at the top of your program, you'll have to write `std::cerr` instead of just `cerr` every time you use them.


## Sources
IBM Documentation: [_Using C and C++ standard streams and redirection_](https://www.ibm.com/docs/en/zos/2.1.0?topic=output-using-c-c-standard-streams-redirection) <br />
CPlusPlus: [_std::ostream_](https://www.cplusplus.com/reference/ostream/ostream/) <br />
StudyMite: [_cerr and clog in C++_](https://www.studymite.com/cpp/cerr-and-clog-in-cpp/) <br />
: [__]() <br />
: [__]() <br />
: [__]() <br />
