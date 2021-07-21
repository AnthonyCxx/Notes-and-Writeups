# Errors in C++ with _cerr_ and _clog_
_clog_ and _cerr_, which stand for 'character log' and 'character error' respectively, belong to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) 
library and are used to write characters to [stderr](http://www.cs.kent.edu/~durand/CS1/Notes/06_IO/cs1_io.html) (the screen). _clog_ and _cerr_ generally use an
[overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) right bit-shift operator (<<) to write to the screen <br />
(e.g. `cerr << "Fatal error: the file could not be opened or does not exist"`), but also has other functions like 

[_()_](https://www.geeksforgeeks.org/cin-get-in-c-with-examples/) and [_()_](https://www.includehelp.com/cpp-programs/cpp-program-to-read-string-using-cin-getline.aspx). 

Note:  is an object within the std (standard) namespace. If you want to use it without `using namespace std;` at the top of your program, you'll have to write `std::cin` instead of just `cin` every time you use it.


## Sources
IBM Documentation: [_Using C and C++ standard streams and redirection_](https://www.ibm.com/docs/en/zos/2.1.0?topic=output-using-c-c-standard-streams-redirection) <br />
StudyMite: [_cerr and clog in C++_](https://www.studymite.com/cpp/cerr-and-clog-in-cpp/) <br />
: [__]() <br />
: [__]() <br />
: [__]() <br />
: [__]() <br />
