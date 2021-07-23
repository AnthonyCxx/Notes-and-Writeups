# Exception Handling in C++
Exceptions are errors that occur during runtime, like a failure to allocate heap memory because there wasn't enough memory left ([_bad\_alloc_](https://www.cplusplus.com/reference/new/bad_alloc/)); exceptions can be managed through a process called _exception handling_. Exception handling allows you to deal
with errors in a way that allows the program to continue running seamlessly (hopefully). Sometimes, an exception cannot be truly 'recovered' from, but can only be dealt with,
in which case exception handing allows a graceful solution to be achieved.

Exception handling is preferable to only error checking (C-style error handling) as exception handling is distinct from the rest of the code and cannot be confused with
standard control flow; moreover, exception handling does not require the programmer to implcitly know that some generic _if_ statment is meant to handle an error because
the exception handling makes it abundently apparent.

## Try and Catch
Exception handling is fundamentally built upon two keywords: _try_ and _catch_. _try_ defines a block of code within which the programmer expects
an error may occur and _catch_ catches the error, defining a block that runs after the error occurs. In the following example, the _catch_ statement
catches a built-in error [_bad\_alloc_](https://www.cplusplus.com/reference/new/bad_alloc/) which is implicitly thrown when `new int[9223372036854775]` 
fails. If there were no catch _try_/_catch_ block, then the program would have crashed with the following message: <br />

_"terminate called after throwing an instance of 'std::bad_alloc'. <br />
what():  std::bad\_alloc.  <br />
Aborted (core dumped)"_ <br />

```C++
try
{
  //Always fails, array size is too large (~9.223 quadrillion bytes or 8 petabytes)
  int* massiveArray = new int[9223372036854775];
}
catch(bad_alloc)  //Fatal error caught, now the program won't crash.
{
  cout << "Error: array could not be allocated...\n";
}
```

## Sources
cplusplus.com: [_Exceptions_](https://www.cplusplus.com/doc/tutorial/exceptions/) <br />
cplusplus.com: [_std::exception_](https://www.cplusplus.com/reference/exception/exception/) <br />
TutorialsPoint: [_C++ Exception Handling_](https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm) <br />
GeeksforGeeks: [_Exception Handling in C++_](https://www.geeksforgeeks.org/exception-handling-c/) <br />
Microsoft C++ Documentation: [_Modern C++ best practices for exceptions and error handling (2020)_](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160) <br />
isocpp.org: [_Exceptions and Error Handling_](https://isocpp.org/wiki/faq/exceptions) <br />
