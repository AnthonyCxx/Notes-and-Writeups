# Catching Errors with _assert()_
C++ inherited the _assert()_ function from C and continues to use it as a viable way of catching errors. _assert()_ is a function under the [_\<cassert\>_](https://www.cplusplus.com/reference/cassert/)
library and is used for errors that ["should have never occured if all your code is correct"](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160#basic-guidelines). This is because unlike error handling, which is meant to deal with errors as they arise, _assert()_ terminates the program
if the expression inside it evaluates to false. If you want to test your program without the _assert()_ statements you've included, you can disable them by writing
`#define NDEBUG`.

Here, the _assert()_ catches the fact that I forgot to add a _break_ statement after the final case. I meant for the flow of execution to fall through to cases
1, 2, and 3, but not to the default case. The _assert()_ statement makes this clear.

```C++
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    int choice = 2;

    switch (choice)
    {
        case 1:
            cout << "Case 1 activated...\n";

        case 2:
            cout << "Case 2 activated...\n";

        case 3:
            cout << "Case 3 activated...\n";

        //This should never happen.
        default:
            assert(0);  //Always false
    }

    return 0;
}
```

## Sources
Microsoft C++ Documentation: [_Modern C++ best practices for exceptions and error handling (2020)_](https://docs.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160) <br />
isocpp.org: [_Exceptions and Error Handling_](https://isocpp.org/wiki/faq/exceptions) <br />
cplusplus.com: [_assert_](https://www.cplusplus.com/reference/cassert/assert/) <br />
StackOverflow: [_Why should I use asserts?_](https://stackoverflow.com/questions/1081409/why-should-i-use-asserts) <br />
