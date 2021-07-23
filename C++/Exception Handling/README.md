# Exception Handling in C++
Exceptions are errors that occur during runtime, like a failure to allocate heap memory because there wasn't enough memory left ([_bad\_alloc_](https://www.cplusplus.com/reference/new/bad_alloc/)); exceptions can be managed through a process called _exception handling_. Exception handling allows you to deal
with errors in a way that allows the program to continue running seamlessly (hopefully). Sometimes, an exception cannot be truly 'recovered' from, but can only be dealt with,
in which case exception handing allows a graceful solution to be achieved.

Exception handling is preferable to only error checking (C-style error handling) as exception handling is distinct from the rest of the code and cannot be confused with
standard control flow; moreover, exception handling does not require the programmer to 

```C++
// PROGRAM 1 //

//Declare three floats to perform division
float numerator, denominator, result;

//Get the numerator and denominator
cin >> numerator >> denominator;

//Divide numerator by denominator
if (denominator != 0)
  result = numerator / denominator;
else
  result = 0;

//Print the result
cout << "Result: " << result << '\n';


// PROGRAM 2 //


```

## Sources
cplusplus.com: [_Exceptions_](https://www.cplusplus.com/doc/tutorial/exceptions/) <br />
cplusplus.com: [_std::exception_](https://www.cplusplus.com/reference/exception/exception/) <br />
TutorialsPoint: [_C++ Exception Handling_](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm) <br />
GeeksforGeeks: [_Exception Handling in C++_](https://www.geeksforgeeks.org/exception-handling-c/) <br />
Microsoft C++ Documentation: [_Modern C++ best practices for exceptions and error handling (2020)_](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160) <br />
isocpp.org: [_Exceptions and Error Handling_](https://isocpp.org/wiki/faq/exceptions) <br />
